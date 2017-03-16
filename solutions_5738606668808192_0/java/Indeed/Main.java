import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    private static String repeat(String s, int times) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0 ; i < times ; ++i)
            sb.append(s);
        return sb.toString();
    }
    public static void main(String[] args) {
        System.out.println("Case #1:");
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        for (int i = 3, cnt = 0 ; cnt < m ; i += 2, ++cnt) {
            BigInteger bin = BigInteger.valueOf(i);
            String comp = bin.toString(2);
            int padding = n - comp.length() * 2;
            String s = comp + repeat("0" , padding) + comp;
            String line = s;
            for (int base = 2 ; base <= 10 ; ++ base) {
                long j = Long.parseLong(s, base);
                long k = Long.parseLong(comp, base);
                if (j % k != 0) {
                    System.err.println(s +  " " + k);
                    throw new RuntimeException();
                }
                line = line + " " + k;
            }
            System.out.println(line.trim());
        }
    }
}

