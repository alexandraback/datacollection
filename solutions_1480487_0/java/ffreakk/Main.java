package googlecodejam;

/**
 *
 * @author ffreakk
 */

import java.util.Scanner;
import java.lang.Math;
public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();

        for (int t=0; t<T; t++) {
            int N = in.nextInt();
            int s[] = new int[N];
            int sum=0;

            for (int n=0; n<N; n++) {
                s[n] = in.nextInt();
                sum += s[n];
            }

            int originalSum = sum;
            boolean repeat = true;
            int nContestants = N;
            double average = (double)(sum+originalSum)/(double)nContestants;

            while (repeat) {
                average = (double)(sum+originalSum)/(double)nContestants;
                repeat = false;
                for (int i=0; i<N; i++){
                    if ( s[i]>average && s[i]>=0 ) {
                        sum -= s[i];
                        s[i] = -1;
                        nContestants--;
                        repeat = true;
                        break;
                    }
                }
            }

            double result[] = new double[N];
            for (int n=0; n<N; n++) {
                if (s[n]<0) result[n]=0.000000;
                else result[n] = (average - s[n])/originalSum;
            }
            int testCase = t+1;
            System.out.print("Case #" + testCase + ": ");
            for (int n=0; n<N; n++) {
                double tempResult = (int) (result[n]*10000000 + 0.5);
                tempResult /= 100000;
                System.out.print(tempResult + " ");
            }
            System.out.println();
        }
    }

}
