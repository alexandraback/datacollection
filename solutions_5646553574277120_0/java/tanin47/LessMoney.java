import java.io.*;
import java.util.Arrays;

public class LessMoney {
    public static void main(String[] args) throws Exception {
        String filename = "C-small-attempt0.in";
        File file = new File("/Users/tanin/Downloads/" + filename);
        File outFile = new File("/Users/tanin/Downloads/" + filename + ".out");
        BufferedReader br = new BufferedReader(new FileReader(file));
        BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));
        int testCases = Integer.parseInt(br.readLine());
        for(int t=1;t<=testCases;t++){
            String[] tokens = br.readLine().split(" ");
            int C = Integer.parseInt(tokens[0]);
            int D = Integer.parseInt(tokens[1]);
            int V = Integer.parseInt(tokens[2]);

            int[] ds = new int[D];
            String[] dtokens = br.readLine().split(" ");
            for (int i=0;i<D;i++) {
                ds[i] = Integer.parseInt(dtokens[i]);
            }

            int result = solve(C, V, ds);
            String outputLine = "Case #" + t + ": " + result + "\n";

            System.out.print(outputLine);
            bw.write(outputLine);
        }
        br.close();
        bw.close();
    }

    private static int solve(int C, int V, int[] ds) {
        Arrays.sort(ds);

        int[] newDs = new int[ds.length + 5];
        for (int i=0;i<ds.length;i++) { newDs[i] = ds[i]; }
        int limitDs = ds.length;

        boolean[] vs = new boolean[V + 1];

        while (true) {
            for (int i=0;i<vs.length;i++) vs[i] = false;
            fill(vs, newDs, limitDs, 0, 0);

            boolean finish = true;
            for (int i = 1; i < vs.length; i++) {
                if (!vs[i]) {
                    newDs[limitDs] = i;
                    limitDs = limitDs + 1;
                    finish = false;
                    break;
                }
            }

            if (finish) break;
        }

        return limitDs - ds.length;
    }

    private static void fill(boolean[] vs, int[] ds, int limit, int value, int index) {
        if (index == limit) {
            if (value < vs.length) {
                vs[value] = true;
            }
            return;
        }

        fill(vs, ds, limit, value + ds[index], index + 1);
        fill(vs, ds, limit, value, index + 1);
    }
}
