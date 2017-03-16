import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by wagner on 04/16/16.
 */
public class TheLastWord {
    public static void main(String[] args) throws FileNotFoundException {
        File file = new File(args[0]);
        Scanner scanner = new Scanner(file);
        long nCases = scanner.nextLong();
        scanner.nextLine();
        for (int i = 1; i <= nCases; i++) {
            String word = scanner.nextLine();
            Character headChar = null;
            List<Character> output = new LinkedList<Character>();
            for(int j = 0; j < word.length(); j++) {
                char current = word.charAt(j);
                if(headChar == null || headChar.compareTo(current) <= 0) {
                    headChar = current;
                    output.add(0, current);
                } else {
                    output.add(current);
                }
            }
            StringBuilder sb = new StringBuilder();
            output.stream().forEach(c -> sb.append(c));
            System.out.println("Case #" + i + ": " + sb.toString());
        }
    }
}
