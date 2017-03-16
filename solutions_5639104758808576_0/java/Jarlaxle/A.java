import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class A {
    private static final String inFile = "A-small-attempt0.in";
    private static final String outFile = "A-out.txt";

    public static void main(String args[]) throws IOException {
        Scanner scanner = new Scanner(new FileReader(inFile));
        String input = scanner.next();
        int T = Integer.parseInt(input);
        FileWriter fw = new FileWriter(outFile);
        for (int t = 1; t <= T; ++t) {
            scanner.next();
            input = scanner.next();
            List<Integer> s = new ArrayList<Integer>();
            for (int i = 0; i < input.length(); ++i) {
                int c = input.charAt(i) - '0';
                for (int j = 0; j < c; ++j) {
                    s.add(i);
                }
            }
            Collections.sort(s);
            fw.write(String.format("Case #%d: %d\n", t, solve(s)));
        }
        fw.close();
    }

    private static int solve(List<Integer> s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            res = Math.max(res, s.get(i) - i);
        }
        return res;
    }
}
