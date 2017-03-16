import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.StringTokenizer;


public class CloseMatch {
  public static void main(String[] args)
  {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    PrintWriter out = new PrintWriter(outputStream);
    CloseMatch solver = new CloseMatch();
    solver.solve(1, new InputStreamReader(inputStream), out);
    out.close();
  }
  static class Pair implements Comparable<Pair> {
    long first;

    long second;

    Pair(long f, long s)
    {
      first = f;
      second = s;
    }

    public int compareTo(Pair o)
    {
      int r = Long.compare(first,  o.first);

      if(r == 0)
        r = Long.compare(second, o.second);

      return r;
    }
    @Override
    public String toString()
    {
      return "Pair(" + first + "," + second + ")";
    }
  }


  long[] dpc;
  long[] dpj;
  
  char[] coders;
  char[] jammers;

  int N;
  
  static final int LT = 1;
  static final int EQ = 0;
  static final int GT = 2;
  
  Pair compare(Pair o, Pair t)
  {
    long d1 = Math.abs(o.first - o.second);
    long d2 = Math.abs(t.first- t.second);
    
    int r = Long.compare(d1, d2);
    if(r < 0)
      return o;
    else if(r > 0)
      return t;
    
    r = Long.compare(o.first, t.first);
    if(r < 0)
      return o;
    else if(r > 0)
      return t;
    
    r = Long.compare(o.second, t.second);
    if(r < 0)
      return o;
    else if(r > 0)
      return t;
    return o;
  }
  
  Pair solve(int index, long sc, long sj)
  {
    if(index == N) return new Pair(sc, sj);
    
    char cc = coders[index];
    char cj = jammers[index];
    sc *= 10;
    sj *= 10;
    Pair res;
    if(cc == cj && cc == '?') {
      res = solve(index + 1, sc, sj);
      for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
          Pair p = solve(index + 1, sc + i, sj + j);
          res = compare(res, p);
        }
      }
    } else if(cc == '?') {
      int d = cj - '0';
      res = solve(index + 1, sc, sj + d);
      for(int i = 1; i < 10; i++) {
        Pair p = solve(index + 1, sc + i, sj + d);
        res = compare(res, p);
      }
    } else if(cj == '?') {
      int d = cc - '0';
      res = solve(index + 1, sc + d, sj);
      for(int i = 1; i < 10; i++) {
        Pair p = solve(index + 1, sc + d, sj + i);
        res = compare(res, p);
      }
    } else {
      res = solve(index + 1, sc + cc - '0', sj + cj - '0');
    }
    return res;
  }
    
  public void solve(int test, Reader input, PrintWriter out)
  {
    MyScanner in = new MyScanner(input);

    int T = in.nextInt();
    
    for(int t = 1; t <= T; t++) {
      coders = in.next().toCharArray();
      jammers = in.next().toCharArray();
      N = coders.length;
      
      Pair res = solve(0, 0, 0);
      
      String format = "Case #%d: %0" + N + "d %0" + N + "d\n";
      
      out.printf(format, t, res.first, res.second);
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
