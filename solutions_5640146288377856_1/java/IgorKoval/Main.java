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

    
    
    String solveTest(){
        long r, c, w;
        r = sc.nextLong(); 
        c = sc.nextLong();
        w = sc.nextLong();
        long ans = r*(c/w) + w - 1;
        if( c % w != 0 ) ++ans;
        return ans + "";
    }
    
    void solve(){
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            String ans = solveTest();
            out.printf("Case #%d: %s\n",i+1,ans);
        }
    }

}


