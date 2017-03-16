
import java.io.*;
import java.util.*;

/**
 *
 * @author Hilos
 */
public class ProblemC {

    public static BufferedWriter bw;
    public static BufferedReader br;

    public static void main(String[] args) {
        try {
            String filename = "C-small-attempt0";
            br = new BufferedReader(new FileReader("E:\\Downloads\\" + filename + ".in"));
            bw = new BufferedWriter(new FileWriter("E:\\Downloads\\" + filename + ".out"));

            int caseCount = Integer.parseInt(br.readLine());

            for (int c = 0; c < caseCount; c++) {
                String[] lineParts = br.readLine().split(" ");

                int A = Integer.parseInt(lineParts[0]);
                int B = Integer.parseInt(lineParts[1]);


                SolveCase(c + 1, A, B);
            }


        } catch (Exception exc) {
            System.out.println(exc.toString());
        }
    }

    public static void SolveCase(int caseNumber, int A, int B) throws Exception {
        int totalRecycledPairs = 0;

        HashSet uniqueNumbers = new HashSet();
        for (int i = A; i <= B; i++) {
            String strVal = String.valueOf(i);

            if (!uniqueNumbers.contains(i)) {

                int recycles = 0;
                String nextStr = strVal;

                do {
                    nextStr = leftShift(nextStr);
                    int nextInt = Integer.parseInt(nextStr);
                    if (A <= nextInt && nextInt <= B) {
                        uniqueNumbers.add(nextInt);
                        recycles++;
                    }
                } while (!nextStr.equals(strVal));

                totalRecycledPairs += NchooseK(recycles, 2);
            }
        }

        bw.write("Case #" + caseNumber + ": " + totalRecycledPairs + "\n");
        bw.flush();
    }

    public static String leftShift(String str) {
        return str.substring(1) + str.charAt(0);
    }

    public static int NchooseK(int n, int k) {
        return factorial(n) / (factorial(k) * factorial(n - k));
    }

    public static int factorial(int i) {
        int result = 1;
        while (i > 1) {
            result *= i;
            i--;
        }
        return result;
    }
}
