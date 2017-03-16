package ch.socaciu.andrei.codejam;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author Andrei Socaciu
 */
public class Tongues {

    private static final Map<Character, Character> mapping = new HashMap<Character, Character>();

    static {
        mapping.put('y', 'a');
        mapping.put('n', 'b');
        mapping.put('f', 'c');
        mapping.put('i', 'd');
        mapping.put('c', 'e');
        mapping.put('w', 'f');
        mapping.put('l', 'g');
        mapping.put('b', 'h');
        mapping.put('k', 'i');
        mapping.put('u', 'j');
        mapping.put('o', 'k');
        mapping.put('m', 'l');
        mapping.put('x', 'm');
        mapping.put('s', 'n');
        mapping.put('e', 'o');
        mapping.put('v', 'p');
        mapping.put('z', 'q');
        mapping.put('p', 'r');
        mapping.put('d', 's');
        mapping.put('r', 't');
        mapping.put('j', 'u');
        mapping.put('g', 'v');
        mapping.put('t', 'w');
        mapping.put('h', 'x');
        mapping.put('a', 'y');
        mapping.put('q', 'z');
    }


    public static void main(String[] args) throws Exception {
        String in = "data/Tongues-small-attempt0.in.txt";
        String out = "data/Tongues-small-attempt0.out.txt";
        String line = null;
        BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(in)));
        List<String> lines = new ArrayList<String>();
        while ((line = reader.readLine()) != null) {
            lines.add(line);
        }
        reader.close();
        int tests = Integer.parseInt(lines.get(0));
        List<String> res = new ArrayList<String>();
        int k = 1;
        for (int i = 1; i <= tests; i++) {
            String message = lines.get(k++);
            String result = translate(message);
            res.add("Case #" + i + ": " + result);
        }
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(out)));
        for (String re : res) {
            writer.write(re);
            writer.write("\n");
        }
        writer.close();
    }

    private static String translate(String message) {
        StringBuilder sb = new StringBuilder(message);
        for (int i = 0; i < sb.length(); i++) {
            if (sb.charAt(i) != ' ') {
                sb.setCharAt(i, mapping.get(sb.charAt(i)));
            }
        }
        return sb.toString();
    }


}
