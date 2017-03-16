/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package typewritermonkey;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

/**
 *
 * @author martin
 */
public class TypewriterMonkey {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        String fileName;
        if (args.length < 1) {
            fileName = "/home/martin/GCJ/2015_1C/B/MyTest.txt";
        } else {
            fileName = args[0];
        }
        BufferedReader br = new BufferedReader(new FileReader(fileName));
        String line = br.readLine(); // Number of test cases
        int n = Integer.parseInt(line);
        for (int i = 0; i < n; i++) {
            String y = getPlay(br);
            System.out.println("Case #" + (i + 1) + ": "+y);
            //System.out.printf("Case #%d: %.8f %.8f\n", i+1, y.d, y.t);
        }
    }
    
    private static String getPlay(BufferedReader br) throws IOException {
        String line = br.readLine();
        Scanner s = new Scanner(line);
        int K = s.nextInt();
        int L = s.nextInt();
        int S = s.nextInt();
        line = br.readLine();
        char[] keyboard = line.toCharArray();
        Set<Character> keyboardSet = new HashSet<>();
        Map<Character, Integer> keyboardCharCounts = new HashMap<Character, Integer>();
        for (int i = 0; i < keyboard.length; i++) {
            keyboardSet.add(keyboard[i]);
            Integer cc = keyboardCharCounts.get(keyboard[i]);
            if (cc == null) {
                cc = 1;
            } else {
                cc = cc + 1;
            }
            keyboardCharCounts.put(keyboard[i], cc);
        }
        line = br.readLine();
        String wordStr = line;
        char[] word = line.toCharArray();
        
        for (int i = 0; i < word.length; i++) {
            if (!keyboardSet.contains(word[i])) {
                return "0";
            }
        }
        long maxBananas;
        int overlap = 0;
        int wl = word.length;
        if (wl > 1) {
            overlap = wl-1;
            while (overlap > 0) {
                if (wordStr.endsWith(wordStr.substring(0, overlap))) {
                    break;
                }
                overlap--;
            }
        }
        maxBananas = S/(wl-overlap);
        
        double wordProbability = 1;
        for (int i = 0; i < word.length; i++) {
            char c = word[i];
            wordProbability *= keyboardCharCounts.get(c).doubleValue()/K;
        }
        
        wordProbability *= maxBananas;
        
        return Double.toString(maxBananas - wordProbability);
        /*
        if (wordProbability > 1) {
            wordProbability = 1;
        }
        */
    }
    
}
