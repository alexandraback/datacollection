import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

/**
 * Created by burger on 4/13/14.
 */
public class DeceitfulWar {

    public static void main(String[] args) {
        Scanner sc = null;
        try {
            sc = new Scanner(new File("small.in"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        try {
            PrintWriter writer = new PrintWriter("answer.out", "UTF-8");

            int T = sc.nextInt();
            for (int t = 1; t <= T; t++) {
                int N = sc.nextInt();

                double[] blockN = new double[N];
                for (int i = 0; i < N; i++)
                    blockN[i] = sc.nextDouble();

                double[] blockK = new double[N];
                for (int i = 0; i < N; i++)
                    blockK[i] = sc.nextDouble();

                Arrays.sort(blockN);
                Arrays.sort(blockK);

                writer.write("Case #" + t + ": "
                        + new DeceitfulWar().solveDeceitfulWar(blockN, blockK) + " "
                        + new DeceitfulWar().solveWar(blockN, blockK) + "\n");
            }
            writer.close();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
    }

    private int solveDeceitfulWar(double[] blockN, double[] blockK) {
        int N = blockN.length;

        ArrayList<Double> nk = new ArrayList<Double>();
        for (double mass : blockK) {
            nk.add(mass);
        }

        int win = 0;
        for (int i = 0; i < N; i++) {
            if (blockN[i] > nk.get(0)) {
                nk.remove(0);
                win++;
            } else {
                nk.remove(nk.size() - 1);
            }
        }

        return win;
    }

    private int solveWar(double[] blockN, double[] blockK) {
        int N = blockN.length;
        ArrayList<Double> nk = new ArrayList<Double>();
        for (double mass : blockK) {
            nk.add(mass);
        }

        int win = 0;
        for (int i = 0; i < N; i++) {
            int index = -Collections.binarySearch(nk, blockN[i]);
            if (index == nk.size() + 1) {
                nk.remove(0);
                win++;
            } else {
                nk.remove(index - 1);
            }
        }

        return win;
    }
}
