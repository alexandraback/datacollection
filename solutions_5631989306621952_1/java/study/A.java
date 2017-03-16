import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 * Created by study on 4/15/16.
 */
public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();
        for (int i = 1; i <= T; i++) {
            System.out.print(String.format("Case #%d: ", i));
            solve(scanner);
        }
    }

    public static void solve(Scanner scanner) {
        String S = scanner.next();

        List<String> words = new ArrayList<>(10);

        Character c = S.charAt(0);
        words.add(c.toString());

        for (int i = 1; i < S.length(); i++) {
            c = S.charAt(i);
            int size = words.size();
            for (int j = 0; j < size; j++) {
                String word = words.get(j);

                String a = word + c;
                String b = c + word;
                if(a.compareTo(b) > 0) {
                    words.set(j, a);
                } else {
                    words.set(j, b);
                }
            }
        }

        Collections.sort(words);

        System.out.println(words.get(words.size() - 1));
    }
}
