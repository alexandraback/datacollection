import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for (int caseNum = 1; caseNum <= cases; caseNum++) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            int K = sc.nextInt();

            int max = 2 * N + 2 * M - 4;
            int[][] board = new int[N][M];
            for (int bitmask = 0; bitmask < (1 << (N * M)); bitmask++) {
                int count = 0;
                for (int n = 0; n < N; n++) {
                    for (int m = 0; m < M; m++) {
                        int index = n * M + m;
                        if ((bitmask & (1 << index)) == 0) {
                            board[n][m] = 0;
                        } else {
                            board[n][m] = 1;
                            count++;
                        }
                    }
                }
                if (count >= max) {
                    continue;
                }
                int enclosed = countEnclosed(board, N, M);
                if (enclosed >= K) {
                    max = count;
                }
            }
            System.out.println("Case #" + caseNum + ": " + max);
        }
    }

    private static int countEnclosed(int[][] board, int N, int M) {
        Set<Integer> seen = new HashSet<Integer>();
        Deque<Integer> queue = new ArrayDeque<Integer>();
        for (int n = 0; n < N; n++) {
            if (board[n][0] == 0) {
                queue.add(n * M);
            }
            if (board[n][M - 1] == 0) {
                queue.add(n * M + M - 1);
            }
        }
        for (int m = 1; m < M - 1; m++) {
            if (board[0][m] == 0) {
                queue.add(m);
            }
            if (board[N - 1][m] == 0) {
                queue.add((N - 1) * M + m);
            }
        }
        while (!queue.isEmpty()) {
            Integer curr = queue.poll();
            if (seen.contains(curr)) {
                continue;
            }
            seen.add(curr);
            int n = curr / M;
            int m = curr % M;
            if (n > 0 && board[n - 1][m] == 0 && !seen.contains(curr - M)) {
                queue.add(curr - M);
            }
            if (m > 0 && board[n][m - 1] == 0 && !seen.contains(curr - 1)) {
                queue.add(curr - 1);
            }
            if (n < N - 1 && board[n + 1][m] == 0 && !seen.contains(curr + M)) {
                queue.add(curr + M);
            }
            if (m < M - 1 && board[n][m + 1] == 0 && !seen.contains(curr + 1)) {
                queue.add(curr + 1);
            }
        }
        return M * N - seen.size();
    }
}
