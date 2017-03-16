/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package kingdomrush;

import java.util.Scanner;

/**
 *
 * @author kin
 */
public class KingdomRush {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int t;
        Scanner scanner = new Scanner(System.in);
        t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            int[] a = new int[n];
            int[] b = new int[n];
            int[] an = new int[n];
            int[] bn = new int[n];
            for (int j = 0; j < n; j++) {
                a[j] = scanner.nextInt();
                b[j] = scanner.nextInt();
                an[j] = j;
                bn[j] = j;
            }
            int star = 0;
            int temp;
            for (int k = 0; k < n; k++) {
                for (int j = 1; j < n; j++) {
                    if (a[j] < a[j - 1]) {
                        temp = a[j - 1];
                        a[j - 1] = a[j];
                        a[j] = temp;
                        temp = an[j - 1];
                        an[j - 1] = an[j];
                        an[j] = temp;
                    }
                    if (b[j] < b[j - 1]) {
                        temp = b[j - 1];
                        b[j - 1] = b[j];
                        b[j] = temp;
                        temp = bn[j - 1];
                        bn[j - 1] = bn[j];
                        bn[j] = temp;
                    }
                }
            }
            int c = 0;
            boolean bad = false;
            for (int d = 0; d < n;) {
                if (b[d] <= star) {
                    boolean flag = false;
                    for (int k = 0; k < c - 1; k++) {
                        if (bn[d] == an[k]) {
                            flag = true;
                        }
                    }
                    if (!flag) {
                        star = star + 2;
                    } else {
                        star = star + 1;
                    }
                    d++;
                } else if ((c < n) && (a[c] <= star)) {
                    boolean flag = false;
                    for (int k = 0; k < d - 1; k++) {
                        if (bn[k] == an[c]) {
                            flag = true;
                        }
                    }
                    if (!flag) {
                        star = star + 1;
                    } 
                    c++;
                } else {
                    bad = true;
                    break;
                }
            }
            if (!bad) {
                System.out.println("Case #" + (i + 1) + ": " + (n + c));
            } else {
                System.out.println("Case #" + (i + 1) + ": Too Bad");
            }
        }
    }
}
