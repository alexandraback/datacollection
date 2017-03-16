/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Codejam;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

/**
 *
 * @author Kyoo
 */
public class Prob2B {
    public static void main(String[] args) throws IOException {
        BufferedReader leer= new BufferedReader(new InputStreamReader(System.in));
        int T=Integer.parseInt(leer.readLine());
        for (int i = 1; i <= T; i++) {
            System.out.print("Case #"+i+": ");
            String[] rango=leer.readLine().trim().split(" ");
            BigInteger r=BigInteger.valueOf(Long.parseLong(rango[0]));
            BigInteger t=BigInteger.valueOf(Long.parseLong(rango[1]));
            BigInteger n=resolver(r,t);
            System.out.println(n);
        }
    }
    private static BigInteger resolver(BigInteger r, BigInteger t) {
        BigInteger inicio=r.add(BigInteger.ONE).pow(2).subtract(r.pow(2));
        int exp=37;
        BigInteger adv=BigInteger.TEN.pow(exp);
        BigInteger n=BigInteger.ZERO;
        
        do{
            n=n.add(adv);
            if(ecuacion(inicio,n).compareTo(t)>0){
                if(--exp<0) break;
                n=n.subtract(adv);
                adv=BigInteger.TEN.pow(exp);
            }
        }while(exp>=0);
        return n;
    }

    private static BigInteger ecuacion(BigInteger inicio, BigInteger n) {
        return n.add(BigInteger.ONE).multiply(inicio.add(n.multiply(BigInteger.valueOf(2))));
    }
}