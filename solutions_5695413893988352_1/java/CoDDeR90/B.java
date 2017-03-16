package com.company.gcj;

import java.io.*;

/**
 * Created by Daniil on 4/30/2016.
 */
public class B {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("file.in"));

        PrintWriter pw = new PrintWriter(new FileWriter("large_output.txt"));

        int t = Integer.parseInt(br.readLine());


        for (int i = 1; i <= t; ++ i){

            StringBuilder cStr = new StringBuilder();
            StringBuilder jStr = new StringBuilder();
            String line = br.readLine();

            String[] p = line.split(" ");

            long c = 0,j = 0;


                for (int k =0 ;k < p[0].length() - 2; ++ k){
                    long min = -1, mincd = -1;
                    long minjd = -1;

                    for (int dc = 0; dc < 1000; ++ dc){
                        if (!check(dc, p[0].substring(k, k + 3)))continue;
                        long tc = c*1000 + dc;

                        for (int dj = 0; dj < 1000; ++ dj){
                            if (!check(dj, p[1].substring(k, k + 3)))continue;
                            long tj = j*1000 + dj;
                            if (min == -1 || min > Math.abs(tc - tj)){
                                min = Math.abs(tc - tj);
                                mincd = dc;
                                minjd = dj;
                            }
                        }
                    }
                    cStr.append((char)(((mincd / 100) % 10) + '0'));
                    jStr.append((char)(((minjd / 100) % 10) + '0'));
                    c = c * 10 + ((mincd / 100) % 10);
                    j = j * 10 + ((minjd / 100) % 10);

                }


            long min = -1, mincd = -1;
            long minjd = -1;

            if (p[0].length() > 1) {
                for (int dc = 0; dc < 100; ++dc) {
                    if (!check(dc, p[0].substring(p[0].length() - 2))) continue;
                    long tc = c * 100 + dc;

                    for (int dj = 0; dj < 100; ++dj) {
                        if (!check(dj, p[1].substring(p[1].length() - 2))) continue;
                        long tj = j * 100 + dj;
                        if (min == -1 || min > Math.abs(tc - tj)) {
                            min = Math.abs(tc - tj);
                            mincd = dc;
                            minjd = dj;
                        }
                    }
                }
                cStr.append((char) (((mincd / 10) % 10) + '0'));
                jStr.append((char) (((minjd / 10) % 10) + '0'));
                c = c * 10 + ((mincd / 10) % 10);
                j = j * 10 + ((minjd / 10) % 10);
            }

            min = -1;
            mincd = -1;
            minjd = -1;

            for (int dc = 0; dc < 10; ++ dc){
                if (!check(dc, p[0].charAt(p[0].length() - 1) + ""))continue;
                long tc = c*10 + dc;

                for (int dj = 0; dj < 10; ++ dj){
                    if (!check(dj, p[1].charAt(p[1].length() - 1) + ""))continue;
                    long tj = j*10 + dj;
                    if (min == -1 || min > Math.abs(tc - tj)){
                        min = Math.abs(tc - tj);
                        mincd = dc;
                        minjd = dj;
                    }
                }
            }
            cStr.append((char)((mincd) + '0'));
            jStr.append((char)((minjd) + '0'));

            c = c * 10 + mincd ;
            j = j * 10 + minjd ;


            pw.println("Case #" + i + ": " + cStr + " " + jStr);
        }

        pw.flush();
        pw.close();
    }

    public static boolean check(int n, String m){
        String s = "" + n;
        while (s.length() < m.length()){
            s = "0" + s;
        }

        for (int i =0 ;i < s.length(); ++ i){
            if (m.charAt(i) != '?' && m.charAt(i) != s.charAt(i))return false;
        }
        return true;
    }

}
