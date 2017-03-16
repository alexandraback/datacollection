import java.io.*;
import java.math.BigInteger;
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

        BigInteger p = new BigInteger(config[0]);
        BigInteger q = new BigInteger(config[1]);

        try {
            return String.valueOf(findSolution(p, q, 0));
        } catch (IllegalArgumentException e) {
            return "impossible";
        }

    }

    private static Integer findSolution(BigInteger p, BigInteger q, int d) {


        if (p.equals(q) || p.equals(BigInteger.ZERO)) {
            return 0;
        } else {

            if (d == 40) {
                throw new IllegalArgumentException();
            }

            BigInteger p2 = p.multiply(new BigInteger("2"));

            if (p2.compareTo(q) > 0) {

                if (findSolution(p2.subtract(q), q, d + 1) >= 0) {
                    return 1;
                } else {
                    throw new IllegalArgumentException();
                }

            } else {
                return findSolution(p2, q, d + 1) + 1;
            }

        }

    }

}
