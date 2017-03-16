import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

public class Dijkstra {

    private void processInput() throws IOException {
        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int testCase = 1; testCase <= T; testCase++) {
            int L = in.nextInt();
            long X = in.nextLong();
            String str = in.next();

            solve(testCase, L, X, str);
        }

        in.close();
    }

    int[][] op = {{0, 1, 2, 3},
                  {1, 0, 3, 2},
                  {2, 3, 0, 1},
                  {3, 2, 1, 0}};
    int[][] sign = {{1, 1, 1, 1},
                    {1, -1, 1, -1},
                    {1, -1, -1, 1},
                    {1, 1, -1, -1}};

    int cx;
    int cl;
    int s;
    int val;
    int exp;
    String str;
    int valstr;
    int sstr;
    
    public void solve(int testCase, int L, long X, String str) {

        this.str = str;
        String res = "NO";
        cl = 0;
        cx = 0;
        val = 0;
        s = 1;
        exp = 10;
        eval();
        valstr = val;
        sstr = s;
        
        cl = 0;
        cx = 0;
        val = 0;
        s = 1;
        exp = 1;

        for (int i = 0; i < 200 && cx < X; i++) {
            eval();
        }

        long rem = X - cx;
        if (rem > 0) {
            long cycle = getCycle(val, s, valstr, sstr);
            rem %= cycle;
            for (int i = 0; i < rem; i++) {
                s *= sign[val][valstr] * sstr;
                val = op[val][valstr];
            }
        }

        if (val == 0 && s == 1 && exp == 4) {
            res = "YES";
        }
        System.out.printf(Locale.ENGLISH, "Case #%d: %s\n", testCase, res);
    }

    int getCycle(int curval, int curs, int valstr, int sstr) {
        int ival = curval;
        int is = curs;
        for (int i = 1; i <= 1000; i++) {
          curs *= sign[curval][valstr] * sstr;
          curval = op[curval][valstr];
          if (ival == curval && is == curs) {
              return i;
          }
        }
        System.err.println("Is this expected???");
        return 1;
    }

    void eval() {
        String idx = "1ijk";
        while (cl < str.length()) {
            int next = idx.indexOf(str.charAt(cl));
            s *= sign[val][next];
            val = op[val][next];
            cl++;
            if (s == 1 && val == exp && exp < 4) {
                exp++;
                val = 0;
                return;
            }
        }
        cl = 0;
        cx++;
    }

    public static void main(String[] args) throws Exception {
        Dijkstra main = new Dijkstra();
        main.processInput();
    }
}
