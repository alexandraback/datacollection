
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();

        for (int t = 1; t <= T; ++t) {
            String s = in.next();
            Map<Character, Integer> cnt = new HashMap<>();
            char[] letters = new char[] {'E', 'G', 'F', 'I', 'H', 'O', 'N', 'S', 'R', 'U', 'T', 'W', 'V', 'X', 'Z'};
            for (char letter : letters) cnt.put(letter, 0);
            for (int i = 0; i < s.length(); ++i) {
                cnt.put(s.charAt(i), cnt.get(s.charAt(i)) + 1);
            }
            int[] res = new int[10];

            String[] d = new String[] {"ZERO", "ONE", "TWO", "THREE", "FOUR",
                    "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
            char[] uniq = new char[] {'Z', 'O', 'W', 'T', 'U', 'F', 'X', 'S', 'G'};

            for (int i = 0; i < 9; i += 2) {
                res[i] = cnt.get(uniq[i]);
                for (int j = 0; j < res[i]; ++j) {
                    for (int k = 0; k < d[i].length(); ++k) {
                        cnt.put(d[i].charAt(k), cnt.get(d[i].charAt(k)) - 1);
                    }
                }
            }

            for (int i = 1; i < 9; i += 2) {
                res[i] = cnt.get(uniq[i]);
                for (int j = 0; j < res[i]; ++j) {
                    for (int k = 0; k < d[i].length(); ++k) {
                        cnt.put(d[i].charAt(k), cnt.get(d[i].charAt(k)) - 1);
                    }
                }
            }
            res[9] = cnt.get('E');

            StringBuilder resStr = new StringBuilder();
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < res[i]; ++j) {
                    resStr.append(i);
                }
            }

            System.out.println("Case #" + t + ": " + resStr);
        }
    }
}
