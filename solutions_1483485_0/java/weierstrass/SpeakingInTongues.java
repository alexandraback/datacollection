package javaapplication2;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class SpeakingInTongues {
    
    private final static String INPUT_PATH = "resources/speaking_in_tongues.in";
    private final static String OUTPUT_PATH = "resources/speaking_in_tongues.out";
    private static int caseNumber = 0;
    
    private final static Map<Character, Character> PERMUTATION = new HashMap<Character, Character>() {
        {
            put(' ', ' ');
            put('a', 'y');
            put('b', 'h');
            put('c', 'e');
            put('d', 's');
            put('e', 'o');
            put('f', 'c');
            put('g', 'v');
            put('h', 'x');
            put('i', 'd');
            put('j', 'u');
            put('k', 'i');
            put('l', 'g');
            put('m', 'l');
            put('n', 'b');
            put('o', 'k');
            put('p', 'r');
            put('q', 'z');
            put('r', 't');
            put('s', 'n');
            put('t', 'w');
            put('u', 'j');
            put('v', 'p');
            put('w', 'f');
            put('x', 'm');
            put('y', 'a');
            put('z', 'q');
        }
    };

    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner scanner = new Scanner(new File(INPUT_PATH));
        
        int T = scanner.nextInt();
        
        scanner.useDelimiter("\n");
        try (FileWriter out = new FileWriter(OUTPUT_PATH)) {
            while (scanner.hasNext()) {
                processCase(scanner.next(), out);
            }
        }
    }
    
    private static void processCase(String string, FileWriter out) throws IOException {
        out.write("Case #" + (++caseNumber) + ": ");
        for (int i = 0; i < string.length(); ++i) {
            out.write(PERMUTATION.get(string.charAt(i)));
        }
        out.write("\n");
    }
}
