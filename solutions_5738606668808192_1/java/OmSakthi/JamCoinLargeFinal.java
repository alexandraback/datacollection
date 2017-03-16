/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jamcoin;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.StringTokenizer;

/**
 *
 * @author user
 */
public class JamCoin {

    public static BigInteger sqrt(BigInteger x) {
        BigInteger div = BigInteger.ZERO.setBit(x.bitLength() / 2);
        BigInteger div2 = div;
        // Loop until we hit the same value twice in a row, or wind
        // up alternating.
        for (;;) {
            BigInteger y = div.add(x.divide(div)).shiftRight(1);
            if (y.equals(div) || y.equals(div2)) {
                return y;
            }
            div2 = div;
            div = y;
        }
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        //variable initialization

        String strLine, output;

//Read in a file and process one line at a time
        FileReader singleFile = new FileReader("E:\\GoogleCodeJam\\input3.txt");
        BufferedReader reader = new BufferedReader(singleFile);
        FileWriter outFile = new FileWriter("E:\\GoogleCodeJam\\output3.txt");
        BufferedWriter writer = new BufferedWriter(outFile);
        BigInteger divisors[] = new BigInteger[10];
        StringTokenizer st;

        strLine = reader.readLine();
        System.out.println("Input" + strLine);

        int count = Integer.parseInt(strLine);
        int numberOfCoins, length;
        BigInteger number;
        boolean alldivisors = Boolean.TRUE;

        for (int j = 1; j <= count; j++) {
            strLine = reader.readLine();
            System.out.println("Input" + strLine);
            st = new StringTokenizer(strLine);
            length = Integer.parseInt(st.nextToken());
            numberOfCoins = Integer.parseInt(st.nextToken());

            System.out.println("Length " + length + " Numer of Coins " + numberOfCoins);
            output = "Case #" + j + ":";
            writer.write(output);
            writer.newLine();
            writer.flush();

            int coinCount = 0;
            String valString = new String();

            int subLength = length - 2;

            for (int subNo = 0; subNo < Math.pow(2, subLength); subNo++) {

                char[] buffer = new char[subLength];
                int bufferPosition = buffer.length;
                int curSubNo = subNo;
                System.out.println("Current Sub No. " + curSubNo);
                while (bufferPosition > 0) {
                    buffer[--bufferPosition] = (char) (48 + (curSubNo & 1));
                    curSubNo >>>= 1;
                }

                valString = "1";
                for (int temp = 0; temp < subLength; temp++) {
                    valString = valString + buffer[temp];
                }

                valString = valString + "1";

                //System.out.println("Value in String: " + valString);
                for (int m = 2; m <= 10; m++) {
                    divisors[m - 1] = new BigInteger("-1");
                }

                divisors[0] = new BigInteger(valString, 10);
                for (int base = 2; base <= 10; base++) {
                    number = new BigInteger(valString, base);

                    //System.out.println("Base: " + base + " value: " + number);
                    BigInteger rootVal = sqrt(number);
                    BigInteger restrictVal = new BigInteger("1000");
                    if (rootVal.compareTo(restrictVal) == -1)
                        restrictVal = rootVal;
                    
                    if ((number.mod(new BigInteger("2"))).compareTo(BigInteger.ZERO) == 0) {
                        divisors[base - 1] = new BigInteger("2");
                    } else {
                        for (BigInteger div = new BigInteger("3"); div.compareTo(restrictVal) == -1; div = div.add(new BigInteger("2"))) {
                            //System.out.println("Values are " + div);
                            if ((number.mod(div)).compareTo(BigInteger.ZERO) == 0) {
                                divisors[base - 1] = div;
                                //System.out.println("Divisor is: " + div);
                                break;
                            }
                        }
                    }
                    if (divisors[base - 1].compareTo(new BigInteger("-1")) == 0) {
                        break;
                    }
                }

                alldivisors = Boolean.TRUE;
                for (int m = 1; m < 10; m++) {
                    if (divisors[m].compareTo(new BigInteger("-1")) == 0) {
                        alldivisors = Boolean.FALSE;
                        break;
                    }
                }
                if (alldivisors == Boolean.TRUE) {
                    output = "" + divisors[0];
                    for (int t = 1; t < 10; t++) {
                        output = output + " " + divisors[t];
                    }

                    System.out.println(output);
                    writer.write(output);
                    writer.newLine();
                    writer.flush();
                    coinCount++;
                }

                if (coinCount == numberOfCoins) {
                    break;
                }
            }

        }

        writer.close();
    }
}
