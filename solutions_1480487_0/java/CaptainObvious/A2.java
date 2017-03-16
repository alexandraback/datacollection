package com.vlatynski;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

public class A2 {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner s = new Scanner(new File(args[0]));

        int N = s.nextInt();

        for(int i=0;i<N;i++) {
            int P = s.nextInt();
            int[] values = new int[P];
            for(int j=0;j<P;j++) {
                values[j] = s.nextInt();
            }
            System.out.println("Case #"+(i+1)+": " + solution(P, values));
        }
        //System.out.println(s.nextInt());
    }

    private static String solution(int p, int[] values) {
        int sum = 0;
        for(int i=0;i<values.length;i++) {
            sum+=values[i];
        }
        double avg = sum * 2.0 / p;

        double [] vals = new double[p];

        StringBuilder res = new StringBuilder();

        double newSum = sum;
        double newAvg = 0;
        int counter = 0;
        for(int i=0;i<p;i++) {
            if(values[i]<avg) {
                newSum+=values[i];
                counter++;
            }
        }
        newAvg = newSum / counter;

        for(int i=0;i<p;i++) {
            vals[i] = values[i]>=avg ? 0 : (newAvg-values[i]) * 1.0 / sum;
            res.append(String.format(Locale.ENGLISH, "%.6f",100 * vals[i]) + " ");
        }
        return res.toString();
    }
}
