package infinitepancakes;

import java.io.*;
import java.util.*;

/**
 * Created by Sayeed on 4/7/2016.
 */
public class InfinitePancakes {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("B-large-practice.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("B-large-practice.out")));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        int d;
        int[] p;
        int bestTime;
        for (int caseNum = 1; caseNum <= T; caseNum++) {
            st = new StringTokenizer(br.readLine());
            d = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            p = new int[d];
            for (int i = 0; i < d; i++) {
                p[i] = Integer.parseInt(st.nextToken());
            }
            bestTime = minTime(p);
            pw.println("Case #" + caseNum + ": " + bestTime);
        }

        br.close();
        pw.close();
    }

    public static int minTime(int[] p) {
        int M = Arrays.stream(p).max().getAsInt();
        int bestTime = M;
        for (int height = 1; height <= M; height++) {
            final int h = height;
            bestTime = Math.min(bestTime, Arrays.stream(p).map(x -> (x-1)/h).sum() + height);
        }
        return bestTime;
    }
}
