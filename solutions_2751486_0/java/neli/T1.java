import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class T1 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("A-small-attempt0.in"));
        int cases = sc.nextInt();
        BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
        char[] vows = {'a', 'e', 'i', 'o', 'u'};
        nextCase:
        for (int ks = 0; ks < cases; ks++) {
            if (ks != 0) {
                out.newLine();
            }
            String s = sc.next();
            StringBuilder sb = new StringBuilder("");
            for (int i = 0; i < s.length(); i++) {
                if (Arrays.binarySearch(vows, s.charAt(i)) >= 0) {
                    sb.append('0');
                } else {
                    sb.append('1');
                }
            }
            s = sb.toString();
            int n = sc.nextInt();
            sb = new StringBuilder("");
            for (int i = 0; i < n; i++) {
                sb.append('1');
            }
            String pattern = sb.toString();
            int res = 0;
            for (int i = 0; i < s.length(); i++) {
                int ind = s.indexOf(pattern, i);
                if (ind >= 0) {
                    res += s.length() - (ind + pattern.length() - 1);
                } else {
                    break;
                }
            }
            out.write("Case #" + (ks + 1) + ": " + res);
        }
        out.close();
    }
}
