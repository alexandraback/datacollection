
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class fair {

    static ArrayList<Long> dp;
    //static long Limit = (long) Math.pow(10, 3);
    static long Limit=(long)Math.pow(10, 14);

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new FileReader("C-large-1.in"));
        BufferedWriter out = new BufferedWriter(new FileWriter("C-large-1.out"));
        Cache();
        int N = Integer.parseInt(in.readLine());
        for (int i = 1; i <= N; i++) {
            String[] temp = in.readLine().split(" ");
            long A = Long.parseLong(temp[0]);
            long B = Long.parseLong(temp[1]);
            int status = Solve(A, B);
            out.write("Case #" + i + ": " + status);
            out.newLine();
        }
        out.close();
    }

    private static void Cache() {
        dp = new ArrayList<Long>();
        long sqrt = (long) Math.sqrt(Limit);
        for (long i = 1; i <= sqrt; i++) {
            if (palin(i) && palin(i * i)) {
                dp.add(i * i);
            }
        }
    }

    private static boolean palin(long x) {
        String t = x + "";
        for (int i = 0; i < t.length() / 2; i++) {
            if (t.charAt(i) != t.charAt(t.length() - i - 1)) {
                return false;
            }
        }
        return true;
    }

    private static int Solve(long A, long B) {
        int count = 0;
        for (int i = 0; i < dp.size(); i++) {
            if (dp.get(i) >= A && dp.get(i) <= B) {
                count++;
            }
        }
        return count;
    }
}
