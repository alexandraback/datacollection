package idv.popcorny.jam2016;

import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by popcorny on 4/9/16.
 */
public class LastWord {

    private static String lastword(String word) {
        ArrayList<Character> result = new ArrayList<>(word.length());

        for (int i=0; i<word.length(); i++) {
            char c = word.charAt(i);
            if(i > 0 && c >= result.get(0)) {
                result.add(0, c);
            } else {
                result.add(c);
            }
        }
        char[] chars = new char[word.length()];
        for (int i=0; i<word.length(); i++) {
            chars[i] = result.get(i);
        }
        return new String(chars);
    }

    public static void main(String[] args) throws Exception {
        Scanner scanner;
        PrintWriter writer;
        String quizname = "lastword";
        String testname = "small";
        String input   = String.format("quiz/%s/%s.in", quizname, testname);
        String output  = String.format("quiz/%s/%s.out", quizname, testname);

        if (new File(input).exists()) {
            scanner = new Scanner(new File(input));
            if (testname.equals("sample")) {
                writer = new PrintWriter(System.out);
            } else {
                writer = new PrintWriter(output);
            }
        } else {
            scanner = new Scanner(System.in);
            writer = new PrintWriter(System.out);
        }


        int t = scanner.nextInt();

        for (int i = 0; i < t; i++) {
            String word = scanner.next();

            writer.printf("Case #%d: %s\n", i + 1, lastword(word));

        }
        writer.flush();
    }
}
