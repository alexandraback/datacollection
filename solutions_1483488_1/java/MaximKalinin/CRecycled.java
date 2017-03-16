import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class CRecycled {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("C-large.in"));
        PrintWriter out = new PrintWriter("C-large.out");
        final int T = in.nextInt();
        //final int T = 50;
        for (int t = 1; t <= T; ++t) {
            final int A = in.nextInt(), B = in.nextInt();
//            final int A = 1000000, B = 2000000;
            int result = 0;
            for (int n = A; n <= B; ++n) {
                String s = Integer.toString(n);
                Set<Integer> ms = new HashSet<Integer>();
                for (int i = 0; i+1 < s.length(); ++i) {
                    s = s.substring(1) + s.charAt(0);
                    int m = Integer.parseInt(s);
                    if (m > n && m <= B && s.charAt(0) != '0') {
                        ms.add(m);
                    }
                }
                result += ms.size();
            }
            out.println("Case #" + t + ": " + result);
        }
        out.close();
    }

}
