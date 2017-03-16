import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));

        int T = sc.nextInt();

        for (int casenumber = 1; casenumber <= T; ++casenumber) {

            int N = sc.nextInt();
            int[] s = new int[N];
            int[] s2 = new int[N];
            for (int i = 0; i < N; ++i) {
                s[i] = sc.nextInt();
                s2[i] = s[i];
            }

            Arrays.sort(s2);
            int[] ss = new int[N + 1];
            ss[0] = 0;
            for (int i = 0; i < N; ++i) {
                ss[i + 1] = ss[i] + s2[i];
            }

            int x = ss[N];

            int j = 1;
            while (j < N) {
                if (s2[j] * j - ss[j] >= x) break;
                ++j;
            }

            double thresh = (ss[j] + x) / (double) j;

            double[] m = new double[N];
            for (int i = 0; i < N; ++i) {
                if (s[i] > thresh) {
                    m[i] = 0;
                } else {
                    m[i] = 100.0 * (thresh - s[i]) / (double) x;
                }
            }

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < N; ++i) {
                sb.append(' ');
                sb.append(m[i]);
            }


            System.out.format("Case #%d: %s%n", casenumber, sb.toString());
        }
    }
}
