import java.io.*;
import java.util.HashSet;
import java.util.Set;

public class C {

    private static final String PREFIIX = C.class.getName().toLowerCase();

    public static void main(String[] args) throws Exception {
        Set<Long> targets = new HashSet<Long>();
        for (int i = 1; i <= 7; i++) {
            getNumbers(targets, i);
        }
        for (Long target : targets) {
            System.out.println(target.toString());
        }
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(PREFIIX + ".in")));
        PrintStream out = new PrintStream(new FileOutputStream(PREFIIX + ".out"));
        long testCaseNumber = readInt(in);
        for (int cas = 0; cas < testCaseNumber; cas++) {
            String[] data = in.readLine().split(" ");
            long a = Long.parseLong(data[0]);
            long b = Long.parseLong(data[1]);
            int ans = 0;
            for (long v : targets) {
                if (v >= a && v <= b) {
                    ans++;
                }
            }
            out.print("Case #" + (cas + 1) + ": ");
            out.print(Integer.toString(ans));
            out.println();
        }
        out.flush();
        out.close();
    }


    static void getNumbers(Set<Long> targets, int len) {
        long[] powers = new long[len];
        powers[0] = 1;
        for (int i = 1; i < powers.length; i++) {
            powers[i] = powers[i-1] * 10;
        }
        long[] add = new long[(len + 1)/2];
        for (int i = 0; i < add.length; i++) {
            int j = len - 1 - i;
            if (i ==j) {
                add[i] = powers[i];
            } else {
                add[i] = powers[i] + powers[j];
            }
        }
        p(targets, add, new int[add.length], 0, 0);
    }

    static void p(Set<Long> targets, long[] add, int[] n, long sum, int cur) {
        if (cur == add.length) {
            String s = Long.toString(sum * sum);
            StringBuilder sb = new StringBuilder(s);
            if (s.equals(sb.reverse().toString())) {
                targets.add(sum * sum);
            }
            return;
        }
        int start = cur == 0 ? 1 : 0;
        for (int v = start; v <=9; v++) {
            n[cur] = v;
            p(targets, add, n, sum + add[cur]*v, cur + 1);
        }
    }



    private static long readInt(BufferedReader in) {
        try {
            return Long.parseLong(in.readLine());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
