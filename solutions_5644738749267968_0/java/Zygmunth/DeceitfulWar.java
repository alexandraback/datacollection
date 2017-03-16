import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.Writer;
import java.util.*;

public class DeceitfulWar {
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        InputStream resourceAsStream = DeceitfulWar.class.getClassLoader().getResourceAsStream("in.txt");
        Scanner scanner = new Scanner(resourceAsStream);
        Writer out = new FileWriter("c:\\temp\\2014.txt");

        int tcc = scanner.nextInt();
        for (int ci = 0; ci < tcc; ci++) {
            int n = scanner.nextInt();
            List<Double> naomi = new ArrayList<>();
            List<Double> ken = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                naomi.add(scanner.nextDouble());
            }
            //scanner.nextLine();
            for (int i = 0; i < n; i++) {
                ken.add(scanner.nextDouble());
            }
            Collections.sort(naomi);
            Collections.sort(ken);
            List<Double> naomi2 = new ArrayList<>();
            List<Double> ken2 = new ArrayList<>();
            naomi2.addAll(naomi);
            ken2.addAll(ken);
            int points = 0;
            while (true){
                if (naomi.size() == 0) {
                    break;
                }
                if (naomi.get(naomi.size()-1) > ken.get(ken.size()-1)) {
                    points++;
                    naomi.remove(naomi.size()-1);
                    ken.remove(ken.size()-1);
                    continue;
                }
                double chosen = naomi.get(0);
                double chosenK = ken.get(ken.size()-1);
                naomi.remove(0);
                ken.remove(ken.size()-1);
                if (chosenK>chosen) {

                    continue;
                }
                points++;
            }
            int points2 = 0;
            while (true){
                if (naomi2.size() == 0) {
                    break;
                }
                if (naomi2.get(naomi2.size()-1) > ken2.get(ken2.size()-1)) {
                    points2++;
                    naomi2.remove(naomi2.size()-1);
                    ken2.remove(0);
                    continue;
                }

                for (int i = 0; i < ken2.size(); i++) {
                    if (ken2.get(i)>naomi2.get(naomi2.size()-1)) {
                        ken2.remove(i);
                        break;
                    }
                }
                naomi2.remove(naomi2.size()-1);
            }
            String res = String.format("Case #%d: %d %d\n",ci+1,points,points2);
            out.write(res);

        }
        out.close();
        return;
    }
}
