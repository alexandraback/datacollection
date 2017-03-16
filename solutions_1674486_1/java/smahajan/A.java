import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
 * 
 * Copyright (c) 2011 D. E. Shaw & Co., L.P. All rights reserved.
 * This software is the confidential and proprietary information
 * of D. E. Shaw & Co., L.P. ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with D. E. Shaw & Co., L.P.
 * 
 * $Id: A.java 516038 2011-09-21 11:28:01Z mahajans $
 * $HeadURL: $
 * $LastChangedBy: mahajans $
 * $LastChangedDate: 2011-09-21 16:58:01 +0530 (Wed, 21 Sep 2011) $
 * $LastChangedRevision: $
 *
 */

/**
 * @author mahajans
 * 
 */
public class A {
    
    static List<List<Integer>> graph = new ArrayList<>();
    static Map<Integer, Boolean> map;
    static Map<Integer, Boolean> checked;
    
    public static void main(String[] args) throws IOException {
        InputStreamReader converter = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(converter);
        String line = in.readLine();
        
        int T = Integer.parseInt(line);
        
        for (int t = 1; t <= T; t++) {
            int n = Integer.parseInt(in.readLine());
            graph = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                line = in.readLine();
                String[] strA = line.split(" ");
                int m = Integer.parseInt(strA[0]);
                ArrayList<Integer> l = new ArrayList<>();
                for (int j = 0; j < m; j++) {
                    l.add(Integer.parseInt(strA[j+1]) - 1);
                }
                graph.add(l);
            }
            
            checked = new HashMap<>();
            boolean done = false;
            for (int i =0; i < n; i++) {
                map = new HashMap<>();
                if (checked.containsKey(i))
                    continue;
                if (solve(i)) {
                    done = true;
                }
            }
            
            if (done)
                System.out.println("Case #" + t + ": Yes");
            else
                System.out.println("Case #" + t + ": No");
        }
    }
    
    static boolean solve(int i) {
        if (map.containsKey(i)) {
            return true;
        }
        
        checked.put(i, true);
        
        map.put(i, true);
        //System.out.println(i + " || " + graph.get(i));
        for (Integer nodes : graph.get(i)) {
            if (solve(nodes))
                return true;
        }
        
        return false;
    }
}
