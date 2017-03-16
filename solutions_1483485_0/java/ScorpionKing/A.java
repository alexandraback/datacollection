package google.codejam;

import java.io.BufferedReader;

import java.io.BufferedWriter;
import java.io.FileReader;

import java.io.FileWriter;

import java.util.HashMap;
import java.util.Map;

public class Problem1 {
    public Problem1() {
        super();
    }
    
    private static Map<Character, Character> map = new HashMap<Character, Character>();
    static {
    map.put('a','y');
    map.put('b','h');
    map.put('c','e');
    map.put('d','s');
    map.put('e','o');
    map.put('f','c');
    map.put('g','v');
    map.put('h','x');
    map.put('i','d');
    map.put('j','u');
    map.put('k','i');
    map.put('l','g');
    map.put('m','l');
    map.put('n','b');
    map.put('o','k');
    map.put('p','r');
    map.put('q','z');
    map.put('r','t');
    map.put('s','n');
    map.put('t','w');
    map.put('u','j');
    map.put('v','p');
    map.put('w','f');
    map.put('x','m');
    map.put('y','a');
    map.put('z','q');
    map.put(' ',' ');
    }
    
    private static String convert(String input) {
        StringBuilder sb = new StringBuilder();
        for(int i =0 ; i<input.length();i++)
            sb.append(map.get(input.charAt(i)));
        return sb.toString();
    }
    
    public static void main(String[] args) {
        try {
        BufferedReader reader = new BufferedReader(new FileReader("D:\\codejam\\2012\\input.in"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("D:\\codejam\\2012\\A-small.out"));

                //... Loop as long as there are input lines.
                String line = null;
            reader.readLine();
            int i=1;
                while ((line=reader.readLine()) != null) {
                    writer.write("Case #"+i+": "+convert(line));
                    writer.newLine();   // Write system dependent end of line.
                    i++;
                }

                //... Close reader and writer.
                reader.close();  // Close to unlock.
                writer.close();  // Close to unlock and flush to disk.

    }
        catch(Exception ex) {
            ex.printStackTrace();
        }
    }
}
