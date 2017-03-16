import java.io.*;
 
public class Main {
 
    static void solve() throws Exception{
        int T = in.readInt(),t = 0;
        String format = "Case #%d: %s%n";
        int N,j;
        long E,e,r,R,a;
        int[] v;
        while(t++<T){
            E = in.readLong();
            R = in.readLong();
            N = in.readInt();
            a = 0;
            e = E;
            v = new int[N];
            for(int i=0; i<N; i++){
                v[i] = in.readInt();
            }
            for(int i=0; i<N; i++){
                if(e == E)
                    r = R;
                else
                    r = R - (E - e);
                j = i+1;
                while(j < N && r < e && v[i] > v[j]){
                    r += R;
                    j++;
                }
                if(j >= N || r > e)
                    r = e;
                if(r > 0){
                    a += r * v[i];
                    e = e - r + R;
                }
                else
                    e += R;
            }
            out.printf(format,t,a);
        }
    }
    
    static InputReader in;
    static OutputWriter out;
    
    static void start() throws FileNotFoundException{
        //in = new InputReader(System.in);
        in = new InputReader(new FileInputStream(new File("test.in")));
        //out = new OutputWriter(System.out);
        out = new OutputWriter(new FileOutputStream(new File("test.out")));
    }
        
    static void finish() throws Exception{
        out.close();
    }
 
    public static void main(String[] args) throws Exception {
        start();
        solve();
        finish();
    }
}
 
class InputReader extends BufferedInputStream{
    
    public InputReader(InputStream In){
        super(In);
    }
    
    public char readChar() throws Exception{
        int c = read();
        while(isStringEnd(c))
            c = read();
        return (char) c;
    }
    
    public int readInt() throws Exception {
        int sign = 1;
        int cur = 0;
        int c = read();
        while(isStringEnd(c))
            c = read();
        if(c == '-'){
            sign = -1;
            c = read();
        }
        do{
            cur *= 10;
            cur += c - '0';
            c = read();
        }while(!isStringEnd(c));
        return cur*sign;
    }
    
    public long readLong() throws Exception {
        long sign = 1;
        long cur = 0;
        int c = read();
        while(isStringEnd(c))
            c = read();
        if(c == '-'){
            sign = -1;
            c = read();
        }
        do{
            cur *= 10;
            cur += c - '0';
            c = read();
        }while(!isStringEnd(c));
        return cur*sign;
    }
    
    public double readDouble() throws Exception {
        double sign = 1;
        double cur = 0;
        int c = read();
        while(isStringEnd(c))
            c = read();
        if(c == '-'){
            sign = -1;
            c = read();
        }
        do{
            cur *= 10;
            cur += c - '0';
            c = read();
        }while(!isStringEnd(c) && c!= '.');
        if(c == '.'){
            c = read();
            double r = 0.1;
            do{
                cur += r*(c - '0');
                r *= 0.1;
                c = read();
            }while(!isStringEnd(c) && c!= '.');
        }
        return cur*sign;
    }
    
    public String readStr() throws Exception{
        int c = readChar();
        while(isStringEnd(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do{
            res.append((char)c);
            c = read();
        }while(!isStringEnd(c));
        return res.toString();
    }
    
    public String readLine() throws Exception{
        int c = readChar();
        while(isStringEnd(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do{
            res.append((char)c);
            c = read();
        }while(!isEOL(c));
        return res.toString();
    }
    
    public char[] readCharArray(int s) throws Exception{
        char[] a = new char[s];
        for(int i=0; i<s; i++)
            a[i] = readChar();
        return a;
    }
    
    public int[] readIntArray(int s) throws Exception{
        int[] a = new int[s];
        for(int i=0; i<s; i++)
            a[i] = readInt();
        return a;
    }
    
    public long[] readLongArray(int s) throws Exception{
        long[] a = new long[s];
        for(int i=0; i<s; i++)
            a[i] = readLong();
        return a;
    }
        
    public double[] readDoubleArray(int s) throws Exception{
        double[] a = new double[s];
        for(int i=0; i<s; i++)
            a[i] = readDouble();
        return a;
    }
    
    public String[] readStrArray(int s) throws Exception{
        String[] a = new String[s];
        for(int i=0; i<s; i++)
            a[i] = readStr();
        return a;
    }
        
    public char[][] readCharMat(int rows,int cols) throws Exception{
        char[][] a = new char[rows][];
        for(int i=0; i<rows; i++)
            a[i] = readCharArray(cols);
        return a;
    }
    
    public int[][] readIntMat(int rows,int cols) throws Exception{
        int[][] a = new int[rows][];
        for(int i=0; i<rows; i++)
            a[i] = readIntArray(cols);
        return a;
    }
    
    public long[][] readLongMat(int rows,int cols) throws Exception{
        long[][] a = new long[rows][];
        for(int i=0; i<rows; i++)
            a[i] = readLongArray(cols);
        return a;
    }
        
    public double[][] readDoubleMat(int rows,int cols) throws Exception{
        double[][] a = new double[rows][];
        for(int i=0; i<rows; i++)
            a[i] = readDoubleArray(cols);
        return a;
    }
    
    public String[][] readStrMat(int rows,int cols) throws Exception{
        String[][] a = new String[rows][];
        for(int i=0; i<rows; i++)
            a[i] = readStrArray(cols);
        return a;
    }
        
    private boolean isStringEnd(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
    
    private boolean isEOL(int c) {
        return c == '\n' || c == '\r';
    }
}
 
class OutputWriter extends PrintWriter{
    
    public OutputWriter(OutputStream out){
        super(out);
    }
    
    public <T> void printArray(T[] a, String del){
        for(int i=0; i<a.length; i++){
            if(i!=0)
                print(del);
            print(a[i]);
        }
    }
    
    public <T> void printMat(T[][] a, String delRows, String delCols){
        for(int i=0; i<a.length; i++){
            if(i!=0)
                print(delRows);
            for(int j=0; i<a[i].length; i++){
                if(j!=0)
                    print(delCols);
                print(a[i][j]);
            }
        }
    }
    
    public <T> void printCollection(Iterable<T> c, String del){
        boolean b = true;
        for(T i : c){
            if(b)
                b = false;
            else
                print(del);
            print(i);
        }
    }
}