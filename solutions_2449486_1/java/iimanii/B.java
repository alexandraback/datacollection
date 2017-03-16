/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Jam2013;

import base.*;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 *
 * @author Ahmed Tarek
 */
public class B extends base {
        
    static String jam = "Jam2013";
    static String round = "Qualification";
    
    static String problem = "B";
    static String inputSize = "large";
    
    public static void main(String[] args) throws Exception {  
        checkDir("input/"+jam+"/"+round); 
        checkDir("output/"+jam+"/"+round);
        Queue<String> file = file("input/"+jam+"/"+round+"/"+problem+"-"+inputSize+".in");
        StringBuilder output = new StringBuilder(200);
        
        int T = Integer.parseInt(file.poll());
        for(int i=0; i < T && !file.isEmpty(); i++) {
            String[] t = file.poll().split(" ");
            int N = Integer.parseInt(t[0]);
            int M = Integer.parseInt(t[1]);
            int map[][] = new int[N][M];
            for(int j=0; j < N; j++) {
                String[] m = file.poll().split(" ");
                for(int k=0; k < M; k++)
                    map[j][k] = Integer.parseInt(m[k]);
            }
            output.append("Case #").append(i+1).append(": ").append(solution(map)).append("\r\n");
        }
        
        writeFile("output/"+jam+"/"+round+"/"+problem+"-"+inputSize+"-.out", output.toString());
        System.out.println(output);
    }
    
    static class triple {
        int i, v;
        char t;
        triple(int a,int b, char c) {
            i = a;
            v = b;
            t = c;
        }
    }
    
    public static String solution(int[][] map) {
        int N = map.length, M = map[0].length;
        int[][] testMap = new int[N][M];
        
        Comparator<triple> compare = new Comparator<triple>() {
            @Override
            public int compare(triple o1, triple o2) {
                return o2.v - o1.v;
            }
        };
        
        PriorityQueue<triple> max = new PriorityQueue<triple>(M+N, compare);
                
        if(N == 1 || M == 1)
           return "YES";
        
        /* get maxes */
        for(int i=0; i < N; i++)
            max.add(new triple(i, map[i][max(map[i])], 'r'));
            
        for(int i=0; i < M; i++) {
            int m = map[0][i];
            for(int j=1; j < N; j++)
                if(map[j][i] > m)
                   m = map[j][i];
            
            max.add(new triple(i, m, 'c'));
        }
        
        while(!max.isEmpty()) {
            triple a = max.poll();
            if(a.t == 'r')
               for(int i=0; i < M; i++)
                   testMap[a.i][i] = a.v;
            else
               for(int i=0; i < N; i++)
                   testMap[i][a.i] = a.v;               
        }

        for(int i=0; i < N; i++)
            for(int j=0; j < M; j++)
                if(map[i][j] != testMap[i][j])
                   return "NO";

        return "YES";
    }
}
