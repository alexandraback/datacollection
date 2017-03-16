/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam12;

import java.io.*;
import java.util.StringTokenizer;

/**
 *
 * @author Mohamed Ibrahim (MIM)
 */
public class Problem_C {

    public static String strSet(String str, char c, int index) {
        return str.substring(0, index) + c + str.substring(index + 1);
    }

    public static void main(String[] args) throws IOException {

        BufferedReader r = new BufferedReader(new FileReader("C-large.in"));
        PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter("C-large.out")));

        int nCases = Integer.parseInt(r.readLine());

        for (Integer k = 1; k <= nCases; k++) {
            w.print("Case #" + k + ": ");
            String line = r.readLine();
            StringTokenizer st = new StringTokenizer(line);
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int ret = 0;
            for (int i = n; i <= m; i++) {
                String val = String.valueOf(i);
                char z = val.charAt(val.length() - 1);
                String cur = val.substring(0, val.length() - 1);
                cur = z + cur;
                while (!val.equals(cur)) {
                    if (Integer.parseInt(cur) <= m && cur.charAt(0) != '0'
                            && Integer.parseInt(val) < Integer.parseInt(cur)) {
                        ret++;
                        //System.out.println(val + " " + cur + " " + m);
                    }
                    z = cur.charAt(val.length() - 1);
                    cur = cur.substring(0, val.length() - 1);
                    cur = z + cur;
                }
            }
        //    System.out.println();
        //    System.out.println();
            w.println(ret);
        }
        w.close();


    }
}
