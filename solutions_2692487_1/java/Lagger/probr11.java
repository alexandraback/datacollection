/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.util.Arrays;

/**
 *
 * @author anubhavg
 */
public class probr11 {

    public static void main(String[] args) throws Exception {
        java.io.BufferedReader r = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
        String s;
        String[] str;
        s = r.readLine();
        int T = Integer.parseInt(s);
        int A, N, count, total, sum;
        int[] motes;
        int[] additions;
        for (int i = 1; i <= T; i++) {
            s = r.readLine();
            str = s.split(" ");
            A = Integer.parseInt(str[0]);
            N = Integer.parseInt(str[1]);

            s = r.readLine();
            str = s.split(" ");
            motes = new int[N];
            for (int j = 0; j < N; j++) {
                motes[j] = Integer.parseInt(str[j]);
            }
            Arrays.sort(motes);
            additions = new int[N];
            total = 0;
            count = 0;

            for (int j = 0; j < N; j++) {
                count = 0;
                if (motes[j] < A) {
                    A += motes[j];
                } else {
                    while (true) {
                        if(A==1) {
                            count = 100000001;
                            break;
                        }
                        A += (A - 1);
                        count++;
                        if (A > motes[j]) {
                            break; //Added
                        }
                    }
                    A += motes[j];
                }
                additions[j] = count;
                total += count;
            }

            int mark = N;
            sum = 0;
            for (int j = N - 1; j >= 0; j--) {
                sum += additions[j];
                if ((mark - j) < sum) {
                    total += ((mark - j) - sum);
                    mark = j;
                    sum = 0;
                }
            }

            System.out.println("Case #" + i + ": " + total);
        }
    }
}
