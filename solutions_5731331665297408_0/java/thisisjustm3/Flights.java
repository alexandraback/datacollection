import java.io.*;
import java.math.BigInteger;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;

/**
 * @author arshsab
 * @since 05 2014
 */

public class Flights {
    public static void main(String[] args) throws IOException {
         ds(args);
    }

    public static void ds(String... args) throws IOException {
        String FILE_NAME = "flights";

        BufferedReader br = new BufferedReader(new FileReader(FILE_NAME + ".in"));

        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(FILE_NAME + ".out")));

        int T = Integer.parseInt(br.readLine());

        for (int t = 1; t <= T; t++) {
            System.out.println("New Test Case");

            String[] log = br.readLine().split(" ");

            final int N = Integer.parseInt(log[0]);
            final int M = Integer.parseInt(log[1]);

            int[] zips = new int[N];

            for (int i = 0; i < N; i++) {
                zips[i] = Integer.parseInt(br.readLine());
            }

            boolean[][] flights = new boolean[N][N];

            for (int i = 0; i < M; i++) {
                String[] flight = br.readLine().split(" ");

                int from = Integer.parseInt(flight[0]) - 1;
                int to = Integer.parseInt(flight[1]) - 1;

                flights[to][from] = flights[from][to] = true;
            }

            BigInteger bn = null;
            ArrayList<Integer> minPath = new ArrayList<>();

            outer:
            for (int[] perm : allPermutations(N)) {
                ArrayList<Integer> path = new ArrayList<>();

                Deque<Integer> stack = new ArrayDeque<>();

                int curr = perm[0];

                path.add(curr);

                for (int i = 1; i < perm.length; i++) {
                    while (!flights[curr][perm[i]]) {
                        if (stack.isEmpty()) {
                            continue outer;
                        }

                        curr = stack.pop();
                    }

                    stack.push(curr);

                    curr = perm[i];

                    path.add(curr);
                }

                String s = "";

                for (int aInt : perm) {
                    s += zips[aInt];
                }

                BigInteger potMin = new BigInteger(s);

                if (bn == null) {
                    bn = potMin;
                    minPath = path;
                } else if (bn.compareTo(potMin) >= 0) {
                    bn = potMin;
                    minPath = path;
                }
            }

            System.out.println(minPath);

            out.printf("Case #%d: %s\n", t, bn.toString());

        }

        out.flush();
        out.close();
    }

    public static ArrayList<int[]> allPermutations(int N) {
        ArrayList<int[]> all = new ArrayList<>();

        int[] arr = new int[N];

        for (int i = 0; i < arr.length; i++) {
            arr[i] = i;
        }

        int[] positions = new int[N];

        allPermutations(all, arr, positions, 0);

        return all;
    }

    public static void allPermutations(ArrayList<int[]> accum, int[] left, int[] positions, int pos) {
        boolean found = false;

        for (int aLeft : left) {
            if (aLeft != -1) {
                found = true;
                break;
            }
        }

        if (!found) {
            accum.add(Arrays.copyOf(positions, positions.length));
            return;
        }

        for (int i = 0; i < left.length; i++) {
            if (left[i] == -1) continue;

            int temp = left[i];
            left[i] = -1;
            positions[pos] = temp;
            allPermutations(accum, left, positions, pos + 1);
            left[i] = temp;
        }
    }
}
