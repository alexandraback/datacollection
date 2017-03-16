import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class B2 {
    public static String leftPad(String s2, int len) {
        while (s2.length() < len) {
            s2 = "0"+s2; 
        }
        return s2;
    }
    public static boolean match(String s, int x) {
        String s2 = "" + x;
        s2 = leftPad(s2, s.length());
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != s2.charAt(i) && s.charAt(i) != '?') {
                return false;
            }
        }
        return true;
    }
    public static void solve(String s1, String s2) {
        String old = s1;
        int ans = 2000000000;
        int u1 = 0, u2 = 0;
        s1 = leftPad(s1, 3);
        s2 = leftPad(s2, 3);
        for (int i = 0; i <= 999; i++) {
            if (match(s2, i)) {
                for (int j = 0; j <= 999; j++) {
                    if (match(s1, j) && Math.abs(i - j) < ans) {
                        ans = Math.abs(i - j);
                        u1 = j;
                        u2 = i;
                    }                    
                }    
            }
        }
        System.out.println(leftPad(u1+"", old.length()) + " " + leftPad(u2+"", old.length()) );
    }
    
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("input.txt"));
        int t = sc.nextInt();
        String s1 = sc.nextLine();
        for (int i = 0; i < t; i++) {
            System.out.print("Case #" + (i+1) + ": ");
            solve(sc.next(), sc.next());
        }
        sc.close();
    }
}
