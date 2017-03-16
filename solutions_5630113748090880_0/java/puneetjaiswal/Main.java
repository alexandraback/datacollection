import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("RankandFile.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        RankandFile solver = new RankandFile();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++) {
            solver.solve(i, in, out);
        }
        out.close();
    }

    static class RankandFile {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            out.print("Case #" + testNumber + ": ");
            int N = in.nextInt();
            int[] missing = new int[N];
            int heights[] = new int[2501];
            for (int i = 0; i < 2 * N - 1; i++) {
                for (int j = 0; j < N; j++) {
                    int k = in.nextInt();
                    heights[k]++;
                }
            }
            int count = 0;
            for (int i = 0; i < heights.length; i++) {
                if (heights[i] % 2 == 1) {
                    missing[count++] = i;
                }
            }
            Arrays.sort(missing);
            String output = "";
            for (int i = 0; i < missing.length; i++) {
                if (i != 0) {
                    output += " ";
                }
                output += missing[i];
            }
            out.println(output);
        }
    }

}

