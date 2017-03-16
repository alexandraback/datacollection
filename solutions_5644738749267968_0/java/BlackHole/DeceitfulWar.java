package Qualification.D;
import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.math.*;
/**
 * Created by mtian on 4/12/14.
 */
public class DeceitfulWar {
    public int war(double[] Naomi, double[] Ken) {
        int i = 0;
        int j = 0;
        int N = Naomi.length;
        while (i < N && j < N) {
            if (Naomi[i] < Ken[j]) {
                i += 1;
                j += 1;
            } else {
                while (j < N && Naomi[i] > Ken[j]) {
                    j += 1;
                }
            }
        }
        return N - i;
    }


    public void solve(ContestReader cr, PrintWriter pw) throws Exception {
        int N = cr.nextInt();
        double[] Naomi = new double[N];
        double[] Ken = new double[N];
        for (int i = 0; i < N; i++) {
            Naomi[i] = cr.nextDouble();
        }
        for (int i = 0; i < N; i++) {
            Ken[i] = cr.nextDouble();
        }
        Arrays.sort(Naomi);
        Arrays.sort(Ken);

        int y = N - war(Ken, Naomi);

        int z = war(Naomi, Ken);

        pw.println(Integer.toString(y) + " " + Integer.toString(z));
    }

    public static void main(String[] args) throws Exception {
        ContestReader cr = new ContestReader(new FileInputStream("D-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("D-small-attempt0.out"));
        DeceitfulWar solver = new DeceitfulWar();
        int T = cr.nextInt();
        for (int caseNum = 1; caseNum <= T; caseNum++) {
            System.out.println("Processing test case " + caseNum);
            pw.print("Case #" + caseNum + ": ");
            solver.solve(cr, pw);
        }
        pw.flush();
        pw.close();
    }
}

class ContestReader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    public ContestReader(InputStream input) {
        reader = new BufferedReader(new InputStreamReader(input));
        tokenizer = new StringTokenizer("");
    }

    public String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}
