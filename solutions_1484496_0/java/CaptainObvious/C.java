package com.vlatynski;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class C {

    public static final String ZEROES = "00000000000000000000";

    public static void main(String[] args) throws FileNotFoundException {
        Scanner s = new Scanner(new File(args[0]));

        int T = s.nextInt();

        for(int i=0;i<T;i++) {
            int N = s.nextInt();
            int[] values = new int[N];
            for(int j=0;j<N;j++) {
                values[j] = s.nextInt();
            }
            System.out.println("Case #"+(i+1)+": " + solution(N, values));
        }
    }

    private static String solution(int n, int[] values) {
        int MAX = Integer.parseInt("11111111111111111111",2);
        Map<Integer,String> sums = new HashMap<Integer, String>();
        String m = "",m1 = "";
        int sum;
        boolean found = false;
        for(int i=0;i<=MAX;i++) {
            sum = 0;
            m = Integer.toString(i,2);
            m = ZEROES.substring(m.length()) + m;
            for(int j=0;j<20;j++) {
                if(m.charAt(j)=='1') sum+=values[j];
            }
            if(sums.containsKey(sum)) {
                // found, yaho-o-o-o
                m1 = sums.get(sum);
                found = true;
                break;
            } else {
                sums.put(sum,m);
            }
        }
        if(found) {
            return "\n"+getByString(m,values) + "\n" + getByString(m1,values);
        } else {
            return "Impossible";
        }
    }

    private static String getByString(String m, int[] values) {
        StringBuilder b = new StringBuilder();
        for(int k=0;k<20;k++) {
            if(m.charAt(k)=='1') b.append(values[k]).append(" ");
        }
        return b.toString();
    }

}
