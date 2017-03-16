/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package codejamb;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;

/**
 *
 * @author JLH
 */
public class A {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        new A();
    }

    public A() throws FileNotFoundException, IOException {
        BufferedReader br = new BufferedReader(new FileReader("A-small-attempt1.in"));

        int cases = Integer.parseInt(br.readLine().trim());

        PrintWriter pw = new PrintWriter("out.txt");
        for (int i = 0; i < cases; i++) {
            String line = br.readLine();
            System.out.println(i + 1);

            pw.println(String.format("Case #%d: %s", i + 1, solve(line)));
        }
        pw.close();
    }

    public String solve(String line) {
        ArrayList<Integer> numbers = new ArrayList<Integer>();
        int lastDigit = 0;

        String s = "";

        for (int i = 0; i < line.length(); i++){
            s += line.charAt(i);
            if (lastDigit <= 0 && containsZero(s)){
                s = removeLetters(s, "ZERO");
                numbers.add(0);
//                ans += "0";
//                lastDigit = 0;
            }
            if (lastDigit <= 1 && containsOne(s)){
                s = removeLetters(s, "ONE");
                numbers.add(1);
//                ans += "1";
//                lastDigit = 1;
            }
            if (lastDigit <= 2 && containsTwo(s)){
                s = removeLetters(s, "TWO");
                numbers.add(2);
//                ans += "2";
//                lastDigit = 2;
            }
            if (lastDigit <= 3 && containsThree(s)){
                s = removeLetters(s, "THREE");
                numbers.add(3);
//                ans += "3";
//                lastDigit = 3;
            }
            if (lastDigit <= 4 && containsFour(s)){
                s = removeLetters(s, "FOUR");
                numbers.add(4);
//                ans += "4";
//                lastDigit = 4;
            }
            if (lastDigit <= 5 && containsFive(s)){
                s = removeLetters(s, "FIVE");
                numbers.add(5);
//                ans += "5";
//                lastDigit = 5;
            }
            if (lastDigit <= 6 && containsSix(s)){
                s = removeLetters(s, "SIX");
                numbers.add(6);
//                ans += "6";
//                lastDigit = 6;
            }
            if (lastDigit <= 7 && containsSeven(s)){
                s = removeLetters(s, "SEVEN");
                numbers.add(7);
//                ans += "7";
//                lastDigit = 7;
            }
            if (lastDigit <= 8 && containsEight(s)){
                s = removeLetters(s, "EIGHT");
                numbers.add(8);
//                ans += "8";
//                lastDigit = 8;
            }
            if (lastDigit <= 9 && containsNine(s)){
                s = removeLetters(s, "NINE");
                numbers.add(9);
//                ans += "9";
//                lastDigit = 9;
            }
        }

        String ans = "";
        if (s.length() >0 ){
            ans = solve(line.substring(1) + line.charAt(0));
//            System.out.println("Error!! " + s);
        } else {
            Collections.sort(numbers);
            for (int i : numbers){
                ans+=i;
            }
        }

        return ans;
    }

    public boolean containsZero(String s){
        return s.contains("Z") && s.contains("E") && s.contains("R") && s.contains("O"); 
    }

    public boolean containsOne(String s){
        return s.contains("O") && s.contains("N") && s.contains("E"); 
    }

    public boolean containsTwo(String s){
        return s.contains("T") && s.contains("W") && s.contains("O"); 
    }

    public boolean containsThree(String s){
        return s.contains("T") && s.contains("H") && s.contains("R") && countChar(s, 'E') >= 2; 
    }

    public boolean containsFour(String s){
        return s.contains("F") && s.contains("O") && s.contains("U") && s.contains("R"); 
    }

    public boolean containsFive(String s){
        return s.contains("F") && s.contains("I") && s.contains("V") && s.contains("E"); 
    }

    public boolean containsSix(String s){
        return s.contains("S") && s.contains("I") && s.contains("X"); 
    }

    public boolean containsSeven(String s){
        return s.contains("S") && s.contains("V") && s.contains("N") && countChar(s, 'E') >= 2; 
    }

    public boolean containsEight(String s){
        return s.contains("E") && s.contains("I") && s.contains("G") && s.contains("H")&& s.contains("T"); 
    }

    public boolean containsNine(String s){
        return s.contains("I") && s.contains("E") && countChar(s, 'N') >= 2; 
    }

    public int countChar(String s, char c){
        int count = 0;
        for (char ch : s.toCharArray()){
            if (ch == c){
                count++;
            }
        }
        return count;
    }

    public static void printIntMatrix(int[][] matrix) {
        for (int row = 0; row < matrix.length; row++) {
            String s = "";
            for (int col = 0; col < matrix[0].length; col++) {
                s += matrix[row][col] + " ";
            }
            System.out.println(s);
        }
    }

    public static void printCharMatrix(char[][] matrix) {
        for (int row = 0; row < matrix.length; row++) {
            String s = "";
            for (int col = 0; col < matrix[0].length; col++) {
                s += matrix[row][col] + " ";
            }
            System.out.println(s);
        }
    }

    private String removeLetters(String s, String letters) {
        for (char c : letters.toCharArray()){
            int cInd = s.indexOf(c);
            s = s.substring(0, cInd) + s.substring(cInd+1) ;
        }
        return s;
    }
}
