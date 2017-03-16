import java.io.BufferedInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.Stack;
 
public class Main {
 
    public void solve() throws Exception{
        int T = in.readInt(),t = 0;
        String format = "Case #%d: ";
        int N,M,temp;
        boolean ans;
        HashMap<Integer,List<Integer>> y = new HashMap<Integer,List<Integer>>();
        Set<Integer> x = new HashSet<Integer>();
        List<Integer> l;
        while(t++<T){
            out.printf(format,t);
            y.clear();
            x.clear();
            N = in.readInt();
            ans = false;
            for(int i=0; i<N;){
                M = in.readInt();
                l = new ArrayList<Integer>();
                for(int j=0; j<M; j++){
                    temp = in.readInt();
                    l.add(temp);
                    x.add(temp);
                }
                y.put(++i, l);
            }
            for(int i=1; i<=N && !ans; i++){
                if(!x.contains(i)){
                    ans = DFS(i,y);
                }
            }
            out.println(ans ? "Yes" : "No");
        }
    }
    
    private boolean DFS(int primerNodo, HashMap<Integer,List<Integer>> x){
        Stack<Integer> lista = new Stack<Integer>(); 
        List<Integer> visitados = new ArrayList<Integer>();
        int temp;
        lista.add(primerNodo); 
        visitados.add(primerNodo);
        while(!lista.isEmpty()){
            temp = lista.pop();
            for(int i : x.get(temp)){
                if(visitados.contains(i))
                    return true;
            }
            lista.addAll(x.get(temp));
            visitados.addAll(x.get(temp));
        }
        return false;
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