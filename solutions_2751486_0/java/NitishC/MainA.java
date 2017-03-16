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
            long output = 0;
            for (int i = n; i <= L; i++) {
                for (int j = 0; j + i <= L; j++) {
                    if (checkString(name.substring(j, j + i), n)) {
                        output++;
                    }
                }
            }
            System.out.println("Case #" + t + ": " + output);
        }
    }

    public static boolean checkString(String name, int n) {
        int c = 0;
        for (int i = 0; i < name.length(); i++) {
            char ch = name.charAt(i);
            if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
                c++;
                if (c == n) {
                    return true;
                }
            } else {
                c = 0;
            }
        }
        return false;
    }
}
