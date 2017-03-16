import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ProblemC {

    public static void main(String[] args) throws Exception {
        new ProblemC();
    }

    private BufferedReader in = null;
    private PrintWriter out = null;
    private StringTokenizer tok = new StringTokenizer("");
    private String fileName = "C-small-attempt0";

    public ProblemC() throws Exception {
        init();
        solve();
        in.close();
        out.close();
    }

    private void solve() throws Exception {
        long[] ans = new long[]{1l, 121l, 4l, 484l, 9l, 10201l, 1002001l, 12321l, 1234321l, 14641l, 40804l, 4008004l,
                44944l, 100020001l, 10000200001l, 102030201l, 10221412201l, 104060401l, 121242121l, 12102420121l,
                123454321l, 12345654321l, 125686521l, 400080004l, 40000800004l, 404090404l, 1000002000001l,
                100000020000001l, 1002003002001l, 100220141022001l, 1004006004001l, 1020304030201l, 102012040210201l,
                1022325232201l, 102234363432201l, 1024348434201l, 1210024200121l, 121000242000121l, 1212225222121l,
                121242363242121l, 1214428244121l, 1232346432321l, 123212464212321l, 1234567654321l, 123456787654321l,
                4000008000004l, 400000080000004l, 4004009004004l, 10000000200000001l, 1000000002000000001l,
                10002000300020001l, 1000220014100220001l, 10004000600040001l, 10020210401202001l, 1002003004003002001l,
                10022212521222001l, 1002223236323222001l, 10024214841242001l, 10201020402010201l, 1020100204020010201l,
                10203040504030201l, 1020322416142230201l, 10205060806050201l, 10221432623412201l, 1022123226223212201l,
                10223454745432201l, 1022345658565432201l, 12100002420000121l, 1210000024200000121l, 12102202520220121l,
                1210242036302420121l, 12104402820440121l, 12122232623222121l, 1212203226223022121l, 12124434743442121l,
                1212445458545442121l, 12321024642012321l, 1232100246420012321l, 12323244744232321l, 1232344458544432321l,
                12343456865434321l, 1234323468643234321l, 12345678987654321l, 40000000800000004l, 4000000008000000004l,
                40004000900040004l};
        Arrays.sort(ans);
        int T = nextInt();
        TEST:
        for (int it = 1; it <= T; ++it) {
            out.print("Case #" + it + ": ");
            long a = nextLong();
            long b = nextLong();
            int cur = 0;
            for (int i = 0; i < ans.length; ++i) {
                if (ans[i] >= a && ans[i] <= b) {
                    ++cur;
                }
            }
            out.println(cur);
        }
    }

    static char[] makePoly(int k, boolean even) {
        char[] c = Long.toString(k).toCharArray();
        char[] ans = new char[c.length * 2 - (even ? 0 : 1)];
        for (int i = 0; i < c.length; ++i) {
            ans[i] = c[i];
        }
        for (int i = ans.length / 2; i < ans.length; ++i) {
            ans[i] = c[c.length - (i - ans.length / 2) - 1];
        }
        return ans;
    }

    static boolean isPalindrome(long k) {
        char[] c = Long.toString(k).toCharArray();
        for (int i = 0; i < c.length / 2; ++i) {
            if (c[i] != c[c.length - i - 1]) {
                return false;
            }
        }
        return true;
    }

    private void init() throws FileNotFoundException {
        if (fileName.equals("#Console")) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else if (fileName.equals("#IOtxt")) {
            in = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
        } else {
            in = new BufferedReader(new FileReader(fileName + ".in"));
            out = new PrintWriter(fileName + ".out");
        }
    }


    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }


    private String nextToken() throws IOException {
        while (!tok.hasMoreTokens()) {
            String s = in.readLine();
            if (s == null) {
                return null;
            }
            tok = new StringTokenizer(s);
        }
        return tok.nextToken();
    }

}
            