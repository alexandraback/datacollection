
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class ManageYourEnergy {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    int E, R, N;
    long[] v;

    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        E = scan.nextInt();
        R = scan.nextInt();
        N = scan.nextInt();
        
        v = new long[(int)N];
        long max = 0;
        line = in.readLine();
        scan = new Scanner(line);
        for(int i = 0; i < N; i++) {
            v[i] = scan.nextLong();
        }
        
        out.println(solve(E,0,N-1,R,0));
    }
    
    BigInteger solve(int startEnergy, int start, int end, int endEnergy, long tot) {
        long max = 0;
        int maxIndex = 0;
        for(int i = start; i <= end; i++) {
            if(v[i] > max) {
                max = v[i];
                maxIndex = i;
            }
        }
        int maxBefore = Math.min(E, startEnergy + R*(maxIndex - start));
        int minAfter = Math.max(R, endEnergy - R*(end - maxIndex));
        int maxSpend = maxBefore - minAfter + R;
        if(maxIndex==start) {
            if(start==end) return BigInteger.valueOf(v[maxIndex] * maxSpend);
            return BigInteger.valueOf(v[maxIndex] * maxSpend).add(solve(minAfter, start+1, end, endEnergy,0));
        }
        if(maxIndex==end) {
            return BigInteger.valueOf(v[maxIndex] * maxSpend).add(solve(startEnergy, start, end - 1, maxBefore,0));
        }
        return BigInteger.valueOf(v[maxIndex] * maxSpend).add( solve(startEnergy,start,maxIndex - 1,maxBefore,0)).add(
                 solve(minAfter, maxIndex+1, end, endEnergy, 0));
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new ManageYourEnergy().run();
    }

}
