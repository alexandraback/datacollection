import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class TheLastWord {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new FileReader("smallA.in"));
        PrintStream out = new PrintStream(new FileOutputStream("A.out"));
        int T = scanner.nextInt();
        scanner.nextLine();
        for (int t = 1; t <= T; t++) {
            String S = scanner.nextLine();
            Deque<Character> chars = new LinkedList<>();
            for (char c : S.toCharArray()) {
                char front = chars.isEmpty() ? 'A' : chars.peekFirst();
                if (c < front) chars.addLast(c);
                else chars.addFirst(c);
            }
            StringBuilder sb = new StringBuilder();
            for (char c : chars) sb.append(c);
            out.println("Case #" + t + ": " + sb);
        }
    }
}
