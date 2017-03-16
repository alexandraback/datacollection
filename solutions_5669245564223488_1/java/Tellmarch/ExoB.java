package exoB;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author jean
 */
public class ExoB {

    public static void main(String[] args) {


        String base = "/home/jean/gcj2014/1c/ExoB/";
        String input = base + "b4.in";
        String output = base + "b4.out";

        try {
            Scanner sc = new Scanner(new FileReader(input));
            PrintWriter pw = new PrintWriter(output);

            int n = sc.nextInt();
            sc.nextLine();
            for (int c = 0; c < n; c++) {
                System.out.println("Test case " + (c + 1) + "...");
                pw.print("Case #" + (c + 1) + ": ");
                test(sc, pw);
                pw.println();
            }
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(ExoB.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    private static void test(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        sc.nextLine();
        String[] ct = sc.nextLine().split(" ");

        int d[] = new int[26];
        int f[] = new int[26];
        int m[] = new int[26];
        int a[] = new int[26];

        int cyc[] = new int[26];
        for (int i = 0; i < 26; i++) {
            cyc[i] = -1;
        }

        for (int i = 0; i < N; i++) {
            List<Character> l = new ArrayList<Character>();
            int il = ct[i].length();
            char cd = ct[i].charAt(0);
            l.add(cd);
            char ce = ct[i].charAt(il - 1);
            if (cd == ce) {
                //System.out.println(" * " + ct[i] + " is a for " + ce);
                a[ce - 'a']++;
            } else {
                //System.out.println(" * " + ct[i] + " is d for " + cd);
                d[cd - 'a']++;
                //System.out.println(" * " + ct[i] + " is f for " + ce);
                f[ce - 'a']++;
            }
            char pc = cd;
            for (int j = 1; j < il - 1; j++) {
                char c = ct[i].charAt(j);
                if (c != pc) {
                    pc = c;
                    if (l.contains(c)) {
                        System.out.println("impossible in " + ct[i]);
                        pw.print("0");
                        return;
                    }
                    l.add(c);
                    if (c != ce) {
                        //System.out.println(" * " + ct[i] + " is m for " + c);
                        m[c - 'a']++;
                    }
                }
            }

            if (pc != ce && l.contains(ce)) {
                System.out.println("******** impossible in " + ct[i]);
                pw.print("0");
                return;
            }

            if (cd != ce) {
                cyc[cd - 'a'] = ce - 'a';
            }
        }

        for (int i = 0; i < 26; i++) {
            if (d[i] > 1 || (d[i] == 1 && m[i] > 0)) {
                System.out.println("impossible starting with " + (char) ('a' + i));
                pw.print("0");
                return;
            }
            if (f[i] > 1 || (f[i] == 1 && m[i] > 0)) {
                System.out.println("impossible ending with " + (char) ('a' + i));
                pw.print("0");
                return;
            }
            if (m[i] > 1) {
                System.out.println("impossible middle with " + (char) ('a' + i));
                pw.print("0");
                return;
            }
        }

        // check for cycles
        for (int i = 0; i < 26; i++) {
            if (cycle(cyc, i)) {
                System.out.println("EEEEEEEEEEEEEEEE cycle");
                pw.print("0");
                return;
            }
        }


        long t = 1;
        for (int i = 0; i < 26; i++) {
            t = (t * fact(a[i])) % 1000000007;
        }

        //number of groups
        int g = N;
        for (int i = 0; i < 26; i++) {
            if (d[i] > 0 && f[i] > 0 && a[i] == 0) {
                g--;
            }
            if (d[i] > 0 && a[i] > 0) {
                g--;
            }
            if (a[i] > 0 && f[i] > 0) {
                g--;
            }
            if (a[i] > 0) {
                g = g - (a[i] - 1);
            }
        }
        System.out.println("found " + g + " groups");


        t = (t * fact(g)) % 1000000007;
        pw.print(t);
    }

    public static long fact(int i) {
        if (i == 0) {
            return 1;
        } else {
            return (i * fact(i - 1)) % 1000000007;
        }
    }

    private static boolean cycle(int[] cyc, int i) {
        int c = i;
        for (int j = 0; j < 30; j++) {
            if (c != -1) {
                c = cyc[c];
            }
        }
        if (c == -1) {
            return false; 
        } else {
            return true;
        }
    }
}
