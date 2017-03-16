package edu;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by �� on 16.04.2016.
 */
public class secondA {

        private static String site = "D:\\ol\\B-large.in";
        String alphsm = "abcdefghijklmnopqrstuvwxyz";
        static String alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        static int[] array = new int[10];
    static ArrayList<Integer> count = new ArrayList<>();

        static long l = 0;
        static long n = 0;

        public static void main(String[] args) {

            try {
//                BufferedReader in = new BufferedReader(new FileReader((new File(site)).getAbsoluteFile()));
                PrintWriter writer = new PrintWriter("D:\\ol\\name.txt", "UTF-8");
                Scanner sc = new Scanner(new File(site));
                n = sc.nextInt();
                for (int i = 0; i < 2555 ; i++) {
                    count.add(i,0);
                }
                for (int i = 0; i < n; i++) {
                    for (int m = 0; m < 2555 ; m++) {
                        count.set(m,0);
                    }
                    l = sc.nextInt();

                for (int k = 0; k < l; k++)
                {
                    for (int j = 0; j < 2*l-1; j++)
                    {
                        int integ = sc.nextInt();
                        if (count.get(integ)!=0) {
                            count.set(integ, count.get(integ)+1);
                        } else {
                            count.set(integ, 1);
                        }
                    }
                }

//                    String val = (in.readLine());
                    writer.println("Case #" + (i + 1) + ": " + getSleepNumber());
                    array = new int[10];
                }
                writer.close();
//                in.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
//        for (int i = 200; i < 500; i++) {
//            System.out.println(i * 5 + "variable value = " + getSleepNumber(i * 5));
//            array = new int[10];
//        }

        }

        private static String getSleepNumber() {

            String res = "";
            for (int i = 0; i < 2555; i++) {
                if (count.get(i) % 2 == 1){
                    res = res + i + " ";
                }
            }
            return res.substring(0,res.length()-1);
        }





}
