import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Scanner;

public class G_3 {

    static int a, b;
    static HashMap<String, Integer> map;

    static String change(int n) {
        String s = "" + n;
        int len = s.length();
        int min = Integer.MAX_VALUE;
        int value;
        // String best = null;
        for (int i = 0; i < len; i++) {
            s = s.charAt(len - 1) + s.substring(0, len - 1);
            value = Integer.parseInt(s);
            if (min > value) {
                min = value;
                // best = s;
            }
        }
        return "" + min;
    }

    public static void main(String[] args) throws IOException {
        PrintWriter bw = new PrintWriter(new FileWriter("1.txt"));
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        map = new HashMap<String, Integer>();
        for (int i = 0; i < T; i++) {
            map.clear();
            a = scan.nextInt();
            b = scan.nextInt();
            for (int j = a; j <= b; ++j) {
                String str = change(j);
                // System.out.println(str);

                if (map.containsKey(str)) {
                    map.put(str, map.get(str) + 1);
                } else {
                    map.put(str, 1);
                }
            }
            long sum = 0;
            for (Entry<String, Integer> e : map.entrySet()) {
                int n = e.getValue();
                sum += n * (n - 1) / 2;
            }
            System.out.println(String.format("Case #%d: %d", (i + 1), sum));
            bw.write(String.format("Case #%d: %d\n", (i + 1), sum));
        }
        bw.flush();
        bw.close();
    }
}
