package com.company.gcj;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;

/**
 * Created by Daniil on 4/30/2016.
 */
public class A {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("file.in"));

        PrintWriter pw = new PrintWriter(new FileWriter("large_output.txt"));


        int t = Integer.parseInt(br.readLine());

        for (int i = 1; i <= t; ++ i){
            int n = Integer.parseInt(br.readLine());

            List<String> f = new ArrayList<>();
            List<String> s = new ArrayList<>();

            for (int j =0 ; j < n; ++ j){
                String[] l = br.readLine().split(" ");
                f.add(l[0]);
                s.add(l[1]);
            }

            boolean[] usedf = new boolean[n];
            boolean[] useds = new boolean[n];
            Arrays.fill(usedf, false);
            Arrays.fill(useds, false);
            for (int j =0; j < n; ++ j){
                for (int k = 0; k < n; ++ k){
                    if (k == j) continue;
                    if (f.get(j).equals(f.get(k))){
                        usedf[j] = true;
                        break;
                    }
                }
            }

            for (int j =0; j < n; ++ j){
                for (int k = 0; k < n; ++ k){
                    if (k == j) continue;
                    if (s.get(j).equals(s.get(k))){
                        useds[j] = true;
                        break;
                    }
                }
            }

            int res = 0;

            for (int j = 0;j < n; ++ j){
                if (usedf[j] == true && useds[j] == true){
                    res++;
                }
            }

            pw.println("Case #" + i + ": " + res);
        }


        pw.flush();
        pw.close();
    }


}
