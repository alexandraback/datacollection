package codejam;

import java.io.*;
import java.util.*;

/**
 * Created by chengpan on 4/15/16.
 */
public class RandAndFile {

    public static void main(String[] args) throws Exception {
        final BufferedInputStream in = new BufferedInputStream(new FileInputStream(new File("B-small-attempt1.in")));
        Scanner sc = new Scanner(in);
        final BufferedWriter writer = new BufferedWriter(new FileWriter(new File("output.out")));

        int T = sc.nextInt();
        for (int i = 0; i<T;i++) {
            int N = sc.nextInt();

            int[][] h = new int[2*N-1][N];
            for (int j = 0; j < (2*N-1); j++) {
                for (int k = 0; k<N;k++) {
                    h[j][k] = sc.nextInt();
                }
            }

            writer.write(String.format("Case #%d: %s\n", i+1, solve(h)));
        }

        in.close();
        writer.close();

    }

    private static String solve(int[][] h) {

        int n = h.length;
        int k = h[0].length;

        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j<k; j++) {
                if (map.containsKey(h[i][j])) {
                    map.put(h[i][j], map.get(h[i][j])+1);
                } else {
                    map.put(h[i][j], 1);
                }
            }
        }

        List<Integer> nums = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (entry.getValue() % 2 != 0) {
                nums.add(entry.getKey());
            }
        }

        Collections.sort(nums);

        final StringBuilder sb = new StringBuilder();
        for (int num : nums) {
            sb.append(num);
            sb.append(" ");
        }

        return sb.toString();
    }
}
