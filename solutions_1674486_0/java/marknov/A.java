package googlejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class A {

    /**
     * @param args
     */
    public static final String FILE_IN = "A-small-attempt0.in";
    public static final String FILE_OUT = "A-small.out";
    public Scanner scanner;
    public PrintStream printer;
    public PrintStream writer;
    public int T, N;
    public int cases = 0;
    Node[] tree;

    class Node {

        List<Integer> child = new ArrayList<Integer>();
    }

    public void fill(int node, int[] ways) {
        for (int c : tree[node].child) {
            ways[c - 1]++;
            fill(c - 1, ways);
        }
    }

    public void solveProblem() {
        T = scanner.nextInt();
        while (cases++ < T) {
            N = scanner.nextInt();
            tree = new Node[N];
            for (int i = 0; i < N; i++) {
                int M = scanner.nextInt();
                tree[i] = new Node();
                for (int j = 0; j < M; j++) {
                    tree[i].child.add(scanner.nextInt());
                }
            }

            int[][] ways = new int[N][N];
            for (int i = 0; i < tree.length; i++) {
                ways[i] = new int[N];
                if (tree[i].child.size() > 1) {
                    fill(i, ways[i]);
                }
            }

            boolean isFound = false;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (ways[i][j] > 1) {
                        isFound = true;
                        break;
                    }
                }
                if (isFound) {
                    break;
                }
            }

            printer.format("Case #%d: %s\n", cases, (isFound) ? "Yes" : "No");
            writer.format("Case #%d: %s\n", cases, (isFound) ? "Yes" : "No");
        }
    }

    public void write(long num) {
        System.out.println(num);
    }

    public static void main(String[] args) {
        A googleJam = new A();
        googleJam.openFiles();
        googleJam.solveProblem();
        googleJam.closeFiles();
    }

    public int openFiles() {
        try {
            scanner = new Scanner(new File(FILE_IN));
            printer = new PrintStream(FILE_OUT);
            writer = System.out;
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
            return -1;
        }
        return 0;
    }

    public int closeFiles() {
        scanner.close();
        printer.close();
        return 0;
    }
}
