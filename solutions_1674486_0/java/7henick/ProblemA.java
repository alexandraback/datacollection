import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

/**
 * Google Code Jam 2012 Round 1C
 * 
 * @author 7henick
 */
public class ProblemA {

    public static void main(String[] args) {
        // Date time = new Date();

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < T; i++) {
            int N = sc.nextInt();

            Map<Integer, List<Integer>> map = new HashMap<Integer, List<Integer>>();

            for (int j = 1; j <= N; j++) {
                sc.nextLine();
                map.put(j, new ArrayList<Integer>());
                int M = sc.nextInt();

                for (int k = 0; k < M; k++) {
                    int I = sc.nextInt();
                    map.get(j).add(I);
                }
            }

            String result = "No";
            for (Integer a : map.keySet()) {
                for (Integer n : map.keySet()) {
                    if (a == n) {
                        continue;
                    }

                    if (findPath(map, a, n) > 1) {
                        result = "Yes";
                        break;
                    }
                }
            }

            System.out.println("Case #" + (i + 1) + ": " + result);
            if (sc.hasNextLine()) {
                sc.nextLine();
            }
        }

        // Date newTime = new Date();
        // System.out.println((newTime.getTime() - time.getTime()) / 1000.0);
    }

    public static int findPath(Map<Integer, List<Integer>> map, int x, int y) {
        int count = 0;
        List<Integer> list = map.get(x);

        for (Integer n : list) {
            if (n == y) {
                count++;
                continue;
            }
            count += findPath(map, n, y);
        }

        return count;
    }
}