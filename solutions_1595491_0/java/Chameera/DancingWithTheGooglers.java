/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.*;

/**
 *
 * @author wijebandara
 */
public class DancingWithTheGooglers {

    public static void main(String[] args) throws FileNotFoundException, IOException {

        //java.io.BufferedReader in = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
        java.io.BufferedReader in=new java.io.BufferedReader(new java.io.FileReader("/home/wijebandara/Desktop/B-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("/home/wijebandara/Desktop/B-small-attempt0.out")));

        int n = Integer.parseInt(in.readLine());
        java.util.StringTokenizer st;
        for (int i = 0; i < n; i++) {
            st = new java.util.StringTokenizer(in.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int answer = 0;
            for (int j = 0; j < a; j++) {
                int hold = Integer.parseInt(st.nextToken());
                int s = check(hold, c);
                if (s == 1) {
                    answer++;
                }
                if (s == 2 && b > 0) {
                    b--;
                    answer++;
                }
            }
            System.out.print("Case #" + (i + 1) + ": ");
            out.print("Case #" + (i + 1) + ": ");
            System.out.println(answer);
            out.println(answer);
        }
        out.close();
        System.exit(0);

    }

    static int check(int x, int y) // 0-no,1 yes no *,2 yes yes *
    {
        if (x % 3 == 0) {
            if (x / 3 >= y) {
                // System.out.println("1");
                return 1;
            }
        }
        if ((x - 1) % 3 == 0) {
            int hold = (x - 1) / 3;
            if (hold >= 0 && hold + 1 >= y) {
                //System.out.println("2");
                return 1;
            }
        }
        if ((x - 2) % 3 == 0) {
            int hold = (x - 2) / 3;

            if (hold >= 0 && hold + 1 >= y) {
                //System.out.println("3");
                return 1;
            }
            if (hold >= 0 && hold + 2 >= y) {
                //System.out.println("4");
                return 2;
            }
        }
        if ((x - 3) % 3 == 0) {
            int hold = (x - 3) / 3;

            if (hold >= 0 && hold + 2 >= y) {
                // System.out.println("5");
                return 2;
            }
        }
        if ((x - 4) % 3 == 0) {
            int hold = (x - 4) / 3;

            if (hold >= 0 && hold + 2 >= y) {
                //System.out.println("6");
                return 2;
            }
        }
        return 0;
    }
}
