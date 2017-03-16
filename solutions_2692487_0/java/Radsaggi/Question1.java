package CodeJam.codejam2013.round1b;

/**
 * Round 1 2013 Problem A. Osmos
 *
 * @author ashutosh
 */
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Question1 {

    private static BufferedReader br;
    private static PrintWriter pw;
    private static int a, n, m[];

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new FileReader("in.txt"));
        pw = new PrintWriter("out.txt");

        int t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; i++) {
            input();
            pw.printf("Case #%d: ", i);
            pw.println(work());
        }

        pw.close();
    }

    private static void input() throws IOException {
        StringTokenizer data = new StringTokenizer(br.readLine());

        a = Integer.parseInt(data.nextToken());
        n = Integer.parseInt(data.nextToken());

        data = new StringTokenizer(br.readLine());
        int idx, v;
        m = new int[n];
        Arrays.fill(m, Integer.MAX_VALUE);
        for (int i = 0; i < n; i++) {
            idx = 0;
            v = Integer.parseInt(data.nextToken());
            for (int j = 0; j < n; j++) {
                if (m[j] >= v) {
                    idx = j;
                    break;
                }
            }
            for (int j = i; j > idx; j--) {
                m[j] = m[j - 1];
            }
            m[idx] = v;
        }
        //System.out.println(Arrays.toString(m));
    }

    private static int work() {
        if (a == 1) {
            return n;
        }

        int count = 0;

        int size = a;
        for (int i = 0; i < n; i++) {
            if (m[i] < size) {
                size += m[i];
            } else if (m[i] < size * 2 - 1) {
                count++;
                size += size - 1 + m[i];
            } else {
                int nm = n - i;
                int size2 = size;
                int i2 = i;
                int count2 = 0;
                while (i2 < n) {
                    if (count2 >= nm) {
                        break;
                    }
                    if (size2 > m[i2]) {
                        size2 += m[i2];
                        i2++;
                    } else {
                        size2 += size2 - 1;
                        count2++;
                    }
                }
                if (count2 >= nm) {
                    return nm + count;
                } else {
                    return count + count2;
                }
            }
        }


        return count;
    }

    private static int work2(int size, int i) {
        int count = 0;
        if (m[i] < size) {
            return work2(size + m[i], i + 1);
        } else if (m[i] < size * 2 - 1) {
            return work2(size + size - 1 + m[i], i + 1) + 1;
        } else {
        }

        return count;
    }
}
