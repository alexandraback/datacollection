/**
 * Created by lyujiazhang on 4/15/16.
 */
import java.util.*;
import java.io.*;

public class winLastWord {
    public static String winLast(String str) {
        char[] arr = str.toCharArray();
        StringBuilder sb = new StringBuilder();
        sb.append(arr[0]);
        for(int i=1; i<arr.length; i++) {
            if(arr[i] >= sb.charAt(0)) {
                sb.insert(0, arr[i]);
            }
            else {
                sb.append(arr[i]);
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
//        winLastWord wlw = new winLastWord();
//        String s = "JAM";
//        String res = wlw.winLast(s);
//        System.out.print(res);
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = Integer.parseInt(in.nextLine());  // Scanner has functions to read ints, longs, strings, chars, etc.
        for (int i = 1; i <= t; i++) {
            String s = in.nextLine();
            String res = winLast(s);
            System.out.println("Case #" + i + ": " + res);
        }
    }
}
