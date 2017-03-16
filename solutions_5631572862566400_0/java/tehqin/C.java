
import java.util.*;
import java.io.*;

public class C
{
   public static void main(String[] args) throws Exception
   {
      FastScanner in = new FastScanner(System.in);
      PrintWriter out = new PrintWriter(System.out);
      int T = in.nextInt();
      for (int tc=1; tc<=T; tc++)
         new C(tc, in, out);
      out.close();
   }

   int N;
   int[] nxt;
   ArrayList<Integer>[] children;

   int dfs(int i, int p, int d)
   {
      int res = d;
      for (int j : children[i]) if (p != j)
         res = Math.max(res, dfs(j, i, d+1));
      return res; 
   }

   public C(int tc, FastScanner in, PrintWriter out)
   {
      N = in.nextInt();
      nxt = new int[N];
      for (int i=0; i<N; i++)
         nxt[i] = in.nextInt()-1;
      children = new ArrayList[N];
      for (int i=0; i<N; i++)
         children[i] = new ArrayList<>();
  
      int res = 0;
      boolean[] seen = new boolean[N];
      for (int i=0; i<N; i++)
      {
         Arrays.fill(seen, false);
         int len = 0;
         int cur = i;
         while (!seen[cur])
         {
            len++;
            seen[cur] = true;
            cur = nxt[cur];
         }

         if (cur == i)
            res = Math.max(res, len);
      }
      for (int i=0; i<N; i++)
         children[nxt[i]].add(i);

      int rr = 0;
      for (int i=0; i<N; i++) if (i < nxt[i] && i == nxt[nxt[i]])
         rr += dfs(i, nxt[i], 1)+dfs(nxt[i], i, 1);
      res = Math.max(res, rr);
      out.printf("Case #%d: %d%n", tc, res);
   }
}

class FastScanner{
   private InputStream stream;
   private byte[] buf = new byte[1024];
   private int curChar;
   private int numChars;

   public FastScanner(InputStream stream)
   {
      this.stream = stream;
   }

   int read()
   {
      if (numChars == -1)
         throw new InputMismatchException();
      if (curChar >= numChars){
         curChar = 0;
         try{
            numChars = stream.read(buf);
         } catch (IOException e) {
            throw new InputMismatchException();
         }
         if (numChars <= 0)
            return -1;
      }
      return buf[curChar++];
   }

   boolean isSpaceChar(int c)
   {
      return c==' '||c=='\n'||c=='\r'||c=='\t'||c==-1;
   }
   
   boolean isEndline(int c)
   {
      return c=='\n'||c=='\r'||c==-1;
   }

   int nextInt()
   {
      return Integer.parseInt(next());
   }
   
   long nextLong()
   {
      return Long.parseLong(next());
   }

   double nextDouble()
   {
      return Double.parseDouble(next());
   }

   String next(){
      int c = read();
      while (isSpaceChar(c))
         c = read();
      StringBuilder res = new StringBuilder();
      do{
         res.appendCodePoint(c);
         c = read();
      }while(!isSpaceChar(c));
      return res.toString();
   }
   
   String nextLine(){
      int c = read();
      while (isEndline(c))
         c = read();
      StringBuilder res = new StringBuilder();
      do{
         res.appendCodePoint(c);
         c = read();
      }while(!isEndline(c));
      return res.toString();
   }
}
