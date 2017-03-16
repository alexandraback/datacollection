import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

/**
 *
 */
public class FairAndSquare {
    private static final String TEST_FILE_NAME = "C-large-1";
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(TEST_FILE_NAME + ".in.txt"));
        BufferedWriter writer = new BufferedWriter(new FileWriter(TEST_FILE_NAME + ".out"));

        Integer index = Integer.valueOf(reader.readLine());
        System.out.println("index = " + index);
        long startTime = System.currentTimeMillis();

        for (int i = 1; i <= index; i++) {
            String[] endpointsStrTokens = reader.readLine().split(" ");

            Long a = new Long(endpointsStrTokens[0]);
            Long b = new Long(endpointsStrTokens[1]);

            String caseResult = "Case #" + i + ": " + countSquareAndFair(a, b);
            System.out.println(caseResult);
            writer.write(caseResult);
            writer.newLine();
        }

        System.out.println("Total time: " + (System.currentTimeMillis() - startTime));

        reader.close();
        writer.close();
    }

    private static long countSquareAndFair(long a, long b) {
        long amount = 0;
        for (long x = Math.round(Math.floor(Math.sqrt(a))); x <= Math.ceil(Math.sqrt(b)); x++) {
            if (isPalindrome(x)) {
                long pow = x * x;
                if (pow > b) {
                    break;
                }
                else if (pow >= a) {
                    if (isPalindrome(pow)) {
                        amount++;
                    }
                }
            }
        }
        return amount;
    }

    private static boolean isPalindrome(long number) {
        long temp = number;
        long reversed = 0;
        while (temp > 0) {
            long remainder = temp % 10;
            reversed = reversed * 10 + remainder;
            temp = temp / 10;
        }
        return reversed == number;
    }
}