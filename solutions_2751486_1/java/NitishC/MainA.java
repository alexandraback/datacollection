import java.util.Scanner;

public class MainA {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();
        for (int t = 1; t <= T; t++) {
            String name = sc.next();
            int L = name.length();
            int n = sc.nextInt();
            sc.nextLine();
            long output = checkString(name, n);
            System.out.println("Case #" + t + ": " + output);
        }
    }

    public static long checkString(String name, int n) {
        int c = 0;
        int L = name.length();
        int i;
        for (i = 0; i < L; i++) {
            char ch = name.charAt(i);
            if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
                c++;
                if (c == n) {
                    break;
                }
            } else {
                c = 0;
            }
        }
        if (i == L)
            return 0;
        int cb = i - n + 1;
        int cb1 = cb;
        int ca = L - i - 1;
        int count = 1;
        while (cb1 >= 0) {
            count += ca;
            cb1--;
            if (cb1 >= 0) {
                count++;
            }
        }
        if (L - cb > n)
            return count + checkString(name.substring(cb + 1, L), n);
        return count;
    }
}
