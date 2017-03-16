import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for (int caseNum = 1; caseNum <= cases; caseNum++) {
            int N = sc.nextInt();
            List<Double> naomi = new ArrayList<Double>();
            for (int i = 0; i < N; i++) {
                naomi.add(sc.nextDouble());
            }

            List<Double> ken = new ArrayList<Double>();
            for (int i = 0; i < N; i++) {
                ken.add(sc.nextDouble());
            }

            int y = N - compute(N, ken, naomi);
            int z = compute(N, naomi, ken);

            System.out.println("Case #" + caseNum + ": " + y + " " + z);
        }
    }

    private static int compute(int N, List<Double> naomi, List<Double> ken) {
        int z = 0;
        List<Double> kenCopy = new LinkedList<Double>(ken);
        for (int i = 0; i < N; i++) {
            double kMass = chooseBlock(kenCopy, naomi.get(i));
            if (kMass < naomi.get(i)) {
                z++;
            }
        }
        return z;
    }

    private static double chooseBlock(List<Double> blocks, double mass) {
        double min = 2;
        int minIndex = -1;
        for (int i = 0; i < blocks.size(); i++) {
            double m = blocks.get(i);
            if (mass < m && m < min) {
                minIndex = i;
                min = m;
            }
        }
        if (minIndex != -1 && min > mass) {
            blocks.remove(minIndex);
            return min;
        }
        return chooseBlock(blocks, -1);
    }
}
