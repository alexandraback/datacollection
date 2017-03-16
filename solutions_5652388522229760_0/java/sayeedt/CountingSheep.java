package countingsheep;

import java.io.*;
import java.util.*;

/**
 * Created by Sayeed on 4/8/2016.
 */
public class CountingSheep {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("A-small-attempt0.out")));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        int n;
        int result;

        for (int caseNum = 1; caseNum <= T; caseNum++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            result = countSheep(n);
            if (result == -1) {
                pw.println("Case #" + caseNum + ": INSOMNIA");
            } else {
                pw.println("Case #" + caseNum + ": " + result);
            }
        }

        br.close();
        pw.close();
    }

    public static int countSheep(int n) {
        if (n == 0) {
            return -1;
        }
        int last = n;

        boolean[] seenDigits = new boolean[10];
        for (int i = 0; i < 10; i++) {
            seenDigits[i] = false;
        }
        int numSeenDigits = 0;
        char[] charArray;
        int a;

        while (numSeenDigits < 10) {
            charArray = Integer.toString(last).toCharArray();
            for (char c : charArray) {
                a = Integer.parseInt(Character.toString(c));
                if (!seenDigits[a]) {
                    seenDigits[a] = true;
                    numSeenDigits += 1;
                    if (numSeenDigits >= 10) {
                        break;
                    }
                }
            }
            if (numSeenDigits >= 10) return last;
            last += n;
        }
        throw new RuntimeException();
    }
}
