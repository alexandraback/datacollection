import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class FairSquare {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int numTests = Integer.parseInt(reader.readLine());

        List<Long> list = prepare();

        for (int testId = 1; testId <= numTests; ++ testId) {
            String[] tmp = reader.readLine().split(" ");
            long A = Long.parseLong(tmp[0]);
            long B = Long.parseLong(tmp[1]);
            int i = 0, ans = 0;
            while (i < list.size() && list.get(i) < A) {
                ++i;
            }
            while (i < list.size() && list.get(i) <= B) {
                ++ans;
                ++i;
            }
            System.out.println("Case #" + testId + ": " + ans);
        }
    }

    private static List<Long> prepare() {
        List<Long> list = new ArrayList<Long>();
        for (long i = 1; i <= 10000000; ++i) {
            if (valid(i) && valid(i * i)) {
                list.add(i * i);
            }
        }
//        Collections.sort(list);
        return list;
    }

    private static boolean valid(long x) {
        String s = String.valueOf(x);
        for (int i = 0; i < s.length() / 2; ++i) {
            if (s.charAt(i) != s.charAt(s.length() - i - 1)) {
                return false;
            }
        }
        return true;
    }
}
