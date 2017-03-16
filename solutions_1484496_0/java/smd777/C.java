package gcj2012.r1b;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

/**
 *
 * @author Scott DellaTorre
 */
public class C {

    public static void main(String[] args) throws IOException {
        try (BufferedReader in = new BufferedReader(new FileReader("src/gcj2012/r1b/in"));
                PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/gcj2012/r1b/C.out")));) {

            int T = Integer.parseInt(in.readLine());
            for (int i = 0; i < T; i++) {
                StringTokenizer st = new StringTokenizer(in.readLine());
                int N = Integer.parseInt(st.nextToken());
                List<Integer> S = new ArrayList<>(N);
                for (int j = 0; j < N; j++) {
                    S.add(Integer.parseInt(st.nextToken()));
                }

                List[] lists = new List[2000000];

                List[] match = findMatch(lists, new ArrayList<Integer>(), S, 0);

                out.print("Case #" + (i + 1) + ": ");
                if (match == null) {
                    out.println("Impossible");
                } else {
                    out.println();
                    for (int j = 0; j < match[0].size(); j++) {
                        out.print(match[0].get(j));
                        if (j < match[0].size() - 1) {
                            out.print(" ");
                        }
                    }
                    out.println();
                    for (int j = 0; j < match[1].size(); j++) {
                        out.print(match[1].get(j));
                        if (j < match[1].size() - 1) {
                            out.print(" ");
                        }
                    }
                    out.println();
                }

            }
        }
    }

    private static List[] findMatch(List[] lists, List<Integer> currList, List<Integer> S, int sum) {
        System.out.println(sum);
        if (sum != 0) {
            if (lists[sum] != null) {
                return new List[]{lists[sum], currList};
            } else {
                lists[sum] = currList;
            }
        }
        for (int i = 0; i < S.size(); i++) {
            List<Integer> newList = new ArrayList<>(currList);
            int num = S.remove(i);
            newList.add(num);
            List[] match = findMatch(lists, currList, S, sum + num);
            if (match != null) {
                return match;
            }
            S.add(i, num);
        }
        return null;
    }
}
