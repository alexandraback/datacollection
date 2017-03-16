import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class C {

    int diff(String s, String t) {
        int c = 0;
        for (int i=0; i<s.length(); i++) {
            if (s.charAt(i)!=t.charAt(i)) c++;
        }
        return c;
    }

    public C() throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("garbled_email_dictionary.txt"));
        List<String>[] lists = new List[11];
        for (int i=1; i<11; i++) lists[i] = new ArrayList();
        String line = null;
        while ((line=br.readLine())!=null) {
            lists[line.length()].add(line);
        }
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);

            String S = in.next();
            int n = S.length();
            int[][] memo = new int[n+1][5];
            for (int i=0; i<=n; i++) Arrays.fill(memo[i], 1<<28);
            memo[0][4] = 0;
            int ans = n/5+1;

            for (int i=1; i<=n; i++) {
                for (int j=max(0, i-10); j<i; j++) {
                    for (int p=0; p<5; p++) {
                        if (memo[j][p]>=ans) continue;

                        int l = i-j;
                        String s = S.substring(j, i);
loop:
                        for (String t:lists[l]) {

                            int first = 1000;
                            int last = -1000;
                            int diff = 0;
                            for (int k=0; k<l; k++) {
                                if (s.charAt(k)!=t.charAt(k)) {
                                    if (first==1000) first = k;
                                    if (k-last<5) continue loop;
                                    last = k;
                                    diff++;
                                }
                            }

                            if (first+p<4) continue;
                            int t2 = min(4, l-1-last);
                            memo[i][t2] = min(memo[i][t2], memo[j][p]+diff);
                        }
                    }
                }
            }

            for (int i=0; i<5; i++) ans = min(ans, memo[n][i]);
            out.println(ans);
        }
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public static void main(String[] args) throws Exception {
        new C();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
