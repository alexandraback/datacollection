import java.io.*;
import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.sql.Time;
import java.util.*;

import java.math.BigInteger;

import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;


public class Main{

    void run(){
        Locale.setDefault(Locale.US);
        boolean oj = System.getProperty("ONLINE_JUDGE") != null;
//        boolean oj = true;
        try{
            if( oj ){
                sc  = new FastScanner( new InputStreamReader(System.in  ) );
                out = new PrintWriter(   new OutputStreamWriter(System.out) );
            } else{
                sc  = new FastScanner(new FileReader("input.txt") );
                out  = new PrintWriter(new FileWriter("C:\\output.txt") );
                //out = new PrintWriter(   new FileWriter("output.txt") );
            }
        } catch (Exception e) {
            MLE();
            System.exit(-1);
        }
        long tB = System.currentTimeMillis();
        solve();
        if( !oj ) System.err.println( "Time: " + (System.currentTimeMillis()-tB)/1e3 );
        out.flush();
    }


    class FastScanner{
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");
        FastScanner( InputStreamReader a ){
            br = new BufferedReader(a);
        }
        FastScanner( FileReader a ){
            br = new BufferedReader(a);
        }
        String next(){
            while( !st.hasMoreTokens() )
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    return null;
                }
            return st.nextToken();
        }
        String readLine(){
            try {
                return br.readLine();
            } catch (Exception e) {
                return null;
            }
        }
        int nextInt(){ return Integer.parseInt(next()); }
        long nextLong(){ return Long.parseLong(next()); }
        double nextDouble(){ return Double.parseDouble(next()); }
    }

    FastScanner sc;
    PrintWriter out;



    public static void main(String[] args){
        new Main().run();
//        new Thread( null, new Runnable() {
//            @Override
//            public void run() {
//                new Main().run();
//            }
//            }, "LOL", 256L * 1024 * 1024 / 2 ).run();
//        }, "LOL", 2000 * 1024 * 1024 ).run();
    }



    void TLE(){ for(;;); }

    void MLE(){
        int[][] adj = new int[1024*1024][];
        for( int i = 0; i < adj.length; ++i )
            adj[i] = new int[1024*1024];
    }

    void exit( int val ){
        out.flush();
        System.exit(val);
    }
    //////////////////////////////////////////////////////////////////////////////////////////


    String[][][] ans = new String[6][6][26];

    int n, m, b;
    char[][] plan;
    int[][] cntBombs;
    boolean[][] isVisited;

    int open( int i, int j ){
        if( isVisited[i][j] )
            return 0;
        isVisited[i][j] = true;
//        out.printf( "%d %d\n", i, j );
        int cntVis = 1;
        if( cntBombs[i][j] == 0 ){
            for( int di = -1; di <= 1; ++di ){
            for( int dj = -1; dj <= 1; ++dj ){
                int toi = i + di;
                int toj = j + dj;
                if( 0 <= toi && toi < n &&
                    0 <= toj && toj < m ){
                    cntVis += open( toi, toj );
                }
            }
            }
        }
        return cntVis;
    }

    boolean can(){
        cntBombs = new int[n][m];
        for( int i = 0; i < n; ++i ){
        for( int j = 0; j < m; ++j ){
            for( int di = -1; di <= 1; ++di ){
            for( int dj = -1; dj <= 1; ++dj ){
                int toi = i + di;
                int toj = j + dj;
                if( 0 <= toi && toi < n &&
                    0 <= toj && toj < m ){
                    if( plan[toi][toj] == '*' && plan[i][j] == '.' )
                        ++cntBombs[i][j];
                }
            }
            }
        }
        }
        loop2:
        for( int i = 0; i < n; ++i )
        for( int j = 0; j < m; ++j )
            if( plan[i][j]=='.' ){
                isVisited = new boolean[n][m];
                int cntOpen = open( i, j );
                if( cntOpen == n*m-b ){
                    plan[i][j] = 'c';
                    return true;
                }
                break loop2;
            }
        return false;
    }

    String recAns;
    boolean rec( int i, int j, int cntSet ){
        if( j == m ){
            ++i;
            j = 0;
        }

        if( i == n ){
            if( cntSet == b && can() ){
                recAns = "";
                for( char[] plani : plan )
                    recAns += new String( plani ) + "\n";
                return true;
            }
            else{
                return false;
            }
        }
        else{
            plan[i][j] = '.';
            if( rec( i, j+1, cntSet ) )
                return true;
            if( cntSet < b ){
                plan[i][j] = '*';
                if( rec( i, j+1, cntSet + 1 ) )
                    return true;
            }
            return false;
        }
    }

    void solve(){
        for( n = 1; n <= 5; ++n ){
        for( m = 1; m <= 5; ++m ){
        for( b = 0; b < n*m; ++b ){
            plan = new char[n][m];
            if( rec( 0, 0, 0 ) ){
                ans[n][m][b] = recAns;
//                out.printf( "%s\n", ans[n][m][b] );
            }
            else
                ans[n][m][b] = "Impossible\n";
            //out.printf( "n,m,b: %d %d %d\n%s\n", n,m,b, ans[n][m][b] );

        }
        }
        }

        int cntTests = sc.nextInt();
        for( int t = 0; t < cntTests; ++t ){
            n = sc.nextInt();
            m = sc.nextInt();
            b = sc.nextInt();
            String rez = ans[n][m][b];
            if( rez == null ) MLE();
            out.printf("Case #%d:\n%s", t + 1, rez );
        }
    }


}