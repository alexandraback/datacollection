import java.util.*;

public class B {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        for (int thisNum = 1; thisNum <= numCases; thisNum++) {
            String pancakes = in.next();
            pancakes = removeDups(pancakes);
            int count = 0;
            if (pancakes.charAt(pancakes.length() - 1) == '-')
                count = pancakes.length();
            else
                count = pancakes.length() - 1;

            // Print results
            System.out.format("Case #%d: %d\n", thisNum, count);
        }
    }

    // Condense duplicates
    private static String removeDups(String pancakes) {
        String update = pancakes;
        do {
            pancakes = update;
            update = update.replace("++", "+");
            update = update.replace("--", "-");
        } while
                (pancakes.length() != update.length() && update.length() > 1);
        return update;
    }

}
