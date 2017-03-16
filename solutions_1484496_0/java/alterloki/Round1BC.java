package jam.jam2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by IntelliJ IDEA.
 * User: ashevenkov
 * Date: 29.04.12
 * Time: 22:15
 */
public class Round1BC {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("input/C-small-attempt0.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("output/C-small-attempt0.out"));
        String line = br.readLine();
        int cases = Integer.parseInt(line);
        for (int i = 0; i < cases; i++) {
            line = br.readLine();
            String[] parts = line.split(" ");
            int n = Integer.parseInt(parts[0]);
            int[] s = new int[n];
            for (int j = 0; j < n; j++) {
                s[j] = Integer.parseInt(parts[j + 1]);
            }
            String[] result = calculate(s, n);
            System.out.println("Case #" + (i + 1) + ": " + (result == null ? "Impossible" : ""));
            if (result != null) {
                System.out.println(result[0]);
                System.out.println(result[1]);
            }
            bw.write("Case #" + (i + 1) + ": " + (result == null ? "Impossible" : "\n"));
            if (result != null) {
                bw.write(result[0] + "\n");
                bw.write(result[1] + "\n");
            }
        }
        bw.flush();
        bw.close();
    }

    private static String[] calculate(int[] s, int n) {
        int k = 1;
        for (int i = 0; i < n; i++) {
            k *= 2;
        }
        Map<Integer, boolean[]> map = new HashMap<Integer, boolean[]>();
        for (int i = 1; i <= k; i++) {
            int ti = i;
            int sum = 0;
            boolean[] b = new boolean[n];
            for (int j = 0; j < n; j++) {
                int r = ti & 1;
                if (r > 0) {
                    sum += s[j];
                    b[j] = true;
                }
                ti = ti >> 1;
            }
            boolean[] bs = map.get(sum);
            if (bs != null) {
                return convert(bs, b, s);
            }
            map.put(sum, b);
        }
        return null;
    }

    private static String[] convert(boolean[] bs, boolean[] b, int[] s) {
        int sum1 = 0;
        StringBuilder sb1 = new StringBuilder();
        for (int i = 0; i < bs.length; i++) {
            boolean b1 = bs[i];
            if(b1) {
                sum1+=s[i];
                sb1.append(s[i]).append(" ");
            }
        }
        int sum2 = 0;
        StringBuilder sb2 = new StringBuilder();
        for (int i = 0; i < b.length; i++) {
            boolean b1 = b[i];
            if(b1) {
                sum2+=s[i];
                sb2.append(s[i]).append(" ");
            }
        }
        if(sum1 != sum2) {
            System.out.println("WRONG!!!");
        }
        return new String[]{sb1.toString().trim(), sb2.toString().trim()};
    }
}