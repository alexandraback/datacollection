import java.io.*;
import java.util.Arrays;
import java.util.Scanner;
import java.util.concurrent.Callable;

public class Diamond {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new BufferedInputStream(new FileInputStream("A-small-attempt0.in")));
        final PrintStream out = new PrintStream(new FileOutputStream("A-small-attempt0.out"));
        int nTests = scanner.nextInt();
        for (int test = 1; test <= nTests; test++) {
            final int n = scanner.nextInt();
            final int[][] a = new int[n][];
            for (int f = 0; f < n; f++) {
                int m = scanner.nextInt();

                a[f] = new int[m];
                for (int g = 0; g < m; g++) {
                    a[f][g] = scanner.nextInt() - 1;
                }
            }
            final int[] mark = new int[n];
            Arrays.fill(mark, -1);
            try {
                for (int f = 0; f < n; f++) {
                    if (mark[f] != -1)
                        continue;
                    final int finalF = f;
                    new Callable<Void>() {

                        @Override
                        public Void call() throws Exception {
                            dfs(finalF, finalF);
                            return null;
                        }

                        private void dfs(int v, int value) throws Exception {
                            mark[v] = value;
                            for (int child : a[v]) {
                                if (mark[child] != value)
                                    dfs(child, value);
                                else
                                    throw new Exception();
                            }

                        }
                    }.call();
                }
            } catch (Exception e) {
//                e.printStackTrace();
                out.printf("Case #%d: Yes\n", test);
                continue;
            }
            out.printf("Case #%d: No\n", test);
        }
        out.close();
    }
}
