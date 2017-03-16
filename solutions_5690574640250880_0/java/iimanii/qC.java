/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Jam2014;

import base.base;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Queue;

/**
 *
 * @author Ahmed Tarek    Apr 12, 2014
 */
public class qC extends base {   
    static String jam = "Jam2014";
    static String round = "Qualification";
    
    static String problem = "C";
    static String inputSize = "small";
    static String attempt = "attempt4";
    
    static HashMap<String, char[][]> memo = new HashMap<String, char[][]>();
            
    public static void main(String[] args) throws Exception {  
        checkDir("input/"+jam+"/"+round); 
        checkDir("output/"+jam+"/"+round);
        Queue<String> file = file("input/"+jam+"/"+round+"/"+problem+"-"+inputSize+"-"+attempt+".in");
        StringBuilder output = new StringBuilder(200);
        
        int T = Integer.parseInt(file.poll());
        for(int i=0; i < T && !file.isEmpty(); i++) {
            String[] t = file.poll().split(" ");
            int R = Integer.parseInt(t[0]);
            int C = Integer.parseInt(t[1]);
            int M = Integer.parseInt(t[2]);
            
            output.append("Case #").append(i+1).append(":").append(solution(R, C, M)).append("\r\n");
        }
        
        writeFile("output/"+jam+"/"+round+"/"+problem+"-"+inputSize+"-"+attempt+".out", output.toString());
        System.out.println(output);
    }
    
    public static String solution(int r, int c, int m) {
        if(impossible(r, c, m))
           return "\r\nImpossible";

        char[][] map = draw(r, c, m);
        
        map[map.length-1][map[0].length-1] = 'c';

        StringBuilder output = new StringBuilder();
        for (char[] row : map)
            output.append("\r\n").append(row);
        
        return output.toString();
    }

    private static boolean impossible(int r, int c, int m) {
        if(r == 1 || c == 1)
           return false;
        
        int freeCells = r * c - m;
        
        if((r == 2 || c == 2) && (m % 2) != 0 && freeCells != 1)
           return true;
        
        switch(freeCells) {
            case 2:
            case 3:
            case 5:
            case 7:
                return true;
        }
        
        return false;
    }
    
    public static char[][] draw(int r, int c, int m) {
        boolean flip = false;
        if(r > c) {
           flip = true;
           int t = c; c = r; r = t;
        }
        
        String key = r+"-"+c+"-"+m;
        char[][] map;
        
        if(memo.containsKey(key)) {
           map = memo.get(key);
        } else {
            map = new char[r][c];

            if(m >= r) {
               for(int i=0; i < r; i++)
                   map[i][0] = '*';

               char[][] sub = draw(r, c-1, m-r);

               for(int i=0; i < r; i++)
                   System.arraycopy(sub[i], 0, map[i], 1, c-1);
            } else {
               for(int i=0; i < r; i++)
                   Arrays.fill(map[i], '.');

               if(m < c-1)
                  Arrays.fill(map[0], 0, m, '*');
               else if(m != 0) {
                  Arrays.fill(map[0], 0, c-2, '*');
                  for(int i=0; i < m-(c-2); i++)
                      map[i+1][0] = '*';
               }
            }
            
            memo.put(key, map);
        }
        
        if(flip)
           map = flip(map);
        
        return map;
    }
    
    public static char[][] flip(char[][] a) {
        char[][] b = new char[a[0].length][a.length];
        
        for(int i=0; i < a.length; i++)
            for(int j=0; j < a[0].length; j++)
                b[j][i] = a[i][j];
        return b;
    }
}

