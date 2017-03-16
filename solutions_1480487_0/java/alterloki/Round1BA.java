package jam.jam2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

/**
 * Created by IntelliJ IDEA.
 * User: ashevenkov
 * Date: 29.04.12
 * Time: 22:15
 */
public class Round1BA {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("input/A-small-attempt3.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("output/A-small-attempt3.out"));
        String line = br.readLine();
        int cases = Integer.parseInt(line);
        for (int i = 0; i < cases; i++) {
            line = br.readLine();
            String[] parts = line.split(" ");
            int n = Integer.parseInt(parts[0]);
            int[] s = new int[n];
            for (int j = 0; j < n; j++) {
                s[j] = Integer.parseInt(parts[j + 1]);
            }
            String result = calculate(s, n);
            System.out.println("Case #" + (i + 1) + ": " + result);
            bw.write("Case #" + (i + 1) + ": " + result);
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }

    private static String calculate(int[] s, int n) {
        StringBuilder sb = new StringBuilder();
        int sum = 0;
        for (int i : s) {
            sum += i;
        }
        double[] res = new double[n];
        calculate1(s, n, sum, res);
        for (int i = 0; i < s.length; i++) {
            double d = res[i];
            if (i > 0) {
                sb.append(" ");
            }
            sb.append(Double.toString(d));
        }
        return sb.toString();
    }

    private static void calculate1(int[] s, int n, int sum, double[] r) {
        int nn = 0;
        int nsum = 0;
        for (int i = 0; i < s.length; i++) {
            int s1 = s[i];
            if (s1 >= 0) {
                double k = 2 / (double) n;
                double d = (k - (double) s1 / (double) sum) * 100;
                if (d >= 0) {
                    r[i] = d;
                    nn++;
                    nsum += s1;
                } else {
                    s[i] = -1;
                    r[i] = 0;
                }
            }
        }
        if (nn < n) {
            calculate2(s, nn, sum, nsum, r);
        }
    }

    private static void calculate2(int[] s, int n, int sum, int nsum, double[] r) {
        int nn = 0;
        for (int i = 0; i < s.length; i++) {
            int s1 = s[i];
            if (s1 >= 0) {
                double k = (double)(nsum + sum) / (double) (n * sum);
                double d = (k - (double) s1 / (double) sum) * 100;
                if (d >= 0) {
                    r[i] = d;
                    nn++;
                } else {
                    s[i] = -1;
                    r[i] = 0;
                }
            }
        }
    }
}