
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author bachu
 */
public class fashion {
    
    public static void main(String args[]) throws FileNotFoundException{
        Scanner scan = new Scanner(new File("fashion.in"));
        PrintWriter writer = new PrintWriter(new File("fashion.out"));
        int cases = scan.nextInt();
        
        for (int i = 0; i < cases; i++) {
            int j, p, s, k;
            j = scan.nextInt();
            p = scan.nextInt();
            s = scan.nextInt();
            k = scan.nextInt();
            HashMap<String, Integer> map = new HashMap<>();
            ArrayList<Outfit> outfits = new ArrayList<>();
            for (int n = 0; n < s; n++) {
                for (int m = 0; m < p; m++) {
                    for (int l = 0; l < j; l++) {
                        outfits.add(new Outfit(l+1, m+1, n+1, map));
                    }
                }
            }
            
            for (Outfit o: outfits) {
                o.set(map, k);
            }
            while(!outfits.isEmpty()) {
                Collections.sort(outfits);
                if (outfits.get(outfits.size() - 1).valid(map)) {
                    outfits.get(outfits.size() - 1).subtract(map);
                }
                else {
                    outfits.remove(outfits.size() - 1);
                }
            }
//            for (int l = 0; l < outfits.size(); l++) {
//                if (outfits.get(l).valid(map)) {
//                    outfits.get(l).subtract(map);
//                }
//                else {
//                    outfits.remove(l);
//                    l--;
//                }
//            }
            writer.write(String.format("Case #%d: %d%n", i+1, outfits.size()));
            for(Outfit o : outfits) {
                writer.write(String.format("%s%n", o));
            }
        }
        writer.close();
    }

    static class Outfit implements Comparable<Outfit> {
        int j, p, s;
        HashMap<String, Integer> map;
        Outfit(int j, int p, int s, HashMap<String, Integer> map) {
            this.j = j;
            this.p = p;
            this.s = s;
            this.map = map;
        }
        
        String[] combos() {
            String one = "" + j + "" + p + " ";
            String two = "" + j + " " + s;
            String three = " " + p + "" + s;
            String arr[] = new String[3];
            arr[0] = one;
            arr[1] = two;
            arr[2] = three;
            return arr;
        }
        
        void subtract(HashMap<String, Integer> map) {
            String arr[] = this.combos();
            for (String s : arr) {
                map.put(s, map.get(s) - 1);
            }
        }
        
        void set(HashMap<String, Integer> map, int k) {
            String arr[] = this.combos();
            for (String s : arr) {
                map.put(s, k);
            }
        }
        
        boolean valid(HashMap<String, Integer> map) {
            String arr[] = this.combos();
            for (String s : arr) {
                if (map.get(s) < 0) {
                    System.out.println("What?");
                    return false;
                }
                if (map.get(s) <= 0) {
                    return false;
                }
            }
            return true;
        }
        
        public String toString() {
            return "" + j + " " + p + " " + s;
        }

        int a() {
            String arr[] = this.combos();
            int min = Integer.MAX_VALUE;
            for (String s : arr) {
                min = Math.min(min, map.get(s));
            }
            return min;
        }
        
        @Override
        public int compareTo(Outfit o) {
            return a() - o.a();
        }
    }
    
}
