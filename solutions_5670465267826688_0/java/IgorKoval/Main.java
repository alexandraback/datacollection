import java.awt.*;
import java.io.*;
import java.util.*;
import java.math.BigInteger;
import static java.math.BigInteger.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

//<editor-fold defaultstate="collapsed" desc="Main">
public class Main {
    // https://netbeans.org/kb/73/java/editor-codereference_ru.html#display

    private void run() {
        try {
            Locale.setDefault(Locale.US);
        } catch (Exception e) {
        }
        boolean oj = true;
        try {
            oj = System.getProperty("MYLOCAL") == null;
        } catch (Exception e) {
        }

        if (oj) {
            sc = new FastScanner(new InputStreamReader(System.in));
            out = new PrintWriter(new OutputStreamWriter(System.out));
//            try {
//                sc = new FastScanner(new FileReader ("stacks.in" ));
//                out = new PrintWriter(new FileWriter("stacks.out"));
//            } catch (IOException e) {
//                MLE();
//            }
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

    public static void main(String[] args) {
        new Main().run();
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
            //for(;;);
        }
    }

    FastScanner sc;
    PrintWriter out;
    static PrintStream err = System.err;

  
    int[][] cntMinus = {
        {0,0,0,0},
        {0,1,0,1},
        {0,1,1,0},
        {0,0,1,1},
    };
    int[][] val = {
        {0,1,2,3},
        {1,0,3,2},
        {2,3,0,1},
        {3,2,1,0},
    };

    int get(char ch){
        if( ch == 'i' ) return 1;
        if( ch == 'j' ) return 2;
        if( ch == 'k' ) return 3;
        aser(false);
        return -1;
    }
    
    
    String solveTest(){
        String s = "";
        sc.nextLong();
        long rep = sc.nextLong();
        String sub = sc.next();
        
        for (int i = 0; i < rep; i++) {
            s += sub;
        }
        
        int[] minus = new int[s.length()];
        int[] vl = new int[s.length()];
        vl[0] = get(s.charAt(0));
        boolean getI = vl[0] == 1;
        boolean getJ = false;
        for (int i = 1; i < s.length(); i++) {
            int prev = vl[i-1];
            int cur = get(s.charAt(i));
            minus[i] = (minus[i-1] + cntMinus[prev][cur]) % 2;
            vl[i] = val[prev][cur];
            getI |= vl[i] == 1 && minus[i] == 0;
            if( getI ){
                getJ |= vl[i] == 3 && minus[i] == 0; // i*j==k
            }
        }

//        err.println(Arrays.toString(vl).replace("1", "i").replace("2", "j").replace("3", "k").replace("0", "1"));
//        err.println(Arrays.toString(minus));
        boolean ans = getI && getJ && vl[s.length()-1]==0 && minus[s.length()-1]==1;
   
        return ans? "YES" : "NO";
    }
        
    
    void solve() {
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            err.println("Test: " + i);
            out.printf( "Case #%d: %s\n", i + 1, solveTest());
        }
        
    }


}