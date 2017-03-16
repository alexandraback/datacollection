import java.util.*;

public class Lottery {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        int curCase = 1;

        while (numCases > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int k = sc.nextInt();

            int wins = 0;

            for (int i = 0; i<a; i++) {
                for (int j = 0; j<b; j++) {
                    if ((i&j) < k) {
                        wins++;
                    }
                }
            }

            System.out.format("Case #%d: %d\n", curCase, wins);

            curCase++;
            numCases--;
        }
    }
}
