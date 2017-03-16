import java.io.*;
import java.util.Vector;

/**
 * Created by skortzy on 02/05/15.
 */
public class CodeJamR1APC {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("C-small-1-attempt1.in")));
        PrintWriter pw = new PrintWriter(new FileOutputStream("C.out"));
        String line = br.readLine();
        int T = Integer.parseInt(line);
        for (int i = 0; i < T; i++) {
            System.out.println("Case #" + (i + 1));

            line = br.readLine();
            int N = Integer.parseInt(line);
            Vector<Integer> positions = new Vector<>();
            Vector<Integer> speeds = new Vector<>();
            for (int j = 0; j < N; j++) {
                line = br.readLine();
                String tokens[] = line.split(" ");
                int position = Integer.parseInt(tokens[0]);
                int count = Integer.parseInt(tokens[1]);
                int speed = Integer.parseInt(tokens[2]);
                for (int k = 0; k < count; k++) {
                    positions.add(position);
                    speeds.add(speed + i);
                }
            }
            pw.println("Case #" + (i + 1) + ": " + solve(positions, speeds));

        }
        pw.close();

    }

    private static String solve(Vector<Integer> positions, Vector<Integer> speeds) {
        if (positions.size() < 2) {
            return "0";
        }
        int p1 = positions.get(0);
        int p2 = positions.get(1);
        int s1 = speeds.get(0);
        int s2 = speeds.get(1);


        double t1 = (360.0 - p1) / s1;
        double t2 = (360.0 - p2) / s2;

        double t11 = (720.0 - p1) / s1;
        double t12 = (720.0 - p2) / s2;

        //System.out.println(p1 + " "  +  s1 + " " + p2 + " " + s2 + " " + (int)(t1 * 1000000000) + " " + (int)(t2 * 1000000000) + " " + (int)(t11 * 1000000000) + " " + (int)(t12 * 1000000000));

        if ((t11 <= t2) || (t12 <= t1)) {
            return "1";
        } else {
            return "0";
        }




    }


}
