
import java.io.File;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class C {

    public static void main(String args[]) throws Exception {
        final String PATH = "/home/goalboy/software installation/codejam-commandline-1.0-beta4/source/";
        final String FILE = "C-large-0";
        Scanner in = new Scanner(new File(PATH + FILE + ".in"));
        PrintWriter out = new PrintWriter(PATH + FILE + ".out");

        int test = in.nextInt();
        for (int t = 1; t <= test; t++) {
            String strA = in.next();
            int A = Integer.parseInt(strA);
            int B = in.nextInt();
            int length = strA.length();
            int result = 0;
            for (int n = A; n < B; n++) {
                String rotated = n + "";
                HashSet<Integer> setM = new HashSet<Integer>();
                for (int i = 0; i < length - 1; i++) {
                    rotated = rotated.substring(1) + rotated.charAt(0);
                    if (rotated.charAt(0) == '0') {
                        continue;
                    }
                    int m = Integer.parseInt(rotated);
                    if (m > n && m <= B) {
                        setM.add(m);
                    }
                }
                result += setM.size();
            }
            out.println("Case #" + t + ": " + result);
        }

        out.close();
    }
}
