import java.util.Scanner;

/**
 * Google Code Jam 2012
 * 
 * @author 7henick
 */
public class ProblemB {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < T; i++) {
            int N = sc.nextInt();
            int S = sc.nextInt();
            int p = sc.nextInt();

            int result = 0;

            for (int j = 0; j < N; j++) {
                int g = sc.nextInt();

                int min = g / 3;
                int best = g - min * 2;

                if (best - min == 0) {
                    if (best >= p) {
                        result++;
                    } else {
                        if (best + 1 >= p && min - 1 >= 0 && S > 0) {
                            result++;
                            S--;
                        }
                    }
                } else if (best - min == 1) {
                    if (best >= p) {
                        result++;
                    }
                } else if (best - min == 2) {

                    if (best - 1 >= p) {
                        result++;
                    } else {
                        if (best >= p && S > 0) {
                            result++;
                            S--;
                        }
                    }
                } else {
                    throw new Exception();
                }
            }

            System.out.println("Case #" + (i + 1) + ": " + result);
            sc.nextLine();
        }
    }
}
