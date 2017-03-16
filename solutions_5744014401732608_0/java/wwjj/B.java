package r1c;

import com.google.common.base.Splitter;
import com.google.common.base.Strings;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class B {

    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(Files.newInputStream(Paths.get("in.txt")));
//        Scanner sc = new Scanner(Files.newInputStream(Paths.get("B-small-attempt0.in")));
//        Scanner sc = new Scanner(Files.newInputStream(Paths.get("B-small-attempt1.in")));
//        Scanner sc = new Scanner(Files.newInputStream(Paths.get("B-small-attempt2.in")));
//        Scanner sc = new Scanner(Files.newInputStream(Paths.get("B-small-attempt3.in")));
        Scanner sc = new Scanner(Files.newInputStream(Paths.get("B-small-attempt4.in")));
//        Scanner sc = new Scanner(Files.newInputStream(Paths.get("")));

        int num = sc.nextInt();
        String s = "";
        for (int i = 0; i < num; i++) {
            
            int b = sc.nextInt();
            long m = sc.nextLong();

            String line = String.format("Case #%d: %s\n", i + 1, solve(b, m));
            System.out.print(line);
            s += line;
        }

        Files.write(Paths.get("out.txt"), s.getBytes());
    }

    private static String solve(int b, long m) {
        long origM = m;
//        if (Math.pow(2, b - 2) < m) return "IMPOSSIBLE";

//        System.out.println("b = [" + b + "], m = [" + m + "]");

        StringBuilder ret = new StringBuilder();

        long[] cnts = new long[b];
        boolean[][] g = new boolean[b][b];
        Set<Integer> roots = new HashSet<>();
        cnts[0] = 1;

        int i = 1;
        for (; i < cnts.length && m > 0; i++) {
            roots.add(i);
            for (int j = i - 1; j >= 0; j--) {
                long rest = m - cnts[j];
                if (rest >= 0) {
                    cnts[i] += cnts[j];
                    g[i][j] = true;
//                    roots.remove(j);
                    m = rest;
                }
            }
            if (m == 0) break;
        }

//        System.out.println("i = " + i);
//        System.out.println("m = " + m);
//        System.out.println(Math.pow(2, b -1));

        if (m > 0) {
            if (Math.pow(2, b - 2) >= origM) throw new AssertionError();
            return "IMPOSSIBLE";
        }

        ret.append("POSSIBLE\n");

//        roots.remove(i);
//        for (int j = i; j + 1 < cnts.length; j++) {
//            g[j + 1][j] = true;
//        }

        for (Integer root : roots) {
            g[b - 1][root] = true;
        }

        for (int j = 0; j < b; j++) {
            for (int k = 0; k < b; k++) {
                boolean edge = g[b - j - 1][b - k - 1];
                ret.append(edge ? "1" : "0");
            }
            ret.append("\n");
        }

        String result = ret.toString().trim();

        check(result, m);


        return result;
    }

    private static void check(String result, long m) {
        List<String> lines = Splitter.on("\n").splitToList(result);
        lines = lines.subList(1, lines.size());

        long[] cnts = new long[lines.size()];
        cnts[0] = 1;
        String lastLine = lines.get(lines.size() - 1);
        if (!lastLine.equals(Strings.repeat("0", lines.size()))) throw new AssertionError();

        for (int i = lines.size() - 2; i >= 0; i--) {
            String lien = lines.get(i);
            for (int j = 0; j < lien.length(); j++) {
                if (lien.charAt(j) == '1') {
                    cnts[i] += cnts[j];
                }
            }
        }

        if (cnts[lines.size() - 1] != m) {
            System.out.println("cnts[lines.size() - 1] = " + cnts[lines.size() - 1]);
            System.out.println("m = " + m);
            throw new AssertionError();
        }

    }

}
