package edu;

import java.io.*;

/**
 * Created by ав on 16.04.2016.
 */
public class firstA {
    private static String site = "D:\\ol\\A-large.in";
    String alphsm = "abcdefghijklmnopqrstuvwxyz";
    static String alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static int[] array = new int[10];
    static int summ = 0;
    static long n = 0;

    public static void main(String[] args) {
        try {
            BufferedReader in = new BufferedReader(new FileReader((new File(site)).getAbsoluteFile()));
            PrintWriter writer = new PrintWriter("D:\\ol\\name.txt", "UTF-8");
            n = Long.valueOf(in.readLine());
            for (int i = 0; i < n; i++) {
                String line = (in.readLine());
                writer.println("Case #" + (i + 1) + ": " + getSleepNumber(line));
                array = new int[10];
            }
            writer.close();
            in.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
//        for (int i = 200; i < 500; i++) {
//            System.out.println(i * 5 + "variable value = " + getSleepNumber(i * 5));
//            array = new int[10];
//        }

    }

    private static String getSleepNumber(String s) {
        if (s == "") {
            return "";
        }
        String res = ""+(s.charAt(0));
        int firsAl = alph.indexOf(s.charAt(0));
        for (int i = 1; i < s.length(); i++) {
            int curr = alph.indexOf(s.charAt(i));
            if (curr >= firsAl){
                res = s.charAt(i) + res;
                firsAl = curr;
            } else {
                res = res + s.charAt(i);
            }
        }
        return res;
    }


}

