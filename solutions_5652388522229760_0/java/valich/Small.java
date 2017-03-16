package A;

import org.junit.Assert;
import org.junit.Test;

import java.util.Scanner;

public class Small {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            final int testsNum = in.nextInt();
            for (int i = 0; i < testsNum; i++) {
                System.out.println("Case #" + (i + 1) + ": " + solve(in.nextInt()));
            }
        }
    }
    
    @Test
    public void rands() {
//        final Random random = new Random();
        for (int i = 0; i <= 1000000; ++i) {
            solve(i);
        }
    }

    private static String solve(int N) {
        if (N == 0) {
            return "INSOMNIA";
        }
        
        
        int was = 0;
        for (int i = 1;; i++) {
            int C = N * i;
            final String s = String.valueOf(C);
            for (int j = 0; j < s.length(); ++j) {
                was |= 1 << s.charAt(j) - '0';
            }
            Assert.assertTrue(C > 0);
            if (was == (1 << 10)-1) {
                return s;
            }
        }
    }
}
