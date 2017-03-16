import java.io.*;
import java.util.*;

/**
 * Created by Rafal on 4/12/14.
 */
public class D {

    public static void main(String[] args) {
        try {

            InputStream in = new FileInputStream("c:/codejam/D.in");
            Scanner scanner = new Scanner(in);
            OutputStream out = new FileOutputStream("c:/codejam/D.out");
            PrintWriter writer = new PrintWriter(new OutputStreamWriter(out, "utf8"));
            int t = scanner.nextInt();
            for (int i = 0; i < t; i++) {
                solve(scanner, i+1, writer);
            }
            writer.close();
        } catch (Exception e) {
            System.out.println("Error: " + e);
            e.printStackTrace();
        }
    }


    public static void solve(Scanner scanner, int t, PrintWriter out) {
        int n = scanner.nextInt();
        Double naomi[] = new Double[n];
        Double ken[] = new Double[n];

        for (int i = 0; i < n; i++) {
            naomi[i] = scanner.nextDouble();
        }
        for (int i = 0; i < n; i++) {
            ken[i] = scanner.nextDouble();
        }

        // normal play
        List<Double> N = new ArrayList<>(Arrays.asList(naomi));
        List<Double> K = new ArrayList<>(Arrays.asList(ken));

        N.sort(Comparator.<Double>naturalOrder());
        K.sort(Comparator.<Double>naturalOrder());
        TreeSet<Double> treeSet = new TreeSet<>(K);

        int naomiPointsNormal = 0;
        for (int i = 0; i < N.size(); i++) {
            double d = N.get(i);
            // find next value higher than d in treeSet
            Double ceiling = treeSet.ceiling(d);
            if (ceiling == null) {
                naomiPointsNormal++;
                treeSet.pollFirst();        // naomi won
            } else {
                treeSet.remove(ceiling);    // ken won
            }
        }

        int naomiPoints = 0;
        treeSet = new TreeSet<>(N);
        for (int i = 0; i < K.size(); i++) {
            double d = K.get(i);
            Double ceiling = treeSet.ceiling(d);
            if (ceiling != null) {
                treeSet.remove(ceiling);
                naomiPoints++;
            } else {
                treeSet.pollFirst();
            }
        }

        System.out.println("Case #" + t + ": " + naomiPoints + " " + naomiPointsNormal);
        out.println("Case #" + t + ": " + naomiPoints + " " + naomiPointsNormal);
    }


}
