import java.io.*;
import java.util.HashSet;
import java.util.Set;

public class C {

    private static final String FILE = "C-small-attempt0";

    private static final boolean SAVE_OUT = true;

    public static void main(String[] args) throws IOException {
        BufferedReader in = createReader();
        FileWriter out;
        if (SAVE_OUT) {
            out = new FileWriter(FILE + ".out");
        }
        int t = Integer.parseInt(in.readLine());
        int c = 0;
        while (t-- > 0) {
            String row = in.readLine();
            String[] split = row.split(" ");
            int a = Integer.parseInt(split[0]);
            int b = Integer.parseInt(split[1]);
            int num = 0;
            for (int i = a; i <= b; ++i) {
                num += calc(i, a, b);
            }
            String res = String.format("Case #%d: %d", ++c, num / 2);
            System.out.println(res);
            if (SAVE_OUT) {
                out.append(res);
                out.append("\n");
            }
        }
        if (SAVE_OUT) {
            out.close();
        }
    }

    private static int calc(int c, int a, int b) {
        int num = 0;
        String s = Integer.toString(c);
        Set<Integer> seen = new HashSet<Integer>();
        for (int i = 1; i < s.length(); ++i) {
            int cc = flip(s, i);
            while (cc <= b) {
                if (seen.contains(cc)) {
                    break;
                }
                if (cc >= a && c != cc) {
                    ++num;
                    seen.add(cc);
                }
                cc *= 10;
            }
        }
        return num;
    }

    private static int flip(String s, int k) {
        String first = s.substring(0, k);
        StringBuilder sb = new StringBuilder();
        sb.append(s.substring(k));
        sb.append(first);
        while (sb.charAt(0) == '0') {
            sb.deleteCharAt(0);
        }
        return Integer.parseInt(sb.toString());
    }

    private static BufferedReader createReader() throws FileNotFoundException {
        return new BufferedReader(new FileReader(FILE + ".in"));
    }
}
