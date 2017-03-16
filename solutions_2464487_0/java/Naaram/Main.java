import com.google.common.base.Splitter;

import java.io.*;
import java.math.BigInteger;
import java.util.Iterator;
import java.util.TreeSet;

public class Main {
    private static final String TEST_INPUT = "5\n" +
            "1 9\n" +
            "1 10\n" +
            "3 40\n" +
            "1 1000000000000000000\n" +
            "10000000000000000 1000000000000000000\n";

    public static final BigInteger FOUR = BigInteger.valueOf(4);
    public static final BigInteger FIVE_HUNDRED = BigInteger.valueOf(500);
    public static final BigInteger THOUSAND = BigInteger.valueOf(1000);
    public static final BigInteger FIVE_HUNDRED_THOUSAND = BigInteger.valueOf(500000);
    public static final BigInteger MILLION = BigInteger.valueOf(1000000);

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new FileReader("c:\\comp\\small.in"));
        //BufferedReader bufferedReader = new BufferedReader(new StringReader(TEST_INPUT));
        final PrintStream outStream = new PrintStream(new FileOutputStream("c:\\comp\\small.out"));
        int numCases = Integer.valueOf(bufferedReader.readLine());

        for(int i = 1; i <= numCases; i++) {
            String line = bufferedReader.readLine();
            Iterator<String> lineTokens = Splitter.on(" ").split(line).iterator();
            BigInteger radius = new BigInteger(lineTokens.next());
            BigInteger amountPaint = new BigInteger(lineTokens.next());

            BigInteger paintNeededForCircle = BigInteger.ZERO;
            paintNeededForCircle = paintNeededForCircle.subtract(radius.multiply(radius));
            radius = radius.add(BigInteger.ONE);
            paintNeededForCircle = paintNeededForCircle.add(radius.multiply(radius));

            BigInteger numCircles = BigInteger.ZERO.subtract(BigInteger.ONE);
            while(amountPaint.compareTo(BigInteger.ZERO) >= 0) {
                BigInteger paintForMillion = paintNeededForCircle.multiply(FIVE_HUNDRED_THOUSAND).add(FOUR.multiply(MILLION.subtract(BigInteger.ONE)).add(paintNeededForCircle).multiply(FIVE_HUNDRED_THOUSAND));
                if(amountPaint.compareTo(paintForMillion) > 0) {
                    numCircles = numCircles.add(MILLION);
                    amountPaint = amountPaint.subtract(paintForMillion);
                    paintNeededForCircle = paintNeededForCircle.add(FOUR.multiply(MILLION));
                } else {
                    BigInteger paintForThousand = paintNeededForCircle.multiply(FIVE_HUNDRED).add(FOUR.multiply(THOUSAND.subtract(BigInteger.ONE)).add(paintNeededForCircle).multiply(FIVE_HUNDRED));
                    if(amountPaint.compareTo(paintForThousand) > 0) {
                        numCircles = numCircles.add(THOUSAND);
                        amountPaint = amountPaint.subtract(paintForThousand);
                        paintNeededForCircle = paintNeededForCircle.add(FOUR.multiply(THOUSAND));
                    } else {
                        numCircles = numCircles.add(BigInteger.ONE);
                        amountPaint = amountPaint.subtract(paintNeededForCircle);
                        paintNeededForCircle = paintNeededForCircle.add(FOUR);
                    }
                }
            }

            System.out.println("Case #" + i + ": " + numCircles);
            outStream.println("Case #" + i + ": " + numCircles);
        }
    }
}
