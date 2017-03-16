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
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 *
 * @author user
 */
public class JamCoin {

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
        long divisors[] = new long[10];
        StringTokenizer st;

        strLine = reader.readLine();
        System.out.println("Input" + strLine);

        int count = Integer.parseInt(strLine);
        int numberOfCoins, length;
        long number;
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

                System.out.println("Value in String: " + valString);
                for (int m = 2; m <= 10; m++) {
                    divisors[m - 1] = -1;
                }

                divisors[0] = Long.valueOf(valString, 10);
                for (int base = 2; base <= 10; base++) {
                    number = Long.valueOf(valString, base);

                    System.out.println("Base: " + base + " value: " + number);
                    long rootVal = (new Double(java.lang.Math.sqrt(number))).longValue(); 
                    for (long div = 2; div <= rootVal;  div++) {
                        if (number % div == 0) {
                            divisors[base - 1] = div;
                            System.out.println("Divisor is: " + div);
                            break;
                        }
                    }
                }

                alldivisors = Boolean.TRUE;
                for (int m = 1; m < 10; m++) {
                    if (divisors[m] == -1) {
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
