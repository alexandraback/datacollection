
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
public class jamcoinbig {
    public static void main(String args[]) throws FileNotFoundException {
        PrintWriter writer = new PrintWriter(new File("jamcoinbig2.out"));
        int pow = 32;
        int j = 500;
        BigInteger start = BigInteger.valueOf((long)Math.pow(2, 31)+1);
        BigInteger end = BigInteger.valueOf((long)Math.pow(2,32));
        ArrayList<String> result = new ArrayList<String>();
        ArrayList<ArrayList<String>> factors = new ArrayList<ArrayList<String>>();
        BigInteger two = BigInteger.valueOf(2);
        int found = 0;
        while (found < 500) {
            start = start.add(two);
            String bin = start.toString(2);
            boolean stuff = true;
            for (int i = 2; i <= 10; i++) {
                BigInteger num = new BigInteger(bin, i);
                if (num.isProbablePrime(30)) {
                    stuff = false;
                    break;
                }
            }
            
            if (!stuff) {
                continue;
            }
            found++;
            result.add(bin);
            factors.add(new ArrayList<String>());
            for (int i = 2; i <= 10; i++) {
                BigInteger num = new BigInteger(bin, i);
                /*System.out.println("Testing " + bin.toString());
                for (BigInteger k = two; k.compareTo(num) < 0; k = k.nextProbablePrime()) {
                    
                    if (num.remainder(k).equals(BigInteger.ZERO)) {
                        factors.get(factors.size() - 1).add(k.toString(10));
                        System.out.println("FOUND");
                        break;
                    }
                }*/
                factors.get(factors.size()-1).add(factor(num).toString(10));
            }
            System.out.println(found);
        }
        writer.write(String.format("Case #1:%n"));
        for (int i = 0; i < result.size(); i++) {
            String resultt = result.get(i);
            for (int k = 0; k < factors.get(i).size(); k++) {
                resultt += " " + factors.get(i).get(k);
            }
            System.out.println(factors.get(i).size() == 9);
            writer.write(resultt + "\n");
        }
        writer.close();
    }
    
    static BigInteger factor(BigInteger num) {
        BigInteger x = BigInteger.valueOf(2);
        BigInteger y = BigInteger.valueOf(2);
        BigInteger d = BigInteger.valueOf(1);
        while (d.equals(BigInteger.ONE)) {
            x = g(x, num);
            y = g(g(y, num), num);
            d = x.subtract(y).abs().gcd(num);
        }
        if (d.equals(num)) {
            throw new RuntimeException(":C");
        }
        return d;
    }
    
    static BigInteger g(BigInteger x, BigInteger n) {
        return x.multiply(x).add(BigInteger.ONE).mod(n);
    }
}
