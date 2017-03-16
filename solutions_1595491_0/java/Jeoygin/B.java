/*******************************************************************************
 * Copyright (c) 2012 by Institute of Computing Technology,
 * 		Chinese Academic of Sciences, Beijing, China.
 *
 * 	Author: Ruijian Wang
 * 	  File: B.java
 * 	  Date: 2012-04-14
 * 	  Time: 13:29:55
 ******************************************************************************/

package gcj12;

import java.util.Scanner;

/**
 * Todo.
 * <p/>
 * User: Ruijian Wang
 * Date: 4/14/12
 * Time: 1:29 PM
 *
 * @author Ruijian Wang<br>
 * @version 1.0.0 2012-04-14<br>
 */
public class B {
    void solve() {
        int tCase, n, s, p;
        Scanner scan = new Scanner(System.in);
        tCase=scan.nextInt();
        for (int i = 1; i <= tCase; i++) {
            int num = 0;
            n = scan.nextInt();
            s = scan.nextInt();
            p = scan.nextInt();
            int t;
            for (int j = 0; j < n; j++) {
                t = scan.nextInt();
                int m = t % 3;
                int max = -1;
                if (m == 1) {
                    max = t / 3 + 1;
                    if (max >= p) {
                        num ++;
                    }
                } else if (m == 2) {
                    max = t / 3 + 1;
                    if (max >= p) {
                        num ++;
                    } else if (s > 0 && max + 1 >= p) {
                        s--;
                        num++;
                    }
                } else {
                    max = t / 3;
                    if (max >= p) {
                        num++;
                    } else if (s > 0 && t >= 3 && max + 1 >= p) {
                        s--;
                        num++;
                    }
                }
            }
            System.out.println("Case #" + i + ": " + num);
        }
    }

    public static void main(String[] args) {
        new B().solve();
    }
}
