import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

import commons.FileUtilities;

public class Googlerese {
    
    private static HashMap<Character, Character> mapping = new HashMap<Character, Character>();
    
    public static void main(String[] args) throws IOException {

        String in = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv qz";
        String out = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up zq";
      
        for (int i = 0; i < in.length(); i++) {
            mapping.put(in.charAt(i), out.charAt(i));
        }
        
        List<String> input = FileUtilities.readFile(new File("A-small-attempt1.in"));
        int number = Integer.parseInt(input.get(0));
        
        List<String> result = new LinkedList<String>();
        
        for (int i = 1; i <= number; i++) {
            StringBuilder sb = new StringBuilder();
            for (char c : input.get(i).toCharArray()) {
                sb.append(mapping.get(c));
            }
            result.add(sb.toString());
        }
        
        FileUtilities.writeFile(result, new File("A-small-solution.out"));
    }

}
