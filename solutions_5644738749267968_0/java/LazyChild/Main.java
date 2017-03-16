import java.util.Scanner;
import java.io.IOException;
import java.util.Arrays;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        double[] naomis = IOUtils.readDoubleArray(in, n);
        double[] kens = IOUtils.readDoubleArray(in, n);

        out.printf("Case #%d: %d %d\n", testNumber, deceitfulWar(naomis, kens), war(naomis, kens));
    }

    private int war(double[] naomis, double[] kens) {
        boolean[] chosen = new boolean[kens.length];
        Arrays.fill(chosen, false);
        int score = 0;
        for (double naomi : naomis) {
            int which = -1;
            for (int i = 0; i < kens.length; ++i) {
                if (!chosen[i] && kens[i] > naomi && (which == -1 || kens[i] < kens[which])) {
                    which = i;
                }
            }
            if (which != -1) {
                chosen[which] = true;
            } else {
                ++score;

                for (int i = 0; i < kens.length; ++i) {
                    if (!chosen[i] && (which == -1 || kens[i] < kens[which])) {
                        which = i;
                    }
                }
                chosen[which] = true;
            }
        }
        return score;
    }

    private int deceitfulWar(double[] naomis, double[] kens) {
        Arrays.sort(naomis);
        boolean[] chosen = new boolean[kens.length];
        Arrays.fill(chosen, false);
        int score = 0;
        for (double naomi : naomis) {
            int which = -1;
            for (int i = 0; i < kens.length; ++i) {
                if (!chosen[i] && (which == -1 || kens[i] < kens[which])) {
                    which = i;
                }
            }
            if (kens[which] < naomi) {
                ++score;
                chosen[which] = true;
            } else {
                which = -1;
                for (int i = 0; i < kens.length; ++i) {
                    if (!chosen[i] && (which == -1 || kens[i] > kens[which])) {
                        which = i;
                    }
                }
                chosen[which] = true;
            }
        }
//        0.389 0.907 0.832 0.959 0.557 0.300 0.899
//        0.728 0.271 0.520 0.700 0.521 0.341 0.458
        return score;
    }
}

class IOUtils {

    public static double[] readDoubleArray(Scanner in, int size) {
        double[] array = new double[size];
        for (int i = 0; i < size; i++) {
            array[i] = Double.parseDouble(in.next());
        }
        return array;
    }
}

