import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;
import java.util.Calendar.*;
import static java.lang.Math.*;
import static java.lang.Math.min;
import static java.util.Arrays.*;
import static java.math.BigInteger.*;

import java.util.jar.*;

public class Main{

    void run(){
        boolean oj = System.getProperty("ONLINE_JUDGE") != null;
//        boolean oj = true;
        Locale.setDefault(Locale.US);
        try{
            err = new PrintWriter(new OutputStreamWriter(System.err));
            try{
                sc  = new FastScanner(new BufferedReader(new FileReader("input.txt" )));
                out = new PrintWriter   (new FileWriter("output.txt"));
                oj = false;
            }
            catch ( Exception e ){
                sc = new FastScanner(new BufferedReader(new InputStreamReader(System.in)));
                out = new PrintWriter(new OutputStreamWriter(System.out));
                oj = true;
            }
        }catch(Exception e){
            MLE();
        }
        tBeg = System.currentTimeMillis();
        solve();
        if( !oj )
            err.println( "TIME: " + (System.currentTimeMillis() - tBeg ) / 1e3 );
        exit(0);
    }

    void exit( int val ){
        err.flush();
        out.flush();
        System.exit(val);
    }

    double tBeg;
    FastScanner sc;
    PrintWriter err, out;

    class FastScanner{

        StringTokenizer st;
        BufferedReader br;

        FastScanner( BufferedReader _br ){
            br = _br;
        }

        String readLine(){
            try {
                return br.readLine();
            } catch (IOException e) {
                return null;
            }
        }

        String next(){
            while( st==null || !st.hasMoreElements() )
                st = new StringTokenizer(readLine());
            return st.nextToken();
        }

        int nextInt(){ return Integer.parseInt(next()); }
        long nextLong(){ return Long.parseLong(next()); }
        double nextDouble(){ return Double.parseDouble(next()); }
    }

    void MLE(){
        int[][] arr = new int[1024*1024][]; for( int i = 0; i < 1024*1024; ++i ) arr[i] = new int[1024*1024];
    }

    void TLE(){
        for(;;);
    }

    public static void main(String[] args) {
        new Main().run();
    }

    ////////////////////////////////////////////////////////////////

    int n, m;
    String[] zip;
    int[] V, T;
    boolean[][] gr;
    String ans;

    StringBuilder sb;
    boolean[] used;
    void dfs( int v ){
        if( used[v] ) return;
        used[v] = true;
        sb.append( zip[v] );

        for( ; ; ){
            int to = -1;
            for( int j = 1; j <= n; ++j ){
                if( !used[j] )
                if( gr[v][j] && ( to == -1 || zip[to].compareTo(zip[j])>0 ) )
                    to = j;
            }
            if( to == -1 ) {
                break;
            }
            dfs( to );
        }

    }


    void f( int pos, int cntUsed ){
        if( pos == m ){
            int root = 1;
            for( int v = 1; v <= n; ++v ){
                if( zip[root].compareTo(zip[v]) >= 0 )
                    root = v;
            }
            used = new boolean[n+1];
            sb = new StringBuilder();
            dfs( root );
            String cur = sb.toString();
            if( cur.length() == 5*n ){
                if( ans==null || ans.compareTo(cur) > 0 ){
                    ans = cur;
                }
            }
        }
        else{

            f( pos + 1, cntUsed );

            if( cntUsed < n - 1 ){
                int a = V[pos];
                int b = T[pos];
                gr[a][b] = true;
                gr[b][a] = true;

                f( pos + 1, cntUsed + 1 );

                gr[a][b] = false;
                gr[b][a] = false;
            }
        }
    }

    void solveTest(){
        n = sc.nextInt();
        m = sc.nextInt();
        zip = new String[n+1];
        for( int i = 1; i <= n; ++i ){
            zip[i] = sc.next();
        }
        V = new int[m];
        T = new int[m];
        for( int i = 0; i < m; ++i ){
            V[i] = sc.nextInt();
            T[i] = sc.nextInt();
        }

        gr = new boolean[n+1][n+1];
        ans = null;
        f( 0, 0 );
        out.println( ans );
//        out.println();
    }

    void solve(){
        int t = sc.nextInt();
        for( int i = 0; i < t; ++i ){
            err.println( "test: " + i );
            out.printf("Case #%d: ", i + 1 );
            solveTest();
            err.println();
        }
    }
}
