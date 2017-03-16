import sun.io.ByteToCharCp037;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class gcjr1cb {
    public static void main(String[] args) {
        try {
            new gcjr1cb().solve();
        } catch (Exception e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    void solve() throws Exception {
        Locale.setDefault(Locale.US);

//        String fn = "E:\\isinev\\develop\\contests\\training\\spoj\\work\\b.in";
        String fn = "E:\\isinev\\download\\B-large.in";

        File fin = new File(fn + ".res");
        PrintWriter pw = new PrintWriter(fin);
        Scanner sc = new Scanner(new File(fn));

        int tc = sc.nextInt();

        for (int tci = 1; tci <= tc; tci++) {
            int n = sc.nextInt();
            char[][] s = new char[n][];
            for (int i = 0; i < n; i++) {
                s[i] = sc.next().toCharArray();
            }
            long res = doSolve(n, s);

            pw.format("Case #%d: %d%n", tci, res);
            pw.flush();
        }
        pw.close();
    }

    private long doSolve(int n, char[][] s) {
        int[] sval = new int[n];
        int[] countRepeatOnes = new int[26];
        int[] cartStartC = new int[26];
        java.util.Arrays.fill(cartStartC, -1);

        for (int i1 = 0; i1 < s.length; i1++) {
            boolean[] uc = new boolean[26];
            char[] si = s[i1];
            int diffc = 0;
            for (int i = 0; i < si.length; i++) {
                if (i > 0 && si[i - 1] == si[i]) {
                    continue;
                }
                if (uc[si[i] - 'a']) {
                    return 0; // duplicate inside a string
                }
                uc[si[i] - 'a'] = true;
                diffc++;
                sval[i1] ^= (1 << (si[i] - 'a'));
            }
            int s0 = si[0] - 'a';
            if (diffc == 1) {
                countRepeatOnes[s0]++;
            } else {
                if (cartStartC[s0] != -1) {
                    return 0;
                }
                cartStartC[s0] = i1;
            }
        }

        long mod = 1000000007;
        long[] fct = new long[n + 1];
        fct[0] = 1;
        for (int i = 1; i < fct.length; i++) {
            fct[i] = (fct[i - 1] * i) % mod;
        }

        int[] belongsToLine = new int[26];
        Arrays.fill(belongsToLine, -1);
        int[] maskFrom = new int[26];

        for (int firstLetter = 0; firstLetter < 26; firstLetter++) {
            if (belongsToLine[firstLetter] > -1 || (countRepeatOnes[firstLetter] == 0 && cartStartC[firstLetter] == -1)) {
                continue;
            }

            belongsToLine[firstLetter] = firstLetter;
            int curLetter = firstLetter;
            int curMask = 1 << firstLetter;

            while (true) {
                int cn = cartStartC[curLetter];
                if (cn == -1) {
                    break;
                }
                if ((curMask & (sval[cn] ^ (1 << curLetter))) > 0) {
                    return 0;
                }
                curMask  = (curMask | sval[cn]);
                curLetter = s[cn][s[cn].length - 1] - 'a';
                belongsToLine[curLetter] = firstLetter;
                maskFrom[curLetter] = 0;
            }
            maskFrom[firstLetter] = curMask;
        }

        int overallMask = 0;
        int linesCount = 0;
        for (int firstLetter = 0; firstLetter < 26; firstLetter++) {
            if (belongsToLine[firstLetter] == firstLetter) {
                if ((overallMask & maskFrom[firstLetter]) > 0) {
                    return 0;
                }
                overallMask ^= maskFrom[firstLetter];
                linesCount++;
            }
        }
        long res = fct[linesCount];
        for (int i = 0; i < 26; i++) {
            res = (res * fct[countRepeatOnes[i]]) % mod;
        }
        return res;
    }

//    int go(int n, int r, String[] s, boolean[] u, StringBuilder sb) {
//        if (r == 0) {
////            System.out.println(sb);
//            return check(sb.toString().toCharArray());
//        }
//        int res = 0;
//        for (int i = 0; i < n; i++) {
//            if (!u[i]) {
//                u[i] = true;
//                sb.append(s[i]);
//                res += go(n, r - 1, s, u, sb);
//                sb.setLength(sb.length() - s[i].length());
//                u[i] = false;
//            }
//        }
//        return res;
//    }
//
//    private int check(char[] s) {
//        boolean[] uc = new boolean[26];
//        for (int i = 0; i < s.length; i++) {
//            if (i > 0 && s[i - 1] == s[i]) {
//                continue;
//            }
//            if (uc[s[i] - 'a']) {
//                return 0;
//            }
//            uc[s[i] - 'a'] = true;
//        }
//        return 1;
//    }
}