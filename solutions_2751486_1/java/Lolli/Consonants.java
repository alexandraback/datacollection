package gcj;

import java.io.*;
import java.util.StringTokenizer;

/**
 * Created with IntelliJ IDEA.
 * User: svasilinets
 * Date: 12.05.13
 * Time: 13:15
 */
public class Consonants {

    private static boolean isCons(char ch) {
        return !(ch == 'a' || ch == 'o' || ch == 'e' || ch == 'i' || ch == 'u');
    }

    private static long newstr(int lastpos, int n){
        if (lastpos == -1) {
            return 0;
        }
        int start = lastpos - n + 1;
        return start + 1;
    }

    private static long solve(String s, int n){
        int lastpos = -1;
        int cur = 0;
        long ans = 0;
        for (int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);
            if (isCons(ch)) {
                cur++;
                if (cur >= n) {
                    lastpos = i;
                }
            } else {
                cur = 0;
            }
            ans += newstr(lastpos, n);
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("cons2.in"));
        int t = new Integer(reader.readLine());
        BufferedWriter writer = new BufferedWriter(new FileWriter("ans.txt"));
        for (int i = 0; i < t; i++) {
            String s = reader.readLine();
            StringTokenizer tokenizer = new StringTokenizer(s);
            long result = solve(tokenizer.nextToken(), new Integer(tokenizer.nextToken()));
            writer.write("Case #" + (i + 1) + ": " + result);

            writer.newLine();
        }
        writer.close();
    }

}
