

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class CoinJam {
  
  /*
   * We note that in the large case, there are only 2^30 possible values, which
   * is iterable so we can just brute force solve.
   * 
   * Uses Pollard rho factorization
   */
  public void solve() throws IOException {
    int T = nextInt();
    for (int t = 1; t <= T; t++) {
      int N = nextInt();
      int J = nextInt();
      
      out.format("Case #%d:%n", t);
      
      boolean[] bitmask = new boolean[N - 2];
      int count = 0;
      while (count < J) {
        BigInteger[] factors = new BigInteger[9];
        boolean success = true;
        for (int base = 2; base <= 10; base++) {
          BigInteger value = BigInteger.ONE;
          BigInteger biBase = BigInteger.valueOf(base);
          
          for (int i = 0; i < N - 2; i++) {
            if (bitmask[i]) {
              value = value.add(biBase.pow(i + 1));
            }
          }
          value = value.add(biBase.pow(N - 1));
          
          if (value.isProbablePrime(10)) {
            success = false;
            break;
          } else {
            // Pollard rho
            BigInteger x = BigInteger.valueOf(2);
            BigInteger y = BigInteger.valueOf(2);
            BigInteger d = BigInteger.ONE;
            while (d.compareTo(BigInteger.ONE) == 0) {
              x = x.pow(2).add(BigInteger.ONE).mod(value);
              y = y.pow(2).add(BigInteger.ONE).mod(value)
                   .pow(2).add(BigInteger.ONE).mod(value);
              d = x.subtract(y).gcd(value);
            }
            if (d.compareTo(value) != 0) {
              factors[base - 2] = d;
            } else {
              success = false;
              break;
            }
          }
        }
        if (success) {
          count++;
          StringBuilder sb = new StringBuilder("1");
          for (int i = N - 3; i >= 0; i--) {
            if (bitmask[i]) {
              sb.append(1);
            } else {
              sb.append(0);
            }
          }
          sb.append(1);
          
          System.out.println(sb.toString() + " " + count);
          out.print(sb.toString());
          for (int i = 0; i < 9; i++) {
            out.print(" ");
            out.print(factors[i].toString());
          }
          out.println();
        }
        
        // Increment bitmask
        for (int i = 0; i < N - 2; i++) {
          if (!bitmask[i]) {
            bitmask[i] = true;
            break;
          } else {
            bitmask[i] = false;
          }
        }
      }
    }
  }

  public BufferedReader br;
  public StringTokenizer st;
  public PrintWriter out;

  public String nextToken() throws IOException {
    while (st == null || !st.hasMoreTokens()) {
      st = new StringTokenizer(br.readLine());
    }

    return st.nextToken();
  }

  public String nextLine() throws IOException {
    return br.readLine();
  }

  public int nextInt() throws IOException {
    return Integer.parseInt(nextToken());
  }

  public long nextLong() throws IOException {
    return Long.parseLong(nextToken());
  }

  public double nextDouble() throws IOException {
    return Double.parseDouble(nextToken());
  }

  public void run() throws IOException {
    boolean oj = System.getProperty("ONLINE_JUDGE") != null;
    oj = false;
    br = new BufferedReader(
        new InputStreamReader(oj ? System.in : new FileInputStream("input.txt")));
    out = new PrintWriter(oj ? System.out : new FileOutputStream("output.txt"));
    solve();
    out.close();
  }

  public static void main(String[] args) throws IOException {
    new CoinJam().run();
  }
}
