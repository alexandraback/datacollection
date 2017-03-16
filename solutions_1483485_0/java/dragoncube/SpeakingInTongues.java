import java.io.*;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class SpeakingInTongues {


    public static void main(String[] args) {
        new SpeakingInTongues().solve();
    }

    public SpeakingInTongues() {
        init();
    }

    private void init() {
        precache("ejp mysljylc kd kxveddknmc re jsicpdrysi",
                 "our language is impossible to understand");
        precache("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                 "there are twenty six factorial possibilities");
        precache("de kr kd eoya kw aej tysr re ujdr lkgc jv",
                 "so it is okay if you want to just give up");
        mapping.put('y', 'a');
        mapping.put('e', 'o');
        mapping.put('q', 'z');

        Collection<Character> values = mapping.values();
        String alphabet = "qwertyuioplkjhgfdsazxcvbnm";
        for (int i = 0; i < alphabet.length(); i++) {
            if (!values.contains(alphabet.charAt(i))) {
                mapping.put('z', alphabet.charAt(i));
            }
        }
    }

    Map<Character, Character> mapping = new TreeMap<Character, Character>();

    private void precache(String orig, String result) {
        for (int i = 0; i < orig.length(); i++) {
            mapping.put(orig.charAt(i), result.charAt(i));
        }
    }
    
    
    private String decode(String s) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            result.append(mapping.get(s.charAt(i)));
        }
        return result.toString();
    }

    private void solve() {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            int T = Integer.parseInt(reader.readLine());
            for (int i = 0; i < T; i++) {
                System.out.println("Case #" + (i+1)+ ": " + decode(reader.readLine()));
            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
