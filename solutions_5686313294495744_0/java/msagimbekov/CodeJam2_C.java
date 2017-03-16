
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Madi
 */
public class CodeJam2_C {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        try (BufferedReader br = new BufferedReader(new FileReader("C:/Users/Madi/codejam/C-small-practice.in"));
                BufferedWriter bw = new BufferedWriter(new FileWriter("C:/Users/Madi/codejam/C-small-practice.out"))) {

            int t = Integer.parseInt(br.readLine());

            for (int i = 0; i < t; i++) {
                int n = Integer.parseInt(br.readLine());
                String[] first = new String[n];
                String[] second = new String[n];
                for (int j = 0; j < n; j++) {
                    String[] s = br.readLine().split(" ");
                    first[j] = s[0];
                    second[j] = s[1];
                }

                solve(i + 1, first, second, bw);
            }

        }

    }

    private static void solve(int cs, String[] first, String[] second, BufferedWriter bw) throws FileNotFoundException, IOException {

        int n = first.length;

        Map<String, Integer> map1 = new HashMap<>();
        Map<String, Integer> map2 = new HashMap<>();

        for (int i = 0; i < n; i++) {
            if (!map1.containsKey(first[i])) {
                map1.put(first[i], 1);
            } else {
                map1.put(first[i], map1.get(first[i]) + 1);
            }

            if (!map2.containsKey(second[i])) {
                map2.put(second[i], 1);
            } else {
                map2.put(second[i], map2.get(second[i]) + 1);
            }
        }

        int[] count1 = new int[n];
        int[] count2 = new int[n];

        for (int i = 0; i < n; i++) {
            count1[i] = map1.get(first[i]);
            count2[i] = map2.get(second[i]);
        }

        int res = 0;
        boolean cont = true;
        while (cont) {
            cont = false;
            int index = 0;
            int min = 100;
            for (int i = 0; i < n; i++) {    
                if (count1[i] > 1 && count2[i] > 1 && min > count1[i] + count2[i]) {
                    cont = true;
                    min = count1[i] + count2[i];
                    index = i;
                }
            }
            if (cont) {
                res++;
                map1.put(first[index], map1.get(first[index]) - 1);
                map2.put(second[index], map2.get(second[index]) - 1);
                for (int j = 0; j < n; j++) {
                    count1[j] = map1.get(first[j]);
                    count2[j] = map2.get(second[j]);
                }
            }
        }

        bw.write("Case #" + cs + ": " + res + "\n");
        bw.flush();
    }
}
