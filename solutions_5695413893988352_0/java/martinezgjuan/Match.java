import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class Match {
  
  static Reader sc = new Reader();
  static PrintWriter out = new PrintWriter(System.out);
  
  public static void main(String[] args) throws IOException {
    int t = sc.nextInt();
    
    for (int cas = 1; cas <= t; cas++) {
      
      char[] c = sc.next().toCharArray();
      char[] j = sc.next().toCharArray();
      
      int missing = 0;
      for (char ch : c) {
        if (ch == '?') {
          missing++;
        }
      }
      for (char ch : j) {
        if (ch == '?') {
          missing++;
        }
      }
      
      int max = 1;
      for (int i = 0; i < missing; i++) {
        max *= 10;
      }
      
      int bestC = 100000000;
      int bestJ = 0;
      int bestDiff = 100000000;
      
      for (int i = 0; i < max; i++) {
        String curNum = i +"";
        curNum = padLeft(curNum, missing, '0');
        
        int checked = 0;
        
        StringBuilder curC = new StringBuilder();
        StringBuilder curJ = new StringBuilder();
        
        for (int k = 0; k < c.length; k++) {
          if (c[k] != '?') {
            curC.append(c[k]);
          } else {
            curC.append(curNum.charAt(checked));
            checked++;
          }
        }
        
        for (int k = 0; k < j.length; k++) {
          if (j[k] != '?') {
            curJ.append(j[k]);
          } else {
            curJ.append(curNum.charAt(checked));
            checked++;
          }
        }
        
        int curCint = Integer.parseInt(curC.toString());
        int curJint = Integer.parseInt(curJ.toString());
        int curDiff = Math.abs(curCint - curJint);
        
        if (curDiff < bestDiff) {
          bestC = curCint;
          bestJ = curJint;
          bestDiff = curDiff;
        } else if (curDiff == bestDiff) {
          if (curCint < bestC) {
            bestC = curCint;
            bestJ = curJint;
            bestDiff = curDiff;
          } else if (curCint == bestC && curJint < bestJ) {
            bestC = curCint;
            bestJ = curJint;
            bestDiff = curDiff;
          }
        }
      }
      
      out.println("Case #" + cas + ": " + padLeft(bestC+"", c.length, '0') + " " + padLeft(bestJ+"", j.length, '0'));  
    }
    
    out.close();
  }
  
  public static String padLeft(String str, int n, char c) {
    if (str.length() >= n) {
      return str;
    }
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < n - str.length(); i++) {
      sb.append(c);
    }
    sb.append(str);
    return sb.toString();
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
