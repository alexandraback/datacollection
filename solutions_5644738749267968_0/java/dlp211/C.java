

import java.util.*;

public class C {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        for (int k = 1; k <= n; ++k ) {
            int a = scanner.nextInt();
            LinkedList<Double> naomi = new LinkedList<Double>();
            LinkedList<Double> ken = new LinkedList<Double>();
            LinkedList<Double> naomi2 = new LinkedList<Double>();
            LinkedList<Double> ken2 = new LinkedList<Double>();
            for ( int i = 0; i < a; ++i ) {
                double d = scanner.nextDouble();
                naomi.add(d);
                naomi2.add(d);
            }
            for ( int i = 0; i < a; ++i ) {
                double d = scanner.nextDouble();
                ken.add(d);
                ken2.add(d);
            }
            Collections.sort(naomi);
            Collections.sort(ken);
            Collections.reverse(naomi);
            Collections.reverse(ken);
            Collections.sort(naomi2);
            Collections.sort(ken2);
            Collections.reverse(naomi2);
            Collections.reverse(ken2);


            //WAR
            int score = 0;
            for ( double d : naomi ) {
                if ( ken.peekFirst() < d ) {
                    ken.removeLast();
                    score++;
                }
                else {
                    int j = -1;
                    double prev = 0;
                    double now = 0;
                    ListIterator<Double> it = ken.listIterator();
                    while (it.hasNext()) {
                        now = it.next();
                        if (now < d) {
                            ken.remove(j);
                            break;
                        }

                        prev = now;
                        ++j;
                    }
                }
            }
            int dscore = 0;
            int temp = 0;
            while(ken2.size() != 0) {
                ListIterator<Double> it1 = naomi2.listIterator();
                ListIterator<Double> it2 = ken2.listIterator();
                temp = 0;
                while (it1.hasNext()) {
                    double w = it1.next();
                    double x = it2.next();
                    if ( w > x )
                        temp++;
                }
                if (temp > dscore)
                    dscore = temp;
                naomi2.removeLast();
                ken2.removeFirst();
                if (dscore > ken2.size())
                    break;

            }
            System.out.format("Case #%d: %d %d\n", k, dscore, score);


        }
    }
}
