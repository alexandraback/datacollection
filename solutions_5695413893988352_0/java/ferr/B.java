import java.io.PrintWriter;
import java.util.*;
import java.util.stream.Collectors;


public class B {
    static PrintWriter pw;
    static Scanner sc;

    public static void main(String[] args) {
        pw = new PrintWriter(System.out);
        sc = new Scanner(System.in);

        new B().run();
        pw.flush();
    }

    private void run() {
        int T = sc.nextInt();
        for (int t = 0; t < T; ++t) {
            System.err.printf("Case %d of %d\n", t + 1, T);
            pw.printf("Case #%d: %s\n", t + 1, nextCase(t));
        }
    }

//    char[] C, J;


    char[] tmp;

    int diff = Integer.MAX_VALUE;
    int Cscore = Integer.MAX_VALUE;
    int Jscore = Integer.MAX_VALUE;

    String ans = null;

    void iter() {
        boolean any = false;
        for (int i = 0; i < tmp.length; ++i) {
            if (tmp[i] == '?') {
                any = true;
                for (int j = 0; j < 10; ++j) {
                    tmp[i] = (char)('0' + j);
                    iter();
                    tmp[i] = '?';
                }
                break;
            }
        }
        if (!any) {
            String[] parts = new String(tmp).split("\\|");
            int csc = Integer.parseInt(parts[0]);
            int jsc = Integer.parseInt(parts[1]);

            int d = Math.abs(csc - jsc);
            if (d < diff ||
                    d == diff && csc < Cscore ||
                    d == diff && csc == Cscore && jsc < Jscore)
            {
                diff = d;
                Cscore = csc;
                Jscore = jsc;
                ans = new String(tmp);
            }
        }
    }

    private String nextCase(int caseNum) {
        diff = Integer.MAX_VALUE;
        Cscore = Integer.MAX_VALUE;
        Jscore = Integer.MAX_VALUE;

        String c = sc.next();
        String j = sc.next();
        tmp = (c + "|" + j).toCharArray();
        iter();
//        System.err.println(tmp);
        return ans.replace('|', ' ');
    }
}