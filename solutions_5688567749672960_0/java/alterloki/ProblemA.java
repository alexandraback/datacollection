package y2015.contest.r1b;

import java.io.*;
import java.util.*;

/**
 * @author ashevenkov
 */
public class ProblemA {

    public static final String TITLE = "A-small-attempt0";
    private static BufferedReader in = prodIn();
    private static BufferedWriter out = prodOut();

    private static BufferedWriter prodOut() {
        try {
            return new BufferedWriter(new FileWriter("codejam/output/" + TITLE + ".out"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    private static BufferedReader prodIn() {
        try {
            return new BufferedReader(new FileReader("codejam/input/" + TITLE + ".in"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return null;
    }


    private static BufferedWriter testOut() {
        return new BufferedWriter(new OutputStreamWriter(System.out));
    }

    private static BufferedReader testIn() {
        return new BufferedReader(new InputStreamReader(System.in));
    }

    public static void main(String[] args) throws Exception {
        new ProblemA().solve(in, out);
        out.flush();
        out.close();
    }

    //implement
    private void solve(BufferedReader in, BufferedWriter out) throws Exception {
        Scanner scanner = new Scanner(in);
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            long n = scanner.nextInt();
            out.write("Case #" + (i + 1) + ": " + solveCase(n));
            out.newLine();
        }
    }

    private long solveCase(long k) {
        int n = (int)k;
        Map<Integer, Boolean> was = new HashMap<>();
        List<Integer> queue = new ArrayList<>();
        queue.add(1);
        long count = 0;
        while(true) {
            count++;
            List<Integer> list = new ArrayList<>();
            for(int num: queue) {
                if(num == k) {
                    return count;
                }
                int a = num + 1;
                int b = (int)reverse(num);
                if(was.get(a) == null) {
                    list.add(a);
                    was.put(a, true);
                }
                if(was.get(b) == null) {
                    list.add(b);
                    was.put(b, true);
                }

            }
            queue = list;
        }
    }

    private long reverse(long n) {
        String result = new StringBuilder(Long.toString(n)).reverse().toString();
        return Long.parseLong(result);
    }


}
