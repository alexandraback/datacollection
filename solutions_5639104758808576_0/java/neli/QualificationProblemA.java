import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 * Created by Darya Shauchenka on 4/11/2015.
 */
public class QualificationProblemA {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("A-small-attempt0.in"));
        BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
        int testCases = sc.nextInt();
        for (int t = 0; t < testCases; t++) {
            int res = 0;
            int sMax = sc.nextInt();
            String s = sc.next();
            int standing = s.charAt(0) - '0';
            for (int shyness = 1; shyness <= sMax; shyness++) {
                if (standing < shyness) {
                    res += shyness - standing;
                    standing += shyness - standing;
                }
                standing += s.charAt(shyness) - '0';
            }
            out.write("Case #" + (t + 1) + ": " + res);
            out.newLine();
        }
        out.close();
    }
}
