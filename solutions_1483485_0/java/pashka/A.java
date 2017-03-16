import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.StringBufferInputStream;
import java.util.Scanner;

/**
 * To be documented
 *
 * @author Pavel Mavrin
 */
public class A {


    private static char[] map;

    public static void main(String[] args) throws FileNotFoundException {
        String s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi\n" +
                "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd\n" +
                "de kr kd eoya kw aej tysr re ujdr lkgc jvq";
        String s2 = "our language is impossible to understand\n" +
                "there are twenty six factorial possibilities\n" +
                "so it is okay if you want to just give upz";

        map = new char[256];
        boolean[] z = new boolean[256];
        for (int i = 0; i < s1.length(); i++) {
            map[s1.charAt(i)] = s2.charAt(i);
            z[s2.charAt(i)] = true;
        }

        for (char c = 'a'; c <= 'z'; c++) {
            if (!z[c]) map['z'] = c;
        }

        for (char c = 'a'; c <= 'z'; c++) {
            if (map[c] == 0) System.out.println("!!!" + c);
        }

        Scanner in = new Scanner(new File(A.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(A.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        in.nextLine();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new A().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        String s = in.nextLine();
        StringBuffer res = new StringBuffer();
        for (int i = 0; i < s.length(); i++) {
            res.append(map[s.charAt(i)]);
        }
        return res.toString();
    }
}
