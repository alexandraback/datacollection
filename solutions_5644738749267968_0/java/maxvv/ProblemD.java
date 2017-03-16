
import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.Scanner;

public class ProblemD {

    public static void main(String[] args) throws Exception {

        String inFile = "D-small-attempt0.in";
        String outFile = "D-small-attempt0.out";
        //String inFile = "D-large-attempt0.in";
        //String outFile = "D-large-attempt0.out";
        //String inFile = "sampleD.in";
        //String outFile = "sampleD.out";

        Scanner sc = new Scanner(new File(inFile));
        PrintWriter writer = new PrintWriter(outFile);
        int numTest = sc.nextInt();
        for (int test = 1; test <= numTest; test++) {
            int n = sc.nextInt();
            ArrayList<Double> naomi = new ArrayList<>();
            ArrayList<Double> ken = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                naomi.add(sc.nextDouble());
            }
            for (int i = 0; i < n; i++) {
                ken.add(sc.nextDouble());
            }
            writer.println("Case #" + test + ": " + solution(naomi, ken));
        }
        writer.close();
    }

    private static String solution(ArrayList<Double> naomi, ArrayList<Double> ken) {
        Collections.sort(ken);
        ArrayList<Double> copyKen = new ArrayList<>(ken);
        int war = 0;
        for (int i = 0; i < naomi.size(); i++) {
            double bN = naomi.get(i);
            boolean kenLoose = true;
            for (Iterator<Double> it = copyKen.iterator(); it.hasNext();) {
                double bK = it.next();
                if (bK > bN) {
                    kenLoose = false;
                    it.remove();
                    break;
                }
            }
            if (kenLoose) {
                war++;
                copyKen.remove(0);
            }
        }

        int deceitfulWar = 0;
        Collections.sort(naomi);

        boolean naomiAlwaysWin = false;
        while (!naomiAlwaysWin) {
            naomiAlwaysWin = true;
            for (int i = 0; i < naomi.size(); i++) {
                if (naomi.get(i) < ken.get(i)) {
                    naomiAlwaysWin = false;
                    naomi.remove(0);
                    ken.remove(ken.size() - 1);
                    break;
                }
            }
        }

        deceitfulWar = naomi.size();

        return deceitfulWar + " " + war;
    }

}
