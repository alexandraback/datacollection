import java.util.*;
import java.io.*;

public class InfinitePancakes {
    public static void main(String[] args) throws Exception {
        if (args.length == 0)
            throw new IllegalArgumentException("Require input file name");
        Scanner sc = new Scanner(new FileReader(args[0]));
        String outFilename = args[0].replaceFirst("[.][^.]+$", "").concat(".out");
        PrintWriter pw = new PrintWriter(new FileWriter(outFilename));
        int caseCnt = Integer.parseInt(sc.nextLine());
        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            pw.print("Case #" + (caseNum + 1) + ": ");
            int D = Integer.parseInt(sc.nextLine());
            String[] P = sc.nextLine().split("\\s+");
            int[] p = new int[D];
            int maxP = Integer.MIN_VALUE;
            for (int i = 0; i < D; i++) {
                p[i] = Integer.parseInt(P[i]);
                if (maxP < p[i]) {
                    maxP = p[i];
                }
            }
            // without any allocation
            // minCost is decided by the diner who owns the most pancakes
            int minCost = maxP;
            // exam every case of allocating every diner with a shares of 2, 3, 4 ... minCost
            int shares = 2;
            // if shares >= minCost, no need to examine, as eat time will be larger than current minCost
            while (shares < minCost) {
                // at least 'shares' minutes to eat them all
                int cost = shares;
                // accumulate the time cost by allocation steps
                for (int i = 0; i < D; i++) {
                    cost += (p[i]-1)/shares;
                }
                // find one min cost, update it
                if (cost < minCost) {
                    minCost = cost;
                }
                shares++;
            }
            pw.println(minCost);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
