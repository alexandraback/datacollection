import java.util.*;

public class JamB2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int i = 1; i <= T; i++) {
            int A = in.nextInt();
            int B = in.nextInt();
            int K = in.nextInt();
            int count = 0;
            for (int j = 0; j < A; j++) {
                for (int k = 0; k < B; k++) {
                    if ((j & k) < K)
                        count ++;
                }
            }
            System.out.println("Case #" + i + ": " + count);
        }
        in.close();
    }
}
