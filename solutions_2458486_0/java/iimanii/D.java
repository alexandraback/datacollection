/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Jam2013;

import base.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Queue;

/**
 *
 * @author Ahmed Tarek
 */
public class D extends base {
        
    static String jam = "Jam2013";
    static String round = "Qualification";
    
    static String problem = "D";
    static String inputSize = "small";
    
    static HashMap<String, String> solutionSet;
    
    static int maxKeys = 201;
    
    public static class Chest {
        int type;
        int[] keys;
        Chest(int t, int[] k) {
            type = t;
            keys = k;
        }
    }
    
    public static void main(String[] args) throws Exception {  
        checkDir("input/"+jam+"/"+round); 
        checkDir("output/"+jam+"/"+round);
        Queue<String> file = file("input/"+jam+"/"+round+"/"+problem+"-"+inputSize+"-attempt3.in");
        StringBuilder output = new StringBuilder(200);
        
        int T = Integer.parseInt(file.poll());
        for(int i=0; i < T && !file.isEmpty(); i++) { 
            String[] t = file.poll().split(" ");
            int N = Integer.parseInt(t[1]);
            int[] keys = new int[maxKeys];
            Chest[] Chests = new Chest[N];
            String[] K = file.poll().split(" ");
            for(String a : K)
                keys[Integer.parseInt(a)]++;
            
            for(int j=0; j < N; j++) {
                String[] l = file.poll().split(" ");
                int type = Integer.parseInt(l[0]);
                int[] k = new int[Integer.parseInt(l[1])];
                for(int m=2; m < k.length+2; m++)
                    k[m-2] = Integer.parseInt(l[m]);
                
                Chests[j] = new Chest(type, k);
            }
            
            solutionSet = new HashMap<String, String>();
            output.append("Case #").append(i+1).append(": ").append(solutionSmall(keys, Chests)).append("\r\n");
        }
        
        writeFile("output/"+jam+"/"+round+"/"+problem+"-"+inputSize+"-attempt3.out", output.toString());
        System.out.println(output);
    }
    
    /* can brute force for 20 chests / memoize */
    public static String solutionSmall(int[] Keys, Chest[] Chests) {
        boolean isEmpty = true;
        for(int i=0; i < Chests.length; i++) {
            if(Chests[i] == null)
               continue;
            
            isEmpty = false;
            Chest a = Chests[i];
            if(Keys[a.type] == 0)
               continue;
            
            /* clone stuff and open it */
            int[] cloneKeys = Keys.clone();
            Chest[] cloneChests = Chests.clone();
            for(int j=0; j < a.keys.length; j++)
                cloneKeys[a.keys[j]]++;
            
            cloneKeys[a.type]--;
            cloneChests[i] = null;
            
            String hash = createHash(cloneChests);
            if(!solutionSet.containsKey(hash))
                solutionSet.put(hash, solutionSmall(cloneKeys, cloneChests));
            
            String t = solutionSet.get(hash);
            
            if(!t.equals("IMPOSSIBLE")) {
                return Integer.toString(i+1) + (t.equals("") ? t:" "+t);
            }
        }

        return isEmpty ? "":"IMPOSSIBLE";
    }
    
    public static String createHash(Chest[] Chests) {
        StringBuilder s = new StringBuilder();
        
        for(Chest c: Chests)
            s.append(c == null ? "0":"1");
        
        return s.toString();
    }
}
