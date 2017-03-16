import java.io.*;

/**
 * Created with IntelliJ IDEA.
 * User: Frederick
 * Date: 4/28/12
 * Time: 7:43 AM
 * To change this template use File | Settings | File Templates.
 */
public class PasswordProblem {

    private static double solve(int typed, int length, double[] probabilities) {
        int i = (int) Math.pow(2, typed);
        int j = typed + 2;
        double min = Double.MAX_VALUE;
        for (int o = 0; o < j - 1; o++) {
            double average = 0.0;
            for (int n = 0; n < i; n++) {
                boolean retype = false;
                double probability = 1;
                for (int l = 0; l < typed; l++) {
                    boolean wrong = ((n >>> l) & 1) == 1;
                    if (!wrong) {
                        probability *= probabilities[l];
                    } else {
                        probability *= 1 - probabilities[l];
                        if (l < typed - o) {
                            retype = true;
                        }
                    }
                }
                int keystrokes = o + o + length - typed + 1;
                if (retype) {
                    keystrokes += length + 1;
                }

                average += keystrokes * probability;
            }

            if (average < min) {
                min = average;
            }
        }

        if (length + 2 < min) {
             min = length + 2;
        }

        return min;
    }

    public static void main(String[] args) throws IOException {
        File input = new File("C:\\Users\\Frederick\\Downloads\\A-small-attempt0 (1).in");
        File output = new File(input.getAbsolutePath() + ".out");
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(input)));
        PrintStream out = new PrintStream(output);
        int cases = Integer.parseInt(in.readLine());
        for (int i = 1; i <= cases; i++) {
            String[] s = in.readLine().split(" ");
            int typed = Integer.parseInt(s[0]);
            int length = Integer.parseInt(s[1]);
            double[] probabilities = new double[typed];


            String[] s2 = in.readLine().split(" ");
            for (int o = 0; o < typed; o++) {
                probabilities[o] = Double.parseDouble(s2[o]);
            }

            double solution = solve(typed, length, probabilities);
            String print = "Case #" + i + ": " + solution;
            System.out.println(print);
            out.println(print);
        }
    }

}
