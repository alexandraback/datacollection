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

    int n;
    Double[] a, b;

    int check( Double[] a, Double[] b ){
        int cnt = 0;
        for( int i = 0; i < max(a.length,b.length); ++i ){
            if( a[i] < b[i] )
                return -1;
            if( a[i] > b[i] )
                ++cnt;
        }
        return cnt;
    }

    int norm( ){
        int ans = 0;
        int posB = n-1;
        for( int i = n-1; 0 <= i; --i ){
            if( a[i] > b[posB] ){
                ++ans;
            }
            else{
                --posB;
            }
        }
        return ans;
    }

    int notNorm(){
        int ans = 0;
        for( int l = 0, r = a.length-1; l < n; ++l, --r ){
            ans = max( ans, check(
                    Arrays.copyOfRange(a,l,n),
                    Arrays.copyOfRange(b,0,r+1)
            ));
        }
        return ans;
    }

    void solve(){
        int cntTests = sc.nextInt();
        for( int t = 0; t < cntTests; ++t ){
            n = sc.nextInt();
            a = new Double[n];
            b = new Double[n];
            for( int i = 0; i < n; ++i ) a[i] = sc.nextDouble();
            for( int i = 0; i < n; ++i ) b[i] = sc.nextDouble();
            sort( a );
            sort( b );
            out.printf("Case #%d: %d %d\n", t + 1,
                    notNorm(),
                    norm()
            );
        }
    }


}
