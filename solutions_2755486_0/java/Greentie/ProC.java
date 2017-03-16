/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam2013;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;

/**
 *
 * @author admin
 */
public class ProC implements Problem {

    @Override
    public void solveSmall(Scanner in, PrintStream out) {
        int x = in.nextInt();
        in.nextLine();
        for (int i = 1; i <= x; i++) {
            int a = in.nextInt();
            in.nextLine();//

            int[][] pc = new int[a][];


            List<Attack> attacks = new ArrayList();
            for (int j = 0; j < pc.length; j++) {
                pc[j] = new int[8];
                for (int k = 0; k < 8; k++) {
                    pc[j][k] = in.nextInt();
                }
                in.nextLine();
            }

            for (int j = 0; j < pc.length; j++) {
                int[] t = pc[j];

                for (int k = 0; k < t[1]; k++) {
                    attacks.add(new Attack(t[0] + t[5] * k, t[4] + t[7] * k, t[2] + t[6] * k, t[3] + t[6] * k));
                }
            }
            Attack[] tt = new Attack[attacks.size()];
            attacks.toArray(tt);
            Arrays.sort(tt);

            out.printf("Case #%d: %d\n", i, checkwall(tt));

        }
    }

    public int checkwall(Attack[] tt) {
        int[] wall = new int[2000];
        int count = 0;
        for (int i = 0; i < tt.length; i++) {
            int t = i;
            while (t<tt.length&&tt[t].day == tt[i].day) {
                t++;
            }
            for (int k = i; k < t; k++) {
                if (checkWall(wall, tt[k])) {
                    continue;
                } else {
                    count++;
                }
            }
            for (int k = i; k < t; k++) {
                buildWall(wall, tt[k]);
            }
            i = t - 1;
        }

        return count;
    }

    private boolean checkWall(int[] wall, Attack t) {
        boolean save = true;
        for (int i = t.a + 1000; i < t.b + 1000; i++) {
            if (wall[i] >= t.strength) {
                save &= true;
            } else {
                save = false;
            }
        }
        return save;
    }

    private void buildWall(int[] wall, Attack t) {
        for (int i = t.a + 1000; i < t.b + 1000; i++) {
            if (wall[i] < t.strength) {
                wall[i] = t.strength;
            }
        }
    }

    @Override
    public void solveLarge(Scanner in, PrintStream out) {
        int x = in.nextInt();
        in.nextLine();
        for (int i = 1; i <= x; i++) {
            out.printf("Case #%d: %s\n", i, "");
            in.nextLine();
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Problem C = new ProC();
        String prepath = "C:\\Documents and Settings\\GreenTie\\My Documents\\NetBeansProjects\\GoogleCodeJam2013-1\\";
        String testname = "test";
        String smallname = "C-small-attempt0";
        String largename = "C-large";
        File tin = new File(prepath + testname + ".txt");
        File sin = new File(prepath + smallname + ".in");
        File lin = new File(prepath + largename + ".in");
        PrintStream testo = new PrintStream(prepath + testname + ".out");
        PrintStream smallo = new PrintStream(prepath + smallname + ".out");
        PrintStream largeo = new PrintStream(prepath + largename + ".out");
        //C.solveSmall(new Scanner(tin), testo);
        C.solveSmall(new Scanner(sin), smallo);
        //System.out.println(prepath + smallname + ".out");
        //C.solveLarge(new Scanner(lin), largeo);
        //System.out.println(prepath + largename + ".out");
    }
}

class Attack implements java.lang.Comparable<Attack> {

    public int strength;
    public int day;
    public int a;
    public int b;

    public Attack(int day, int strength, int a, int b) {
        this.day = day;
        this.strength = strength;
        this.a = a;
        this.b = b;
    }

    @Override
    public String toString() {
        return String.format("day%d:[%d,%d],%d\n", day, a, b, strength);
    }

    @Override
    public int compareTo(Attack o) {
        if (this.day < o.day) {
            return -1;
        } else if (this.day == o.day) {
            return 0;
        } else {
            return 1;
        }
    }
}
