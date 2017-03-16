/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.*;
import java.math.*;

/**
 *
 * @author .
 */
public class C {

    public static class Num {

        int number;
        String num;
        ArrayList<Integer> recycled;

        Num(int number) {
            this.number = number;
            num = new String();
            num += number;
            recycled = new ArrayList<Integer>();
            //pl(number);
            findAllRecycleds();
        }

        void findAllRecycleds() {
            String sub;
            int subValue;
            for (int i = 1; i < num.length(); i++) {
                sub = num.substring(i, num.length()) + num.substring(0, i);
                //pl("-" + sub);
                if (sub.charAt(0) == '0') {
                    continue;
                }
                subValue = Integer.parseInt(sub);
                if (subValue > number) {
                    
                    if(!recycled.contains(subValue)) {
                    recycled.add(subValue);
                    } else {
                        //pl(number + " contains " + subValue);
                    }
                    
                    Collections.sort(recycled);
                }
            }

            
        }

        int countRecycleds(int max) {
            int count = 0;

            for (Integer i : recycled) {
                if (i <= max) {
                    count++;
                } else {
                    break;
                }
            }

            return count;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = Integer.parseInt(in.nextLine());

        HashMap<Integer, Num> array = new HashMap<Integer, Num>(2000001);

        int MIN = 1;
        int MAX = 2000000;

        for (int kase = 1; kase <= T; kase++) {
            int A = in.nextInt();
            int B = in.nextInt();

            //----------------------------------------------------

            int count = 0;
            
            for (int i = A; i <= B; i++) {
                if(!array.containsKey(i)) {
                    array.put(i, new Num(i));
                }
                count += array.get(i).countRecycleds(B);
            }

            pl("Case #" + kase + ": " + count);
        }
    }

    public static void pf(String s, Object... o) {
        System.out.printf(s, o);
    }

    public static void pl(Object o) {
        System.out.println(o);
    }

    public static void pr(Object o) {
        System.out.print(o);
    }
}
