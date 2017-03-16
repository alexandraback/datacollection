import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 * Created by Darya Shauchenka on 4/11/2015.
 */
public class QualificationProblemB {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("B-large.in"));
        BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
        int testCases = sc.nextInt();
        for (int t = 0; t < testCases; t++) {
            int res = 1000;
            int d = sc.nextInt();
            int[] plates = new int[1001];
            int pancakesMax = 0;
            for (int i = 0; i < d; i++) {
                int pancakesNum = sc.nextInt();
                plates[pancakesNum]++;
                pancakesMax = Math.max(pancakesMax, pancakesNum);
            }

            for (int i = pancakesMax; i > 0; i--) {
                int processingTime = i;
                for (int j = pancakesMax; j > i; j--) {
                    processingTime += plates[j] * (Math.ceil(1.0 * j / i) - 1);
                }
                res = Math.min(res, processingTime);
            }
            out.write("Case #" + (t + 1) + ": " + res);
            out.newLine();
        }
        out.close();
    }
}
