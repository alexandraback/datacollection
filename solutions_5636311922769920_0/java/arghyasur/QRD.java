import java.io.IOException;

/**
 * Copyright - Arghya Sur
 * Created by sur on 4/9/16.
 */
public class QRD {
    private static long getPowerIndex(int K, int p, int i) {
        if(p == 1) {
            return i + 1;
        }
        return getPowerIndex(K, p-1, i) + (long)Math.pow(K, p-1) * i;
    }

    public static void main(String[] args) throws IOException {

        java.io.BufferedReader r = new java.io.BufferedReader
                (new java.io.InputStreamReader (System.in));

        String line;
        int c = 0;
        int t = Integer.parseInt(r.readLine());

        while(t > 0) {
            line = r.readLine();
            String kcs[] = line.split(" ");
            int K = Integer.parseInt(kcs[0]);
            int C = Integer.parseInt(kcs[1]);
            int S = Integer.parseInt(kcs[1]);

            long tilesToClean[] = new long[K];
            String outStr = "Case #" + (c + 1) + ":";
            for(int i = 0; i < K; i++) {
                //tilesToClean[i] = getPowerIndex(K, C, i);
                outStr = outStr + " " + (i+1);//tilesToClean[i];
            }
            System.out.println(outStr);
            t--;
            c++;
        }
    }
}
