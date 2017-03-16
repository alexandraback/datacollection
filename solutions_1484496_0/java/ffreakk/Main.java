package googlecodejam;

/**
 *
 * @author ffreakk
 */

import java.util.Scanner;
import java.lang.Math;
import java.lang.Object;
import java.util.Arrays;
public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();

        for (int t=0; t<T; t++) {
            int N = in.nextInt();
            int S[] = new int[N];
            int sum = 0;

            for (int n=0; n<N; n++) {
                S[n] = in.nextInt();
                sum += S[n];
            }

            

            int half = sum/2;
            boolean possible = false;

            int result[][] = new int[2000001][21];
            for (int i=0; i<2000001; i++)
                for (int j=0; j<21; j++)
                    result[i][j] = 0;

            int bit[] = new int[N];

            for (bit[0]=0; bit[0]<2; bit[0]++)
                for (bit[1]=0; bit[1]<2; bit[1]++)
                    for (bit[2]=0; bit[2]<2; bit[2]++)
                        for (bit[3]=0; bit[3]<2; bit[3]++)
                            for (bit[4]=0; bit[4]<2; bit[4]++)
                                for (bit[5]=0; bit[5]<2; bit[5]++)
                                    for (bit[6]=0; bit[6]<2; bit[6]++)
                                        for (bit[7]=0; bit[7]<2; bit[7]++)
                                            for (bit[8]=0; bit[9]<2; bit[9]++)
                                                for (bit[9]=0; bit[9]<2; bit[9]++)
                                                    for (bit[10]=0; bit[10]<2; bit[10]++)
                                                        for (bit[11]=0; bit[11]<2; bit[11]++)
                                                            for (bit[12]=0; bit[12]<2; bit[12]++)
                                                                for (bit[13]=0; bit[13]<2; bit[13]++)
                                                                    for (bit[14]=0; bit[14]<2; bit[14]++)
                                                                        for (bit[15]=0; bit[15]<2; bit[15]++)
                                                                            for (bit[16]=0; bit[16]<2; bit[16]++)
                                                                                for (bit[17]=0; bit[17]<2; bit[17]++)
                                                                                    for (bit[18]=0; bit[18]<2; bit[18]++)
                                                                                        for (bit[19]=0; bit[19]<2; bit[19]++) {

                                                                                            if (!possible) { int curSum = 0;
                            for (int i=0; i<N; i++)
                                if (bit[i] == 1) curSum += S[i];
                            if (result[curSum][20] ==  0) {
                                result[curSum][20] = 1;
                                for (int run=0; run<N; run++) {
                                    result[curSum][run] = bit[run];
                                }
                            } else {
                                possible = true;
                                System.out.println("Case #" +(t+1)+ ":");
                                for (int run=0; run<N; run++)
                                    if (bit[run]==1) System.out.print(S[run] +" ");
                                System.out.println();
                                for (int run=0; run<N; run++)
                                    if (result[curSum][run]==1) System.out.print(S[run] +" ");
                                System.out.println();
                            }
                                                                                            }
                                                                                        }
            if (!possible) {
                System.out.println("Case #" +(t+1)+ ":");
                System.out.println("Impossible");
            }



//            for (int n=0; n<N; n++) {
//                if (possible) break;                                                                //if found answer, stop
//                for (bit[n] = 0; bit[n]<2; bit[n]++){
//                    if (n == N) {
//                        int curSum = 0;
//                        for (int i=0; i<N; i++)
//                            if (bit[i] == 1) curSum += S[i];
//                        if (result[curSum][20] ==  0) {
//                            result[curSum][20] = 1;
//                            for (int run=0; run<N; run++) {
//                                result[curSum][run] = bit[run];
//                            }
//                        } else {
//                            possible = true;
//                            System.out.println("Case #" +(t+1)+ ":");
//                            for (int run=0; run<N; run++)
//                                if (bit[run]==1) System.out.print(S[run] +" ");
//                            System.out.println();
//                            for (int run=0; run<N; run++)
//                                if (result[curSum][run]==1) System.out.print(S[run] +" ");
//                            System.out.println();
//                        }
//
////                        if (curSum == half) {
////                            possible = true;
////                            System.out.println("Case #" +(t+1)+ ":");
////                            for (int nn=0; nn<N; nn++)
////                                if (bit[nn] == 1) System.out.print(S[nn] + " ");
////                            System.out.println();
////                            for (int nn=0; nn<N; nn++)
////                                if (bit[nn] == 0) System.out.print(S[nn] + " ");
////                            System.out.println();
////                        }
//                    }
//                }
//            }
        }
    }

}
