import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

/**
 * Created by Patrick on 12-4-14.
 */
public class DeceitfulWar {

    final static String INPUTFILE = "D:\\gcj\\2014\\DeceitfulWar\\D-large.in";

    static void docase(int casenumber) throws Exception {

        int blocksNumber = in.nextInt();

        ArrayList<ArrayList<Double>> blocks1 = new ArrayList<ArrayList<Double>>();
        ArrayList<ArrayList<Double>> blocks2 = new ArrayList<ArrayList<Double>>();

        for (int i = 0; i < 2; i++) {
            blocks1.add(new ArrayList<Double>());
            blocks2.add(new ArrayList<Double>());
            for (int j = 0; j < blocksNumber; j++) {
                double nextDouble = in.nextDouble();
                blocks1.get(i).add(nextDouble);
                blocks2.get(i).add(nextDouble);
            }
            Collections.sort(blocks1.get(i));
            Collections.sort(blocks2.get(i));
        }


        out.add(String.format("Case #%s: %s %s", casenumber, getDeceitfulWins(blocks2), getNormalWins(blocks1)));

    }

    static int getNormalWins(ArrayList<ArrayList<Double>> blocks) {
        int wins = 0;

        while (blocks.get(0).size() > 0) {

            // is our largest smaller than their largest?
            if (blocks.get(0).get(blocks.get(0).size() - 1) < blocks.get(1).get(blocks.get(1).size() - 1)) {
                // play our largest, take theirs that's slightly larger
                int theirsSlightlyLarger = 0;
                for (int i = 0; i < blocks.get(1).size(); i++) {
                    if (blocks.get(0).get(blocks.get(0).size() - 1) < blocks.get(1).get(i)) {
                        theirsSlightlyLarger = i;
                        break;
                    }
                }

                if (blocks.get(0).get(0) > blocks.get(1).get(theirsSlightlyLarger)) {
                    wins++;
                }

                blocks.get(0).remove(blocks.get(0).size() - 1);
                blocks.get(1).remove(theirsSlightlyLarger);
            }

            // is our largest larger than their largest?
            else {
                // play our smallest, take theirs that's slightly larger
                int theirsSlightlyLarger = 0;
                for (int i = 0; i < blocks.get(1).size(); i++) {
                    if (blocks.get(0).get(0) < blocks.get(1).get(i)) {
                        theirsSlightlyLarger = i;
                        break;
                    }
                }

                if (blocks.get(0).get(0) > blocks.get(1).get(theirsSlightlyLarger)) {
                    wins++;
                }

                blocks.get(0).remove(0);
                blocks.get(1).remove(theirsSlightlyLarger);
            }

        }

        return wins;
    }

    static int getDeceitfulWins(ArrayList<ArrayList<Double>> blocks) {
        int wins = 0;

        while (blocks.get(0).size() > 0) {

            // is our smallest smaller than their smallest? we're gonna lose this one anyway
            if (blocks.get(0).get(0) < blocks.get(1).get(0)) {
                // pretend to be their biggest - 0.000001, remove their biggest, remove our smallest
                blocks.get(0).remove(0);
                blocks.get(1).remove(blocks.get(1).size() - 1);
                continue;
            }

            // our smallest is bigger than their smallest, pretend to be their biggest + 0.000001
            // they will give up their smallest - we win!
            blocks.get(0).remove(0);
            blocks.get(1).remove(0);
            wins++;
        }
        return wins;
    }

    public static void main(String args[]) {
        try {

            int totalcases = in.nextInt();

            caseloop:
            for (int currentcase = 1; currentcase <= totalcases; currentcase++) {

                docase(currentcase);

            }

            out.write();

        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    static class In {
        BufferedReader br;
        String buffer = "";

        In() throws Exception {
            br = new BufferedReader(new FileReader(INPUTFILE));
        }

        String nextLine() throws Exception {
            buffer = "";
            return br.readLine();
        }

        String nextString() throws Exception {
            if (buffer.equals("")) {
                buffer = nextLine();
            }

            String line = buffer;

            if (line.contains(" ")) {
                int spacePos = line.indexOf(" ");
                buffer = line.substring(spacePos + 1, line.length());
                return line.substring(0, spacePos);
            } else {
                buffer = "";
                return line;
            }

        }

        int nextInt() throws Exception {
            return Integer.parseInt(nextString());
        }

        BigInteger nextBigInteger() throws Exception {
            return new BigInteger(nextString());
        }

        double nextDouble() throws Exception {
            return Double.parseDouble(nextString());
        }
    }

    static class Out {
        StringBuilder strBuilder = new StringBuilder();

        void add(Object str) {
            strBuilder.append(str.toString());
            strBuilder.append("\n");
            log(str);
        }

        void write() throws Exception {
            File file = new File(INPUTFILE.replace(".in", ".out"));
            if (file.exists()) {
                file.delete();
                file.createNewFile();
            }

            BufferedWriter bw = new BufferedWriter(new FileWriter(file.getAbsoluteFile()));
            bw.write(strBuilder.toString());
            bw.close();
        }
    }

    static In in;
    static Out out;
    static {
        try {
            in = new In();
            out = new Out();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }


    static void log(Object o) {
        System.out.println("" + o);
    }
}
