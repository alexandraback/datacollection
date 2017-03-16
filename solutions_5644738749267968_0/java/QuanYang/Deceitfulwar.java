/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam;

import java.util.*;

/**
 *
 * @author QuanYang Matric No: A0111889W
 */
public class Deceitfulwar {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numTC = sc.nextInt();
        for (int x = 0; x < numTC; x++) {
            int numBlock = sc.nextInt();
            ArrayList<Double> Naomi = new ArrayList<Double>();
            ArrayList<Double> Ken = new ArrayList<Double>();
            ArrayDeque<Double> Naomi2 = new ArrayDeque<Double>();
            ArrayDeque<Double> Ken2 = new ArrayDeque<Double>();
            ArrayDeque<Double> Naomi3 = new ArrayDeque<Double>();
            ArrayDeque<Double> Ken3 = new ArrayDeque<Double>();

            for (int i = 0; i < numBlock; i++) {
                Naomi.add(sc.nextDouble());
            }
            for (int i = 0; i < numBlock; i++) {
                Ken.add(sc.nextDouble());
            }
            Collections.sort(Naomi);
            Collections.sort(Ken);
        //    System.out.println(Naomi);
        //    System.out.println(Ken);
            int legit = 0;
            int deceit = 0;
            for (int i = 0; i < numBlock; i++) {
                Naomi2.offer(Naomi.get(i));
                Ken2.offer(Ken.get(i));

                Naomi3.offer(Naomi.get(i));
                Ken3.offer(Ken.get(i));
            }

            while (!Naomi2.isEmpty()) {
                //legit
                if (Naomi2.peekLast() > Ken2.peekLast()) {
                    legit++;
                    Naomi2.pollLast();
                    Ken2.pollFirst();
                } else {
                    Naomi2.pollLast();
                    Ken2.pollLast();
                }
                
                if (Naomi3.peekLast() < Ken3.peekLast()){
                    Naomi3.pollFirst();
                    Ken3.pollLast();
                } else {
                    deceit++;
                    Naomi3.pollLast();
                    Ken3.pollLast();
                }
            }
            System.out.print("Case #" + (x + 1) + ": ");
            System.out.println(deceit+" "+legit);

        }
    }
}
