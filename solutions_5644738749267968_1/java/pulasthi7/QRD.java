import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class QRD {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int n = sc.nextInt();
            ArrayList<Double> naomi = new ArrayList<Double>(n);
            ArrayList<Double> ken = new ArrayList<Double>(n);

            for (int j = 0; j < n; j++) {
                naomi.add(sc.nextDouble());
            }
            for (int j = 0; j < n; j++) {
                ken.add(sc.nextDouble());
            }
            Collections.sort(naomi);
            Collections.sort(ken);

            int d = 0, w=0;
            ArrayList<Double> wnaomi = new ArrayList<Double>(naomi);
            ArrayList<Double> wken = new ArrayList<Double>(ken);

            for (int j = n-1; j >= 0; j--) {
                if(wnaomi.get(j)>wken.get(j)){
                    double kenMn = wken.get(0);
                    wken.remove(0);
                    wken.add(j,kenMn);
                    w++;
                }
            }
            for (int j = 0; j < n; j++) {
                if(naomi.get(j)<ken.get(j)){
                    double kenMx = ken.get(n-1);
                    ken.remove(n-1);
                    ken.add(j,kenMx);
                }
                else {
                    d++;
                }
            }
            System.out.println("Case #"+(i+1)+": "+d+" "+w);
        }
    }
}
