
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author bachu
 */
public class jamcoin {
    static boolean prime[];
    public static void main(String args[]) throws FileNotFoundException {
        PrintWriter writer = new PrintWriter(new File("jamcoin.out"));
        int pow = 16;
        prime = new boolean[(int)Math.pow(2, 16)];
        for (int i = 0; i < prime.length; i++) {
            prime[i] = true;
        }
        for (long i = 2; i < Math.pow(2, 16); i++) {
            if (!prime[(int)i]) {
                continue;
            }
            for (long j = i + i; j < prime.length; j += i) {
                prime[(int)j] = false;
            }
        }
        int found = 0;
        ArrayList<String> ans = new ArrayList<String>();
        ArrayList<ArrayList<String>> factors = new ArrayList<ArrayList<String>>();
        for (int i = (int)Math.pow(2, 15) + 1; i < prime.length; i+=2) {
            String bin = Integer.toBinaryString(i);
            boolean stuff = true;
            for (int j = 2; j <= 10; j++) {
                BigInteger asd = new BigInteger(bin, j);
                if (asd.isProbablePrime(40)) {
                    stuff = false;
                }
                
            }
            if (!stuff) {
                continue;
            }
            ans.add(bin);
            factors.add(new ArrayList<String>());
            for (int j = 2; j <= 10; j++) {
                BigInteger asd = new BigInteger(bin, j);
                for (BigInteger k = BigInteger.valueOf(2); k.compareTo(asd) < 0; k=k.add(BigInteger.valueOf(1))) {
                    if (asd.remainder(k).equals(BigInteger.valueOf(0))) {
                        factors.get(factors.size() - 1).add(k.toString(10));
                        if (j == 2) {
                            //System.out.println("For " + bin + " adding " + k.toString(10));
                        }
                        break;
                    }
                }
            }
            found++;
            if (found == 50) {
                break;
            }
        }
        writer.write(String.format("Case #1:%n"));
        for (int i = 0; i < ans.size(); i++) {
            String result = ans.get(i);
            for (int j = 0; j < factors.get(i).size(); j++) {
                result += " " + factors.get(i).get(j);
            }
            //System.out.println(factors.get(i).size() == 9);
            writer.write(result + "\n");
        }
        writer.close();
    }
}
