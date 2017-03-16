import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Pogo {
    static BigInteger TWO = BigInteger.valueOf(2l);
    static BigInteger FOUR = BigInteger.valueOf(4l);

    public static void main(String[] args) throws IOException {
        // Input and output files
        File inputFile = new File(args[0]);
        File outputFile = new File(inputFile.getAbsolutePath() + ".output");
        if (outputFile.exists()) {
            System.out.println("Warning, output file already exists. Deleting");
            outputFile.delete();
        }
        outputFile.createNewFile();
        PrintWriter writer = new PrintWriter(outputFile);
        Scanner s = new Scanner(inputFile);

        int testCases = s.nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            BigInteger x = s.nextBigInteger();
            BigInteger y = s.nextBigInteger();
            BigInteger total = x.abs().add(y.abs());
            // Number of jumps we need
            BigInteger root = bigIntegerSquareRootFloor(total.multiply(FOUR).add(BigInteger.ONE)).subtract(BigInteger.ONE);
            StringBuffer output = new StringBuffer();
            while (root.compareTo(BigInteger.ZERO) != 0) {
                if (x.abs().compareTo(y.abs()) >= 0) {
                    if (x.compareTo(BigInteger.ZERO) > 0) {
                        x = x.subtract(root);
                        output.insert(0, "E");
                    } else {
                        x = x.add(root);
                        output.insert(0, "W");
                    }
                } else {
                    if (y.compareTo(BigInteger.ZERO) > 0) {
                        y = y.subtract(root);
                        output.insert(0, "N");
                    } else {
                        y = y.add(root);
                        output.insert(0, "S");
                    }
                }
                root = root.subtract(BigInteger.ONE);
            }
            
            

            if(x.compareTo(BigInteger.ZERO) > 0) {
                //Should only be off by 1 max
                output.append("EW");
            } else if (x.compareTo(BigInteger.ZERO) < 0){
                //Should only be off by 1 max
                output.append("WE");
            }
            if(y.compareTo(BigInteger.ZERO) > 0) {
                //Should only be off by 1 max
                output.append("NS");
            } else if (y.compareTo(BigInteger.ZERO) < 0){
                //Should only be off by 1 max
                output.append("SN");
            }
            writer.println("Case #" + testCase + ": " + output.toString());
        }
        writer.close();
    }

    // See Example at Newtons Rule http://stackoverflow.com/questions/4407839/how-can-i-find-the-square-root-of-a-java-biginteger
    public static BigInteger bigIntegerSquareRootFloor(BigInteger bigInt) {
        if (bigInt == BigInteger.ZERO || bigInt == BigInteger.ONE) {
            return bigInt;
        }
        BigInteger guess;
        // starting with y = x / 2 avoids magnitude issues with x squared
        for (guess = bigInt.divide(TWO); guess.compareTo(bigInt.divide(guess)) > 0; guess = ((bigInt.divide(guess)).add(guess)).divide(TWO))
            ;
        return guess;
    } // end bigIntSqRootFloor
}
