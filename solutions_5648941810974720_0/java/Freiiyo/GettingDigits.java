package com.nwollmann.codejam.year_2016.round1b;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 * Created by Nicholas on 4/30/2016.
 */
public class GettingDigits {

    static final boolean CONSOLE_MODE = true;
    static String fileName = "";

    static File in, out;
    static PrintWriter writer;
    static Scanner reader;

    public static void main(String[] args) throws Exception{
        if(CONSOLE_MODE) {
            writer = new PrintWriter(System.out);
            reader = new Scanner(System.in);
        } else {
            in = new File("C:/Codejam/in/" + fileName + ".in");
            out = new File("C:/Codejam/result.out");
            writer = new PrintWriter(new FileOutputStream(out));
            reader = new Scanner(new FileInputStream(in));
        }

        solve();

        writer.close();
        reader.close();
    }

    public static void solve(){

        int cases = reader.nextInt();

        for(int i = 1; i <= cases; i++) {
            writer.println("Case #" + i + ": " + solveCase());
        }

    }

    public static String solveCase(){

        String text = reader.next();
        ArrayList<Character> characters = new ArrayList<>();
        for(char c : text.toCharArray())
            characters.add(c);

        ArrayList<Integer> numbers = new ArrayList<>();

        while(characters.size() > 0) {
            if(characters.contains('Z')) {
                numbers.add(0);
                characters.remove((Character) 'Z');
                characters.remove((Character)'E');
                characters.remove((Character)'R');
                characters.remove((Character)'O');
            } else if(characters.contains('W')) {
                numbers.add(2);
                characters.remove((Character)'T');
                characters.remove((Character)'W');
                characters.remove((Character)'O');
            } else if(characters.contains('X')) {
                numbers.add(6);
                characters.remove((Character)'S');
                characters.remove((Character)'I');
                characters.remove((Character)'X');
            } else if (characters.contains('U')) {
                numbers.add(4);
                characters.remove((Character)'F');
                characters.remove((Character)'O');
                characters.remove((Character)'U');
                characters.remove((Character)'R');
            } else if (characters.contains('O')) {
                numbers.add(1);
                characters.remove((Character)'O');
                characters.remove((Character)'N');
                characters.remove((Character)'E');
            } else if (characters.contains('G')) {
                numbers.add(8);
                characters.remove((Character)'E');
                characters.remove((Character)'I');
                characters.remove((Character)'G');
                characters.remove((Character)'H');
                characters.remove((Character)'T');
            } else if (characters.contains('R')) {
                numbers.add(3);
                characters.remove((Character)'T');
                characters.remove((Character)'H');
                characters.remove((Character)'R');
                characters.remove((Character)'E');
                characters.remove((Character)'E');
            } else if (characters.contains('F')){
                numbers.add(5);
                characters.remove((Character)'F');
                characters.remove((Character)'I');
                characters.remove((Character)'V');
                characters.remove((Character)'E');
            } else if (characters.contains('V')) {
                numbers.add(7);
                characters.remove((Character)'S');
                characters.remove((Character)'E');
                characters.remove((Character)'V');
                characters.remove((Character)'E');
                characters.remove((Character)'N');
            } else if (characters.contains('N')) {
                numbers.add(9);
                characters.remove((Character)'N');
                characters.remove((Character)'I');
                characters.remove((Character)'N');
                characters.remove((Character)'E');
            }
        }

        Collections.sort(numbers);

        String toReturn = "";
        for(int number : numbers) toReturn += number;

        return toReturn;

    }

}
