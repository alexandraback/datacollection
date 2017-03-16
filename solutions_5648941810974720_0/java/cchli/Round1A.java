package Round1;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * @auther chao
 * @date 16/4/30
 */
public class Round1A {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("/Users/chao/Downloads/A-small-attempt0.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        FileWriter out = new FileWriter("/Users/chao/Desktop/A-small-attempt0.txt");
        //PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        String s = in.readLine();
        int m = Integer.parseInt(s);
        int[] digit = new int[]{0,6,7,5,4,8,9,3,2,1};
        List<String> letter = new ArrayList<>();
        letter.add("ZERO");
        letter.add("XSI");
        letter.add("SEVEN");
        letter.add("VFIE");
        letter.add("UFOR");
        letter.add("GEIHT");
        letter.add("INNE");
        letter.add("HTREE");
        letter.add("TWO");
        letter.add("ONE");
        int[] ans = new int[10];
        for (int cases = 1; cases <= m; cases++) {
            int[] a = new int[26];
            s = in.readLine();
            for (int i = 0; i < s.length(); i++) {
                a[s.charAt(i)-'A']++;
            }
            int[] num = new int[10];
            for (int i = 0; i < digit.length; i++) {
                String ss = letter.get(i);
                int cnt = a[ss.charAt(0)-'A'];
                if (cnt > 0) {
                    for (int j = 0; j < ss.length(); j++) {
                        a[ss.charAt(j)-'A'] -= cnt;
                    }
                    ans[digit[i]] = cnt;
                }
            }
            out.write("Case #"+cases+": ");
            for (int k = 0; k <= 9; k++) {
                while (--ans[k]>=0) {
                    out.write(""+k);
                }
            }
            out.write('\n');
        }
        out.flush();
        out.close();
        in.close();
    }
}
