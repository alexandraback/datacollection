/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package R1B2016;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author astorres
 */
public class B {
    
    static char arr1[], arr2[];
    static int res1, res2, res3;
    
    public static void parr() {
        System.out.println(new String(arr1)+" "+new String(arr2));
    }
    
    public static void res(int n) {
        if(n>=arr1.length+arr2.length) {
            //parr();
            int n1 = Integer.parseInt(new String(arr1));
            int n2 = Integer.parseInt(new String(arr2));
            if(Math.abs(n2-n1)<res3) {
                res3 = Math.abs(n2-n1);
                res1 = n1;
                res2 = n2;
            }
            if(Math.abs(n2-n1)==res3) {
                if(res1>n1) {
                    res1 = n1;
                    res2 = n2;
                }
                if(res1==n1&&res2>n2) {
                    res2 = n2;
                }
            }
            return;
        }
        if(n<arr1.length) {
            if(arr1[n]=='?') {
                for(int i=0;i<10;i++) {
                    arr1[n] = (char)(i+'0');
                    res(n+1);
                    arr1[n]='?';
                }
            } else {
                res(n+1);
            }
        } else {
            if(arr2[n-arr1.length]=='?') {
                for(int i=0;i<10;i++) {
                    arr2[n-arr1.length] = (char)(i+'0');
                    res(n+1);
                    arr2[n-arr1.length]='?';
                }
            } else {
                res(n+1);
            }
        }
    }
    
    public static void main(String args[]) throws FileNotFoundException {
        String file = "B-small-attempt0.in";
        Scanner in = new Scanner(new File("C:\\Users\\astorres\\Desktop\\Personal\\CodeJam\\src\\CodeJam\\data\\"+file));
        int n = in.nextInt();
        for(int i=1;i<=n;i++) {
            
            String a = in.next(), b = in.next();
            arr1 = a.toCharArray();
            arr2 = b.toCharArray();
            res1 = res2 = res3 = 1000000000;
            res(0);
            a = Integer.toString(res1);
            b = Integer.toString(res2);
            while(a.length()<arr1.length)
                a = "0"+a;
            while(b.length()<arr2.length)
                b = "0"+b;
            System.out.println("Case #"+i+": "+a+" "+b);
        }
    }
    
}
