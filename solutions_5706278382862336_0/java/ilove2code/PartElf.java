import java.io.*;
import java.util.HashMap;
import java.util.HashSet;

/**
 * @author vilmantas baranauskas
 */
public class PartElf {


    public static void main(String[] args) throws IOException {

        BufferedReader in = new BufferedReader(new FileReader("in.txt"));
        BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));

        // number of test cases
        int t = Integer.parseInt(in.readLine());

        for (int i = 0; i < t; i++) {
            CharSequence solution = "Case #" + (i + 1) + ": " + solveTestCase(in);
            System.out.println(solution);
            out.write(solution.toString());
            out.newLine();
        }

        in.close();
        out.close();

    }

    private static String solveTestCase(BufferedReader in) throws IOException {

        String line = in.readLine();

        String[] config = line.split("/");

        int p = Integer.parseInt(config[0]);
        int q = Integer.parseInt(config[1]);

        HashMap<String, Integer> cache = new HashMap<String, Integer>();


        try {
            return String.valueOf(findSolution(p, q, cache, 0));
        } catch (IllegalArgumentException e) {
            return "impossible";
        }

    }

    private static Integer findSolution(int p, int q, HashMap<String, Integer> cache, int d) {

        String key = p + "/" + q;

        Integer cachedValue = cache.get(key);
        if (cachedValue != null) {
            return cachedValue;
        }

        if (p == q || p == 0) {
            return 0;
        } else {

            if (d == 40) {
                throw new IllegalArgumentException();
            }

            int p2 = p * 2;

            if (p2 > q) {

                if (findSolution(p2 - q, q, cache, d + 1) >= 0) {
                    return 1;
                } else {
                    throw new IllegalArgumentException();
                }

            } else {
                return findSolution(p2, q, cache, d + 1) + 1;
            }

        }

    }

}
