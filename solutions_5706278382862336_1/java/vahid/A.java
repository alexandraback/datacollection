package com.vahid.google.codejam.round1c2014;

import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: 8
 * Date: 5/11/14
 * Time: 11:22 AM
 * To change this template use File | Settings | File Templates.
 */
public class A {
    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner((A.class.getClassLoader().getResourceAsStream("data.txt")));

        PrintWriter out = new PrintWriter("A.out");

        int lines = scanner.nextInt();
        scanner.nextLine();

        for (int i = 1; i<= lines; i++){
            String line = scanner.nextLine();
            String[] list = line.split("/");
            BigInteger soorat = new BigInteger(list[0]);
            BigInteger makhraj = new BigInteger(list[1]);

            BigInteger gcd = makhraj.gcd(soorat);
            soorat = soorat.divide(gcd);
            makhraj = makhraj.divide(gcd);

            boolean impossible = true;

            long check = 1;

            while (check < makhraj.longValue())
                check *= 2;

            String response = "impossible";
            int counter = 0;
            if (check == makhraj.longValue()){
                while (makhraj.compareTo(soorat)>0){
                    soorat =soorat.multiply(new BigInteger(new Integer(2).toString()));
                    counter++;
                }
                response = new Integer(counter).toString();

            }


            out.println("Case #" + i + ": " + response);


        }

        scanner.close();
        out.close();
    }
}
