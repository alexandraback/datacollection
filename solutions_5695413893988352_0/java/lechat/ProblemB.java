import com.sun.java_cup.internal.runtime.lr_parser;

import java.io.PrintWriter;
import java.util.*;
import java.util.Queue;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.math.*;


public class ProblemB {

    private static final int CPU_CORES = 8;

    public static String solve(String s1, String s2) {
        int q1 = 0;
        for(int i=0; i<s1.length(); i++) {
            if(s1.charAt(i)=='?') {
                q1++;
            }
        }

        int q2 = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s2.charAt(i) == '?') {
                q2++;
            }
        }

        List<String> perm1 = new ArrayList<>();
        perm(q1, 0, new char[q1], perm1);
        List<String> perm2 = new ArrayList<>();
        perm(q2, 0, new char[q2], perm2);

        int min = Integer.MAX_VALUE;
        for(int i=0; i<perm1.size(); i++) {
            for(int j=0; j<perm2.size(); j++) {
                min = Math.min(min, Math.abs(convert(perm1.get(i), s1)-convert(perm2.get(j), s2)));
            }
        }

        List<String[]> pairs = new ArrayList<>();

        for (int i = 0; i < perm1.size(); i++) {
            for (int j = 0; j < perm2.size(); j++) {
                int diff = Math.abs(convert(perm1.get(i), s1) - convert(perm2.get(j), s2));
                if(diff == min) {
                    pairs.add(new String[]{make(perm1.get(i), s1), make(perm2.get(j), s2)});
                }
            }
        }

        min = Integer.MAX_VALUE;
        for(int i=0; i<pairs.size(); i++) {
            min = Math.min(min, Integer.parseInt(pairs.get(i)[0]));
        }

        List<String[]> matchingPairs = new ArrayList<>();
        for(int i=0; i<pairs.size(); i++) {
            int n = Integer.parseInt(pairs.get(i)[0]);
            if(n==min) {
                matchingPairs.add(pairs.get(i));
            }
        }

        pairs = matchingPairs;

        min = Integer.MAX_VALUE;
        for (int i = 0; i < pairs.size(); i++) {
            min = Math.min(min, Integer.parseInt(pairs.get(i)[1]));
        }

        for (int i = 0; i < pairs.size(); i++) {
            int n = Integer.parseInt(pairs.get(i)[1]);
            if (n == min) {
                return pairs.get(i)[0] + " " + pairs.get(i)[1];
            }
        }

        return "HMMMM something is wrong";
    }

    static String make(String perm, String num) {
        for (int i = 0; i < perm.length(); i++) {
            num = num.replaceFirst("\\?", perm.charAt(i) + "");
        }
        return num;
    }

    static int convert(String perm, String num) {
        return Integer.parseInt(make(perm, num));
    }

    public static void perm(int k, int i, char[] r, List<String> res) {
        if(i==k) {
            res.add(new String(r));
            return;
        }

        for (int n=0; n<10; n++) {
            r[i] = (char)(n+'0');
            perm(k, i+1, r, res);
        }
    }

    public static void main(String[] args) {
        ExecutorService exec = Executors.newFixedThreadPool(CPU_CORES);

        Queue<Future<String>> resultQueue = new ArrayDeque<>();

        try (Scanner sc = new Scanner(System.in); PrintWriter out = new PrintWriter(System.out)) {
            int T = sc.nextInt();
            sc.nextLine();

            for (int i = 1; i <= T; i++) {
                final String s1 = sc.next();
                final String s2 = sc.next();
                // Read test case input
                Future<String> future = exec.submit(
                        new Callable<String>() {
                            @Override
                            public String call() throws Exception {
                                return solve(s1, s2);
                            }
                        });
                resultQueue.offer(future);
            }

            int i = 1;
            while (!resultQueue.isEmpty()) {
                out.println("Case #" + (i++) + ": " + resultQueue.poll().get());
            }
        } catch (Throwable ex) {
            System.out.println(ex.getMessage());
            ex.printStackTrace();
        } finally {
            exec.shutdownNow();
        }
    }
}