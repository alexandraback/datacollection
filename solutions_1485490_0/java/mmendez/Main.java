import java.io.BufferedInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
 
public class Main {
 
    public void solve() throws Exception{
        int T = in.readInt(),t = 0;
        String format = "Case #%d: ";
        int N,M;
        long count;
        List<Tuple<Long,Long>> a = new ArrayList<Tuple<Long,Long>>(),b = new ArrayList<Tuple<Long,Long>>();
        while(t++<T){
            out.printf(format,t);
            count = 0;
            N = in.readInt();
            M = in.readInt();
            a.clear();
            b.clear();
            for(int i=0; i<N; i++)
                a.add(new Tuple<Long,Long>(in.readLong(), in.readLong()));
            for(int i=0; i<M; i++)
                b.add(new Tuple<Long,Long>(in.readLong(), in.readLong()));
            count = asdf(N,M,a,b,0,0,0);
            out.println(count);
        }
    }
    
    private long asdf(int N, int M, List<Tuple<Long,Long>> a,List<Tuple<Long,Long>> b, long count, int k, int l){
        long t1,t2;
        List<Tuple<Long,Long>> a1, b1;
        for(int i=k,j=l; i<N && j<M;){
            if(a.get(i).y.equals(b.get(j).y)){
                if(a.get(i).x.compareTo(b.get(j).x) < 0){
                    count += a.get(i).x;
                    b.get(j).x -= a.get(i).x;
                    i++;
                }
                else
                if(a.get(i).x.compareTo(b.get(j).x) > 0){
                    count += b.get(j).x;
                    a.get(i).x -= b.get(j).x;
                    j++;
                }
                else
                if(a.get(i).x.equals(b.get(j).x)){
                    count += b.get(j).x;
                    i++;
                    j++;
                }
            }
            else{
                a1 = new ArrayList<Tuple<Long,Long>>();
                b1 = new ArrayList<Tuple<Long,Long>>();
                for(Tuple<Long,Long> w : a)
                    a1.add(new Tuple<Long,Long>(w.x,w.y));
                for(Tuple<Long,Long> w : b)
                    b1.add(new Tuple<Long,Long>(w.x,w.y));
                t1 = asdf(N,M,a1,b1,count,i+1,j);
                a1 = new ArrayList<Tuple<Long,Long>>();
                b1 = new ArrayList<Tuple<Long,Long>>();
                for(Tuple<Long,Long> w : a)
                    a1.add(new Tuple<Long,Long>(w.x,w.y));
                for(Tuple<Long,Long> w : b)
                    b1.add(new Tuple<Long,Long>(w.x,w.y));
                t2 = asdf(N,M,a1,b1,count,i,j+1);
                return t1 > t2 ? t1 : t2;
            }
        }
        return count;
    }
    
    InputReader in;
    OutputWriter out;
    
    public void start(){
        in = new InputReader(System.in);
        out = new OutputWriter(System.out);
    }
        
    public void finish() throws Exception{
        out.close();
    }
 
    public static void main(String[] args) throws Exception {
        Main m = new Main();
        m.start();
        m.solve();
        m.finish();
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

class Tuple<U,V> implements Comparable<Tuple<U,V>>{

    public U x;
    public V y;
    
    public Tuple(U f, V s){
        x = f;
        y = s;
    }
    
    @Override
    public int compareTo(Tuple<U, V> o) {
        int ans = ((Comparable<U>)x).compareTo(o.x);
        if(ans == 0)
            return ((Comparable<V>)y).compareTo(o.y);
        return ans;
    }
    
    @Override
    public String toString(){
        return x.toString() + " " + y.toString();
    }
}