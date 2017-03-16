package gcj2013.qual;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class FairAndSquare {
    private static String folder = "src/gcj2013/qual";
    private static String filename = "C-large-1";

    private static long[] fairSquares = new long[] { 1L, 4L, 9L, 121L, 484L,
            10201L, 12321L, 14641L, 40804L, 44944L, 1002001L, 1234321L,
            4008004L, 100020001L, 102030201L, 104060401L, 121242121L,
            123454321L, 125686521L, 400080004L, 404090404L, 10000200001L,
            10221412201L, 12102420121L, 12345654321L, 40000800004L,
            1000002000001L, 1002003002001L, 1004006004001L, 1020304030201L,
            1022325232201L, 1024348434201L, 1210024200121L, 1212225222121L,
            1214428244121L, 1232346432321L, 1234567654321L, 4000008000004L,
            4004009004004L };

    private static long countFairSquare(long a, long b) {
        int lower = 0;
        for (; lower < fairSquares.length; ++lower) {
            if (a <= fairSquares[lower]) {
                break;
            }
        }

        int higher = fairSquares.length - 1;
        for (; higher >= 0; --higher) {
            if (b >= fairSquares[higher]) {
                break;
            }
        }

        int numFairSquare = higher - lower + 1;
        
        return numFairSquare;
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
                long A = Long.parseLong(tokens[0]);
                long B = Long.parseLong(tokens[1]);
                long numFairSquare = countFairSquare(A, B);

                String result = String.format("Case #%d: %d",
                                              t + 1,
                                              numFairSquare);
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
