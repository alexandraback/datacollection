package codejam.y2016.round1.subroundB;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * @author Max Myslyvtsev
 * @since 4/30/16
 */
public class A {

    public static void main(String[] args) throws Exception {
        //Scanner in = new Scanner(new FileInputStream("/Users/max/Work/Source/foobar/src/main/resources/input.txt"));
        Scanner in = new Scanner(new FileInputStream("/Users/max/Downloads/A-large.in"));
        PrintStream out = new PrintStream(new FileOutputStream("/Users/max/Work/Source/foobar/src/main/resources/output.txt"));
        int T = in.nextInt();
        in.nextLine();
        for (int t = 1; t <= T; t++) {
            String s = in.nextLine();
            String a = solve(s);
            String answ = "Case #" + t + ": " + a;
            out.println(answ);
            System.out.println(answ);
        }
    }

    private static String solve(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) {
            Integer count = map.get(c);
            if (count == null) {
                count = 0;
            }
            count++;
            map.put(c, count);
        }
        int[] ans = new int[10];

        // Single witness
        while (map.containsKey('Z')) {
            pickChars(map, 'Z', 'E', 'R', 'O');
            ans[0]++;
        }
        while (map.containsKey('W')) {
            pickChars(map, 'T', 'W', 'O');
            ans[2]++;
        }
        while (map.containsKey('U')) {
            pickChars(map, 'F', 'O', 'U', 'R');
            ans[4]++;
        }
        while (map.containsKey('X')) {
            pickChars(map, 'S', 'I', 'X');
            ans[6]++;
        }
        while (map.containsKey('G')) {
            pickChars(map, 'E', 'I', 'G', 'H', 'T');
            ans[8]++;
        }

        // O with 0,2,4 is removed, so it is single witness for 1
        while (map.containsKey('O')) {
            pickChars(map, 'O', 'N', 'E');
            ans[1]++;
        }

        // F with 4 is removed, so it is single witness for 5
        while (map.containsKey('F')) {
            pickChars(map, 'F', 'I', 'V', 'E');
            ans[5]++;
        }

        // I with 6,8,5 is removed, so it is single witness for 9
        while (map.containsKey('I')) {
            pickChars(map, 'N', 'I', 'N', 'E');
            ans[9]++;
        }

        // V with 5 is removed, so it is single witness for 7
        while (map.containsKey('V')) {
            pickChars(map, 'S', 'E', 'V', 'E', 'N');
            ans[7]++;
        }

        // 3 is left
        while (!map.isEmpty()) {
            pickChars(map, 'T', 'H', 'R', 'E', 'E');
            ans[3]++;
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 10; i++) {
            char c = (char)('0' + i);
            for (int j = 0; j < ans[i]; j++) {
                sb.append(c);
            }
        }
        return sb.toString();
    }

    static void pickChars(Map<Character, Integer> map, char ...chars) {
        for (char c : chars) {
            pickChar(map, c);
        }
    }

    static void pickChar(Map<Character, Integer> map, char c) {
        Integer count = map.get(c);
        count--;
        if (count == 0) {
            map.remove(c);
        } else {
            map.put(c, count);
        }
    }
}
