/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam2016.round0;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;

/**
 *
 * @author admin
 */
public class ProD implements Problem {

    @Override
    public void solveSmall(Scanner in, PrintStream out) {
        int count = in.nextInt();
        in.nextLine();
        for (int i = 1; i <= count; i++) {
            String list[] = in.nextLine().split(" ");
            int k = Integer.valueOf(list[0]);
            int c = Integer.valueOf(list[1]);
            int s = Integer.valueOf(list[2]);
            StringBuilder sb = new StringBuilder();
            for (int j = 1; j <= s; j++) {
                sb.append(" ").append(j);
            }
            out.printf("Case #%d:%s\n", i, sb.toString());
        }
    }

    @Override
    public void solveLarge(Scanner in, PrintStream out) {
        int count = in.nextInt();
        in.nextLine();
        for (int i = 1; i <= count; i++) {
            String list[] = in.nextLine().split(" ");
            int k = Integer.valueOf(list[0]);
            int c = Integer.valueOf(list[1]);
            int s = Integer.valueOf(list[2]);
            String result = "IMPOSSIBLE";

            if (s == k) {
                StringBuilder sb = new StringBuilder();
                for (int j = 1; j <= s; j++) {
                    sb.append(" ").append(j);
                }
                result = sb.toString().trim();
            } else if (s + c > k) {
                result = "";
                if (c >= k) {
                    long index = 0;
                    int temp = 0;
                    do {
                        index = index * k + temp;
                        temp++;
                    } while (temp < k);
                    index++;
                    result = String.valueOf(index);
                } else {
                    for (int j = 0; j < s; j++) {
                        long index = 0;
                        int temp = j;
                        do {
                            index = index * k + temp;
                            temp++;
                        } while (temp < c + j);
                        index++;
                        result += String.valueOf(index) + " ";
                    }
                }
            }

            out.printf("Case #%d: %s\n", i, result.trim());
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Problem D = new ProD();
        String prepath = "F:\\codejam\\D\\";
        String testname = "test-D";
        String smallname = "D-small-attempt0";
        String largename = "D-large";
        File tin = new File(prepath + testname + ".txt");
        File sin = new File(prepath + smallname + ".in");
        File lin = new File(prepath + largename + ".in");
        PrintStream testo = new PrintStream(prepath + testname + ".out");
        PrintStream smallo = new PrintStream(prepath + smallname + ".out");
        PrintStream largeo = new PrintStream(prepath + largename + ".out");
        D.solveSmall(new Scanner(tin), testo);
        D.solveSmall(new Scanner(sin), smallo);
        //System.out.println(prepath + smallname + ".out");
        D.solveLarge(new Scanner(lin), largeo);
        //System.out.println(prepath + largename + ".out");

    }
}
