import java.io.BufferedInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.text.DecimalFormat;
 
public class Main {
 
    
    public static void solve() throws Exception{
        int T = in.readInt(),t = 0;
        String format = "Case #%d: ";
        int A, B, size, last, temp;
        double val, m[];
        double a[],ans;
        boolean b;
        while(t++<T){
            out.printf(format,t);
            A = in.readInt();
            B = in.readInt();
            size = 1;
            for(int i=0; i<A; i++)
                size *= 2;
            m = new double[A];
            a = new double[size];
            for(int i=0; i<size; i++)
                a[i] = 1.0;
            temp = size/2;
            last = -1;
            for(int i=0; i<A; i++){
                m[i] = in.readDouble();
                b = true;
                for(int j=0,k=0; j<size; j++,k++){
                    if(k == temp){
                        k = 0;
                        b = !b;
                    }
                    if(b)
                        a[j] *= m[i];
                    else
                        a[j] *= 1 - m[i];
                }
                temp /= 2;
                if(a[0] == 1)
                    last = i;
            }
            ans = 0;
            if(a[0] == 1){
                ans = B - A + 1;
            }
            else{
                ans = -1;
                for(int i=0; i<=A; i++){
                    temp = (int)Math.pow(2,i);
                    val = 0;
                    for(int j=0; j<temp; j++){
                        val += a[j] * (B - A + 1 + i * 2);
                    }
                    for(int j=temp; j<size; j++){
                        val += a[j] * (B - A + 2 + i * 2 + B);
                    }
                    if(ans == -1 || ans > val){
                        ans = val;
                    }
                }
                val = B + 2;
                if(ans == -1 || ans > val){
                    ans = val;
                }
            }
            DecimalFormat f = new DecimalFormat("#.000000");
            out.println(f.format(ans));
        }
    }

    static InputReader in;
    static OutputWriter out;
    
    public static void start(){
        in = new InputReader(System.in);
        out = new OutputWriter(System.out);
    }
        
    public static void finish() throws Exception{
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