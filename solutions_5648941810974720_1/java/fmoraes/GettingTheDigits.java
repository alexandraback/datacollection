import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.StringTokenizer;


public class GettingTheDigits {
  public static void main(String[] args)
  {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    PrintWriter out = new PrintWriter(outputStream);
    GettingTheDigits solver = new GettingTheDigits();
    solver.solve(1, new InputStreamReader(inputStream), out);
    out.close();
  }
  
  static final String[] NUMS = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
  
  void updateCounts(int[] cnt, String w)
  {
    for(int i = 0; i < w.length(); i++)
      cnt[w.charAt(i) - 'A']--;
  }
  
  String solve(String s)
  {
    int[] counts = new int[10];
    
    char[] c = s.toCharArray();
    
    int[] cnt = new int[26];
    
    for(char ch : c) {
      cnt[ch - 'A']++;
    }
    while(cnt[25] > 0) {
      counts[0]++;
      updateCounts(cnt, NUMS[0]);
    }
    while(cnt[22] > 0) {
      counts[2]++;
      updateCounts(cnt, NUMS[2]);
    }
    while(cnt[20] > 0) {
      counts[4]++;
      updateCounts(cnt, NUMS[4]);
    }
    while(cnt[23] > 0) {
      counts[6]++;
      updateCounts(cnt, NUMS[6]);
    }
    while(cnt[6] > 0) {
      counts[8]++;
      updateCounts(cnt, NUMS[8]);
    }
    while(cnt[5] > 0) {
      counts[5]++;
      updateCounts(cnt, NUMS[5]);
    }
    while(cnt[19] > 0) {
      counts[3]++;
      updateCounts(cnt, NUMS[3]);
    }
    while(cnt[14] > 0) {
      counts[1]++;
      updateCounts(cnt, NUMS[1]);
    }
    while(cnt[18] > 0) {
      counts[7]++;
      updateCounts(cnt, NUMS[7]);
    }
    while(cnt[4] > 0) {
      counts[9]++;
      updateCounts(cnt, NUMS[9]);
    }
    StringBuilder res = new StringBuilder();
    for(int i = 0; i < 10; i++) {
      for(int j = 0; j < counts[i]; j++)
        res.append(i);
    }
    return res.toString();
  }

  public void solve(int test, Reader input, PrintWriter out)
  {
    MyScanner in = new MyScanner(input);
    
    int T = in.nextInt();
    
    for(int t = 1; t <= T; t++) {
      String s = in.next();
      
      String r = solve(s);
      
      out.printf("Case #%d: %s\n", t, r);
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
