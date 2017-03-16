import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Round1BProblemB {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(
                new InputStreamReader(new FileInputStream("B-small-attempt0.in")));
        String line = br.readLine();
        int T = Integer.parseInt(line);
        PrintWriter pw = new PrintWriter("B-small.out");

        for (int test = 0; test < T; test++) {
            line = br.readLine();
            String tokens[] = line.split(" ");
            pw.println("Case #" + (test + 1) + ": " + solve(tokens[0], tokens[1]));
        }
        pw.close();
        br.close();
    }

    private static String solve(String first, String second) {
        int diff = 1000;
        String sol1 = "";
        String sol2 = "";

        List<String> list1 = getMatching(first);
        List<String> list2 = getMatching(second);



        for (String s1 :list1) {
            int v1 = Integer.parseInt(s1);
            for (String s2 :list2) {
                int v2 = Integer.parseInt(s2);
                if (Math.abs(v1 - v2) < diff) {
                    sol1 = s1;
                    sol2 = s2;
                    diff = Math.abs(v1 - v2);
                }
            }
        }

        return sol1 + " " + sol2;

    }

    private static List<String> getMatching(String first) {
        int max = 10;
        if (first.length() == 2) max = 100;
        if (first.length() == 3) max = 1000;

        List<String> result = new ArrayList<>();
        for (int i = 0; i < max; i++) {
            String current = String.valueOf(i);
            while (current.length() < first.length()) {
                current = "0" + current;
            }
            boolean ok = true;
            for (int j = 0; j < first.length(); j++) {
                if (first.charAt(j) == '?') continue;
                if (first.charAt(j) != current.charAt(j)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                result.add(current);
            }
        }
        return result;
    }
}
