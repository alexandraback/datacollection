package codejam.c1;

import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Arrays;
import java.util.List;

public class Second {
    public static void main(String[] args) throws IOException {
        Path path = FileSystems.getDefault().getPath("in", "c1b.txt");
        List<String> allLines = Files.readAllLines(path);
        int num = Integer.parseInt(allLines.get(0));
        for (int i = 1; i <= num; i++) {
            solve(i, allLines.get(i));
        }
    }

    private static void solve(int i, String s) {
        long[] is = Arrays.stream(s.split("\\s")).mapToLong(Long::parseLong).toArray();
        int b = (int) is[0];
        long count = is[1];
        long start = 2;
        if (b == 2) {
            if (count == 1) {
                System.out.println("Case #" + i + ": POSSIBLE");
                System.out.println("01\n00");
            } else {
                System.out.println("Case #" + i + ": IMPOSSIBLE");
            }
            return;
        }
        int[][] matrix = new int[b][b];
        if (count == 1) {
            for (int j = 0; j < b; j++) {
                for (int k = 0; k < b; k++) {
                    if (j == k - 1) {
                        matrix[j][k] = 1;
                    }
                }
            }
            System.out.println("Case #" + i + ": POSSIBLE");
            print(matrix);
            return;
        }
        long[] all = new long[b - 1];
        all[0] = 2;
        for (int i1 = 1; i1 < all.length; i1++) {
            all[i1] = all[i1 - 1] * 2;
        }
        if (all[b - 3] < count) {
            System.out.println("Case #" + i + ": IMPOSSIBLE");
            return;
        }
        System.out.println("Case #" + i + ": POSSIBLE");
        for (int j = 0; j < all.length; j++) {
            int number = all.length - j;
            long target = all[number - 1];
            if (count >= target) {
                count -= target;
                mapAll(matrix, number + 1);
            }
        }
        if (count > 0) {
            count--;
            matrix[1][matrix.length - 1] = 1;
        }
        if (count > 0) {
            count--;
            matrix[0][matrix.length - 1] = 1;
        }
        if (count > 0) {
            System.err.println("fuck");
        }
        print(matrix);
    }

    private static void mapAll(int[][] matrix, int number) {
        for (int i = 0; i <= number; i++) {
            for (int j = 0; j < i; j++) {
                matrix[j][i] = 1;
            }
        }
        if (number != matrix.length - 1) {
            matrix[number][matrix.length - 1] = 1;
        }

    }

    private static void print(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int i1 = 0; i1 < matrix[i].length; i1++) {
                System.out.print(matrix[i][i1]);
            }
            System.out.println("");
        }
    }
}
