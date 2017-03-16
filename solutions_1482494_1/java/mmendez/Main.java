import java.io.BufferedInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
 
public class Main {
 
    
    public static void solve() throws Exception{
        int T = in.readInt(),t = 0;
        String format = "Case #%d: ";
        long current;
        long games;
        int N,a,b;
        List<Tuple<Integer,Integer>> miss = new ArrayList<Tuple<Integer,Integer>>();
        List<Tuple<Integer,Integer>> rem = new ArrayList<Tuple<Integer,Integer>>();
        while(t++<T){
            out.printf(format,t);
            rem.clear();
            miss.clear();
            N = in.readInt();
            current = 0;
            games = 0;
            for(int i=0; i<N; i++){
                a = in.readInt();
                b = in.readInt();
                    miss.add(new Tuple(a,b));
            }
            games = s(miss,rem,current,games,new ArrayList<Tuple<Integer,Integer>>());
            out.println(games == -1 ? "Too Bad" : games);
        }
    }

    static long s(List<Tuple<Integer,Integer>> miss, List<Tuple<Integer,Integer>> rem, long current, long games, List<Tuple<Integer,Integer>> donex){
        boolean f = false, first = true;
        while(!miss.isEmpty() && (!rem.isEmpty() || first)){
            rem.clear();
            first = false;
            for(int j=0; j<miss.size(); j++){
                Tuple<Integer,Integer> i = miss.get(j);
                if(current >= i.y){
                    if(donex.contains(i)){
                        current++;
                        donex.remove(i);
                    }
                    else{
                        current+=2;
                    }
                    games++;
                    rem.add(i);
                    f = true;
                }
            }
            for(Tuple<Integer,Integer> i : rem){
                miss.remove(i);
            }
        }
        int best = -1, besty = -1, bestx = -1;
        if(!miss.isEmpty()){
            f = false;
            for(int j=0; j<miss.size(); j++){
                Tuple<Integer,Integer> i = miss.get(j);
                if(current >= i.x){
                    if(best == -1 || besty < i.y){
                        best = j;
                        besty = i.y;
                        bestx = i.x;
                        f = true;
                    }
                }
            }
            if(f){
                current++;
                games++;
                Tuple<Integer,Integer> i = miss.get(best);
                i.x = i.y;
                if(i.y <= current){
                    current++;
                    games++;
                    miss.remove(i);
                }
                else
                    donex.add(i);
                return games = s(miss,rem,current,games,donex);
            }
            else
                return -1;
        }
        return games;
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

class Tuple<U,V> implements Comparable<Tuple<U,V>>{

    public U x;
    public V y;
    
    public Tuple(U f, V s){
        x = f;
        y = s;
    }
    
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