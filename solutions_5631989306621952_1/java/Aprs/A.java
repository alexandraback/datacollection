package edu.utdallas;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by sycheng on 4/15/16.
 */
public class A {
    public static String lastWord(String s) {
        char []a = s.toCharArray();
        String re = ""+s.charAt(0);
        char f = s.charAt(0);
        for (int i = 1; i < s.length(); i++) {
            if (a[i] < re.charAt(0) ) re = re + a[i];
            else re =""+ a[i] + re;
        }
        return re;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        List<String> list = new ArrayList<>(n);
        in.nextLine();
        for (int i = 0; i < n; i++)
            list.add(in.nextLine());
        for (int i = 0; i < list.size(); i++) {
            System.out.println("Case #"+ (i + 1) + ": "+ lastWord(list.get(i)));
        }
    }
}
