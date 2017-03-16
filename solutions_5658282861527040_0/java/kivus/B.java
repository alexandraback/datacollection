import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

/**
 * Created by Rafal on 4/12/14.
 */
public class B {

    public static void main(String[] args) {
        try {

            InputStream in = new FileInputStream("c:/projekty/codejam/src/B.in");
            Scanner scanner = new Scanner(in);
            OutputStream out = new FileOutputStream("c:/projekty/codejam/src/B.out");
            PrintWriter writer = new PrintWriter(new OutputStreamWriter(out, "utf8"));
            int t = scanner.nextInt();
            for (int i = 0; i < t; i++) {
                solve(scanner, i+1, writer);
            }
            writer.close();
        } catch (Exception e) {
            System.out.println("Error: " + e);
            e.printStackTrace();
        }
    }


    public static void solve(Scanner scanner, int t, PrintWriter out) {
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int k = scanner.nextInt();

        long result = 0;
        int c;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                c = i & j;
                if (c < k) {
                    result++;
                }
            }
        }
        String resultTxt = "" + result;
        System.out.println("Case #" + t + ": " + resultTxt);
        out.println("Case #" + t + ": " + resultTxt);
    }

}
