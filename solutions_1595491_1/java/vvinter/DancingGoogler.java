import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintStream;
import java.util.regex.Pattern;

/**
 * @(#)DancingGoogler.java, 2012-4-14. 
 * 
 * Copyright 2012 Netease, Inc. All rights reserved.
 * NETEASE PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/**
 *
 * @author bjdengdong
 *
 */
public class DancingGoogler {

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("E:\\google_code_jam\\B-large.in")));
        PrintStream out = new PrintStream(new FileOutputStream("E:\\google_code_jam\\B-large.out"));
        
        int cases = Integer.parseInt(br.readLine());
        
        for (int i = 1; i <= cases; i++) {
            String line = br.readLine();
            String[] sp = line.split(Pattern.quote(" "));
            
            int n = Integer.parseInt(sp[0]);//num of googlers
            int s = Integer.parseInt(sp[1]);//num of surprises
            int p = Integer.parseInt(sp[2]);//best score p
            
            int[] scores = new int[n];
            int result = 0;
            int usedSurprise = s;
            for (int j = 0; j < n; j++) {
                scores[j] = Integer.parseInt(sp[j + 3]);
                if (canReachWithoutSuprise(scores[j], p)) {
                    result++;
                } else if (canReachWithSuprise(scores[j], p)) {
                    if (usedSurprise > 0) {
                        result++;
                        usedSurprise--;
                    }
                }
            }
            out.println("Case #" + i + ": " + result);
        }
        out.close();
    }

    private static boolean canReachWithSuprise(int score, int p) {
        if (score == 0 || score == 1)
            return false;
        return (score >= (3 * p - 4)) && (score <= (3 * p - 3));
    }

    private static boolean canReachWithoutSuprise(int score, int p) {
        if (p == 0)
            return true;
        return score >= (3 * p - 2);
    }

}
