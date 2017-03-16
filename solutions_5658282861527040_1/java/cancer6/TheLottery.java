
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * Created by rohit.sharma on 03/05/14.
 */
public class TheLottery {

    private static void bits(int n, int[] l){
        for(int i=0; i<32; i++){
            l[i] = ( (n & (1<<i)) > 0 ? 1 : 0);
        }
    }
    static Long[][][][] dp = new Long[32][2][2][2];
    static int[] dbA = new int[32];
    static int[] dbB = new int[32];
    static int[] dbK = new int[32];

    private static long rec(int t, int prevA, int prevB, int prevK){
        if(dp[t][prevA][prevB][prevK] == -1){
            dp[t][prevA][prevB][prevK] = 0L;
            if(t == 0)
                dp[t][prevA][prevB][prevK] = 1L;
            else {
                dp[t][prevA][prevB][prevK] = 0L;
                for(int p=0; p<2; p++){
                    for(int q=0; q<2; q++){
                        int r = p & q;
                        if( (prevA == 0 || (p <= dbA[t-1])) &&
                            (prevB == 0 || (q <= dbB[t-1])) &&
                            (prevK == 0 || (r <= dbK[t-1]))) {

                            dp[t][prevA][prevB][prevK] += rec(t-1,
                                    prevA == 1 && (p == dbA[t-1]) ? 1 : 0,
                                    prevB == 1 && (q == dbB[t-1]) ? 1 : 0,
                                    prevK == 1 && (r == dbK[t-1]) ? 1 : 0);

                        }
                    }
                }
            }
        }
        return dp[t][prevA][prevB][prevK];
    }


    public static void main(String[] args){
        MyScanner sc = new MyScanner();
        int cases = sc.nextInt();
        for(int t=1; t<=cases; t++){
            String[] s = sc.nextLine().split(" ");
            int a = Integer.parseInt(s[0]);
            int b = Integer.parseInt(s[1]);
            int k = Integer.parseInt(s[2]);

            bits(a-1, dbA);
            bits(b-1, dbB);
            bits(k-1, dbK);
            for(int i=0; i<32; i++){
                for(int j=0; j<2; j++){
                    for(int k1=0; k1<2; k1++){
                        for(int l=0; l<2; l++){
                            dp[i][j][k1][l] = -1L;
                        }
                    }
                }
            }
            long ans = rec(30, 1, 1, 1);
            System.out.println("Case #" + t + ": " + ans);
        }
    }

    public static class MyScanner {
              BufferedReader br;
              StringTokenizer st;

              public MyScanner() {
                 br = new BufferedReader(new InputStreamReader(System.in));
              }

              String next() {
                  while (st == null || !st.hasMoreElements()) {
                      try {
                          st = new StringTokenizer(br.readLine());
                      } catch (IOException e) {
                          e.printStackTrace();
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

              String nextLine(){
                  String str = "";
        	  try {
        	     str = br.readLine();
        	  } catch (IOException e) {
        	     e.printStackTrace();
        	  }
        	  return str;
              }

           }
}
