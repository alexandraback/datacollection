import java.io.*;
import java.util.*;

/**
 * @author OleGG
 */
public class QualTaskB {
    public static void main(String[] args) throws Throwable {
        StreamTokenizer st = new StreamTokenizer(new BufferedReader(new FileReader("B-large.in.txt")));
        PrintWriter pw = new PrintWriter(new FileWriter("B-large.out.txt"));
        //StreamTokenizer st = new StreamTokenizer(new InputStreamReader(System.in));
        st.nextToken();
        int t = (int)st.nval;

        for (int test = 1; test <= t; ++test) {
            st.nextToken();
            int n = (int)st.nval;
            st.nextToken();
            int s = (int)st.nval;
            st.nextToken();
            int p = (int)st.nval;

            int[] val = new int[n];
            for (int i = 0; i < n; ++i) {
                st.nextToken();
                val[i] = (int)st.nval;
            }

            int[][] dyn = new int[n + 1][s + 1];
            for (int i = 0; i <= n; ++i) {
                Arrays.fill(dyn[i], 0);
            }

            for (int i = 0; i < n; ++i) {
                dyn[i + 1][0] = dyn[i][0];
                if ((val[i] + 2) / 3 >= p) {
                     ++dyn[i + 1][0];
                }

                for (int j = 0; j < s; ++j) {
                    int add = (val[i] + 2) / 3 >= p ? 1 : 0;
                    int addS = Integer.MIN_VALUE;
                    if (val[i] >= 2 && val[i] <= 28) {
                        switch (val[i] % 3) {
                            case 0:
                            case 1:
                                addS = val[i] / 3 + 1 >= p ? 1 : 0;
                                break;
                            case 2:
                                addS = val[i] / 3 + 2 >= p ? 1 : 0;
                                break;
                        }
                    }
                    dyn[i + 1][j + 1] = Math.max(dyn[i][j+1] + add, dyn[i][j] + addS);
                }
            }
            pw.printf("Case #%d: %d\n", test, dyn[n][s]);
        }
        pw.close();
    }
}
