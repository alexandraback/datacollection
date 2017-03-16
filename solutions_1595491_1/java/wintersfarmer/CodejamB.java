import java.io.*;
import java.util.*;

class CodejamB {
    public static char[] map;
    public static void main (String [] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("E:/B-large.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("E:/outB.txt")));
        int nTest = Integer.parseInt(in.readLine());
        for (int testIndex = 0; testIndex < nTest; testIndex++) {
            out.print("Case #" + (testIndex + 1) + ": ");
            /***** start **********/
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());
            int[] data = new int[n];
            int remainingS = s;
            int result = 0;
            for (int i = 0; i < n; i++) {
                data[i] = Integer.parseInt(st.nextToken());
                if (data[i] >= p + 2 * Math.max(0, p - 1)) {
                    result++;
                } else if (data[i] >= p + 2 * Math.max(0, p - 2) && remainingS > 0) {
                    remainingS--;
                    result++;
                }
            }
            out.print(result);
            /***** end   **********/
            out.println();
        }
        out.close();
    }
}