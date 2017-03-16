/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Bc. Vojtech Kral, student of FIT at CTU in Prague
 */
public class DeceitfulWar {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        File f = new File(Helper.inputFolder + "D-small-attempt0.in");

        Scanner sc = new Scanner(f);

        int numberOfTestCase = Integer.parseInt(sc.nextLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= numberOfTestCase; i++) {
            sc.nextLine();//number of numbers
//            String naomi = "0.186 0.389 0.907 0.832 0.959 0.557 0.300 0.992 0.899";
//            String ken = "0.916 0.728 0.271 0.520 0.700 0.521 0.215 0.341 0.458";
            String naomi = sc.nextLine();
            String ken = sc.nextLine();



            List<Double> naomis = new ArrayList<Double>();
            List<Double> kens = new ArrayList<Double>();
            for (String string : naomi.split(" ")) {
                naomis.add(Double.parseDouble(string));
            }

            for (String string : ken.split(" ")) {
                kens.add(Double.parseDouble(string));
            }

            int normalWar = normalWar(naomis, kens);
            int deceitfulWar = deceitfulWar(naomis, kens);
            sb.append("Case #").append(i).append(":").append(" ").append(deceitfulWar).append(" ").append(normalWar).append(System.getProperty("line.separator"));

        }
        System.out.println(sb.toString());
         Helper.write(sb, DeceitfulWar.class.getName() + ".txt");
    }

    private static int normalWar(List<Double> naomis, List<Double> kens) {
        List<Double> kensCopy = new ArrayList<Double>(kens.size());
        for (Double double1 : kens) {
            kensCopy.add(double1);
        }

        int naomiPoints = 0, kenPoints = 0;
        for (Double naomisPick : naomis) {
            Double kensPick = kensPick(naomisPick, kensCopy);
            if (naomisPick < kensPick) {
                kenPoints++;
            } else {
                naomiPoints++;
            }
            kensCopy.remove(kensPick);
        }

        return naomiPoints;
    }

    /**
     * 
     * @param naomis
     * @param kens
     * @return  points naomi
     */
    private static int deceitfulWar(List<Double> naomis, List<Double> kens) {
        List<Double> kensCopy = new ArrayList<Double>(kens.size());
        for (Double double1 : kens) {
            kensCopy.add(double1);
        }

        int naomiPoints = 0, kenPoints = 0;
        Collections.sort(naomis);
        for (Double naomisPick : naomis) {
            Double naomisSay = getNaomisSay(naomisPick, kensCopy);
            Double kensPick = kensPick(naomisSay, kensCopy);
            if (naomisPick < kensPick) {

                kenPoints++;
            } else {
                naomiPoints++;
            }
            kensCopy.remove(kensPick);
        }

        return naomiPoints;
    }

//    static List<List<Double>> createAllPermutations(List<Double> naomis){
//        
//    }
//    
//    static void recursive(List<List<Double>> output, List<Double> naomis, int index){
//        for (List<Double> list : output) {
//            for (int i = i; i < naomis.size(); i++) {
//                Object object = arr[i];
//                
//            }
//               
//        }
//    }
    private static Double getNaomisSay(Double realNaomis, List<Double> kens) {
        Collections.sort(kens);
        Double kensHighest = kens.get(kens.size() - 1);
//        Double kensSecondHighes = kens.get(kens.size() - 2);
        Double kensLowest = kens.get(0);

        if (realNaomis > kensLowest) {
            return kensHighest + 0.000001;
        } else if (realNaomis < kensHighest) {
            return kensHighest - 0.000001;
        } else {
            return realNaomis;
        }

    }

    private static Double kensPick(Double naomis, List<Double> kens) {
        Collections.sort(kens);
        Double minimum = kens.get(0);

        Double closesHigher = null;

        for (Double integer : kens) {
            if (integer > naomis) {
                closesHigher = integer;
                break;
            }
        }

        if (closesHigher == null) {
            return minimum;
        } else {
            return closesHigher;
        }

    }
}
