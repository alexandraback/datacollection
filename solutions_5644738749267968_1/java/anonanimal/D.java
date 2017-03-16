import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class D {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            System.out.printf("Case #%d: ", t);
            solve(in);
        }

    }

    public static void solve(Scanner in) {

        int N = in.nextInt();
        double[] naomi = new double[N];
        double[] ken = new double[N];

        for (int i = 0; i < N; i++) {
            naomi[i] = in.nextDouble();
        }
        for (int i = 0; i < N; i++) {
            ken[i] = in.nextDouble();
        }
        Arrays.sort(naomi);
        Arrays.sort(ken);

        int normalWar = playWar(naomi, ken);
        int otherWar = playOther(naomi, ken);

        System.out.println(otherWar + " " + normalWar);

    }

    public static int playOther(double[] nao, double[] ken) {
        int N = ken.length;

        int ans = 0;

        // Throw the first i mathces to knock out his best
        for (int i = 0; i < N; i++) {

            int res = 0;
            for (int j = 0; j < N - i; j++) {
                if (ken[j] < nao[i + j]) res++;
            }
            ans = Math.max(ans, res);
        }

        //        for (int i = 0; i < N; i++) {
        //            double naoTurn = nao[i];
        //            double kenTurn = ken[N - 1 - i];
        //
        //            if (naoTurn > kenTurn) {
        //                ans++;
        //            }
        //
        //        }

        return ans;

    }

    public static int playWar(double[] nao, double[] ken) {
        int N = ken.length;

        int ans = 0;

        ArrayList<Double> kens = new ArrayList<Double>();
        for (Double d : ken)
            kens.add(d);

        // Each round
        for (int i = 0; i < N; i++) {

            double naoTurn = nao[i];
            double kenTurn = -1;

            for (int j = 0; j < kens.size(); j++) {
                if (kens.get(j) > naoTurn) {
                    kenTurn = kens.remove(j);
                    break;
                }
            }

            if (kenTurn == -1) {
                kenTurn = kens.remove(0);
            }

            if (naoTurn > kenTurn) ans++;

        }

        return ans;
    }

}
