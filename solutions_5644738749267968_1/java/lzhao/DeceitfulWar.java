import java.util.*;
public class DeceitfulWar {

    public static int deceitWar(List<Double> naomi, List<Double> ken, int nScore) {
        if(naomi.size() == 0) {
            return nScore;
        }

        if(naomi.get(0) < ken.get(0)) {
            naomi.remove(0);
            ken.remove(ken.size() - 1);
        } else {
            naomi.remove(0);
            ken.remove(0);
            nScore ++;
        }

        return deceitWar(naomi, ken, nScore);

    }

    public static int war(List<Double> naomi, List<Double> ken) {
        if(naomi.size() == 0) {
            return 0;
        }

        int nextKenLarger = -1;

        for(int i = 0; i < ken.size(); ++i) {
            if(ken.get(i) > naomi.get(0)) {
                nextKenLarger = i;
                break;
            }
        }

        if(nextKenLarger >= 0) {
            naomi.remove(0);
            ken.remove(nextKenLarger);
            return war(naomi, ken);
        } else {
            return naomi.size();
        }


    }

    public static void main (String[] args) {
        Arrays.sort(args);
        System.out.println(Arrays.toString(args));
    }

}
