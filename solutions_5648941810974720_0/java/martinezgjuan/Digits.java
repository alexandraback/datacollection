import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class Digits {
  
  static Reader sc = new Reader();
  static PrintWriter out = new PrintWriter(System.out);
  
  public static void main(String[] args) throws IOException {
    int t = sc.nextInt();
    
    for (int cas = 1; cas <= t; cas++) {
      char[] word =  sc.next().toCharArray();
      
      int[] count = new int[26];
      
      for (char c : word) {
        count[c - 'A']++;
      }
      
      int[] nums = new int[10];
      
      int times = count['W' - 'A'];
      nums[2] = times;
      
      count['T' - 'A'] -= times;
      count['W' - 'A'] -= times;
      count['O' - 'A'] -= times;
      
      times = count['X' - 'A'];
      nums[6] = times;
      
      count['S' - 'A'] -= times;
      count['I' - 'A'] -= times;
      count['X' - 'A'] -= times;
      
      times = count['Z' - 'A'];
      nums[0] = times;
      
      count['Z' - 'A'] -= times;
      count['E' - 'A'] -= times;
      count['R' - 'A'] -= times;
      count['O' - 'A'] -= times;
      
      times = count['U' - 'A'];
      nums[4] = times;
      
      count['F' - 'A'] -= times;
      count['O' - 'A'] -= times;
      count['U' - 'A'] -= times;
      count['R' - 'A'] -= times;
      
      times = count['G' - 'A'];
      nums[8] = times;
      
      count['E' - 'A'] -= times;
      count['I' - 'A'] -= times;
      count['G' - 'A'] -= times;
      count['H' - 'A'] -= times;
      count['T' - 'A'] -= times;
      
      times = count['O' - 'A'];
      nums[1] = times;
      
      count['O' - 'A'] -= times;
      count['N' - 'A'] -= times;
      count['E' - 'A'] -= times;

      times = count['R' - 'A'];
      nums[3] = times;
      
      count['T' - 'A'] -= times;
      count['H' - 'A'] -= times;
      count['R' - 'A'] -= times;
      count['E' - 'A'] -= times;
      count['E' - 'A'] -= times;
     
      times = count['F' - 'A'];
      nums[5] = times;
      
      count['F' - 'A'] -= times;
      count['I' - 'A'] -= times;
      count['V' - 'A'] -= times;
      count['E' - 'A'] -= times;

      times = count['I' - 'A'];
      nums[9] = times;
      
      count['N' - 'A'] -= times;
      count['I' - 'A'] -= times;
      count['N' - 'A'] -= times;
      count['E' - 'A'] -= times;
      
      times = count['V' - 'A'];
      nums[7] = times;
      
      count['S' - 'A'] -= times;
      count['E' - 'A'] -= times;
      count['V' - 'A'] -= times;
      count['E' - 'A'] -= times;
      count['N' - 'A'] -= times;
      
      out.print("Case #" + cas + ": ");
      
      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < nums[i]; j++) {
          out.print(i);
        }
      }
      
      out.println();
    }
    
    out.close();
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
