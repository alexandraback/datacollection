/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Vector;

/**
 *
 * @author Paris
 */
public class task3 {

    static BigInteger getnum(boolean bits[], int base) {

        BigInteger num = new BigInteger("0");
        BigInteger bigbase = new BigInteger(Integer.toString(base));
        for (int i = 0; i < bits.length; i++) {
            if (bits[i]) {
               num= num.add(bigbase.pow(bits.length - 1 - i));
            }
        }
        return num;
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {

        BufferedReader in = new BufferedReader(new FileReader("data.txt"));
        BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
        int T = Integer.parseInt(in.readLine());

        BigInteger[] cache = new BigInteger[500];
        
        for (int i = 0; i < 100; i++) {
            cache[i] = new BigInteger(Integer.toString(3 * i + 3));
        }
        for (int i = 0; i < 100; i++) {
            cache[100 + i] = new BigInteger(Integer.toString(5 * i + 5));
        }
        for (int i = 0; i < 100; i++) {
            cache[200 + i] = new BigInteger(Integer.toString(7 * i + 7));
        }
        for (int i = 0; i < 100; i++) {
            cache[300 + i] = new BigInteger(Integer.toString(9 * i + 9));
        }
        for (int i = 0; i < 100; i++) {
            cache[400 + i] = new BigInteger(Integer.toString(11 * i + 11));
        }

        for (int i = 0; i < T; i++) {

            int N = Integer.parseInt(in.readLine());
            int J = Integer.parseInt(in.readLine());

            BigInteger[] found = new BigInteger[J];
            BigInteger[][]dividers=new BigInteger[J][10];
            
            boolean[] bits = new boolean[N];

            bits[0] = true;
            bits[N - 1] = true;
            int ok = 0;
            int foundloc = 0;
            int bitloc = 0;
            while (foundloc < J) {
                ok = 0;
                for (int j = 1; j < N - 2; j++) {
                    bits[j] = (bitloc >> (j-1) & 1) == 1;
                }

                for (int base = 2; base < 11; base++) {
                    BigInteger num = getnum(bits, base);
                    for (int k = 0; k < 500; k++) {
                        if (num.mod(cache[k]) == BigInteger.ZERO) {
                            ok++;
                            dividers[foundloc][base-2]=cache[k];
                            if (ok == 9) {
                                found[foundloc] = num;                                
                                foundloc++;

                            }
                            break;

                        }
                    }
                }

                bitloc++;
            }
            out.append("Case #" + (i + 1) + ": " + "\n");
            for(int j=0;j<J;j++){
                System.out.println(found[j].toString());
                 out.append(found[j].toString()+" ");
                for(int k=0;k<9;k++){
                      out.append(dividers[j][k].toString()+" ");
                }
                  out.append("\n");
            }
            
        }
        out.close();

    }
}
