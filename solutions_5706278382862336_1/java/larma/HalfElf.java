import java.util.Scanner;

public class HalfElf {

    public static boolean isTwo(long x) {
        do {
            if (x % 2 == 1) return false;
            x /= 2;
        } while (x != 1);
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < n; i++) {
            String[] split = scanner.nextLine().split("/");
            long p = Long.parseLong(split[0]);
            long q = Long.parseLong(split[1]);
            System.out.printf("Case #%d: ", i + 1);
            test(p, q);
        }
    }

    public static void test(long p, long q) {
        long n = 1;
        long g = gcd(p, q);
        p /= g;
        q /= g;
        if (!isTwo(q)) {
            System.out.println("Impossible");
            return;
        }
        while (true) {
            long qn = q / 2;
            if (p >= qn) {
                System.out.println(n);
                return;
            } else {
                q = qn;
                n++;
            }
        }
    }

    public static long gcd(long p, long q) {
        while (q != 0) {
            long temp = q;
            q = p % q;
            p = temp;
        }
        return p;
    }
}
