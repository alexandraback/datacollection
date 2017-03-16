import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Problem2 {
    static long best = Long.MAX_VALUE;
    static long bc;
    static long bj;
    static int n = 0;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("data/B-small-attempt2.in"));
        PrintWriter pw = new PrintWriter(new File("data/B-small-attempt2.out"));
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            String c = sc.next();
            String j = sc.next();
            n = c.length();
            best = Long.MAX_VALUE;
            dfs(c.toCharArray(), j.toCharArray(), 0, 0);
            String s1 = String.format("%0" + n + "d", bc);
            String s2 = String.format("%0" + n + "d", bj);
            pw.println("Case #" + tc + ": " + s1 + " " + s2);
        }
        sc.close();
        pw.close();
    }

    static char d1[] = new char[] { '0', '0', '0', '1', '9'};
    static char d2[] = new char[] { '0', '1', '9', '0', '0'};
    static int d3[] = new int[] {0,-1,-1, 1,1};
//    static char d1[] = new char[] { '0', '9', '0', '0', '1' };
//    static char d2[] = new char[] { '9', '0', '0', '1', '0' };
//    static int d3[] = new int[] { -1, 1, 0, -1, 1 };

    static void dfs(char[] c, char[] j, int i, int res) {
        if (i == n) {
            long cs = Long.parseLong(new String(c));
            long js = Long.parseLong(new String(j));
            if (Math.abs(cs - js) < best) {
                best = Math.abs(cs - js);
                bc = cs;
                bj = js;
            }
            return;
        }

        if (res == 0) {
            char cp = c[i];
            char jp = j[i];
            if (c[i] == '?' && j[i] == '?') {
                for(char a='0';a<='9';a++){
                    for(char b=a;b<='9';b++){
                        c[i] = a;
                        j[i] = b;
                        dfs(c,j,i+1,a-b);
                    }
                }
                for(char a='0';a<='9';a++){
                    for(char b='0';b<a;b++){
                        c[i] = a;
                        j[i] = b;
                        dfs(c,j,i+1,a-b);
                    }
                }
                c[i] = cp;
                j[i] = jp;
            } else if (cp == '?') {
                for(char a='0';a<='9';a++){
                    c[i] = a;
                    dfs(c,j,i+1,a-jp);
                    c[i] = cp;
                }
            } else if (jp == '?') {
                for(char a='0';a<='9';a++){
                    j[i] = a;
                    dfs(c,j,i+1,cp-a);
                    j[i] = jp;
                }
            } else {
                dfs(c, j, i + 1, c[i] - j[i]);
            }

        } else if (res < 0) {
            char cp = c[i];
            char jp = j[i];
            if (c[i] == '?') {
                c[i] = '9';
            }
            if (j[i] == '?') {
                j[i] = '0';
            }
            dfs(c, j, i + 1, res);
            c[i] = cp;
            j[i] = jp;
        } else {
            char cp = c[i];
            char jp = j[i];
            if (c[i] == '?') {
                c[i] = '0';
            }
            if (j[i] == '?') {
                j[i] = '9';
            }
            dfs(c, j, i + 1, res);
            c[i] = cp;
            j[i] = jp;
        }
    }
}
