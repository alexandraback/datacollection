import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.*;

public class CounterCulture {
    Scanner sc = new Scanner(getClass().getResourceAsStream(IN));
    static final String FILENAME = "A-small-attempt1";
    static final String IN = FILENAME + ".in";
    static final String OUT = FILENAME + ".out";

    PrintStream out = System.out;

    private void solveBfs(long N) {
        Queue<Long> q = new LinkedList<Long>();
        q.add(1L);
        Map<Long, Integer> level = new HashMap<Long, Integer>();
        level.put(1L, 1);
        while(!q.isEmpty()) {
            long current = q.remove();
            if(current == N) {
                out.println(level.get(current));
                return;
            }
            int curLevel = level.get(current);
            long rev = reverse(current);
            long iter = current + 1;
            if(!level.containsKey(iter)) {
                q.add(iter);
                level.put(iter, curLevel + 1);
            }
            if(!level.containsKey(rev)) {
                q.add(rev);
                level.put(rev, curLevel + 1);
            }
        }
    }

    private void solve(long N) {
        int steps = 1;
        while(N > 1) {
            long rev = reverse(N);
            if(rev < N && N % 10 != 0)
                N = rev;
            else
                N--;
            steps++;
        }
        out.println(steps);
    }

    private long reverse(long N) {
        while(N % 10 == 0)
            N = N / 10;
        long ret = 0;
        int numDigits = Long.toString(N).length();
        for(int i = 0; i < numDigits; i++) {
            ret *= 10;
            ret += ((N / Math.pow(10, i)) % 10);
        }
        return ret;
    }


    private void run() throws Exception {
        out = new PrintStream(new FileOutputStream(OUT));
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.println("******************* TC" + i + " ********************");
            long N = sc.nextLong();
            out.print("Case #" + i + ": ");
            solveBfs(N);
        }
        sc.close();
        out.close();
    }

    public static void main(String args[]) throws Exception {
        new CounterCulture().run();
    }
}
