package gcj2016.round1B;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class CloseMatch {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt(); 
        for (int i = 1; i <= t; ++i) {
            String c = in.next();
            String j = in.next();
            String[] ans = f(c,j);
            System.out.println("Case #" + i + ": " + ans[0]+ " "+ ans[1]);
        }
        in.close();
    }
    
    public static String[] f(String c, String j){
        int questionmark = c.indexOf('?');
        if (questionmark != -1){
            String[] cs = new String[]{c.substring(0, questionmark), c.substring(questionmark+1)};
            int min = -1;
            String[] maxs = {};
            for (int i=0; i<10; ++i){
                String[] r = f(cs[0]+i+cs[1],j);
                int diff = Math.abs(Integer.parseInt(r[0])-Integer.parseInt(r[1]));
                if (min == -1 || diff < min || (diff == min && 
                        (Integer.parseInt(r[0]) < Integer.parseInt(maxs[0]) || Integer.parseInt(r[1]) < Integer.parseInt(maxs[1])))){
                    min = diff;
                    maxs = r;
                }
            }
            return maxs;
        } else {
            questionmark = j.indexOf('?');
            if (questionmark == -1){
                return new String[]{c,j};
            }
            String[] js = {j.substring(0, questionmark), j.substring(questionmark+1)};
            int min = -1;
            String[] maxs = {};
            for (int i=0; i<10; ++i){
                String[] r = f(c,js[0]+i+js[1]);
                int diff = Math.abs(Integer.parseInt(r[0])-Integer.parseInt(r[1]));
                if (min == -1 || diff < min || (diff == min && 
                        (Integer.parseInt(r[0]) < Integer.parseInt(maxs[0]) || Integer.parseInt(r[1]) < Integer.parseInt(maxs[1])))){
                    min = diff;
                    maxs = r;
                }
            }
            return maxs;
        }
    }
}