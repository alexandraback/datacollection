
import java.util.Scanner;

public class GettingTheDigits {
    
    // source: https://stackoverflow.com/a/8910767
    static int count(String s, String x) {
        return s.length() - s.replace(x, "").length();
    }
    
    static String occurences(String s) {
        int[] c = new int[10];
        
        c[4] = count(s, "U");
        c[2] = count(s, "W");
        c[6] = count(s, "X");
        c[0] = count(s, "Z");
        c[8] = count(s, "G");
        c[7] = count(s, "S") - c[6];
        c[5] = count(s, "V") - c[7];
        c[3] = count(s, "H") - c[8];
        c[1] = count(s, "O") - c[0] - c[2] - c[4];
        c[9] = count(s, "I") - c[5] - c[6] - c[8];      
        
        String result = "";
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j < c[i]; j++) {
                result += i;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            String s = sc.next();
            System.out.println("Case #" + i + ": " + occurences(s));
        }
        
    }
    
}
