import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class Slides {
  
  static Reader sc = new Reader();
  static PrintWriter out = new PrintWriter(System.out);
  
  public static void main(String[] args) throws IOException {
    int t = sc.nextInt();
    
    for (int cas = 1; cas <= t; cas++) {
      int n = sc.nextInt();
      int m = sc.nextInt();
      
      boolean[][] mat = new boolean[6][6];
      boolean done = false;
      
      for (int i5 = 0; i5 < (1 << 5) && !done; i5++) {
        for (int bit = 0; bit < n; bit++) {
          if ((i5 & (1 << bit)) != 0) {
            mat[0][1 + bit] = true;
          }
        }
        for (int i4 = 0; i4 < (1 << 4) && !done; i4++) {
          for (int bit = 0; bit < n; bit++) {
            if ((i4 & (1 << bit)) != 0) {
              mat[1][2 + bit] = true;
            }
          }
          for (int i3 = 0; i3 < (1 << 3) && !done; i3++) {
            for (int bit = 0; bit < n; bit++) {
              if ((i3 & (1 << bit)) != 0) {
                mat[2][3 + bit] = true;
              }
            }
            for (int i2 = 0; i2 < (1 << 2) && !done; i2++) {
              for (int bit = 0; bit < n; bit++) {
                if ((i2 & (1 << bit)) != 0) {
                  mat[3][4 + bit] = true;
                }
              }
              for (int i1 = 0; i1 < (1 << 1) && !done; i1++) {
                for (int bit = 0; bit < n; bit++) {
                  if ((i1 & (1 << bit)) != 0) {
                    mat[4][5 + bit] = true;
                  }
                }
                int ways = getWays(mat, 6 - n, n);
                if (ways == m) {
                  done = true;
                  out.println("Case #" + cas + ": " + "POSSIBLE");
                  for (int i = 6 - n; i < 6; i++) {
                    for (int j = 6 - n; j < 6; j++) {
                      if (mat[i][j]) {
                        out.print("1");
                      } else {
                        out.print("0");
                      }
                    }
                    out.println();
                  }
                }
                for (int bit = 0; bit < n; bit++) {
                  mat[4][bit] = false;
                }
              }
              for (int bit = 0; bit < n; bit++) {
                mat[3][bit] = false;
              }
            }
            for (int bit = 0; bit < n; bit++) {
              mat[2][bit] = false;
            }
          }
          for (int bit = 0; bit < n; bit++) {
            mat[1][bit] = false;
          }
        }
        for (int bit = 0; bit < n; bit++) {
            mat[0][bit] = false;
        }
      }
      
      if (!done) {
        out.println("Case #" + cas + ": " + "IMPOSSIBLE");   
      }
       
    }
    
    out.close();
  }
  
  static int getWays(boolean[][] mat, int cur, int n) {
    if (cur == 5) {
      return 1;
    }
    int res = 0;
    for (int i = 0; i < 6; i++) {
      if (mat[cur][i]) {
        res += getWays(mat, i, n);
      }
    }
    return res;
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
