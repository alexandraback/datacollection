import java.util.*;
import java.math.*;

public class B {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        s.nextLine();
        for (int t = 1; t <= T; t++) {
            String line = s.nextLine();
            int loc = line.indexOf(' ');
            char[] C = line.substring(0, loc).toCharArray();
            char[] J = line.substring(loc + 1).toCharArray();
            int n = C.length;
            ansC = new char[n];
            ansJ = new char[n];
            diff = 1000000;
            find(C, J, 0);
            System.out.println(String.format("Case #%d: %s %s", t, new String(ansC), new String(ansJ)));
        }
        s.close();
    }

    public static void find(char[] C, char[] J, int k) {
        int n = C.length;
        if (k < n) {
            if (C[k] == '?') {
                for (char ch = '0'; ch <= '9'; ch++) {
                    C[k] = ch;
                    find(C, J, k + 1);
                }
                C[k] = '?';
            } else {
                find(C, J, k + 1);
            }
        } else if (k < n + n) {
            k -= n;
            if (J[k] == '?') {
                for (char ch = '0'; ch <= '9'; ch++) {
                    J[k] = ch;
                    find(C, J, k + 1 + n);
                }
                J[k] = '?';
            } else {
                find(C, J, k + 1 + n);
            }
        } else {
            int tmpC = convert(C), tmpJ = convert(J), tmpDiff = Math.abs(tmpC - tmpJ);
            if (tmpDiff < diff || (tmpDiff == diff && (tmpC < c || (tmpC == c && tmpJ < j)))) {
                c = tmpC;
                j = tmpJ;
                diff = tmpDiff;
                System.arraycopy(C, 0, ansC, 0, n);
                System.arraycopy(J, 0, ansJ, 0, n);
            } 
        }
    }

    public static int convert(char[] chs) {
        String str = new String(chs);
        return Integer.parseInt(str);
    }

    public static int MAX = 1000000;

    public static int c = 0, j = 0, diff = MAX;
    public static char[] ansC, ansJ;
}