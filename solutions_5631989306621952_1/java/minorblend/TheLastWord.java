import java.util.*;

public class TheLastWord {
    static String find(String input) {
        StringBuilder word = new StringBuilder();
        for (char letter: input.toCharArray()) {
            if (word.length() == 0) {
                word.append(letter);
                continue;
            }

            char firstLetter = word.charAt(0);
            if (letter >= firstLetter) {
                word.insert(0, letter);
            } else {
                word.append(letter);
            }
        }

        return word.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < t; i++) {
            String string = sc.nextLine();
            System.out.printf("Case #%d: %s\n", i + 1, find(string));
        }
    }
}
