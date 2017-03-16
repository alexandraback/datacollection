
package codejam2026.round1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author Dean
 */
public class OneA {
        public static void main(String args[]) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(reader.readLine().trim());
        for (int i = 0; i < cases; i++) {
            String line = reader.readLine().trim();
            System.out.println(String.format("Case #%d: %s", (i+1), getNumber(line)));
        }
    }
        
        public static String getNumber(String line) {
            char chars[] = line.toCharArray();
            int z = 0;
            int w = 0;
            int u = 0;
            int x = 0;
            int s = 0;
            int g = 0;
            int f = 0;
            int is = 0;
            int h = 0;
            int o = 0;
            
            for (int i = 0; i < chars.length; i++) {
                if (chars[i] == 'Z') {
                    z++;
                }
                else if (chars[i] == 'W') {
                    w++;
                }
                                else if (chars[i] == 'U') {
                    u++;
                }
                                                else if (chars[i] == 'X') {
                    x++;
                }
                                                else if (chars[i] == 'S') {
                    s++;
                }
                                                                else if (chars[i] == 'G') {
                    g++;
                }
                                                                                else if (chars[i] == 'F') {
                    f++;
                }
                                                                                                else if (chars[i] == 'I') {
                    is++;
                }
                                                                                                                else if (chars[i] == 'H') {
                    h++;
                }
                                                                                                                                else if (chars[i] == 'O') {
                    o++;
                }
            }
            int zero = z;
            int two = w;
            int four = u;
            int five = f - four;
            int six = x;

            int eight = g;
                        int seven = s - six;
            int nine = is - five - six - eight;
            int three = h - eight;
            int one = o - zero - two - four;
            int nums[] = new int[]{zero, one, two, three, four, five, six, seven, eight, nine};
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < nums.length; i++) {
                for (int j = 0; j < nums[i]; j++) {
                    builder.append(i);
                }
            }
            return builder.toString();
        }
}
