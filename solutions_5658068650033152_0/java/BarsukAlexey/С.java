import java.io.*;
import java.util.*;
import java.math.BigInteger;
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.math.BigInteger.*;

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

    final int inf = (int)1e8;

    int solveTest( int n, int m, int k ){
        int[][][][] dp;

        dp = new int[n][n][m][n*m+1];

        int ans = k;

        for( int ibeg1 =     0; ibeg1 < n; ibeg1++ ){
        for( int ibeg2 = ibeg1; ibeg2 < n; ibeg2++ ){

            for( int[][][] anInt : dp ){
                for( int[][] ints1 : anInt ){
                    for( int[] ints2 : ints1 ){
                        fill( ints2, inf );
                    }
                }
            }


            dp[ibeg1][ibeg2][0][ibeg2-ibeg1+1] = ibeg2-ibeg1+1;

            for( int j = 1; j < m; j++ ){
            for( int i1 = 0; i1 < n; i1++ ){
            for( int i2 = i1; i2 < n; i2++ ){
            for( int sq = 0; sq <= n*m; sq++ ){
                for( int pi1 = i1-1; pi1 <= i1+1; pi1++ ){
                for( int pi2 = i2-1; pi2 <= i2+1; pi2++ ){
                    if( 0<=pi1 && pi1 <= pi2 && pi2 < n ){
                        int cntStoneOnI = i1 == i2? 1 : 2;
                        int sqOnI = i2 - i1 + 1;
                        if(!( 0<=sq-sqOnI )) continue;
                        dp[i1][i2][j][sq] = min( dp[i1][i2][j][sq],
                            dp[pi1][pi2][j-1][sq-sqOnI] + cntStoneOnI
                        );
                    }
                }
                }
            }
            }
            }
            }

            for( int i1 =  0; i1 < n; i1++ ){
            for( int i2 = i1; i2 < n; i2++ ){
            for( int j = 0; j < m; j++ ){
            for( int sq = 0; sq <= n*m; sq++ ){
                int cntIn = max( 0, i2 - i1 - 1 );
                ans = min( ans,
                        cntIn + dp[i1][i2][j][sq] + max(0,k - sq) );
            }
            }
            }
            }
        }
        }
        return ans;
    }


    int solveTest(){
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        return min( solveTest(n,m,k), solveTest(m,n,k) );
    }

    void solve(){
        int t = sc.nextInt();
        for( int i = 1; i <= t; i++ ){
            err.printf("Case #%d: \n", i );
            out.printf("Case #%d: %d\n", i, solveTest());
        }
    }
}