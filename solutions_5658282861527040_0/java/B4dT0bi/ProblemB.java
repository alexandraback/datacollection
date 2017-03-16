import java.io.BufferedReader;
import java.io.FileReader;
import java.util.HashSet;

public class ProblemB {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader(args[0]));
        int anzTC = Integer.parseInt(br.readLine());
        for (int tc = 0; tc < anzTC; tc++) {
            String tmp[] = br.readLine().split(" ");
            int A = Integer.parseInt(tmp[0]);
            int B = Integer.parseInt(tmp[1]);
            int K = Integer.parseInt(tmp[2]);
            solve(tc + 1, A, B, K);
        }
        br.close();
    }

    private static void solve(int tc, int A, int B, int K) {
        System.out.println("Case #" + tc + ": " + nr(A,B,K));
    }
    private static int nr(int A, int B, int K) {
        HashSet<String> tmp = new HashSet<String>();
        for (int i=0;i<A;i++) {
            for (int n=0;n<B;n++) {
                if ((i&n) < K) {
                    tmp.add(""+i+":"+n);
                }
            }
        }
        return tmp.size();
    }
}
