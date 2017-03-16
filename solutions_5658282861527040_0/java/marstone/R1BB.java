import java.util.Scanner;

public class R1BB {

    public static void main(String args[]) {

        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int A = in.nextInt();
            int B = in.nextInt();
            int K = in.nextInt();

            int count = 0;
            for(int x = 0; x < A; x++) {
                for(int y = 0; y < B; y++) {
                    int s = x & y;
                    if(s < K)
                        count++;
                }
            }
            System.out.format("Case #%d: %d\n", t, count);
        }
    }

}
