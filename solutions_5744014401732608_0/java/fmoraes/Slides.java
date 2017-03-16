import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.StringTokenizer;


public class Slides {
  public static void main(String[] args)
  {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    PrintWriter out = new PrintWriter(outputStream);
    Slides solver = new Slides();
    solver.solve(1, new InputStreamReader(inputStream), out);
    out.close();
  }
  
  long M;
  int B;
  long[][] C;

  boolean addPaths(boolean[][] m, int start, int dest)
  {
    for(int i = start + 1; i < dest; i++) {
      if(M == 0) return false;
      m[start][i] = true;
      m[i][dest] = true;
      M--;
    }
    
    if(M > 0) {
      for(int i= start + 1; i < dest; i++) {
        boolean r = addPaths(m, i, dest);
        if(!r) return false;
      }
    }
    
    return true;
  }
  
  public void solve(int test, Reader input, PrintWriter out)
  {
    MyScanner in = new MyScanner(input);
    
    // Get combinations using Pascal's triangle.
    C = new long[51][51];
    for(int i = 0; i <= 50; i++) {
      C[i][0] = 1;
      for(int j = 1; j <= i; j++) {
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
      }
    }
    
    int T = in.nextInt();
    
    for(int t = 1; t <= T; t++) {
      B = in.nextInt();
      M = in.nextInt();
      
      boolean[][] m = new boolean[B][B];
      
      long r = 1L;
      for(int i = 0; i < B - 2; i++)
        r = r << 1;
      if(M > r) {
        out.printf("Case #%d: IMPOSSIBLE\n", t);
      } else {
        m[0][B - 1] = true; // first path
        M--;
        addPaths(m, 0, B - 1);
        out.printf("Case #%d: POSSIBLE\n", t);
        StringBuilder sb = new StringBuilder();
        for(boolean[] i : m) {
          for(boolean b : i)
            if(b) sb.append('1');
            else sb.append('0');
          out.println(sb.toString());
          sb.setLength(0);
        }
      }
    }
  }

  //-----------MyScanner class for faster input----------
  public static class MyScanner {
    BufferedReader br;

    StringTokenizer st;

    public MyScanner(Reader reader)
    {
      br = new BufferedReader(reader);
    }

    String next()
    {
      while(st == null || !st.hasMoreElements()) {
        try {
          st = new StringTokenizer(br.readLine());
        }
        catch(IOException e) {
          e.printStackTrace();
        }
      }
      return st.nextToken();
    }

    String rest()
    {
      StringBuilder res = new StringBuilder();
      while(st != null && st.hasMoreTokens()) {
        res.append(st.nextToken());
        if(st.hasMoreTokens())
          res.append(' ');
      }
      return res.toString();
    }

    int nextInt()
    {
      return Integer.parseInt(next());
    }

    int[] nextIntArray(int n)
    {
      int[] r = new int[n];
      for(int i = 0; i < n; i++)
        r[i] = nextInt();
      return r;
    }

    long nextLong()
    {
      return Long.parseLong(next());
    }

    double nextDouble()
    {
      return Double.parseDouble(next());
    }

    String nextLine()
    {
      String str = "";
      try {
        str = br.readLine();
      }
      catch(IOException e) {
        e.printStackTrace();
      }
      return str;
    }

  }
  //--------------------------------------------------------
}
