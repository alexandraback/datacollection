import java.util.*;
import java.io.*;

public class B {
    private BufferedReader br;
    
    public B() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }


    private int testcase() throws IOException {
        int D = Integer.parseInt(br.readLine());
        int[] vals = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt)
            .sorted()
            .toArray();

        int best = vals[vals.length - 1];
        for(int eating = 1; eating <= best; ++eating) {
            int cur = 0;
            for(int i = 0; i < vals.length; ++i)
                cur += (vals[i] + eating - 1) / eating - 1;
            best = Math.min(best, eating + cur);
        }
        return best;
    }

    public void solve() throws IOException {
        int T = Integer.parseInt(br.readLine());
        for(int i = 1; i <= T; ++i) {
            System.out.println("Case #" + i + ": " + testcase());
        }
    }

    public static void main(String[] args) {
        B b = new B();
        try {
            b.solve();
        }
        catch(IOException e) {
            System.err.println("...WTF...");
        }
    }
}
