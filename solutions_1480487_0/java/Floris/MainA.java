package codejam.round1b_2012;

import java.io.File;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class MainA {

    static char[] mapping = new char[256];
    
    public static void main(String[] args) throws Exception {

        String f = "/home/floris/dev/java/Test/src/codejam/round1b_2012/A-small-attempt2.in";
        Scanner sc = new Scanner(new File(f));
        System.setOut(new PrintStream(new File(f+".out")));
        int T = sc.nextInt();
        for (int i=1; T-- > 0; i++) {
            int contestantCount = sc.nextInt();
            int[] scores = new int[contestantCount];
            for (int j = 0; j < contestantCount; j++) scores[j] = sc.nextInt();
            System.out.printf("Case #%d:%s%n", i, solve(scores));
        }
    }

    private static String solve(int[] scores) {
        String result ="";
        int total = 0;
        for (int i = 0; i < scores.length; i++) total += scores[i];
        int[] scores2 = new int[scores.length];
        for (int i = 0; i < scores.length; i++) scores2[i]=scores[i];
        Arrays.sort(scores2);
        int left = total;
        double tres = 0;
        int i;
        for (i = 1; i < scores2.length; i++) {
            if (i *(scores2[i]-scores2[i-1]) <= left) {
                left -= i*(scores2[i]-scores2[i-1]);
            } else break;
        }
        if (i==scores.length) {
            tres = scores2[scores.length-1] + (double)left/scores.length;
        } else {
            tres = scores2[i-1]+(double)left/i;
        }
//        System.err.println(tres);
        for (i = 0; i < scores.length; i++) {
            if (scores[i]>= tres) {
                result+=String.format(" %.06f", 0.0);
            } else {
                result+=String.format(" %.06f", 100*(tres-scores[i])/total);
            }
        }
        return result;
    }
}
