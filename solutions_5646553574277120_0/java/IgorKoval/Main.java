//import java.awt.Dimension;
import java.awt.Point;
import java.io.*;
import static java.lang.Math.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import static java.math.BigInteger.*;
import java.util.*;
import static java.util.Arrays.*;
//import java.math.BigInteger;
//import static java.lang.Character.*;
//import static java.lang.Math.*;
//import static java.math.BigInteger.*;

//import static java.util.Arrays.*;

//import java.awt.Point; // interger !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//import java.awt.Polygon;
//import java.awt.Rectangle;
//import java.awt.geom.AffineTransform;
//import java.awt.geom.Line2D;
//import java.awt.geom.Point2D;
//import javafx.scene.shape.Line;
//import javafx.scene.transform.Rotate;

//<editor-fold defaultstate="collapsed" desc="Main">
public class Main implements Runnable{

    // https://netbeans.org/kb/73/java/editor-codereference_ru.html#display

    static boolean oj;
    
    @Override
    public void run(){
        try {
            Locale.setDefault(Locale.US);
        } catch (Exception e) {
        }
        oj = true;
        try {
            oj = System.getProperty("MYLOCAL") == null;
        } catch (Exception e) {
        }
//
        if (oj) {
            sc = new FastScanner(new InputStreamReader(System.in));
            out = new PrintWriter(new OutputStreamWriter(System.out));
        } else {
            try {
                sc = new FastScanner(new FileReader("input.txt"));
                out = new PrintWriter(new FileWriter("output.txt"));
            } catch (IOException e) {
                MLE();
            }
        }
        Solver s = new Solver();
        s.sc = sc;
        s.out = out;

        s.solve();
        if (!oj) {
            err.println("Time: " + (System.currentTimeMillis() - timeBegin) / 1e3);
            err.printf("Mem: %d\n", (Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) >> 20);
        }
        out.flush();
    }

    private void show(int[] arr) {
        for (int v : arr) {
            err.print(" " + v);
        }
        err.println();
    }

    public static void exit() {
        err.println("Time: " + (System.currentTimeMillis() - timeBegin) / 1e3);
        err.printf("Mem: %d\n", (Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) >> 20);
        out.flush();
        out.close();
        System.exit(0);
    }

    public static void MLE() {
        int[][] arr = new int[1024 * 1024][];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = new int[1024 * 1024];
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        //new Main().run();
        new Thread(null, new Main(), "myThread", 100 * 1024 * 1024).start();
    }

    static long timeBegin = System.currentTimeMillis();
    static FastScanner sc;
    static PrintWriter out;
    static PrintStream err = System.err;
}
    //</editor-fold>

//<editor-fold defaultstate="collapsed" desc="FastScanner">
class FastScanner {

    BufferedReader br;
    StringTokenizer st;

    FastScanner(InputStreamReader reader) {
        br = new BufferedReader(reader);
        st = new StringTokenizer("");
    }

    String next() {
        while (!st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception ex) {
                return null;
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }

    String nextLine() {
        try {
            return br.readLine();
        } catch (IOException ex) {
            return null;
        }
    }
}
//</editor-fold>

class Solver {

    void aser(boolean OK) {
        if (!OK) {
            Main.MLE();
        }
    }

    FastScanner sc;
    PrintWriter out;
    static PrintStream err = System.err;

    
    /*/
    int S;
    char[] keys;
    String tag;
    char[] str;
    long sum, cntAll;
    long maxCnt = 0;
    
    int getCnt( String str ){
        int cnt = 0;
        for (int i = 0; i < str.length(); i++) 
            if( str.substring(i).startsWith(tag) )
                ++cnt;
        maxCnt = max(cnt, maxCnt);
        return cnt;
    }
    
    void f(int pos){
        if( pos == str.length ){
            sum += getCnt(new String(str));
            //err.println(new String(str));
            ++cntAll;
            //if( cntAll%100==0 )err.println(cntAll);
        } else {
            for( char ch : keys ){
                str[pos] = ch;
                f( pos + 1 );
            }
        }
    }
    
    String solveTest(){
        sc.next();
        sc.next();
        S = sc.nextInt();
        keys = sc.next().toCharArray();
        tag = sc.next();
        
        str = new char[S];
        sum = cntAll = 0;
        maxCnt = 0;
        f(0);
        //return String.format("%.6f", (double)sum / cntAll);
        return String.format("%.6f", maxCnt - (double)sum / cntAll);
    }
    /**/
    
    
    /*/
    int S;
    char[] keys;
    String tag;
    char[] str;
    double[] probCh;
    
    String solveTest(){
        sc.next();
        sc.next();
        S = sc.nextInt();
        keys = sc.next().toCharArray();
        tag = sc.next();
        
        probCh = new double[500];
        for( char ch : keys ) probCh[ch] += 1.0 / keys.length;
        
        int[][] maxLength = new int[tag.length() + 1][255];
        maxLength[0][tag.charAt(0)] = 1;
        for (int i = 0; i + 1 < tag.length(); i++) {
            for (char ch = 'A'; ch <= 'Z'; ch++) {
                for( int beg = i; 0 <= beg; --beg ){
                    String sub = tag.substring(beg,i+1) + ch;
                    if( tag.startsWith(sub) )
                        maxLength[i + 1][ch] = sub.length();
                }
            }
        }
        
        
        double[][][] dp;
        dp = new double[S+1][tag.length() + 1][S+1];
        dp[0][0][0] = 1;
        for( int pos = 0; pos+1 <= S; ++pos ){
            for (int lpr = 0; lpr <= tag.length(); lpr++) {
                for (int cnt = 0; cnt + 1 <= S; cnt++) {
                    double curDp = dp[pos][lpr][cnt];
                    if( lpr == tag.length() ){
                        for( char ch = 'A'; ch <= 'Z'; ++ch ){
                            int toLpr = maxLength[lpr][ch];
                            dp[pos+1][toLpr][cnt+1] += probCh[ch] * curDp;
                        }
                    } else {
                        for( char ch = 'A'; ch <= 'Z'; ++ch ){
                            int toLpr = maxLength[lpr][ch];
                            dp[pos+1][toLpr][cnt] += probCh[ch] * curDp;
                        }
                    }
                }
            }
        }
        
        long maxCnt = 0;
        double exp = 0;
        for (int lpr = 0; lpr <= tag.length(); lpr++) {
            for (int cnt = 0; cnt <= S; cnt++) {
                if( dp[S][lpr][cnt] != 0.0 ){
                    int c = cnt;
                    if(lpr == tag.length()) ++c;
                    if( c != 0 ){
                        exp += c * dp[S][lpr][cnt];
                        maxCnt = max(c, maxCnt);
                    }
                }
            }
        }
        
        err.println("maxCnt: " + maxCnt);
        err.println("exp: " + exp);
        return String.format("%.6f", maxCnt - exp);
//        return String.format("%.6f", maxCnt - (double)sum / cntAll);
//        return "sd";
    }
    /**/
    
    
    int c, v;
    int[] vals;
    int ans;
    int posAdd;
    int[] add = new int[100];
    boolean[] used;
    boolean[] dp;
    
    void xx(int val){
        for( int j = v; 0 <= j-val; --j )
            if( dp[j - val] )
                dp[j] = true;
    }
    
    boolean ff(){
        dp = new boolean[v + 1];
        dp[0] = true;
        for (int cc = 1; cc <= c; cc++) {
            for( int i = 0; i < posAdd; ++i )
                xx(add[i] * cc);
            for( int val : vals )
                xx(val * cc);
        }
        for( int i = 1; i <= v; ++i )
            if( !dp[i] )
                return false;
        return true;
    }
    
    long cntIter = 0;
    
    boolean f( int pos, int cntUsed, int maxCnt ){
        if( cntUsed == maxCnt ){
            boolean ret = ff();
            if( ret ) ans = maxCnt;
            ++cntIter;
            return ret;
        } else {
            //for( int x = (pos==0? 1 : add[pos-1] + 1); x <= (v + 1) / 2; ++x ){
            for( int x = (pos==0? 1 : add[pos-1] + 1); x <= v; ++x ){
                if( !used[x] ){
                    used[x] = true;
                    add[posAdd++] = x;
                            
                    if( f(pos+1, cntUsed + 1, maxCnt) )
                        return true;
                    
                    add[--posAdd] = -1;
                    used[x] = false;
                }
            }
            return false;
        }
    }
    
    String solveTest(){
        
        c = sc.nextInt();
        vals = new int[sc.nextInt()];
        v = sc.nextInt();
        used = new boolean[100];
        for( int i = 0; i < vals.length; ++i ){
            used[vals[i] = sc.nextInt()] = true;
        }
            
        
        
        ans = -1;
        
        for( int cnt = 0; cnt <= 5; ++ cnt ){
            posAdd = 0;
            if( f(0,0,cnt) ){
                return ans + "";
            }
        }
        
        return "-1";
    }
    
    void solve(){
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            err.printf("Case #%d\n",i+1);
            String ans = solveTest();
            out.printf("Case #%d: %s\n",i+1,ans);
            
        }
        err.println("cntIter: " + cntIter);
    }

}


