package gcj2013.qual;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Lawnmower {
    private static String folder = "src/gcj2013/qual";
    private static String filename = "B-small-attempt0";

    private static boolean isLawnFeasible(int[][] lawn) {
        int N = lawn.length;
        int M = lawn[0].length;
        int[] rowMaxArray = new int[N];
        int[] colMaxArray = new int[M];
        for (int i = 0; i < N; ++i) {
            int rowMax = 0;
            for (int j = 0; j < M; ++j) {
                if (rowMax < lawn[i][j]) {
                    rowMax = lawn[i][j];
                }
            }
            rowMaxArray[i] = rowMax;
        }
        for (int j = 0; j < M; ++j) {
            int colMax = 0;
            for (int i = 0; i < N; ++i) {
                if (colMax < lawn[i][j]) {
                    colMax = lawn[i][j];
                }
            }
            colMaxArray[j] = colMax;
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (lawn[i][j] < rowMaxArray[i] && lawn[i][j] < colMaxArray[j]) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {
        try {
            File inputFile = new File(folder, filename + ".in");
            File outputFile = new File(folder, filename + ".out");
            BufferedReader reader = new BufferedReader(new FileReader(inputFile));
            PrintWriter pw = new PrintWriter(outputFile);
            int numTestCases = Integer.parseInt(reader.readLine());
            for (int t = 0; t < numTestCases; ++t) {
                String[] tokens = reader.readLine().trim().split(" ");
                int N = Integer.parseInt(tokens[0]);
                int M = Integer.parseInt(tokens[1]);
                int[][] lawn = new int[N][M];
                for (int i = 0; i < N; ++i) {
                    tokens = reader.readLine().trim().split(" ");
                    for (int j = 0; j < M; ++j) {
                        lawn[i][j] = Integer.parseInt(tokens[j]);
                    }
                }

                boolean isFeas = isLawnFeasible(lawn);

                String result = String.format("Case #%d: %s", t + 1, isFeas ? "YES" : "NO");
                System.out.println(result);
                pw.println(result);
            }
            reader.close();
            pw.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (NumberFormatException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
