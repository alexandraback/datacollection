import java.io.*;
import java.util.Scanner;

/**
 * Created by burger on 5/4/14.
 */
public class B {
    public int solveSmall(int A, int B, int K) {
        int res = 0;
        for (int a = 0; a < A; a++)
            for (int b = 0; b < B; b++)
                if ((a & b) < K)
                    res++;
        return res;
    }

    public static void main(String[] args) {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("small.in");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("answer.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int A = in.nextInt();
            int B = in.nextInt();
            int K = in.nextInt();
            out.write("Case #" + t + ": " + new B().solveSmall(A, B, K) + "\n");
        }

        out.close();
    }

}
