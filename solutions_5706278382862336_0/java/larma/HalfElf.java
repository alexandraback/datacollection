import java.util.Scanner;

public class HalfElf {

    public static boolean isTwo(int x) {
        do {
            if (x % 2 == 1) return false;
            x /= 2;
        } while (x != 1);
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < n; i++) {
            String[] split = scanner.nextLine().split("/");
            int p = Integer.parseInt(split[0]);
            int q = Integer.parseInt(split[1]);
            System.out.printf("Case #%d: ", i + 1);
            test(p, q);
        }
    }

    public static void test(int p, int q) {
        int n = 1;
        int g = gcd(p, q);
        p /= g;
        q /= g;
        if (!isTwo(q)) {
            System.out.println("Impossible");
            return;
        }
        while (true) {
            int qn = q / 2;
            if (p >= qn) {
                System.out.println(n);
                return;
            } else {
                q = qn;
                n++;
            }
        }
    }

    public static int gcd(int p, int q) {
        while (q != 0) {
            int temp = q;
            q = p % q;
            p = temp;
        }
        return p;
    }
}
