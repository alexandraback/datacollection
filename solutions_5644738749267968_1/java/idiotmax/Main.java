import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        int roundCount = 0;

        BufferedReader br = null;
        BufferedWriter bw = null;
        try {
            br = new BufferedReader(new FileReader("D-large.in"));
            bw = new BufferedWriter(new FileWriter("D-large.out"));
            String line = br.readLine();

            roundCount = Integer.parseInt(line);
            for (int roundIndex = 0; roundIndex < roundCount; roundIndex++) {
                int items = Integer.parseInt(br.readLine());

                String[] roundInputs = new String[2];
                for (int i = 0; i < 2; i++) {
                    roundInputs[i] = br.readLine();
                }
                Round round = parseRound(items, roundInputs);
                if (round == null) {
                    break;
                }
                // println("%s", round);
                doCompute(round);

                bw.write(String.format("Case #%d: %d %d\n", roundIndex + 1, round.result1, round.result2));
                println(String.format("Case #%d: %d %d", roundIndex + 1, round.result1, round.result2));
            }

        } catch (IOException e) {
        } catch (NumberFormatException e) {
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (br != null) {
                try {
                    br.close();
                } catch (IOException e) {
                }
            }
            if (bw != null) {
                try {
                    bw.close();
                } catch (IOException e) {
                }
            }
        }

    }

    private static Round parseRound(int items, String[] args) {
        if (items < 1 || args == null || args.length != 2) {
            return null;
        }
        float[] row1 = new float[items];
        float[] row2 = new float[items];

        String[] a = args[0].split(" ");
        for (int i = 0; i < items; i++) {
            row1[i] = Float.parseFloat(a[i]);
        }
        a = args[1].split(" ");
        for (int i = 0; i < items; i++) {
            row2[i] = Float.parseFloat(a[i]);
        }

        return new Round(row1, row2);
    }

    private static final class Round {
        final float[] row1;

        final float[] row2;

        int result1 = 0;

        int result2 = 0;

        Round(float[] row1, float[] row2) {
            Arrays.sort(row1);
            Arrays.sort(row2);
            this.row1 = new float[row1.length];
            this.row2 = new float[row2.length];

            for (int i = 0; i < row1.length; i++) {
                this.row1[i] = row1[row1.length - i - 1];
            }
            for (int i = 0; i < row2.length; i++) {
                this.row2[i] = row2[row2.length - i - 1];
            }
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();

            sb.append("row1:");
            for (float i : row1) {
                sb.append(" ");
                sb.append(i);
            }
            sb.append("\n");

            sb.append("row2:");
            for (float i : row2) {
                sb.append(" ");
                sb.append(i);
            }
            sb.append("\n");

            return sb.toString();
        }

    }

    private static void doCompute(Round round) {

        int i = 0, j = 0;
        for (int size = round.row1.length; i < size; i++) {
            for (; j < size; j++) {

                if (round.row1[i] > round.row2[j]) {
                    // println("qqq: round.row1[i] [%f,%f] round.row2[j]",
                    // round.row1[i], round.row2[j]);
                    round.result1++;
                    j++;
                    break;
                }
            }
        }

        i = 0;
        j = 0;
        for (int size = round.row2.length; i < size; i++) {
            for (; j < size; j++) {
                if (round.row2[i] > round.row1[j]) {
                    // println("ccc: round.row2[i] [%f,%f] round.row1[j]",
                    // round.row2[i], round.row1[j]);
                    round.result2++;
                    j++;
                    break;
                }
            }
        }
        round.result2 = round.row2.length - round.result2;

        return;
    }

    private static void println(String format, Object... args) {
        System.out.println(String.format(format, args));
    }

}
