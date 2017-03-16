package mp.kotter.challenges.gcj.round1c;

import mp.kotter.challenges.utils.LineCaseSolution;

public class Pogo extends LineCaseSolution {

    public static void main(final String[] args) throws Exception {
        (new Pogo()).run(args);
    }

    @Override
    protected String solveLine(final String line) {
        final String[] splitted = line.split(" ");
        int x = Integer.parseInt(splitted[0]);
        int y = Integer.parseInt(splitted[1]);
        final StringBuilder result = new StringBuilder();

        while(x > 0) {
            result.append("WE");
            x--;
        }

        while(x < 0) {
            result.append("EW");
            x++;
        }

        while(y > 0) {
            result.append("SN");
            y--;
        }

        while(y < 0) {
            result.append("NS");
            y++;
        }

        return result.toString();
    }
}
