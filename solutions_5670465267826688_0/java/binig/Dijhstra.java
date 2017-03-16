import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by benoi_000 on 4/11/2015.
 */
public class Dijhstra {
    static int I=2;
    static int J=3;
    static int K=4;
    static int[][] MULTI = {
            {1,I,J,K},
            {I,-1,K,-J},
            {J,-K,-1,I},
            {K,J,-I,-1},};

    public static void main(String args[]) throws IOException {
        InputStream inputStream = args.length<1?System.in:Thread.currentThread().getContextClassLoader().getResourceAsStream(args[0]);
        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
        PrintStream out = args.length<2?System.out:new PrintStream(new FileOutputStream(args[1]));
        int nbPb = Integer.parseInt( reader.readLine());
        for (int i=0;i<nbPb;i++) {
            processLine(i+1, reader.readLine(), reader.readLine(),out);
        }

    }

    // you need to move at least 2 to be worth it
    // and have a stack of 4 , moving 2 from 3 is useless
    // decide how to split ?  well if
    private static void processLine(int caseNb, String spec , String s, PrintStream out) {
        boolean reduce =false;
        int size = Integer.parseInt(spec.substring(0,spec.indexOf(' ')));
        int repeat = Integer.parseInt(spec.substring(spec.indexOf(' ')+1));
        int[] seq = new int[size];
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            int val;
            if (c=='i') {
                val = I;
            } else if (c=='j') {
                val = J;

            } else if (c=='k') {
                val = K;

            } else
                throw new IllegalArgumentException(Character.toString(c));
            seq[i] = val;
        }

        int lookFor = I;
        int curr =1;
        for (int i=0;i<repeat*size;i++) {
            int next = seq[i%size];
            if (curr<0) {
                curr = -MULTI[-curr-1][next-1];
            } else {
                curr = MULTI[curr-1][next-1];
            }
            if (curr==lookFor&&lookFor<K) {
                lookFor++;
                curr =1;
            }
        }
        reduce = lookFor==K && curr==K;
        out.println( "Case #" +
                + caseNb+
                ": " +
                ( reduce?"YES":"NO")  );
    }


}
