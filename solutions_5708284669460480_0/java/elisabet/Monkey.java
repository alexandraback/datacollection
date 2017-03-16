package com.elsa.monkey;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by elisabet on 2015-05-10.
 */
public class Monkey {
    public static void main(String[] args) {
        try {
            String path = args[0];
            Monkey m = new Monkey();
            List<String> result = m.readFile(path);
            String outPath = "/home/elisabet/temp.out";

            PrintWriter pw = new PrintWriter(outPath);
            for (String s : result) {
                pw.println(s);
            }
            pw.close();
        } catch (IOException e) {
            System.out.println("IOException: "+e.getMessage());
        }
    }
    private List<String> readFile(String path) throws IOException {
        FileReader fr = new FileReader(path);
        BufferedReader br = new BufferedReader(fr);
        List<String> result = new ArrayList<String>();

        int m = Integer.parseInt(br.readLine());

        for (int i = 1; i<=m; i++){
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.append("Case #"+i+": ");

            int[] t = readExample(br);
            String keys = br.readLine();
            String word = br.readLine();
            double a = solve(t[0], t[1], t[2], keys, word);
            String str = String.format("%.6f", a);

            stringBuilder.append(str);
            result.add(stringBuilder.toString());
            System.out.println(stringBuilder);
        }
        return result;
    }


    private int[] readExample(BufferedReader br) throws IOException{
        String[] strings= br.readLine().split(" ");
        int[] ret = new int[strings.length];
        for (int i = 0; i < strings.length; i++) {
            ret[i] = Integer.parseInt(strings[i]);
        }
        return ret;
    }

    private double solve(int K, int L, int S, String keys, String word) {
        if (L > S) return 0;
        Set<String> keyset = new HashSet<String>(Arrays.asList(keys.split("")));
        Set<String> lettersNeeded = new HashSet<String>(Arrays.asList(word.split("")));
        if (keyset.size() < lettersNeeded.size()) return 0;
        if (!keyset.containsAll(lettersNeeded)) return 0;
        int overlap = 0;
        int j =0;
        for (int i = L; i > 1 ; i--) {
            j++;
            if (word.startsWith(word.substring(i))) overlap = j;
        }
        int maxBananas = (S-L) / (L - overlap);
        maxBananas++;
        double expected = 0.0;

        List<String> keylist = Arrays.asList(keys.split(""));
        List<String> wordlist = Arrays.asList(word.split(""));
        //System.out.println(wordlist.size() + ", l:"+L);
        //System.out.println(keylist.size() + ", k:"+K);

        for (int i = 0; i < S-L+1; i++) {
            double p= 1.0;
            for (int k = 1; k < wordlist.size(); k++) {
                String letter = wordlist.get(k);
                double occurrences = Collections.frequency(keylist, letter);

                p *= occurrences/K;
                //System.out.println(p+" "+occurrences +" " +K);
            }
            //System.out.println(false);
            expected += p;
        }
        //System.out.println("max: "+maxBananas+", expected: "+expected);
        return maxBananas - expected;
    }
}
