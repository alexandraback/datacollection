package google.code.jam.oneA;

import java.io.IOException;
import java.util.LinkedList;
import java.util.Scanner;

public class TheLastWord {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int numTests = sc.nextInt();
        // Consume newline
        sc.nextLine();
        for (int numTest = 0; numTest < numTests; numTest++) {
            char[] inp = sc.nextLine().toCharArray();
            String answer = solve(inp);
            System.out.format("Case #%d: %s%n", numTest + 1, answer);
        }
    }

    private static String solve(char[] inp) {
        LinkedList<Character> answer = new LinkedList<>();
        char prev = inp[0];
        answer.push(prev);
        for (int i = 1; i < inp.length; i++) {
            char curr = inp[i];
            if (curr >= answer.peek()) {
                answer.push(curr);
            } else {
                answer.add(curr);
            }
            //System.out.println("\t" + toString(answer));
        }
        return toString(answer);
    }

    private static String toString(LinkedList<Character> list) {
        StringBuilder sb = new StringBuilder(list.size());
        for(Character ch: list) {
            sb.append(ch);
        }
        return sb.toString();
    }
}
