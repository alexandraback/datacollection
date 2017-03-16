package round1b;


import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 * Created by Benedek on 4/30/2016.
 */
public class BA {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        in.nextLine();

        for (int t = 1; t <= T; t++) {
            String string = in.nextLine();
            string = string.toLowerCase();
            ArrayList<Integer> numbers = new ArrayList<>();
            if (string.contains("z")){
                int numberOfDigit = string.length() - string.replace("z", "").length();
                for (int i = 0; i < numberOfDigit; i++) {
                    numbers.add(0);
                    string = string.replaceFirst("z", "");
                    string = string.replaceFirst("e", "");
                    string = string.replaceFirst("r", "");
                    string = string.replaceFirst("o", "");
                }
            }
            if (string.contains("w")){
                int numberOfDigit = string.length() - string.replace("w", "").length();
                for (int i = 0; i < numberOfDigit; i++) {
                    numbers.add(2);
                    string = string.replaceFirst("t", "");
                    string = string.replaceFirst("w", "");
                    string = string.replaceFirst("o", "");
                }
            }
            if (string.contains("u")){
                int numberOfDigit = string.length() - string.replace("u", "").length();
                for (int i = 0; i < numberOfDigit; i++) {
                    numbers.add(4);
                    string = string.replaceFirst("f", "");
                    string = string.replaceFirst("o", "");
                    string = string.replaceFirst("u", "");
                    string = string.replaceFirst("r", "");
                }
            }
            if (string.contains("x")){
                int numberOfDigit = string.length() - string.replace("x", "").length();
                for (int i = 0; i < numberOfDigit; i++) {
                    numbers.add(6);
                    string = string.replaceFirst("s", "");
                    string = string.replaceFirst("i", "");
                    string = string.replaceFirst("x", "");
                }
            }
            if (string.contains("o")){
                int numberOfDigit = string.length() - string.replace("o", "").length();
                for (int i = 0; i < numberOfDigit; i++) {
                    numbers.add(1);
                    string = string.replaceFirst("o", "");
                    string = string.replaceFirst("n", "");
                    string = string.replaceFirst("e", "");
                }
            }
            if (string.contains("f")){
                int numberOfDigit = string.length() - string.replace("f", "").length();
                for (int i = 0; i < numberOfDigit; i++) {
                    numbers.add(5);
                    string = string.replaceFirst("f", "");
                    string = string.replaceFirst("i", "");
                    string = string.replaceFirst("v", "");
                    string = string.replaceFirst("e", "");
                }
            }
            if (string.contains("v")){
                int numberOfDigit = string.length() - string.replace("v", "").length();
                for (int i = 0; i < numberOfDigit; i++) {
                    numbers.add(7);
                    string = string.replaceFirst("s", "");
                    string = string.replaceFirst("e", "");
                    string = string.replaceFirst("v", "");
                    string = string.replaceFirst("e", "");
                    string = string.replaceFirst("n", "");
                }
            }
            if (string.contains("n")){
                int numberOfDigit = string.length() - string.replace("n", "").length();
                numberOfDigit /= 2;
                for (int i = 0; i < numberOfDigit; i++) {
                    numbers.add(9);
                    string = string.replaceFirst("n", "");
                    string = string.replaceFirst("i", "");
                    string = string.replaceFirst("n", "");
                    string = string.replaceFirst("e", "");
                }
            }
            if (string.contains("i")){
                int numberOfDigit = string.length() - string.replace("i", "").length();
                for (int i = 0; i < numberOfDigit; i++) {
                    numbers.add(8);
                    string = string.replaceFirst("e", "");
                    string = string.replaceFirst("i", "");
                    string = string.replaceFirst("g", "");
                    string = string.replaceFirst("h", "");
                    string = string.replaceFirst("t", "");
                }
            }
            int numberOfDigit = string.length() / 5;
            for (int i = 0; i < numberOfDigit; i++) {
                numbers.add(3);
                string = string.replaceFirst("t", "");
                string = string.replaceFirst("h", "");
                string = string.replaceFirst("r", "");
                string = string.replaceFirst("e", "");
                string = string.replaceFirst("e", "");
            }

            Collections.sort(numbers);

            System.out.printf("Case #%d: ", t);
            for (int i = 0; i < numbers.size(); i++) {
                System.out.print(numbers.get(i));
            }
            System.out.println();
        }
    }
}
