package qual2013;

import java.io.File;
import java.io.FileReader;
import java.util.Scanner;

public class FairSquare {
    private final long A;
    private final long B;

    public FairSquare(long A, long B) {
        this.A = A;
        this.B = B;
    }

    public long answer() {
        long result = 0;
        long lowerLimit = (long) Math.ceil(Math.sqrt(A));
        long upperLimit = (long) Math.floor(Math.sqrt(B));
        for (long i = lowerLimit; i <= upperLimit; i++) {
            if (isPalindrome(i) && isPalindrome(i * i))
                result++;
        }
        return result;
    }

    private boolean isPalindrome(long number) {
        long reverse = 0;
        long n = number;
        while (number != 0) {
            long remain = number % 10;
            number = number / 10;
            reverse = reverse * 10 + remain;
        }
        return reverse == n;
    }

    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(new FileReader(new File(args[0])));
        long N = input.nextLong();

        for (long i = 1; i <= N; i++) {
            long a = input.nextLong();
            long b = input.nextLong();

            FairSquare fairSquare = new FairSquare(a, b);
            System.out.println("Case #" + i + ": " + fairSquare.answer());
        }
    }
}
