import java.util.*;
import java.io.*;
public class LastWord {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt();    // Scanner has functions to read ints, longs, strings, chars, etc.
        for (int i = 1; i <= t; ++i) {
            String s = in.next();

            char max = s.charAt(0);

            Deque<Character> deque = new LinkedList<Character>();
            deque.addFirst(max);

            for (int j = 1; j < s.length(); j++) {
                char c = s.charAt(j);
                if (c >= max) {
                    deque.addFirst(c);
                    max = c;
                } else {
                    deque.addLast(c);
                }
            }

            String res = "";

            while(deque.size() > 0) {
                res += String.valueOf(deque.removeFirst());
            }
            System.out.println("Case #" + i + ": " + res);
        }
    }
}