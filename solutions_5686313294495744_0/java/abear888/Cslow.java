import java.io.*;
import java.util.*;

public class Cslow {

    public static int pow (int base, int power) {
        int num = 1;
        for (int i = 0; i < power; i++) {
            num *= base;
        }
        return num;
    }
    
    public static void main(String[]args) throws IOException {
        BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(x.readLine());
        for (int cases = 1; cases <= t; cases++) {
            int n = Integer.parseInt(x.readLine());
            String[]first = new String[n];
            String[]second = new String[n];
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(x.readLine());
                first[i] = st.nextToken();
                second[i] = st.nextToken();
            }
            int max = 0;
            for (int i = 0; i < pow(2, n); i++) {
                String bit = Integer.toBinaryString(i);
                while (bit.length() < n) {
                    bit = "0" + bit;
                }
                HashSet<String> gfirst = new HashSet<String>();
                HashSet<String> gsecond = new HashSet<String>();
                int cur = n;
                for (int j = 0; j < n; j++) {
                    if (bit.charAt(j) == '0') { //good
                        cur--;
                        gfirst.add(first[j]);
                        gsecond.add(second[j]);
                    }
                }
                boolean good = true;
                for (int j = 0; j < n; j++) {
                    if (bit.charAt(j) == '1') {
                        if (!gfirst.contains(first[j]) || !gsecond.contains(second[j])) {
                            good = false;
                            break;
                        }
                    }
                }
                if (good && cur > max) {
                    max = cur;
                }
            }
            System.out.println("Case #" + cases + ": " + max);
        }
    }
}