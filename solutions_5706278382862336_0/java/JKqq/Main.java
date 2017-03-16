import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main
{
  static BufferedReader reader;
  static StringTokenizer tokenizer;
  static PrintWriter writer;
  
  static int nextInt() throws IOException
  {
    return Integer.parseInt(nextToken());
  }
  
  static long nextLong() throws IOException
  {
    return Long.parseLong(nextToken());
  }
  
  static double nextDouble() throws IOException
  {
    return Double.parseDouble(nextToken());
  }
  
  static boolean eof = false;
  
  static String nextToken() throws IOException
  {
    while (tokenizer == null || !tokenizer.hasMoreTokens())
    {
      tokenizer = new StringTokenizer(reader.readLine());
    }
    return tokenizer.nextToken();
  }
  
  public static void main(String[] args) throws IOException
  {
    tokenizer = null;
    reader = new BufferedReader(new FileReader("in"));
    writer = new PrintWriter(new FileWriter("out.txt"));
    banana();
    reader.close();
    writer.close();
  }
  
  static long gcd(long x, long y)
  {
    if (y == 0)
      return x;
    return gcd(y, x % y);
  }
  
  static void banana() throws IOException
  {
    int n = nextInt();
    Set<Long> s = new HashSet<Long>();
    long cur = 1;
    for (int i = 0; i < 41; ++i, cur *= 2)
      s.add(cur);
    
    for (int i = 0; i < n; ++i)
    {
      writer.print("Case #" + (i + 1) + ": ");
      String t = nextToken();
      
      String p[] = t.split("/");
      long x = Long.parseLong(p[0]);
      long y = Long.parseLong(p[1]);
      
      long xx = x / gcd(x, y);
      long yy = y / gcd(x, y);
      
      
      if (!s.contains(yy))
      {
        writer.println("impossible");
      }
      else
      {
        if (yy == 1)
        {
          if (xx == 0)
            writer.println("impossible");
          else
            writer.println("1");
        }
        int counter = 1;
        while (xx < yy/2)
        {
          yy /= 2;
          counter++;
        }
        writer.println(counter);
      }
    }
  }
}