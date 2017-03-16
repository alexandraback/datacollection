/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam;

import java.util.*;

/**
 *
 * @author QuanYang
 */
public class CookieClicker {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numTC = sc.nextInt();
        for (int x = 0; x < numTC; x++) {

            double rate = 2.0;//starting rate
            double costFact = sc.nextDouble();
            double factoryRate = sc.nextDouble();
            double aim = sc.nextDouble();
            //base case
            double minTime = aim / rate;
            double fastestFactory = minTime;
            System.out.print("Case #" + (x + 1) + ": ");
            if (aim <= costFact) {
            } else {
                //buy factory
                boolean isFaster = false;
                double tTF = costFact / rate;
                rate += factoryRate;
                double newTime = aim / rate;
                fastestFactory = newTime + tTF;
                while (!isFaster) {
                    tTF += costFact / rate;
                    rate += factoryRate;
                    newTime = aim / rate;
                    if (fastestFactory > (newTime + tTF)) {
                        fastestFactory = newTime + tTF;
                    } else {
                        isFaster = true;
                    }
                }
            }
            System.out.println(Math.min(minTime, fastestFactory));



        }
    }
}
