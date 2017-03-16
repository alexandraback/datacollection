/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlerese;

import java.io.File;
import java.util.HashMap;
import java.util.Scanner;

/**
 *
 * @author Serban
 */
public class Translator {

    HashMap<Character, Character> forward;
    HashMap<Character, Character> reverse;

    public Translator(String input, String output) {
        forward = new HashMap<Character, Character>();
        reverse = new HashMap<Character, Character>();

        forward.put('a', 'y');
        reverse.put('y', 'a');

        forward.put('o', 'e');
        reverse.put('e', 'o');

        forward.put('z', 'q');
        reverse.put('q', 'z');
        
        forward.put('q', 'z');
        reverse.put('z', 'q');
        
        forward.put(' ', ' ');
        reverse.put(' ', ' ');

        int T;
        try {
            Scanner scanIn = new Scanner(new File(input));
            Scanner scanOut = new Scanner(new File(output));
            T = scanIn.nextInt();
            scanIn.nextLine();
            for (int i = 0; i < T; i++) {
                String G = scanIn.nextLine();
                String S = scanOut.nextLine();
                for(int j=0;j<S.length();j++)
                    if(!forward.containsKey(S.charAt(j))) {
                        forward.put(S.charAt(j), G.charAt(j));
                        reverse.put(G.charAt(j), S.charAt(j));
                    }
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        
        System.out.println(reverse.get('z'));
    }
    
    public char translate(char c) {
        return reverse.get(c);
    }
}
