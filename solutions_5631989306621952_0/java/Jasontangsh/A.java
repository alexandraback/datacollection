package GoogleR1A;

import java.util.Scanner;

/**
 * Created by Jason on 4/15/2016.
 */
public class A {

    public static void main(String args[]) {
        Scanner reader = new Scanner(System.in);
        int T = reader.nextInt();
        for (int i = 0; i < T; i++) {
            String s = reader.next();
            StringBuilder answer = new StringBuilder();
            answer.append(s.charAt(0));
            s = s.substring(1);
            for (char c : s.toCharArray()) {
                if (answer.charAt(0) > c) {
                    answer.append(c);
                } else {
                    answer.insert(0, c);
                }
            }
            System.out.println("Case #" + (i+1) + ": " + answer);
        }
    }

}
