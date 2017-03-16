package codejam;

import java.util.Scanner;

public class C {

    public static void main(String... args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        System.out.println("Case #" + T + ":");

        int N = scanner.nextInt();
        int J = scanner.nextInt();

        int j = 0;
        long jamcoin = (1L << (N - 1)) + 1;

        while (j < J) {
            if (valid(jamcoin)) {
                String s = Long.toString(jamcoin, 2);
                System.out.println(s + " 3 2 3 2 7 2 3 2 3");
                j++;
            }
            jamcoin += 2;
        }
    }

    private static boolean valid(long j) {
        String s = Long.toString(j, 2);
        int a = 0;
        int b = 0;
        for (int i = 0; i < s.length(); i++) {
            int d = Integer.valueOf(s.charAt(i) + "");
            a += d;
            if (i % 2 == 0) {
                b += d;
            } else {
                b -= d;
            }
        }
        return a % 6 == 0 && b == 0;
    }
}
