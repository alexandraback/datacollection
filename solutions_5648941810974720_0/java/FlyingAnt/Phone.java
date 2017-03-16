import java.util.Scanner;

public class Phone {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        for (int kase = 1, kases = scanner.nextInt(); kase <= kases; kase++) {
            String ss = "";
            while (ss.isEmpty()) {
                ss = scanner.nextLine();
            }
            int[] s = new int[26];
            int[] count = new int[10];

            for (char c : ss.toCharArray()) {
                s[ind(c)]++;
            }

            // ZERO
            while (s[ind('Z')] > 0) {
                count[0]++;
                remove("ZERO", s);
            }

            // SIX
            while (s[ind('X')] > 0) {
                count[6]++;
                remove("SIX", s);
            }

            // EIGHT
            while (s[ind('G')] > 0) {
                count[8]++;
                remove("EIGHT", s);
            }

            // FOUR
            while (s[ind('U')] > 0) {
                count[4]++;
                remove("FOUR", s);
            }

            // THREE
            while (s[ind('H')] > 0) {
                count[3]++;
                remove("THREE", s);
            }

            // TWO
            while (s[ind('W')] > 0) {
                count[2]++;
                remove("TWO", s);
            }

            // ONE
            while (s[ind('O')] > 0) {
                count[1]++;
                remove("ONE", s);
            }

            // FIVE
            while (s[ind('F')] > 0) {
                count[5]++;
                remove("FIVE", s);
            }

            // SEVEN
            while (s[ind('V')] > 0) {
                count[7]++;
                remove("SEVEN", s);
            }

            // NINE
            while (s[ind('E')] > 0) {
                count[9]++;
                remove("NINE", s);
            }

            String ans = "";
            for (int i = 0; i < 10; i++) {
                while (count[i] > 0) {
                    count[i]--;
                    ans += "" + i;
                }
            }
            System.out.println("Case #" + kase + ": " + ans);
        }
    }

    private static void remove(String number, int[] s) {
        for (char c : number.toCharArray()) {
            s[ind(c)]--;
        }
    }

    private static int ind(char c) {
        return c - 'A';
    }
}
