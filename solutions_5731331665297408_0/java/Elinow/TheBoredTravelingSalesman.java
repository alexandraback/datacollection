import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.Scanner;

import org.apache.commons.lang3.StringUtils;

import com.google.common.collect.Collections2;

public class TheBoredTravelingSalesman {
    private static final String inputName = "e:/downloads/C-small-attempt0.in";
    private static final String outputName = "C:/workspaces/algo/GCJ/src/prolemC.out";

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new FileReader(inputName));
        // Scanner sc = new Scanner(System.in);
        BufferedWriter bw = new BufferedWriter(new FileWriter(outputName));
        int T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            String[] zips = new String[N];
            for (int i = 0; i < N; i++) {
                zips[i] = sc.next();
            }
            boolean[][] flights = new boolean[N][N];
            for (int i = 0; i < M; i++) {
                int start = sc.nextInt();
                int end = sc.nextInt();
                flights[start - 1][end - 1] = true;
                flights[end - 1][start - 1] = true;
            }
            String res = solve(N, M, zips, flights);
            String str = String.format("Case #%s: %s\n", t + 1, res);
            bw.write(str);
            System.out.print(str);
        }
        bw.close();
    }

    private static String solve(int n, int m, String[] zips, boolean[][] flights) {
        if (n == 1) {
            return zips[0];
        }
        List<Integer> cities = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            cities.add(i);
        }
        Collection<List<Integer>> permutations = Collections2.permutations(cities);
        String res = StringUtils.repeat('9', 200);
        for (List<Integer> perm : permutations) {
            String tempRes = "";
            for (int i = 0; i < perm.size(); i++) {
                tempRes += zips[perm.get(i)];
            }
            if (tempRes.compareTo(res) < 0) {
                if (check(n, m, perm, flights)) {
                    res = tempRes;
                }
            }
        }
        return res;
    }

    private static boolean check(int n, int m, List<Integer> perm, boolean[][] flights) {
        List<Integer> visited = new ArrayList<>();
        visited.add(perm.get(0));
        for (int i = 1; i < perm.size(); i++) {
            int city = perm.get(i);
            boolean flew = false;
            while (!visited.isEmpty() && !flew) {
                int prev = visited.get(visited.size() - 1);
                if (flights[prev][city]) {
                    visited.add(city);
                    flew = true;
                } else {
                    visited.remove(visited.size() - 1);
                }
            }
            if (!flew) {
                return false;
            }
        }
        return true;
    }

}
