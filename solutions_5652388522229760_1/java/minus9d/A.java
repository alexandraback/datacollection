import java.util.Scanner;
import java.util.HashSet;
import java.util.ArrayList;

public class A {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int T = sc.nextInt();
        for(int t = 1; t <= T; ++t) {
            System.out.printf("Case #" + t + ": ");
            Long n = sc.nextLong();
            solve(n);
        }
    }

    private static void solve(Long n) {
        if (n == 0) {
            System.out.println("INSOMNIA");
            return;
        }

        HashSet<Character> seen = new HashSet<Character>();  // can't compile
        Long cnt = 1L;
        while(true) {
            Long val = n * cnt;
            String val_s = String.valueOf(val);
            for(char ch : val_s.toCharArray()) {
                seen.add(ch);
            }

            if (seen.size() == 10) {
                System.out.println(val_s);
                break;
            }
            cnt++;
        }
    }
}
