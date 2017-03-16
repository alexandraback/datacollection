import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class Titles {
  
  static Reader sc = new Reader();
  static PrintWriter out = new PrintWriter(System.out);
  
  static String[][] titles;
  static int[][] dp; // set last
  static int n;
  
  public static void main(String[] args) throws IOException {
    int t = sc.nextInt();
    
    for (int cas = 1; cas <= t; cas++) {
      
      n  = sc.nextInt();
      titles = new String[n][2];
      
      int res = 0;
      
      for (int i = 0; i < n; i++) {
        titles[i][0] = sc.next();
        titles[i][1] = sc.next();
      }
      
      int full = power(2, n);
      
      dp =  new int[full][n];
      
      for (int i = 0; i < full; i++) {
        Arrays.fill(dp[i], -1);
      }
      
      for (int i = 0; i < n; i++) {
        res = Math.max(res, get(full - 1, i));
      }
      
      out.println("Case #" + cas + ": " + res);  
    }
    
    out.close();
  }
  
  public static int get(int set, int last) {
    if (dp[set][last] != -1) {
      return dp[set][last];
    }
    
    if (set == 0) {
      dp[set][last] = 0;
      return 0;
    }
    
    boolean hasFirst = false;
    boolean hasSecond = false;
    
    for (int i = 0; i < n; i++) {
      if (i == last) {
        continue;
      }
      if ((set & (1 << i)) != 0) {
        if (titles[i][0].equals(titles[last][0])) {
          hasFirst = true;
        }
        if (titles[i][1].equals(titles[last][1])) {
          hasSecond = true;
        }
      }
    }
    
    int toAdd = hasFirst && hasSecond ? 1 : 0;
    
    int max = 0;
    
    int before = clearBit(set, last);
    
    for (int i = 0; i < n; i++) {
      if ((before & (1 << i)) != 0 ) {
        max = Math.max(max, get(before, i));
      }
    }
    
    dp[set][last] = max + toAdd;
    return max + toAdd;
  }
  
  static int clearBit(int S, int j) {
    return S & ~(1 << j);
  }
  
  public static int power(int base,  int exp) {
    int result = 1;
    int power = base;
    while (exp > 0) {
      if (exp % 2 == 1) 
        result = result * power;
      power = power * power;
      exp = exp / 2;
    }
    return result;
  }
  
  static class Reader {
    final private int BUFFER_SIZE = 1 << 12; private byte[] buffer; private int bufferPointer, bytesRead; private boolean eof = false;
    public Reader() {buffer = new byte[BUFFER_SIZE];bufferPointer = bytesRead = 0;}
    public boolean reachedEOF() {return eof;}
    private void fillBuffer() throws IOException {bytesRead = System.in.read(buffer, bufferPointer = 0, BUFFER_SIZE); if (bytesRead == -1) { buffer[0] = -1;eof = true;}}
    private byte read() throws IOException {if (bufferPointer == bytesRead)fillBuffer();return buffer[bufferPointer++];}
    public String next() throws IOException {StringBuilder sb = new StringBuilder();byte c;while ((c = read()) <= ' ') {if (c == -1)return null;};do {sb.append((char) c);} while ((c = read()) > ' ');if (sb.length() == 0)return null;return sb.toString();}
    public String nextLine() throws IOException {StringBuilder sb = new StringBuilder();byte c;boolean read = false;while ((c = read()) != -1) {if (c == '\n') {read = true;break;}if (c >= ' ')sb.append((char) c);}if (!read)return null;return sb.toString();}
    public int nextInt() throws IOException {int ret = 0;byte c = read();while (c <= ' ')c = read();boolean neg = (c == '-');if (neg)c = read();do {ret = ret * 10 + c - '0';} while ((c = read()) >= '0' && c <= '9');if (neg)return -ret;return ret;}
    public long nextLong() throws IOException {long ret = 0;byte c = read();while (c <= ' ')c = read();boolean neg = (c == '-');if (neg)c = read();do {ret = ret * 10L + c - '0';} while ((c = read()) >= '0' && c <= '9');if (neg)return -ret;return ret;}
    public double nextDouble() throws IOException {double ret = 0, div = 1;byte c = read();while (c <= ' ')c = read();boolean neg = (c == '-');if (neg)c = read();do {ret = ret * 10 + c - '0';} while ((c = read()) >= '0' && c <= '9');if (c == '.')while ((c = read()) >= '0' && c <= '9')ret += (c - '0') / (div *= 10);if (neg)return -ret;return ret;}
    public int[] nextIntArrray(int n) throws IOException {int[] a = new int[n];for (int i = 0; i < n; i++)a[i] = nextInt();return a;}
    public int[][] nextIntMatrix(int n, int m) throws IOException {int[][] map = new int[n][m];for (int i = 0; i < n; i++)map[i] = nextIntArrray(m);return map;}
    public char[][] nextCharacterMatrix(int n) throws IOException {char[][] a = new char[n][];for (int i = 0; i < n; i++)a[i] = next().toCharArray();return a;}
    public void close() throws IOException {if (System.in == null)return;System.in.close();}
  }
  
  static void print(int[] A) {for(int i=0;i<A.length;i++){if(i!=0) out.print(' ');out.print(A[i]);}out.println();}
  static <T> void print(Iterable<T> A) {int i = 0;for(T act : A){if(i!=0)out.print(' ');out.print(act);i++;}out.println();}
  static void printPlus1(Iterable<Number> A) {int i = 0;for(Number act : A){if(i!=0)out.print(' ');out.print(act.longValue() + 1L);i++;}out.println();}
  static void debug(Object... o) { System.err.println(Arrays.deepToString(o)); }
  
  /*
  long s = System.currentTimeMillis();
  debug(System.currentTimeMillis()-s+"ms");
   */
}
