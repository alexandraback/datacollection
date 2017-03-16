package codejam.one;

import java.text.DecimalFormat;

/**
 * Created with IntelliJ IDEA.
 * User: ofer
 * Date: 4/28/12
 * Time: 3:49 AM
 * To change this template use File | Settings | File Templates.
 */
public class OneTest {

    private final static String newline = System.getProperty("line.separator");
    protected StringBuilder output = new StringBuilder();

    public String getOutput(int testNum) {
        return "Case #" + testNum + ": " + output.toString() + newline;
    }

    double strategy1(int guessed, int total, double[] p) {
        int left = total - guessed + 1;

        // chance i haven't made a mistake
        double chance = 1;
        for (int i = 0; i < guessed; i++) {
            chance *= p[i];
        }

        double chance2 = 1 - chance;

        return left * chance + (left + total + 1) * chance2;

    }

    double strategy2(int guessed, int total, double[] p) {
        double min = Double.MAX_VALUE;
        // backspaces
        for (int i = 1; i < guessed; i++) {
            double chance = 1;
            for (int j = 0; j < guessed - i; j++) {
                chance *= p[j];
            }
            int keys = i + (total - guessed + i) + 1;
            min = Math.min(min, chance * keys + (1-chance) * (keys + total + 1));
        }
        return min;
    }

    double strategy3(int guessed, int total, double[] p) {
        return 1 + total + 1;
    }

    public void run(String[] strings) {

        String[] vals = strings[0].split("\\s");
        int guessed = Integer.parseInt(vals[0]);
        int total = Integer.parseInt(vals[1]);

        String[] val2 = strings[1].split("\\s");

        double[] p = new double[val2.length];
        for (int i = 0; i < val2.length; i++) {
            p[i] = Double.parseDouble(val2[i]);
        }

        double best = strategy1(guessed,total,p);
        best = Math.min(strategy2(guessed, total, p), best);
        best = Math.min(strategy3(guessed, total, p), best);
        DecimalFormat df = new DecimalFormat();
        df.setMinimumFractionDigits(6);
        df.setMaximumFractionDigits(6);
        output.append(df.format(best));
    }
}
