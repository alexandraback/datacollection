package google.code.jam.round1b;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by chen on 4/15/16.
 */
public class A {

    public static String[] caps = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new FileReader("A.in"));
        PrintWriter out = new PrintWriter(new FileWriter("A.out"));

        int T = Integer.parseInt(in.readLine());

        for (int k = 1; k <= T; k ++) {
            String line = in.readLine();
            Map<Character, Integer> map = new HashMap<>();
            for (char a = 'A'; a <= 'Z'; a ++) {
                map.put(a, 0);
            }

            for (int i = 0; i < line.length(); ++ i) {
                char ch = line.charAt(i);
                if (map.containsKey(ch)) {
                    map.put(ch, map.get(ch) + 1);
                }
                else {
                    map.put(ch, 1);
                }
            }

            int[] ans = new int[10];

            ans[0] = map.get('Z');
            ans[1] = map.get('O') - map.get('Z') - map.get('W') - map.get('U');
            ans[2] = map.get('W');
            ans[3] = map.get('H') - map.get('G');
            ans[4] = map.get('U');
            ans[5] = map.get('F') - map.get('U');
            ans[6] = map.get('X');
            ans[7] = map.get('S') - map.get('X');
            ans[8] = map.get('G');
            ans[9] = map.get('I') - map.get('X') - map.get('G') - map.get('F') + map.get('U');

            String st = "";

            for (int i = 0; i < 10; ++ i) {
                for (int j = 0; j < ans[i]; ++ j) {
                    st += i;
                }
            }

            out.printf("Case #%d: %s\n", k, st);
        }

        in.close();
        out.close();
    }
}
