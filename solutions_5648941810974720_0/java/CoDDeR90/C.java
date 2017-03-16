package com.company.gcj;

import java.io.*;
import java.util.Arrays;
import java.util.LinkedHashMap;
import java.util.Map;

/**
 * Created by Daniil on 4/30/2016.
 */
public class C {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("file.in"));

        LinkedHashMap<Integer, String> words = new LinkedHashMap<>();

        words.put(0, "ZERO");
        words.put(1, "ONE");
        words.put(2, "TWO");
        words.put(3, "THREE");
        words.put(4, "FOUR");
        words.put(5, "FIVE");
        words.put(6, "SIX");
        words.put(7, "SEVEN");
        words.put(8, "EIGHT");
        words.put(9, "NINE");

        LinkedHashMap<Integer, Character> map = new LinkedHashMap<>();

        map.put(0, 'Z');
        map.put(2, 'W');
        map.put(6, 'X');
        map.put(8, 'G');
        map.put(4, 'U');
        map.put(1, 'O');
        map.put(3, 'T');
        map.put(5, 'F');
        map.put(7, 'S');
        map.put(9, 'I');

        PrintWriter pw = new PrintWriter(new FileWriter("large_output.txt"));


        int t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; ++ i){
            int[] cnt = new int[500];
            Arrays.fill(cnt, 0);
            String s = br.readLine();
            for (int j = 0;j < s.length(); ++j){
                cnt[s.charAt(j)]++;
            }

            StringBuilder res = new StringBuilder();
            for (Map.Entry<Integer, Character> e: map.entrySet()){
                int c = cnt[e.getValue()];
                String word = words.get(e.getKey());
                for (int j = 0 ;j < c; ++ j){
                    res.append(e.getKey());
                    for (int k = 0; k < word.length(); ++ k){
                        cnt[word.charAt(k)]--;
                    }
                }
            }

            String original = res.toString();
            char[] chars = original.toCharArray();
            Arrays.sort(chars);
            String sorted = new String(chars);

            pw.println("Case #" + i + ": " + sorted);
        }

        pw.flush();
        pw.close();
    }
}
