import java.util.Scanner;

public class B {

    public static int countFlips(char[] pancakes) {
        int flips = 0;
        char last = '+';
        for (int i = pancakes.length - 1; i >= 0; i--) {
            if (pancakes[i] != last) {
                last = pancakes[i];
                flips++;
            }
        }
        return flips;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int casesCount = scanner.nextInt();
        for (int i = 1; i <= casesCount; i++) {
            char[] pancakes = scanner.next().toCharArray();
            System.out.format("Case #%d: %s\n", i, countFlips(pancakes));
        }
    }
}
