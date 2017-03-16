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
 * $Id: C.java 516038 2011-09-21 11:28:01Z mahajans $
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
public class C {
    
    static long[] tType;
    static long[] tCnt;
    static long[] bType;
    static long[] bCnt;
    static List<Integer> toyList;
    static List<Integer> boxList;
    
    public static void main(String[] args) throws IOException {
        InputStreamReader converter = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(converter);
        String line = in.readLine();
        
        int T = Integer.parseInt(line);
        
        for (int t = 1; t<= T; t++) {
            line = in.readLine();
            int n = Integer.parseInt(line.split(" ")[0]);
            int m = Integer.parseInt(line.split(" ")[1]);
            
            tType = new long[n];
            tCnt = new long[n];
            bType = new long[m];
            bCnt = new long[m];
            
            line = in.readLine();
            String numArr[] = line.split(" ");
            toyList = new ArrayList<>();
            for (int i = 0; i < 2*n; i+=2) {
                int type = Integer.parseInt(numArr[i+1]);
                long cnt = Long.parseLong(numArr[i]);
                tType[i/2] = type;
                tCnt[i/2] = cnt;
            }
            
            line = in.readLine();
            numArr = line.split(" ");
            boxList = new ArrayList<>();
            for (int i = 0; i < 2*m; i+=2) {
                int type = Integer.parseInt(numArr[i+1]);
                long cnt = Long.parseLong(numArr[i]);
                bType[i/2] = type;
                bCnt[i/2] = cnt;
            }
            
            //System.out.println(toyList);
            //System.out.println(boxList);
            
            map = new HashMap<>();
            nm = new HashMap<>();
            long res = solve(0, 0);
            
            System.out.println("Case #" + t + ": " + res);
        }
    }
    
    static Map<Integer, Map<Integer, Long>> map;
    static Map<String, Long> nm;
    
    static long solve(int i, int j) {
        if (i >= tType.length)
            return 0;
        if (j >= bType.length)
            return 0;
        
        String key = i + "|" + tCnt[i] + j + "|" + bCnt[j];
        if (nm.containsKey(key))
            return nm.get(key);
        /*if (map.containsKey(i))
            if (map.get(i).containsKey(j))
                return map.get(i).get(j);*/
        
        long res = 0;
        long tc = tCnt[i];
        long bc = bCnt[j];
        if (tType[i] == bType[j]) {
            if (tc == bc) {
                res = tc + solve(i + 1, j + 1);
            }
            else if (tc < bc) {
                bCnt[j] -= tc;
                res = tc + solve(i + 1, j);
                bCnt[j] = bc;
            }
            else {
                tCnt[i] -= bc;
                res = bc + solve(i, j + 1);
                tCnt[i] = tc;
            }
        }
        else {
            long res2 = 0, res3 = 0;
            res2 = solve(i + 1, j);
            res3 = solve(i, j + 1);
            
            res = Math.max(res, Math.max(res3, res2));
        }
        /*if (!map.containsKey(i))
            map.put(i, new HashMap<Integer, Long>());
        map.get(i).put(j, res);*/
        nm.put(key, res);
        // System.out.println(i + " || " + j  + " || " + res);
        return res;
    }
    
}
