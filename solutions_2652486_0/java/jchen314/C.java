import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] sets = new int[20][3];
        double[] prob = new double[20];
        int index = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = i; j < 4; j++) {
                for (int k = j; k < 4; k++) {
                    sets[index][0] = i + 2;
                    sets[index][1] = j + 2;
                    sets[index][2] = k + 2;

                    int combs;
                    if (i == k)
                        combs = 1;
                    else if (i == j || j == k)
                        combs = 3;
                    else
                        combs = 6;
                    prob[index++] = combs / 64.;
                }
            }
        }
        List<Map<Integer, Double>> probs = new ArrayList<Map<Integer, Double>>();
        for (int i = 0; i < 20; i++) {
            Map<Integer, Double> map = new HashMap<Integer, Double>();
            for (int bits = 0; bits < 8; bits++) {
                int prod = 1;
                for (int k = 0; k < 3; k++) {
                    if ((bits & (1 << k)) != 0)
                        prod *= sets[i][k];
                }
                if (!map.containsKey(prod))
                    map.put(prod, 0.0);
                map.put(prod, map.get(prod) + 1.0 / 8 * prob[i]);
            }
            probs.add(map);
        }

        int cases = sc.nextInt();
        for (int caseNum = 1; caseNum <= cases; caseNum++) {
            int R = sc.nextInt();
            int N = sc.nextInt();
            int M = sc.nextInt();
            int K = sc.nextInt();

            System.out.println("Case #" + caseNum + ": ");

            for (int c = 0; c < R; c++) {
                double[] arr = new double[20];
                Arrays.fill(arr, 1);
                for (int i = 0; i < K; i++) {
                    int n = sc.nextInt();
                    for (int j = 0; j < 20; j++) {
                        arr[j] *= (probs.get(j).containsKey(n) ? probs.get(j).get(n) : 0);
                    }
                }
                int maxIndex = 0;
                for (int i = 1; i < 20; i++) {
                    if (arr[i] > arr[maxIndex])
                        maxIndex = i;
                }
                System.out.println(sets[maxIndex][0] + "" + sets[maxIndex][1] + "" + sets[maxIndex][2]);
            }
        }
    }
}
