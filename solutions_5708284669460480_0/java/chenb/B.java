package CJ15.round1C;

import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: chenbin
 * Date: 5/10/15
 * Time: 5:53 PM
 * To change this template use File | Settings | File Templates.
 */
public class B {

    private int maximum;
    private int sum;

    private String keyboard;
    private String word;
    private int length;

    public static void main(String... args) {
        B b = new B();
        Scanner scanner = new Scanner(System.in);
        int caseNum = scanner.nextInt();
        for(int i=0; i< caseNum; i++) {

            b.maximum = 0;
            b.sum = 0;
            int K = scanner.nextInt();
            int L = scanner.nextInt();
            b.length = scanner.nextInt();

            b.keyboard = scanner.next();
            b.word = scanner.next();

            b.type(new StringBuilder());
            double answer = b.maximum - b.sum / Math.pow(b.keyboard.length(), b.length);
            System.out.println(String.format("Case #%d: %.7f", i + 1, answer));
        }
    }


    private void type(StringBuilder s) {
        if (s.length() == length) {
            int matchCount = matchCount(s.toString());
            maximum = Math.max(maximum, matchCount);
            sum += matchCount;
            return;
        }
        for (int i = 0; i < keyboard.length(); i++) {
            s.append(keyboard.charAt(i));
            type(s);
            s.deleteCharAt(s.length() - 1);
        }
    }

    private int matchCount(String s) {
        int answer = 0;
        int fromIndex = 0;
        while (s.indexOf(word, fromIndex) > -1) {
            fromIndex = s.indexOf(word, fromIndex) + 1;
            answer++;
        }
        return answer;
    }
}
