/**
 * @(#)KingdomRush.java, 2012-4-28. 
 * 
 * Copyright 2012 Netease, Inc. All rights reserved.
 * NETEASE PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */
package jam2012;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.regex.Pattern;

/**
 *
 * @author bjdengdong
 *
 */
public class KingdomRush {

    static int[] stars;
    static int N;
    static int playCount;
    static int[] req1;
    static int[] req2;
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
                new InputStreamReader(
                        new FileInputStream(
                                "E:\\google_code_jam\\2012\\Kingdom_input_small.txt")));
        PrintStream out = new PrintStream(new FileOutputStream(
                "E:\\google_code_jam\\2012\\Kingdom_output_small.txt"));
        
        int T = Integer.parseInt(br.readLine());
        
        for (int t = 1; t <= T; t++) {
            
            N = Integer.parseInt(br.readLine());
            stars = new int[N];
            req1 = new int[N];
            req2 = new int[N];
            playCount=0;
            
            for (int n = 0; n < N; n++) {
                String[] sp = br.readLine().split(Pattern.quote(" "));
                req1[n] = Integer.parseInt(sp[0]);
                req2[n] = Integer.parseInt(sp[1]);
            }
            
            int total = 0;
            while (total < 2 * N) {
                int i = chooseReq2(total);
                if (i < 0) {
                    i = chooseReq11(total);
                    if (i < 0) {
                        i = chooseReq1(total);
                        if (i < 0) {
                            break;
                        } else {
                            playReq1(i);
                            total += 1;
                        }
                    } else {
                        playReq11(i);
                        total += 1;
                    }
                } else {
                    playReq2(i);
                    total += 2;
                }
            }
            if (total < 2 * N) {
                out.println("Case #" + t + ": Too Bad");
            } else {
                out.println("Case #" + t + ": " + playCount);
            }
            
        }
    }

    private static void playReq11(int i) {
        stars[i]++;
        playCount++;
    }

    /**
     * @param total
     * @return
     */
    private static int chooseReq11(int total) {
        for (int i = 0; i < N; i++) {
            if (stars[i] == 1 && req2[i] <= total)
                return i;
        }
        return -1;
    }

    private static void playReq2(int i) {
        stars[i] += 2;
        playCount++;
    }

    private static void playReq1(int i) {
        stars[i]++;
        playCount++;
    }

    private static int chooseReq1(int total) {
        for (int i = 0; i < N; i++) {
            if (stars[i] == 0 && req1[i] <= total)
                return i;
        }
        return -1;
    }

    private static int chooseReq2(int total) {
        for (int i = 0; i < N; i++) {
            if (stars[i] == 0 && req2[i] <= total)
                return i;
        }
        return -1;
    }

}
