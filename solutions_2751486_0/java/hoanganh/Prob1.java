/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package CodejamRound1C;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author Anh Nguyen
 */
public class Prob1 {

   static String file = "A-small-attempt0.in"; // file with .in extension

   static boolean check(String name, int n)
   {
       int a = 0;
       for (int i = 0; i < name.length(); i++) {
           if("qwrtyplkjhgfdszxcvbnm".contains(name.charAt(i)+"")) 
           {
               a++;
               if(a == n) return true;
           }
           else{ a=0;}           
       }
       return false;
   }
   
   public static void main(String[] args) throws IOException {
        go();
        //r.next();
        for (int i = 0; i < nCase; i++) {
            String []line = rString();
            String name = line[0];
            int n = rInt();
            int count = 0;
            for (int k = n; k <= name.length(); k++) {
                  for (int j = 0; j <= name.length()-k ;  j++) {
                    String subname = name.substring(j, j+k);
                if(check(subname, n)) count++;
                  }
            }
          
            
            
            
           out(i, (count)+"");
           
        }
        end();
    }

    static int rInt() {
        return r.nextInt();
    }

    static double rDouble() {
        return r.nextDouble();
    }

    static float rFloat() {
        return r.nextFloat();
    }

    static long rLong() {
        return r.nextLong();
    }

    static int[] rInts(int time) {
        if (time > 0) {
            int[] arr = new int[time];
            for (int i = 0; i < time; i++) {
                arr[i] = rInt();
            }
            return arr;
        } else {
            String[] s = r.nextLine().split(" ");
            int[] arr = new int[s.length];
            for (int i = 0; i < s.length; i++) {
                arr[i] = Integer.parseInt(s[i]);
            }
            return arr;
        }
    }

    static long[] rLongs(int time) {
        if (time > 0) {
            long[] arr = new long[time];
            for (int i = 0; i < time; i++) {
                arr[i] = rLong();
            }
            return arr;
        } else {
            String[] s = r.nextLine().split(" ");
            long[] arr = new long[s.length];
            for (int i = 0; i < s.length; i++) {
                arr[i] = Long.parseLong(s[i]);
            }
            return arr;
        }
    }

    static double[] rDoubles(int time) {
        if (time > 0) {

            double[] arr = new double[time];
            for (int i = 0; i < time; i++) {
                arr[i] = rDouble();
            }
            return arr;
        } else {
            String[] s = r.nextLine().split(" ");
            double[] arr = new double[s.length];
            for (int i = 0; i < s.length; i++) {
                arr[i] = Double.parseDouble(s[i]);
            }
            return arr;
        }
    }

    static float[] rFloats(int time) {
        if (time > 0) {

            float[] arr = new float[time];
            for (int i = 0; i < time; i++) {
                arr[i] = rFloat();
            }
            return arr;
        } else {
            String[] s = r.nextLine().split(" ");
            float[] arr = new float[s.length];
            for (int i = 0; i < s.length; i++) {
                arr[i] = Float.parseFloat(s[i]);
            }
            return arr;
        }
    }

    static String r1Char() {
        return r.next();
    }

    static String[] rString() {
        return r.next().split(" ");
    }

    static char[] rNChars() {
        char[] arr = r.next().toCharArray();
        return arr;
    }

    static void go() throws IOException {
        r = new Scanner(new FileReader(file));
        w = new PrintWriter(new FileWriter(file.replace(".in", ".out")));
        nCase = rInt();
    }

    static void end() {
        w.flush();
        w.close();
        r.close();
    }

    private static void out(int i, String result) {
        w.println("Case #" + (i + 1) + ": " + result);
       // System.out.println("Case #" + (i + 1) + ": " + result);
    }
    static Scanner r;
    static PrintWriter w;
    static int nCase;
}
