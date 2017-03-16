package Round1C;

import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 * Created by ocozalp on 5/11/14.
 */
public class BStupid {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileInputStream("/home/ocozalp/Downloads/B-small-attempt0.in"));
        //Scanner sc = new Scanner(System.in);

        int testCase = sc.nextInt();

        for(int i = 1; i<=testCase; i++) {
            int n = sc.nextInt();
            sc.nextLine();
            String [] cars = new String[n];
            for(int j = 0; j<n; j++) {
                cars[j] = sc.next();
            }
            int result = solve(cars);

            System.out.println("Case #" + i + ": " + result);
        }

        sc.close();
    }

    private static int solve(String [] cars) {
        int [] counts = new int['z' - 'a' + 1];
        for(int i = 0; i<cars.length; i++) {
            for(int j = 0; j<cars[i].length(); j++)
                counts[cars[i].charAt(j) - 'a']++;
        }

        int [] perm = new int[cars.length];
        boolean [] ctrl = new boolean[cars.length];

        return calc(cars, perm, counts,ctrl, 0);
    }

    private static int calc(String[] cars, int [] perm, int [] counts, boolean[] ctrl, int level) {
        if(level == perm.length) {
            if(control(cars, perm, counts)) return 1;

            return 0;
        }

        int result = 0;

        for(int i = 0; i<cars.length; i++) {
            if(!ctrl[i]) {
                ctrl[i] = true;
                perm[level] = i;
                result += calc(cars, perm, counts, ctrl, level + 1);
                ctrl[i] = false;
            }
        }

        return result % 1000000007;
    }

    private static boolean control(String[] cars, int[] perm, int [] counts) {
        StringBuffer sb = new StringBuffer();
        for(int i = 0; i<perm.length; i++) {
            sb.append(cars[perm[i]]);
        }

        boolean [] seen = new boolean['z' - 'a' + 1];
        String s = sb.toString();

        /*
        for(int i = 1; i<perm.length; i++) {
            char c0 = cars[perm[i-1]].charAt(cars[perm[i-1]].length() - 1);
            char c1 = cars[perm[i]].charAt(0);

            if(c0 != c1 && counts[c0-'a'] > 1 && counts[c1-'a'] > 1) return false;
        }
        */


        char last = 0;
        for(int i = 0; i<s.length(); i++) {
            char c = s.charAt(i);
            if(seen[c - 'a']) {
                if(last != c) return false;
            }

            seen[c - 'a'] = true;
            last = c;
        }

        return true;
    }
}
