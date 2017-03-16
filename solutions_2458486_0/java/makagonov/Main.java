import java.io.*;
import java.util.*;

public class Main {
    final int MAX_TYPES_COUNT = 40;
    final int MAXN = 20;
    int [] requiredTypes, result;
    long [][] hasTypes;
    long [] hasTypesMask;
    int n;
    void solve() throws Exception{
        result = null;
        hasTypes = new long[MAXN][MAX_TYPES_COUNT];
        requiredTypes = new int[MAXN];
        usedStates.clear();
        hasTypesMask = new long[MAXN];
        int k = nextInt();
        n = nextInt();
        int [] haveTypes = new int[MAX_TYPES_COUNT];
        for (int i = 0; i < k; i++) {
            int type = nextInt() - 1;
            haveTypes[type]++;
        }
        for (int i = 0; i < n; i++) {
            requiredTypes[i] = nextInt() - 1;
            int ki = nextInt();
            for (int j = 0; j < ki; j++) {
                int type = nextInt() - 1;
                hasTypes[i][type]++;
            }
        }
        int [] parent = new int[n];
        Arrays.fill(parent, -1);
        rec(0, haveTypes, parent, -1);
    }
    HashMap<Integer, HashSet<Long>> usedStates = new HashMap<Integer, HashSet<Long>>();
    void rec(int used_mask, int [] haveTypes, int [] parent, int last) {
        long have_mask = 0;
        for (int i = 0; i < haveTypes.length; i++)
            if (haveTypes[i] > 0)
                have_mask |= (1L << i);

        if (result != null) return;
        if (!usedStates.containsKey(used_mask))
            usedStates.put(used_mask, new HashSet<Long>());
        if (!usedStates.get(used_mask).add(have_mask))
            return;
        if (Integer.bitCount(used_mask) == n) {
            result = new int[n];
            for (int i = n - 1; i >= 0; result[i--] = last, last = parent[last]);
            return;
        }
        for (int i = 0; i < n; i++) {
            if ((used_mask&(1<<i)) == 0) {
                if (haveTypes[requiredTypes[i]] > 0) {
                    haveTypes[requiredTypes[i]]--;
                    for (int j = 0; j < MAX_TYPES_COUNT; j++)
                        if (hasTypes[i][j] > 0)
                            haveTypes[j]+= hasTypes[i][j];
                    parent[i] = last;
                    rec(used_mask | (1 << i), haveTypes, parent, i);
                    haveTypes[requiredTypes[i]]++;
                    for (int j = 0; j < MAX_TYPES_COUNT; j++)
                        if (hasTypes[i][j] > 0)
                            haveTypes[j] -= hasTypes[i][j];
                    parent[i] = -1;
                }
            }
        }
    }

    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;
    String next() throws Exception {
        if (st == null || !st.hasMoreElements())
            st = new StringTokenizer(in.readLine());
        return st.nextToken();
    }
    int nextInt() throws Exception {
        return Integer.parseInt(next());
    }
    public Main() throws Exception {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        int T = nextInt();
        for (int test=1;test<=T;test++) {
            solve();
            out.print("Case #" + test + ": ");
            if (result == null)
                out.print("IMPOSSIBLE");
            else
                for (int i = 0; i < result.length; i++)
                    out.print((result[i] + 1) + " ");
            out.println();
        }
        out.close();
    }
    public static void main(String[] args) throws Exception{
        new Main();
    }
}
