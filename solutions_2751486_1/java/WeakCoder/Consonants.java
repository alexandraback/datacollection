package Round_1_C;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Consonants {

    /**
     * @param args
     */
    public static void main(String[] args) {
        Scanner in = null;
        PrintWriter out = null;
        try {
            in = new Scanner(new File("A-small-attempt0.in"));
            out = new PrintWriter(new File("a_small.out"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        int cases = Integer.parseInt(in.nextLine());
        for (int cs=1; cs<=cases; cs++) {
            String[] words = in.nextLine().split(" ");
            String name = words[0];
            int least = Integer.parseInt(words[1]);
            long number = 0;
            long start = 0;
            int length = name.length();
            int[] link = new int[length];
            for (int i=0; i<length; i++) {
                if (!isYuanYin(name.charAt(i))) {
                    if (i==0)
                        link[0] = 1;
                    else
                        link[i] = link[i-1]+1;
                } else {
                    link[i] = 0;
                }
            }
            //System.out.println(Arrays.toString(link));
            for (int i=0; i<length; i++) {
                if (link[i] >= least) {
                    long begin = i-least+1;
                    long end = i;
                    number += (begin-start+1) * (length-end);
                    start = begin+1;
                }
            }
            out.println("Case #"+cs+": " + number);
            out.flush();
        }
    }

    public static boolean isYuanYin(char c) {
        if (c=='a' || c=='e'||c=='i'||c=='o'||c=='u')
            return true;
        return false;
    }
}
