package gcj2014.round1C;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.TreeSet;
import java.util.Vector;

/**
 * Created by khabat95 on 11/05/14.
 */
public class b {

    public static String alg(Vector<String> trains) {
        TreeSet<Integer> done = new TreeSet<Integer>();
        long res = rec("", done, trains);
        return String.valueOf(res % 1000000007);
    }

    private static long rec(String s, TreeSet<Integer> done, Vector<String> trains) {
        if (done.size() == trains.size()) {
            return check(s);
        }
        if (check(s) == 0)
            return 0;
        long res = 0;
        for (int i=0; i<trains.size(); ++i) {
            if (!done.contains(i)) {
                String newS = s + trains.get(i);
                TreeSet<Integer> newDone = new TreeSet<Integer>(done);
                newDone.add(i);
                res += rec(newS, newDone, trains);
            }
        }
        return res;
    }

    private static long check(String s) {
        TreeSet<Character> chars = new TreeSet<Character>();
        char c = s.charAt(0);
        chars.add(c);
        for (int i=0; i<s.length(); i++) {
            if (s.charAt(i) != c) {
                if (chars.contains(s.charAt(i))) {
                    return 0;
                } else {
                    c = s.charAt(i);
                    chars.add(c);
                }
            }
        }
        return 1;
    }

    public static void main(String args[]) {
        try {
            Scanner sc = new Scanner(new FileReader("/home/khabat95/gcj2014/round1C/b1.in"));
            PrintWriter pw = new PrintWriter("/home/khabat95/gcj2014/round1C/b1.out");

            int T = sc.nextInt();
            for (int i = 0; i < T; i++) {
                int n = sc.nextInt();
                Vector<String> trains = new Vector<String>();
                for (int j=0; j<n; ++j) {
                    trains.add(sc.next());
                }
                System.out.println("Test case " + (i + 1) + "...");
                pw.println("Case #" + (i + 1) + ": " + alg(trains));
            }

            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
