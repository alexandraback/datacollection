package codejam;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class InfiniteHousePancakes {

    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        Scanner in = new Scanner(new FileReader("B-small-attempt0 (3).in"));
        PrintWriter out = new PrintWriter("output.txt", "UTF-8");
        
        int T = in.nextInt();
        
        for (int t = 1; t <= T; t++) {
           int D = in.nextInt();
           List<Integer> times = new ArrayList<Integer>();
           for (int i = 0; i < D; i++)
               times.add(in.nextInt());
           int ans = minTime(times);
           out.println("Case #" + t + ": " + ans);
           System.out.println(ans);
        }
        in.close();
        out.close();
    }

    public static int minTime(List<Integer> times) {
        Collections.sort(times);
        
        int max = times.get(times.size() - 1);
        
        int best = Integer.MAX_VALUE;
        for (int i = 1; i <= max; i++) {
            int flipTimes = 0;
            for (Integer j : times) {
                if (j % i == 0)
                    flipTimes += j / i - 1;
                else
                    flipTimes += j / i;
            }
            if (flipTimes + i < best)
                best = flipTimes + i;
        }
        return best;
    }
    
}
