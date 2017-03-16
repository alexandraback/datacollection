import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: Neptun
 * Date: 4/27/13
 * Time: 3:57 AM
 * To change this template use File | Settings | File Templates.
 */
public class Round {

    PrintWriter logger;
    PrintWriter output;
    int caseNumber;
    String rS;
    String tS;
    //int r;
    //int t;
    BigInteger r;
    BigInteger t;

    Round() throws IOException {

        logger = new PrintWriter(new FileWriter("log"));
        output = new PrintWriter(new FileWriter("output"));
    }

    void closeFiles() throws IOException {

        output.close();
        logger.close();
    }

    public static BigInteger bigIntSqRootFloor(BigInteger x)
            throws IllegalArgumentException {
        if (x.compareTo(BigInteger.ZERO) < 0) {
            throw new IllegalArgumentException("Negative argument.");
        }
        // square roots of 0 and 1 are trivial and
        // y == 0 will cause a divide-by-zero exception
        if (x == BigInteger.ZERO || x == BigInteger.ONE) {
            return x;
        } // end if
        BigInteger two = BigInteger.valueOf(2L);
        BigInteger y;
        // starting with y = x / 2 avoids magnitude issues with x squared
        for (y = x.divide(two);
             y.compareTo(x.divide(y)) > 0;
             y = ((x.divide(y)).add(y)).divide(two));
        return y;
    } // end bigIntSqRootFloor

    void readInputs() throws FileNotFoundException {

        File input = new File("input");
        Scanner scanner = new Scanner(input);

        caseNumber = scanner.nextInt();
        logger.println(caseNumber);

        for(int c=1; c<= caseNumber; c++) {

            rS = scanner.next();
            tS = scanner.next();

            //r = scanner.nextInt();
            //t = scanner.nextInt();
            logger.println(rS+" "+tS);
            r = new BigInteger(rS);
            t = new BigInteger(tS);

            BigInteger n;

            BigInteger dis = r.pow(2).multiply(new BigInteger("4")).
                    add(new BigInteger("1")).
                    subtract(r.multiply(new BigInteger("4"))).
                    add(t.multiply(new BigInteger("8")));

            BigInteger sqrtDis = bigIntSqRootFloor(dis);

            BigInteger negativeB = new BigInteger("1").
                    subtract(r.multiply(new BigInteger("2")));

            // eklemek lazimsa
            if(negativeB.add(sqrtDis).compareTo(new BigInteger("0")) == 1) {

                n = negativeB.add(sqrtDis).divide(new BigInteger("4"));
            }
            else {

                n = negativeB.subtract(sqrtDis).divide(new BigInteger("4"));
            }

            output.println("Case #" + c + ": " + n);
        }
    }

    public static void main(String[] args) throws IOException {

        Round r = new Round();

        r.readInputs();

        r.closeFiles();
    }

}
