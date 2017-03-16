//Uses Java 8

import java.io.*;
import java.util.*;

public class GCJ161BA {

    static Scanner sc = new Scanner(System.in);

    public void run(int Case) {
        String S = sc.next();
        int[] count = new int[26];
        int[] count2 = new int[10];
        for (int i = 0; i < S.length(); i++) {
            count[S.charAt(i) - 'A']++;
        }

        while (count['Z' - 'A'] > 0 && count['E' - 'A'] > 0 && count['R' - 'A'] > 0 && count['O' - 'A'] > 0) {
            count['Z' - 'A']--;
            count['E' - 'A']--;
            count['R' - 'A']--;
            count['O' - 'A']--;
            count2[0]++;
        }
        while (count['T' - 'A'] > 0 && count['W' - 'A'] > 0 && count['O' - 'A'] > 0) {
            count['T' - 'A']--;
            count['W' - 'A']--;
            count['O' - 'A']--;
            count2[2]++;
        }
        while (count['F' - 'A'] > 0 && count['U' - 'A'] > 0 && count['R' - 'A'] > 0 && count['O' - 'A'] > 0) {
            count['F' - 'A']--;
            count['U' - 'A']--;
            count['R' - 'A']--;
            count['O' - 'A']--;
            count2[4]++;
        }
        while (count['S' - 'A'] > 0 && count['I' - 'A'] > 0 && count['X' - 'A'] > 0) {
            count['S' - 'A']--;
            count['I' - 'A']--;
            count['X' - 'A']--;
            count2[6]++;
        }
        while (count['H' - 'A'] > 0 && count['E' - 'A'] > 0 && count['I' - 'A'] > 0 && count['T' - 'A'] > 0 && count['G' - 'A'] > 0) {
            count['H' - 'A']--;
            count['E' - 'A']--;
            count['I' - 'A']--;
            count['G' - 'A']--;
            count['T' - 'A']--;
            count2[8]++;
        }
        while (count['O' - 'A'] > 0 && count['E' - 'A'] > 0 && count['N' - 'A'] > 0) {
            count['N' - 'A']--;
            count['E' - 'A']--;
            count['O' - 'A']--;
            count2[1]++;
        }
        while (count['T' - 'A'] > 0 && count['H' - 'A'] > 0 && count['R' - 'A'] > 0 && count['E' - 'A'] > 1) {
            count['T' - 'A']--;
            count['E' - 'A'] -= 2;
            count['R' - 'A']--;
            count['H' - 'A']--;
            count2[3]++;
        }
        while (count['F' - 'A'] > 0 && count['E' - 'A'] > 0 && count['I' - 'A'] > 0 && count['V' - 'A'] > 0) {
            count['F' - 'A']--;
            count['E' - 'A']--;
            count['I' - 'A']--;
            count['V' - 'A']--;
            count2[5]++;
        }
        while (count['S' - 'A'] > 0 && count['E' - 'A'] > 1 && count['V' - 'A'] > 0 && count['N' - 'A'] > 0) {
            count['S' - 'A']--;
            count['E' - 'A'] -= 2;
            count['V' - 'A']--;
            count['N' - 'A']--;
            count2[7]++;
        }
        while (count['N' - 'A'] > 1 && count['E' - 'A'] > 0 && count['I' - 'A'] > 0) {
            count['N' - 'A'] -= 2;
            count['E' - 'A']--;
            count['I' - 'A']--;
            count2[9]++;
        }
        
        StringBuilder solution = new StringBuilder();
        for(int i = 0; i<10;i++) {
            while(count2[i]>0) {
                count2[i]--;
                solution.append(String.valueOf(i));
            }
        }

        String answer = "Case #" + Case + ": " + solution.toString();
        System.out.println(answer);
    }

    public static void main(String[] args) throws FileNotFoundException {
        //Generates output file, can be removed to get everything from default output
        System.setOut(new PrintStream(new BufferedOutputStream(new FileOutputStream("C://Users/s142589/Desktop/output.txt")), true));

        int runs = sc.nextInt();
        for (int i = 0; i < runs; i++) {
            new GCJ161BA().run(i + 1);
        }
    }
}
