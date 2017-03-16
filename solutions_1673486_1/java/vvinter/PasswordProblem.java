/**
 * @(#)PasswordProblem.java, 2012-4-28. 
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
public class PasswordProblem {

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
                new InputStreamReader(
                        new FileInputStream(
                                "E:\\google_code_jam\\2012\\Password_input_large.txt")));
        PrintStream out = new PrintStream(new FileOutputStream(
                "E:\\google_code_jam\\2012\\Password_output_large.txt"));
        
        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            String[] sp = br.readLine().split(Pattern.quote(" "));
            int A = Integer.parseInt(sp[0]);// already typed
            int B = Integer.parseInt(sp[1]);// whole length
            sp = br.readLine().split(Pattern.quote(" "));
            double[] p = new double[A+1];
            for (int i = 1; i < p.length; i++) {
                p[i] = Double.parseDouble(sp[i-1]);
            }
            
            double[] pp = new double[A+1];
            pp[0] = 1.0;
            for (int i = 1; i < pp.length; i++) {
                pp[i] = pp[i - 1] * p[i];
            }
            
            double minExp = Double.MAX_VALUE;
            
            double keepTyping = B - A + 1 + (1 - pp[A]) * (B + 1);
            if (keepTyping < minExp)
                minExp = keepTyping;
            for (int i = 1; i <= A; i++) {
                double backi = (i + B - A + i + 1) + (1 - pp[A - i]) * (B + 1);
                if (backi < minExp)
                    minExp = backi;
            }
            double giveup = 1 + B + 1;
            if (giveup < minExp)
                minExp = giveup;
            
            out.printf("Case #%d: %.6f", t, minExp);
            out.println();
        }
    }
    
    

}
