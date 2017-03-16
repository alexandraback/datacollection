import java.io.*;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class CodeJam2014Q4 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("D-small.in")));
            PrintWriter pw = new PrintWriter(new FileOutputStream("D-small.out"));
            //BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("D-large.in")));
            //PrintWriter pw = new PrintWriter(new FileOutputStream("D-large.out"));
            String line = br.readLine();
            int T = Integer.parseInt(line);
            for (int i = 0; i < T; i++) {
                System.out.println((i + 1) + " / " + T + "...");

                line = br.readLine();
                String[] values = line.split(" ");
                int N = Integer.parseInt(values[0]);
                line = br.readLine();
                values = line.split(" ");
                List<Double> naomi = new ArrayList<Double>();
                List<Double> ken = new ArrayList<Double>();
                List<Double> naomi2 = new ArrayList<Double>();
                List<Double> ken2 = new ArrayList<Double>();
                for (int j = 0; j < N; j++) {
                    naomi.add(Double.parseDouble(values[j]));
                    naomi2.add(Double.parseDouble(values[j]));
                }
                line = br.readLine();
                values = line.split(" ");
                for (int j = 0; j < N; j++) {
                    ken.add(Double.parseDouble(values[j]));
                    ken2.add(Double.parseDouble(values[j]));
                }
                Collections.sort(naomi);
                Collections.sort(ken);
                Collections.sort(naomi2);
                Collections.sort(ken2);


                long result1 = solve1(naomi, ken);
                long result2 = solve2(naomi2, ken2);

                pw.println("Case #" + (i + 1) + ": " + result1 + " " + result2);
            }
            pw.close();
            System.out.println("DONE");
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    private static long solve1(List<Double> naomi, List<Double> ken) {
        int score = 0;
        System.out.println("Naomi:");
        display(naomi);
        System.out.println("Ken:");
        display(ken);

        for (int i = 0; i < naomi.size(); i++) {
            double current = naomi.get(i);
            if (current > ken.get(0)) {
                score++;
                ken.remove(0);
            } else {
                ken.remove(ken.size() - 1);
            }
            display(ken);
        }
        return score;
    }

    private static long solve2(List<Double> naomi, List<Double> ken) {
        int score = 0;
        System.out.println("Naomi:");
        display(naomi);
        System.out.println("Ken:");
        display(ken);

        for (int i = 0; i < naomi.size(); i++) {
            double current = naomi.get(i);
            if (current > ken.get(ken.size() - 1)) {
                score++;
                ken.remove(0);
            } else {
                int k = ken.size() - 1;
                while (k >= 0 && current < ken.get(k)) {
                    k--;
                }
                ken.remove(k + 1);
            }
            display(ken);
        }
        return score;
    }

    private static void display(List<Double> list) {
        for (Double v : list) {
            System.out.print(v + " ");
        }
        System.out.println();
    }

}
