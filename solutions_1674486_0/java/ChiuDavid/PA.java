
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class PA {

    static boolean transverse(boolean[][] graph, boolean[][] end, int[] noInher, int from, int to) {
        if (end[from][to]) {
            return true;
        }
        boolean out = false;
        end[from][to] = true;
        if (noInher[to] > 0) {
            for (int i = 0; i < graph[to].length && !out; i++) {
                if (graph[to][i]) {
                    out = transverse(graph, end, noInher, from, i);
                }
            }
        }
        return out;
    }

    public static void main(String[] args) throws FileNotFoundException {
        if (args.length == 1) {
            File inFile = new File(args[0]);
            Scanner sc = new Scanner(inFile);
            PrintWriter out = new PrintWriter("out.txt");
            int T = sc.nextInt();
            for (int i = 0; i < T; i++) {
                out.printf("Case #%d: ", i + 1);
                int N = sc.nextInt();
                boolean[][] graph = new boolean[N][N];
                boolean[][] end = new boolean[N][N];
                int[] noInher = new int[N];
                for (int j = 0; j < N; j++) {
                    noInher[j] = sc.nextInt();
                    for (int k = 0; k < noInher[j]; k++) {
                        int to = sc.nextInt();
                        graph[j][to - 1] = true;
                    }
                }
                boolean found = false;
                for (int j = 0; j < N && !found; j++) {
                    if (noInher[j] >= 2) {
                        for (int k = 0; k < N && !found; k++) {
                            if (graph[j][k]) {
                                found = transverse(graph, end, noInher, j, k);
                            }
                        }
                    }
                }
                if (found) {
                    out.println("Yes");
                } else {
                    out.println("No");
                }
            }
            out.close();
            sc.close();
            System.out.println("Completed");
        }
    }
}
