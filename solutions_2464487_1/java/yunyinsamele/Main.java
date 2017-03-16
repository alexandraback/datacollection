/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package main;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.ArrayList;
/**
 *
 * @author yunyin
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here
        Scanner cin = new Scanner(System.in);
        FileOutputStream out;
        out=new FileOutputStream("C://Users//yunyin//Desktop//1A//A_large.out");
        int T;
        BigInteger r,t,now,middle;
        int left,right,mid;
        String ans;
        T = cin.nextInt();
        for(int i=1;i<=T;i++)
        {
            r = cin.nextBigInteger();
            t = cin.nextBigInteger();
            left = 0;
            right = 907106780;
            while(left<=right)
            {
                mid = (left+right)>>1;
                middle = BigInteger.valueOf(mid);
                now = (((r.multiply(BigInteger.valueOf(2))).add(middle.add(middle))).subtract(BigInteger.ONE)).multiply(middle);
                if(now.compareTo(t)>0) right = mid-1;
                else left = mid +1;
            }
            ans = "Case #"+i+": "+right+'\n';
            byte[] buffer = new byte[] {};
            buffer = ans.getBytes();
            out.write(buffer,0,buffer.length);
            //
        }
    }
}
