import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.Console;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Main {

    public static void main(String[] args) {
        Console console = System.console();
        int count = 0;

        BufferedReader br = null;
        BufferedWriter bw = null;
        try {
            br = new BufferedReader(new FileReader("B-large.in"));
            bw = new BufferedWriter(new FileWriter("B-large.out"));
            String line = br.readLine();

            count = Integer.parseInt(line);
            for (int i = 0; i < count; i++) {
                line = br.readLine();
                Round round = parseRound(line);
                if (round == null) {
                    break;
                }
                double time = doCompute(round);
                bw.write(String.format("Case #%d: %.7f\n", i + 1, time));
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

    private static Round parseRound(String line) {
        String[] args = line.split(" ", 3);
        if (args == null || args.length != 3) {
            return null;
        }
        double argC = Double.parseDouble(args[0]);
        double argF = Double.parseDouble(args[1]);
        double argX = Double.parseDouble(args[2]);
        return new Round(argC, argF, argX);
    }

    private static final class Round {
        final double c;

        final double f;

        final double x;

        Round(double c, double f, double x) {
            this.c = c;
            this.f = f;
            this.x = x;
        }
    }

    private static double doCompute(Round round) {
        int farms = 0;
        double resultTime = 0;

        do {
            double production = (farms * round.f) + 2;
            double nextTime = round.c / production + round.x / (production + round.f);
            double lastingTime = round.x / production;

            if (lastingTime < nextTime) {
                resultTime += lastingTime;
                break;
            } else {
                resultTime += getTime(farms, round.c, round.f);
                farms++;
            }

        } while (true);

        return resultTime;
    }

    private static double getTime(int farms, double c, double f) {
        return c / (2.0 + farms * f);
    }

    private static void println(String format, Object... args) {
        System.out.println(String.format(format, args));
    }

}
