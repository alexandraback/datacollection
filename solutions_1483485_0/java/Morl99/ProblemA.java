package codejam.morl99.a;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

public class ProblemA {
    
    /**
     * Maps Googlerese characters to real language
     */
    HashMap<Character, Character> mapping = new HashMap<>();
    
    public void setUpHashMap() {
        mapping.put('y','a');
        mapping.put('e','o');
        mapping.put('q','z');
        addLineToMap("ejp mysljylc kd kxveddknmc re jsicpdrysi","our language is impossible to understand");
        addLineToMap("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","there are twenty six factorial possibilities");
        addLineToMap("de kr kd eoya kw aej tysr re ujdr lkgc jv","so it is okay if you want to just give up");
        
       System.out.println(mapping.size());
    }
    
    public void addLineToMap(String googlerese, String english){
        char[] g = googlerese.toCharArray();
        char[] e = english.toCharArray();
        assert g.length == e.length;
        for (int i = 0; i < g.length; i++) {
            Character c = mapping.put(g[i], e[i]);
            if (c != null && !c.equals(e[i])) {
                assert false : "Remapping different Character";
            }
        }
    }
    
    public String lineToEnglish (String googlerese) {
        char[] g = googlerese.toCharArray();
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < g.length; i++) {
            s.append(mapping.get(g[i]));
        }
        
        return s.toString();
    }
    
    public void solveSet(PrintWriter pw, BufferedReader reader) throws IOException {

        String firstLine = reader.readLine();
        Scanner scanner = new Scanner(firstLine);
        scanner.useDelimiter(" ");
        int l = scanner.nextInt();
        
        for (int i = 1; i <= l; i++) {
            String solution = lineToEnglish(reader.readLine());
            pw.printf("Case #%d: %s",i,solution);
            pw.println();
        }
        
    }
    
    public void findMissingChar() {
        char g = 0;
        char e = 0;
        for (char c = 'a'; c <= 'z';c++ ) {
            if (!mapping.containsKey(c)) {
                System.out.println("Missing Googlerese Letter is: " + String.valueOf(c));
                g = c;
            }
            if (!mapping.containsValue(c)) {
                System.out.println("Missing English Letter is: " + String.valueOf(c));
                e = c;
            }
            
            
        }
        
        if (g > 0 && e > 0) {
            mapping.put(g, e);
        } else {
            assert false : "missing Character not found";
        }
    }
    
    public static void main(String[] args) throws IOException {
        ProblemA p = new ProblemA();
        
        p.setUpHashMap();
        p.findMissingChar();
        
        
        OutputStream output = new FileOutputStream("res/A.out", false);
        PrintWriter pw = new PrintWriter(output);
        BufferedReader reader = new BufferedReader(new FileReader("res/A-small-attempt1.in"));
        p.solveSet(pw, reader);
        pw.close();
        reader.close();
        
        
    }
    
}
