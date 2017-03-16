import java.io.*;
import java.util.StringTokenizer;

/*
ID: arshdee1
LANG: JAVA
PROB: ConcentricCircles 
*/

public class ConcentricCircles {
    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new FileReader("ConcentricCircles.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ConcentricCircles.out")));
        int T = Integer.parseInt(f.readLine());
//        final int maxR = 1000;
//        long[] evens = new long[maxR];
//        long[] odds = new long[maxR];
//        for (int i = 1; i < maxR; i++) {
//            evens[i] += - (i - 1) * (i - 1) + i * i + ( (i - 2 >= 1) ? evens[i - 2] : 0);
//        }
        for (int i = 1; i <= T; i++) {
            StringTokenizer st = new StringTokenizer(f.readLine());
            long r = Long.parseLong(st.nextToken());
            long t = Long.parseLong(st.nextToken());
            long totRing = 0;
            while (true) {
                long mlNeeded = (r + 1) * (r + 1) - r * r;
                if (mlNeeded <= t) {
                    t -= mlNeeded;
                    totRing++;
                } else {
                    break;
                }
                r += 2;
            }
            out.println("Case #" + i + ": " + totRing);
            System.out.println(i);
        }
        out.close();
        System.exit(0);
    }
}
