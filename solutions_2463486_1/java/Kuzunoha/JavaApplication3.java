/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

class Functions{
    public static Set<Integer> generatePalindromes(int max) {
        Set<Integer> ans = new TreeSet<>();
        for(int c=0;c<10&&c<=max;c++) {
            ans.add(c);
        }
        boolean cek = true;
        for(int c=1;cek;c++) {
            StringBuffer str = new StringBuffer(""+c).reverse();
            cek = false;
            for(String d : "0123456789".split("")) {
                int n = Integer.parseInt(""+c+d+str);
                if(n<=max) {
                    cek = true;
                    ans.add(n);
                }
            }
        }
        return ans;
    }
    
    public static boolean isPalindrome(BigInteger n) {
        String str = n.toString();
        int l = str.length();
        for(int c=0;c<l/2;c++) {
            if(str.charAt(c)!=str.charAt(l-c-1)) {
                return false;
            }
        }
        return true;
    }
};

/**
 *
 * @author Gracius
 */
public class JavaApplication3 {
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)  {
        Set<Integer> palindromes = Functions.generatePalindromes(10000002);
        List<BigInteger> palindromicSquares = new ArrayList<>();
        for(Integer c : palindromes) {
            BigInteger a = BigInteger.valueOf(c);
            BigInteger b = a.multiply(a);
            if(Functions.isPalindrome(b)) {
                palindromicSquares.add(b);
            }
        }
        try {
            File inp = new File("C:\\Users\\Gracius\\Desktop\\c.in");
            File out = new File("C:\\Users\\Gracius\\Desktop\\c.out");
            Scanner sc = new Scanner(inp);
            BufferedWriter writer = new BufferedWriter(new FileWriter(out));
            int T = sc.nextInt();
            for(int tc=1;tc<=T;tc++) {
                BigInteger A = sc.nextBigInteger();
                BigInteger B = sc.nextBigInteger();
                if(A.compareTo(B)==1) {
                    BigInteger S = A;
                    A = B;
                    B = S;
                }
                int nA, nB;
                for(nA=0;nA<palindromicSquares.size();nA++) {
                    if(palindromicSquares.get(nA).compareTo(A)!=-1) {
                        break;
                    }
                }
                for(nB=0;nB<palindromicSquares.size();nB++) {
                    if(palindromicSquares.get(nB).compareTo(B)!=-1) {
                        break;
                    }
                }
                int ans;
                if(B.compareTo(palindromicSquares.get(nB))==0) {
                    ans = nB - nA + 1;
                }
                else {
                    ans = nB - nA;
                }
                writer.write("Case #" + tc + ": " + ans);
                writer.newLine();
            }
            writer.close();
        }
        catch(Exception ex) {
        }
    }
}
