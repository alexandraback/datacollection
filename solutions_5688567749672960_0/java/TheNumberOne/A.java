package rounds.round1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;

public class A {

    int input;

    static Scanner in;
    static PrintStream out;

    public static void main(String[] args) throws FileNotFoundException {
        out = new PrintStream("out.txt");
        in = new Scanner(new File(args[0]));

        int N = in.nextInt();
        in.nextLine();

        for (int i = 0; i < N; i++) {
            runTestCase(i + 1);
        }
    }

    private static void runTestCase(int id) {
        int input = in.nextInt();
        int solution = new A(input).solve();
        out.printf("Case #%d: %d\n", id, solution);
    }

    public A(int input) {
        this.input = input;
    }

    int solve() {
        Integer[] digits = digits(input).toArray(new Integer[0]);
        if (digits.length == 1){
            return digits[0];
        }
        int length = 0;
        int cost = 0;
        int a = 0;
        while (length < digits.length){
            length++;
            if (length == 1){
                a = 1;
            } else if (length == 2){
                a = 9;
            } else {
                a += 10;
            }
            cost += a;
        }
        boolean specialCase = digits[0] != 1 && digits.length > 1;
        for (int i = 1; i < digits.length; i++) {
            specialCase &= digits[i]==0;
        }
        if (specialCase) {
            cost += digits[0] - 1;
            cost += 10 * (digits.length - 1);
        } else {
            for (int i = 0; i < digits.length; i++) {
                if (digits[i] == 0) {
                    continue;
                }
                if (i == 0) {
                    if (digits[i] > 1) {
                        cost += digits[i];
                    }
                    continue;
                }
                if (i == digits.length - 1) {
                    cost += digits[i];
                    continue;
                }
                cost += digits[i] + 1;
            }
        }
        return cost;
    }

    List<Integer> digits(int i) {
        List<Integer> digits = new ArrayList<Integer>();
        while(i > 0) {
            digits.add(0, i % 10);
            i /= 10;
        }
        return digits;
    }

}