
import java.util.Scanner;

public class CloseMatch {
    
    static boolean valid(String s, int a) {
        for (int i = s.length() - 1; i >= 0; i--) {
            int b = a % 10;
            a /= 10;
            if (s.charAt(i) != '?' && s.charAt(i) != (char) (b + '0')) {
                return false;
            } 
        }
        return true;
    }
    
    static String best(String s1, String s2) {
        int a = -10000;
        int b = 10000;
        int limit;
        if (s1.length() == 1) {
            limit = 9;
        } else if (s1.length() == 2) {
            limit = 99;
        } else {
            limit = 999;
        }
        for (int i = 0; i <= limit; i++) {
            if (valid(s1, i)) {
                for (int j = 0; j <= limit; j++) {
                    if (valid(s2, j)) {
                        if (Math.abs(i - j) < Math.abs(a - b)) {
                            a = i;
                            b = j;
                        }
                    }
                }
            }
        }
        String r1 = Integer.toString(a);
        String r2 = Integer.toString(b);
        while (r1.length() < s1.length()) {
            r1 = "0" + r1;
        }
        while (r2.length() < s2.length()) {
            r2 = "0" + r2;
        }
        return r1 + " " + r2;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            String s1 = sc.next();
            String s2 = sc.next();
            System.out.println("Case #" + i + ": " + best(s1, s2));
        }
    }
    
}
