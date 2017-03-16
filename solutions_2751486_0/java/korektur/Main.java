
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner in = new Scanner(new FileReader("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int t = in.nextInt();
        ArrayList<Character> r = new ArrayList<Character>();
        r.add('a');
        r.add('e');
        r.add('i');
        r.add('o');
        r.add('u');
        for (int tt = 1; tt <= t; tt++) {
            HashSet<String> map = new HashSet<String>();
            String s = in.next();
            int x = in.nextInt();
            long ans = 0;
            int xx = 0;
            int n = s.length();
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    int max = 0;
                    int tmp = 0;
                    for (int xt = i; xt <= j; xt++) {
                        if (!r.contains(s.charAt(xt))) {
                            tmp++;
                            max = Math.max(max, tmp);
                        } else {
                            
                            tmp = 0;
                        }
                    }
                    if (max >= x)
                        ans++;
                }
            }
            out.println("Case #" + tt + ": " + ans);
        }
        out.close();
    }
}