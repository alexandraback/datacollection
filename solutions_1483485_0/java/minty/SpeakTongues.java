
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class SpeakTongues {

    Scanner in;
    BufferedWriter out;
    Map<Character, Character> map;

    SpeakTongues(String input, String output) throws Exception {
        in = new Scanner(new File(input));
        FileWriter fstream = new FileWriter(output);
        out = new BufferedWriter(fstream);
        map = new HashMap<Character, Character>();
    }
    
    public void preprocess() {
        map.put('a', 'y');map.put('b', 'h');map.put('c', 'e');map.put('d', 's');
        map.put('e', 'o');map.put('f', 'c');map.put('g', 'v');map.put('h', 'x');
        map.put('i', 'd');map.put('j', 'u');map.put('k', 'i');map.put('l', 'g');
        map.put('m', 'l');map.put('n', 'b');map.put('o', 'k');map.put('p', 'r');
        map.put('q', 'z');map.put('r', 't');map.put('s', 'n');map.put('t', 'w');
        map.put('u', 'j');map.put('v', 'p');map.put('w', 'f');map.put('x', 'm');
        map.put('y', 'a');map.put('z', 'q');
    }

    public void solveAll() throws IOException {
        int T = in.nextInt();
        in.nextLine();
        String line;

        for (int test = 1; test <= T; test++) {
            line = in.nextLine();
            out.write("Case #" + test + ": " + solve(line));
            out.newLine();
        }

    }

    public String solve(String line) {
        String newLine = "";
        for(String word : line.split(" ")) {
            String newWord = "";
            for(Character c : word.toCharArray()) {
                newWord = newWord + map.get(c);
            }
            if("".equals(newLine)) {
                newLine = newWord;
            } else {
                newLine = newLine + " " + newWord;
            }
        }
        return newLine;
    }

    public void close() throws IOException {
        in.close();
        out.close();
    }

    public static void main(String[] args) throws Exception {
        SpeakTongues pb = new SpeakTongues("input.txt", "output.txt");

        pb.preprocess();
        pb.solveAll();

        pb.close();
    }

    
}
