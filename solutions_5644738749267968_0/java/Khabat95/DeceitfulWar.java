import java.util.*;

/**
 * Created by khabat95 on 12/04/14.
 */
public class DeceitfulWar {


    public static int war(Vector<Double> naomi, Vector<Double> ken) {
        int res = 0;
        while (!naomi.isEmpty()) {
            if (naomi.lastElement() > ken.lastElement()) {
                res++;
                naomi.remove(naomi.lastElement());
                ken.remove(ken.firstElement());
            } else {
                naomi.remove(naomi.lastElement());
                ken.remove(ken.lastElement());
            }
        }
        return res;
    }

    public static int deceitfulWar(Vector<Double> naomi, Vector<Double> ken) {
        int res = 0;
        while (!naomi.isEmpty()) {
            if (naomi.lastElement() > ken.lastElement()) {
                res++;
                Double ken_val = ken.firstElement();
                Double naomi_val = naomi.firstElement();
                for (int i=0; i<naomi.size(); i++) {
                    naomi_val = naomi.get(i);
                    if (naomi_val > ken_val) {
                        break;
                    }
                }
                naomi.remove(naomi_val);
                ken.remove(ken_val);
            } else {
                naomi.remove(naomi.firstElement());
                ken.remove(ken.lastElement());
            }
        }
        return res;
    }

    public static void main(String args[]) {
        int T = Integer.valueOf(args[0]);
        int cur = 1;
        for (int i = 0; i < T; i++) {
            int size = Integer.valueOf(args[cur]);
            cur++;
            Vector<Double> naomi = new Vector<Double>();
            Vector<Double> ken = new Vector<Double>();
            for (int j = 0; j < size; j++) {
                naomi.add(Double.valueOf(args[cur]));
                cur++;
            }
            for (int j = 0; j < size; j++) {
                ken.add(Double.valueOf(args[cur]));
                cur++;
            }
            Collections.sort(naomi);
            Collections.sort(ken);
            System.out.println("Case #" + (i + 1) + ": " + deceitfulWar(new Vector<Double>(naomi), new Vector<Double>(ken)) + " " + war(new Vector<Double>(naomi), new Vector<Double>(ken)));
        }
    }
}
