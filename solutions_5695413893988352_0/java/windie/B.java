import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by linxy on 4/29/16.
 */
public class B {

    private static String toString(int num, int length) {
        String s = Integer.toString(num);
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < length - s.length(); i++) {
            builder.append('0');
        }
        builder.append(s);
        return builder.toString();
    }

    private static boolean isMatch(String s, int num) {
        String ns = toString(num, s.length());
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '?') {
                continue;
            }
            if (c != ns.charAt(i)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new FileInputStream("B-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new FileOutputStream("B-small-attempt0.out"));
        int numCase = in.nextInt();
        in.nextLine();
        for (int caseNum = 1; caseNum <= numCase; caseNum++) {
            out.print("Case #" + caseNum + ": ");
            String line = in.nextLine();
            String[] splits = line.split(" ");
            int bestI = 0;
            int bestJ = 0;
            int bestAbs = -1;
            int maxV;
            int len = splits[0].length();
            if (len == 1) {
                maxV = 10;
            } else if (len == 2) {
               maxV = 100;
            } else {
                maxV = 1000;
            }
            for (int i = 0; i < maxV; i++) {
                for (int j = 0; j < maxV; j++) {
                    if (isMatch(splits[0], i) && isMatch(splits[1], j)) {
                        int abs = Math.abs(i - j);
                        if (bestAbs < 0 || bestAbs > abs) {
                            bestI = i;
                            bestJ = j;
                            bestAbs = abs;
                        }
                    }
                }
            }
            out.println(toString(bestI, len) + " " + toString(bestJ, len));
        }
        in.close();
        out.close();
    }
}
