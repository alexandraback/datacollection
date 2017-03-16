/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication5;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.Map;

/**
 *
 * @author ucho
 */
public class JavaApplication5 {
    static final String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".toLowerCase();
    Map<Character, Character> gg2en = new HashMap<Character, Character>();
    public JavaApplication5() throws FileNotFoundException, IOException {
        
        feed("our language is impossible to understand", "ejp mysljylc kd kxveddknmc re jsicpdrysi");
        feed("there are twenty six factorial possibilities", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
        feed("so it is okay if you want to just give up", "de kr kd eoya kw aej tysr re ujdr lkgc jv");
        feed("aozq", "yeqz"); //'a' -> 'y', 'o' -> 'e', and 'z' -> 'q'.
        PrintWriter writer = new PrintWriter(new FileWriter("output"));
        BufferedReader reader = new BufferedReader(new FileReader("input"));
        int count = Integer.parseInt(reader.readLine());
        for (int i = 0; i < count; i++) {
            String msg = "Case #"+(i+1)+": "+translate(reader.readLine());
            System.out.println(msg);
            writer.println(msg);
        }
        writer.close();
    }
    
    



/**
Output
Case #1: 
Case #2: 
Case #3: 
*/
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        new JavaApplication5();
    }

    private String translate(String input) {        
        StringBuilder sb = new StringBuilder();
        for (Character c : new CharacterIterator(input)) {
            if (c.equals(' ') || c.equals('\n')) {
                sb.append(c);
            } else {
                sb.append(gg2en.get(c));
            }
        }
        return sb.toString();
    }

    static class Mapping {

        public String en;
        public String gg;
    }

    class CharacterIterator implements Iterable<Character> {

        private final String str;
        private int pos = 0;

        public CharacterIterator(String str) {
            this.str = str;
        }

        @Override
        public Iterator<Character> iterator() {
            return new Iterator<Character>() {

                @Override
                public boolean hasNext() {
                    return pos < str.length();
                }

                public Character next() {
                    return str.charAt(pos++);
                }

                @Override
                public void remove() {
                    throw new UnsupportedOperationException("Not supported yet.");
                }
            };
        }
    }
    
    public static class CharWithCount {

        public CharWithCount(Character chr, int count) {
            this.chr = chr;
            this.count = count;
        }
        
        public Character chr;
        public int count;        
    }
    
    void feed(String clear, String cypher) {
        for(int i=0;i<clear.length();i++) {
            gg2en.put(cypher.charAt(i), clear.charAt(i));
        }
    }
}
