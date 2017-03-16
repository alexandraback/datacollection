import java.util.*;

class Main {
    public static void main(String[] args) {
        new Main().solve();
    }

    public void solve() {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t=0; t<T; t++) {
            int N = sc.nextInt();
            int[] scores = new int[N];
            double sum = 0;
            for (int i=0; i<N; i++) {
                sum += scores[i] = sc.nextInt();
            }
            double avg = sum * 2 / N;
            System.out.printf("Case #%d:", t+1);
            int M = N;
            double sum2 = 0;
            for (int i=0; i<N; i++) {
                if (avg <= scores[i]) {
                    M--;
                } else {
                    sum2 += scores[i];
                }
            }
            double avg2 = (sum2 + sum) / M;
            double check = 0;
            for (int i=0; i<N; i++) {
                double p = avg <= scores[i] ? 0.0 : (avg2-scores[i]) / sum;
                check += p;
                System.out.print(" " + p * 100);
            }
            System.out.println();
        }
    }
}