import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class cj7 {
  public static void main(String[] args) throws Exception {
    final Scanner scanner = new Scanner(new File("D:\\unsorted\\in.txt"));
    final int T = scanner.nextInt();
    for (int t = 1; t <= T; t++) {
      final int A = scanner.nextInt(), N = scanner.nextInt();
      final int[] motes = new int[N];
      for (int n = 0; n < N; n++)
        motes[n] = scanner.nextInt();
      Arrays.sort(motes);

      System.out.println("Case #" + t + ": " + solve(motes, A, 0, N, 0));
    }
  }

  public static int solve(int[] motes, int size, int position, int N, int changes) {
    if (position == N) {
      return changes;
    }
    if (size > motes[position]) {
      return solve(motes, size + motes[position], position + 1, N, changes);
    }

    if (size < 2) {
      return solve(motes, size, position + 1, N, changes + 1);
    }

    return Math.min(
      solve(motes, size + size - 1, position, N, changes + 1),
      solve(motes, size, position + 1, N, changes + 1)
    );
  }
}
