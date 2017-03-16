import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.io.FileNotFoundException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Arrays;

public class ProblemA {
  public static void main(String[] args) throws FileNotFoundException {
//    InputStream inStream = System.in;
//    OutputStream outStream = System.out;
    InputStream inStream = new FileInputStream("A-small-attempt0.in");
    OutputStream outStream = new FileOutputStream("A-small-0.out");
    InputReader in = new InputReader(inStream);
    PrintWriter out = new PrintWriter(outStream);
    CounterCulture solver = new CounterCulture();
    int t = in.nextInt();
    for (int i = 1; i <= t; i++)
      solver.solve(i, in, out);
    out.close();
  }
}

class CounterCulture {
  public final int MAX = (int)1e6;
  public int[] dist;
  public CounterCulture() {
    dist = new int[MAX + 1];
    Arrays.fill(dist, Integer.MAX_VALUE);
    dist[1] = 1;
    for (int i = 1; i <= MAX; i++) {
      if (i + 1 <= MAX) dist[i + 1] = Math.min(dist[i] + 1, dist[i + 1]);
      int rev = reverse(i);
      if (rev <= MAX) dist[rev] = Math.min(dist[i] + 1, dist[rev]);
    }
  }
    
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    int n = in.nextInt();    
    out.println("Case #" + testNumber + ": " + dist[n]);
  }
  
  public int reverse(int n) {
    String str = Integer.toString(n);
    String answer = "";
    for (int i = str.length() - 1; i >= 0; i--)
      answer += str.charAt(i);
    return Integer.parseInt(answer);
  }
}

class InputReader {
  public BufferedReader reader;
  public StringTokenizer tokenizer;
  
  public InputReader(InputStream stream) {
    reader = new BufferedReader(new InputStreamReader(stream), 32678);
    tokenizer = null;
  }
  
  public String next() {
    while (tokenizer == null || !tokenizer.hasMoreTokens()) {
      try {
        tokenizer = new StringTokenizer(reader.readLine());
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
    }
    return tokenizer.nextToken();
  }
  
  public String nextLine() {
    String str = "";
    try {
      str = reader.readLine();
    } catch (IOException e) {
      throw new RuntimeException(e);
    }
    return str;
  }
  
  public int nextInt() {
    return Integer.parseInt(next());
  }
  
  public long nextLong() {
    return Long.parseLong(next());
  }
  
  public double nextDouble() {
    return Double.parseDouble(next());
  }
}

    
    