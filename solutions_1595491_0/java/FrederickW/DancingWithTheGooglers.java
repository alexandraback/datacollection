import java.io.*;

/**
 * Created with IntelliJ IDEA.
 * User: Frederick
 * Date: 4/14/12
 * Time: 8:36 AM
 * To change this template use File | Settings | File Templates.
 */
public class DancingWithTheGooglers {

    private static int solve(int number, int surprising, int p, int[] totalPoints) {
        int count = 0;
        for (int i = 0; i < number; i++) {
            int total = totalPoints[i];
            if (total >= p * 3) {
                count++;
                continue;
            }
            total -= p;
            if (total < 0) {
                continue;
            }
            int lower = total / 2;
            int higher = total - lower;
            int dif;
            if (lower > p) {
                dif = higher - p;
            } else {
                dif = p - lower;
            }
            if (dif < 2) {
                count++;
            } else if (surprising > 0 && dif == 2) {
                surprising--;
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) throws IOException {
        File input = new File("C:\\Users\\Frederick\\Downloads\\B-small-attempt0.in");
        File output = new File(input.getAbsolutePath() + ".out");
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(input)));
        PrintStream out = new PrintStream(output);
        int cases = Integer.parseInt(in.readLine());
        for (int i = 1; i <= cases; i++) {
            String[] s = in.readLine().split(" ");
            int number = Integer.parseInt(s[0]);
            int surprising = Integer.parseInt(s[1]);
            int p = Integer.parseInt(s[2]);
            int[] totalPoints = new int[number];
            for (int o = 0; o < number; o++) {
                 totalPoints[o] = Integer.parseInt(s[o + 3]);
            }
            int maximum = solve(number, surprising, p, totalPoints);
            String print = "Case #" + i + ": " + maximum;
            System.out.println(print);
            out.println(print);
        }
    }
}
