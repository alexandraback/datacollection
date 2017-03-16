import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Google Code Jam 2012
 * 
 * @author 7henick
 */
public class ProblemA {

    public static void main(String[] args) {

        // Create the map from the example
        String a = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv qz";
        String b = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up zq";
        Map<Character, Character> map = new HashMap<Character, Character>();
        for (int i = 0; i < a.length(); i++) {
            Character ca = a.charAt(i);
            if (ca == ' ') {
                continue;
            }
            Character cb = b.charAt(i);
            map.put(ca, cb);
        }

        // start reading input
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < T; i++) {
            String line = sc.nextLine();

            String output = "";

            for (int j = 0; j < line.length(); j++) {
                char c = line.charAt(j);
                if (c == ' ') {
                    output += ' ';
                } else {
                    output += map.get(c);
                }
            }
            System.out.println("Case #" + (i + 1) + ": " + output);
        }
    }
}
