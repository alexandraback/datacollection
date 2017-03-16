import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Set;
import java.util.regex.Pattern;

/**
 * @(#)RecycleNumber.java, 2012-4-14. 
 * 
 * Copyright 2012 Netease, Inc. All rights reserved.
 * NETEASE PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

/**
 *
 * @author bjdengdong
 *
 */
public class RecycleNumber {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("E:\\google_code_jam\\C-small-attempt0.in")));
        PrintStream out = new PrintStream(new FileOutputStream("E:\\google_code_jam\\C-small-attempt0.out"));
        
        int t = Integer.parseInt(br.readLine());
        
        for (int i = 1; i <= t; i++) {
            String line = br.readLine();
            String[] sp = line.split(Pattern.quote(" "));
            int digits = sp[0].length();
            int a = Integer.parseInt(sp[0]), b = Integer.parseInt(sp[1]);
            if (a < 10 && b < 10) {
                out.println("Case #" + i + ": 0");
                continue;
            }
            int result = 0;
            Set<Integer> set = new HashSet<Integer>();
            for (int num = a; num <= b; num++) {
                String str = ("" + num);
                set.clear();
                for (int j = digits - 1, k = 1; j >= 1; j--, k++) {
                    if (str.charAt(k) == '0')
                        continue;
                    int rec = Integer.parseInt(str.substring(k)
                            + str.substring(0, k));
                    if (rec > num && rec <= b) {
                        if(!set.contains(rec)){
                            set.add(rec);
                            result++;
                        }
                    }
                }
            }
            out.println("Case #" + i + ": " + result);
        }
        
    }

}
