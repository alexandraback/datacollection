import java.io.*;
import java.math.BigInteger;
import java.util.Locale;

/**
 * Created by Patrick on 12-4-14.
 */
public class CookieClickerAlpha {

    final static String INPUTFILE = "D:\\gcj\\2014\\cookieclickeralpha\\B-large.in";

    static void docase(int casenumber) throws Exception {

        double cost = Double.parseDouble(in.nextString());
        double farmgain = Double.parseDouble(in.nextString());
        double goal = Double.parseDouble(in.nextString());

        double ps = 2.0;
        double cookies = 0.0;
        double time = 0.0;

        while (true) {

            double method1 = getTime(cookies, ps, goal);

            double duration = (cost - cookies) / ps;
            double method2 = duration + getTime(cookies + duration * ps - cost, ps + farmgain, goal);

            if (method1 < method2) {
                out.add("Case #" + casenumber + ": " + String.format(Locale.US, "%.7f", (time + method1)));
                break;
            }

            cookies += duration * ps - cost;
            ps += farmgain;
            time += duration;
        }


    }

    static double getTime(double current, double ps, double goal) {
        return (goal - current) / ps;
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
