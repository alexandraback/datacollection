package round1c;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by alemar on 11.05.2014.
 */
public class P1 {
    //private static final String inputFileName = "input/round1c/p1/test.in";
    private static final String inputFileName = "input/round1c/p1/A-small-attempt0.in";
    private static final String outputFileName = "answer.out";

    public static void main(String[] args) throws Exception {
        File inputFile = new File(inputFileName);
        Scanner scanner = new Scanner(inputFile);

        File outputFile = new File(outputFileName);
        outputFile.delete();
        outputFile.createNewFile();
        FileWriter fw = new FileWriter(outputFile);
        BufferedWriter bw = new BufferedWriter(fw);

        int numOfTestCases = scanner.nextInt();
        scanner.nextLine();

        for (int i = 1; i <= numOfTestCases; i++) {
            String[] s = scanner.nextLine().split("/");
            long p = Long.parseLong(s[0]);
            long q = Long.parseLong(s[1]);

            Problem1 problem = new Problem1();

            String testCase = "Case #" + i + ": " + problem.solve(p, q);
            bw.append(testCase + "\n");
            System.out.println(testCase);
        }

        bw.flush();
        fw.flush();

        bw.close();
        fw.close();
    }
}


class Problem1 {
    public String solve(long p, long q) {

        long gcd = gcd(p,q);

        p = p / gcd;
        q = q / gcd;

        if (Long.bitCount(q) == 1) {
            return String.valueOf(Long.toBinaryString(q).length() - Long.toBinaryString(p).length());
        }

        return "impossible";
    }

    public long gcd(long a, long b) {
        if (b == 0) return a;
        long x = (long)(a % b);
        return gcd(b, x);
    }
}