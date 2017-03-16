import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class DWar {
    public static void main ( String[] args) throws FileNotFoundException {
        final Scanner s = new Scanner(new File("D-large.in.txt"));
        PrintWriter out = new PrintWriter(new File("D.out"));
        final int tc = s.nextInt();
        s.nextLine();
        for (int tci = 1; tci <= tc; tci++) {
            final int n = s.nextInt();
            s.nextLine();
            final ArrayList<Double> nao = new ArrayList<Double>();
            for (int i = 0; i < n; i++) {
                nao.add(s.nextDouble());
            }
            s.nextLine();
            final ArrayList<Double> ken = new ArrayList<Double>();
            for (int i = 0; i < n; i++) {
                ken.add(s.nextDouble());
            }
            s.nextLine();

            Collections.sort(nao, Collections.reverseOrder());
            Collections.sort(ken, Collections.reverseOrder());

            final int scoreD = getScore(nao, ken);
            final int scoreW = n - getScore(ken, nao);
            out.printf("Case #%d: %d %d%n", tci, scoreD, scoreW);
        }
        s.close();
        out.close();
    }

    private static int getScore (ArrayList<Double> a1, ArrayList<Double> a2) {
        int i = 0;
        int j = 0;
        int score = 0;
        while (i < a1.size() && j < a2.size()){
            final double va1 = a1.get(i);
            final double va2 = a2.get(j);
            if (Double.compare(va1, va2)>0){
                i++;
                score++;
            }
            j++;
        }
        return score;
    }
}
