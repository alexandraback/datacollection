package y2014.contest.r1b;

import common.ParseUtil;

/**
 * Created with IntelliJ IDEA.
 * User: ashevenkov
 * Date: 03.05.14
 * Time: 19:55
 */
public class ProblemB {

    static String INPUT =
            "5\n" +
                    "3 4 2\n" +
                    "4 5 2\n" +
                    "7 8 5\n" +
                    "45 56 35\n" +
                    "103 143 88";

    public static void main(String[] args) {
        //new ProblemB().run(INPUT);
        new ProblemB().run(ParseUtil.parseFile("B-small-attempt0.in"));
    }

    private void run(String input) {
        String[] lines = input.split("\n");
        int ln = 0;
        int n = Integer.parseInt(lines[ln++]);
        for (int i = 0; i < n; i++) {
            String line = lines[ln++];
            String[] parts = line.split(" ");
            int a = Integer.parseInt(parts[0]);
            int b = Integer.parseInt(parts[1]);
            int k = Integer.parseInt(parts[2]);
            System.out.println("Case #" + (i + 1) + ": " + solve(a, b, k));
        }
    }

    private String solve(int a, int b, int k) {
        int result = 0;
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                int r = i & j;
                if(r < k) {
                    result++;
                }
            }
        }
        return Integer.toString(result);
    }
}
