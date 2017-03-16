package gcj2016.round1B;

import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class GettingTheDigits {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        //String[] digits = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
        // "THREE",
        int t = in.nextInt(); 
        for (int i = 1; i <= t; ++i) {
            String s = in.next();
            int[] occ = new int[26];
            for (int j=0; j<s.length(); ++j){
                ++occ[s.charAt(j)-'A'];
            }
            ArrayList<Integer> number = new ArrayList<Integer>();
            int n = occ['Z'-'A'];
            take(occ,"ZERO",n);
            for (int j=0; j<n; ++j){
                number.add(0);
            }
            n = occ['W'-'A'];
            take(occ,"TWO",n);
            for (int j=0; j<n; ++j){
                number.add(2);
            }
            n = occ['X'-'A'];
            take(occ,"SIX",n);
            for (int j=0; j<n; ++j){
                number.add(6);
            }
            n = occ['U'-'A'];
            take(occ,"FOUR",n);
            for (int j=0; j<n; ++j){
                number.add(4);
            }
            n = occ['F'-'A'];
            take(occ,"FIVE",n);
            for (int j=0; j<n; ++j){
                number.add(5);
            }
            n = occ['O'-'A'];
            take(occ,"ONE",n);
            for (int j=0; j<n; ++j){
                number.add(1);
            }
            n = occ['V'-'A'];
            take(occ,"SEVEN",n);
            for (int j=0; j<n; ++j){
                number.add(7);
            }
            n = occ['G'-'A'];
            take(occ,"EIGHT",n);
            for (int j=0; j<n; ++j){
                number.add(8);
            }
            n = occ['I'-'A'];
            take(occ,"NINE",n);
            for (int j=0; j<n; ++j){
                number.add(9);
            }
            n = occ['T'-'A'];
            take(occ,"THREE",n);
            for (int j=0; j<n; ++j){
                number.add(3);
            }
            
            Integer[] sorted = {}; 
            sorted = number.toArray(sorted);
            Arrays.sort(sorted);
            System.out.println("Case #" + i + ": " + toString(sorted));
        }
        in.close();
    }
    
    public static String toString(Integer[] a){
        String s = "";
        for (int i= 0; i<a.length; ++i){
            s += a[i];
        }
        return s;
    }
    
    public static void take(int[] occ, String s, int n){
        for (int i=0; i<s.length(); ++i){
            take(occ, s.charAt(i), n);
        }
    }
    
    public static void take(int[] occ, char c, int n){
        occ[c-'A'] -= n;
    }
}