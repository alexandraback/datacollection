import java.util.Scanner;
import java.math.BigInteger;

class c {
    public static int getDivisor(BigInteger x) {
        for (int i = 2; i <= 100; i++) {
            if (x.mod(BigInteger.valueOf(i)) == BigInteger.ZERO) return i;
        }
        return 0;
    }
    public static void main(String args[]) {
        int N = 16, J = 50;
        System.out.println("Case #1:");
        BigInteger power10[] = new BigInteger[50];
        power10[0] = BigInteger.ONE;
        //int ten = 10;
        for (int i = 1; i < 50; i++) power10[i] = power10[i - 1].multiply(BigInteger.valueOf(10));
        for (int i = 0; i < (1 << (N - 2)); i++) {
            String number = "1";
            for (int j = 0; j < N - 2; j++) {
                if ((i & (1 << j)) > 0) number = number + "1";
                else number = number + "0";
            }
            number = number + "1";
            boolean fail = false;
            int divisor[] = new int[11];
            for (int base = 2; base <= 10; base++) {
                BigInteger tmp = new BigInteger(number, base);
                if (getDivisor(tmp) == 0) {
                    fail = true;
                    break;
                } else divisor[base] = getDivisor(tmp);
            }
            if (!fail) {
                J--;
                String out = number;
                for (int base = 2; base <= 10; base++) out = out + " " + String.valueOf(divisor[base]);
                System.out.println(out);
                if (J == 0) return;
            }
        }
        System.out.println("Warning!");
    }
};
