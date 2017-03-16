import java.awt.*;
import java.util.*;
import java.util.List;

public class JamB3 {
    private String result;
    private final int[] zip;
    private final boolean[][] matrix;

    JamB3(int[] zip, boolean[][] matrix) {
        this.zip = zip;
        this.matrix = matrix;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int i = 1; i <= T; i++) {
            int N = in.nextInt();
            int M = in.nextInt();
            boolean[][] matrix = new boolean[N][N];
            int[] zip = new int[N];
            for (int j = 0; j < N; j++) {
                zip[j] = in.nextInt();
            }

            for (int j = 0; j < M; j++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                matrix[a][b] = matrix[b][a] = true;
            }

            JamB3 jamB3 = new JamB3(zip, matrix);
            ArrayList<Integer> perm = new ArrayList<Integer>(N);
            for (int j = 0; j < N; j++) {
                perm.add(j);
            }
            jamB3.permutation(perm);
            System.out.println("Case #" + i + ": " + jamB3.result);
        }
        in.close();
    }

    public void permutation(ArrayList<Integer> perm) {
        permutation(Collections.<Integer>emptyList(), perm);
    }

    private void permutation(List<Integer> prefix, List<Integer> tail) {
        int n = tail.size();
        if (n == 0) {
            int start = prefix.get(0);
            Stack<Integer> current = new Stack<Integer>();
            current.push(start);
            for (int i = 1; i < prefix.size(); i++) {
                int next = prefix.get(i);
                boolean[] paths = matrix[next];
                while (!current.isEmpty()) {
                    if (paths[current.peek()]) {
                        current.push(next);
                        break;
                    } else
                        current.pop();
                }
                if (current.isEmpty())
                    return;
            }
            StringBuilder b = new StringBuilder();
            for (Integer integer : prefix) {
                b.append(zip[integer]);
            }
            String candidate = b.toString();
            if (result == null)
                result = candidate;
            else if (result.compareTo(candidate) > 0)
                result = candidate;
        } else {
            for (int i = 0; i < n; i++) {
                ArrayList<Integer> newTail = new ArrayList<Integer>(tail);
                Integer integer = newTail.remove(i);
                ArrayList<Integer> newPrefix = new ArrayList<Integer>(prefix);
                newPrefix.add(integer);
                permutation(newPrefix, newTail);
            }
        }
    }

}
