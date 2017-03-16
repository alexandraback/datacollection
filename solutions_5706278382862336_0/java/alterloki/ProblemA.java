package y2014.contest.r1c;

import common.ParseUtil;

import java.util.ArrayList;
import java.util.List;

/**
 * Created with IntelliJ IDEA.
 * User: ashevenkov
 * Date: 11.05.14
 * Time: 13:00
 * To change this template use File | Settings | File Templates.
 */
public class ProblemA {

    static String INPUT =
            "5\n" +
                    "1/2\n" +
                    "3/4\n" +
                    "1/4\n" +
                    "2/23\n" +
                    "123/31488";

    public static void main(String[] args) {
        //new ProblemA().run(INPUT);
        new ProblemA().run(ParseUtil.parseFile("A-small-attempt1.in"));
    }

    private void run(String input) {
        String[] lines = input.split("\n");
        int ln = 0;
        int n = Integer.parseInt(lines[ln++]);
        for (int i = 0; i < n; i++) {
            String line = lines[ln++];
            String[] parts = line.split("/");
            long p = Long.parseLong(parts[0]);
            long q = Long.parseLong(parts[1]);
            System.out.println("Case #" + (i + 1) + ": " + solve(p, q));
        }
    }

    private String solve(long p, long q) {
        long result = 0;
        while(p < q) {
            if(q % 2 != 0) {
                return "impossible";
            }
            q = q / 2;
            result++;
        }
        while(q > 2) {
            if(q % 2 != 0) {
                return "impossible";
            }
            q = q / 2;
        }
        return Long.toString(result);
    }
}
