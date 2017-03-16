import java.io.*;
import java.util.*;
import java.lang.*;

public class BFF {

    public static void print(Object o) {
        System.out.print(o);
    }

    public static void println(Object o) {
        System.out.println(o);
    }

    // debugging
    public static void printArray(int[] arr) {
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    public static int nextInt(StringTokenizer st) {
        return Integer.parseInt(st.nextToken());
    }

    public static int nextInt(BufferedReader br) throws IOException {
        return Integer.parseInt(br.readLine());
    }

    public static long nextLong(StringTokenizer st) {
        return Long.parseLong(st.nextToken());
    }

    public static int[] nextInts(BufferedReader br, int n) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        return arr;
    }

    public static long[] nextLongs(BufferedReader br, int n) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }
        return arr;
    }

    public static boolean allDiff(int[] bffs) {
        HashSet<Integer> seen = new HashSet<>();
        for (int m : bffs) { seen.add(m); }
        return seen.size() == bffs.length;
    }

    public static ArrayList<Integer> getCycle(int vert, int[] bffs) {
        // return null if not in cycle, o.w. return cycle
        ArrayList<Integer> out = new ArrayList<>();
        boolean[] seen = new boolean[bffs.length];
        int curr = vert;
        out.add(vert);
        seen[vert] = true;
        curr = bffs[curr];
        while (!seen[curr]) {
            seen[curr] = true;
            out.add(curr);
            curr = bffs[curr];
        }
        if (curr == vert) { return out; }
        return null;
    }

    public static void findLevels(int start, int[][] backwards) {
        HashSet<Integer> visited = new HashSet<>();
        visited.add(start);
        LinkedList<Integer> tovisit = new LinkedList<>();
        tovisit.add(start);

        int levels = 0;
        while (tovisit.size() > 0) {
            levels++;
            int vert = tovisit.pollFirst();
            for (int i = 0; i < backwards[0][vert]; i++) {
                if (!visited.contains(backwards[vert][i])) {
                    visited.add(backwards[vert][i]);
                    tovisit.add(backwards[vert][i]);
                }
            }
        }
    }

    public static int key(int n, ArrayList<Integer> cyc) {
        // assume 2
        int a = cyc.get(0);
        int b = cyc.get(1);
        return Math.min(a,b) + (n+1) * Math.max(a,b);
    }

    public static void doCase2(BufferedReader br) throws IOException {
        int n = nextInt(br);
        int[] bffs = new int[n+1];
        int[] s = nextInts(br, n);
        for (int i = 1; i <=n; i++) {
            bffs[i] = s[i-1];
        }
    }

    public static void doCase(BufferedReader br) throws IOException {
        int n = nextInt(br);
        int[] bffs = new int[n+1];
        int[] s = nextInts(br, n);
        for (int i = 1; i <=n; i++) {
            bffs[i] = s[i-1];
        }
        // backwards edges (use 0 as sentinel)
        // use first row as index
        int[][] backwards = new int[n+1][n+1];
        for (int i=1; i <=n; i++) {
            // a's BFF is b => add a to b's list
            int ind = bffs[i];
            backwards[bffs[i]][backwards[0][bffs[i]]++] = i;
        }

        ArrayList<ArrayList<Integer>> cycles = new ArrayList<>();
        cycles.add(null);
        for (int i = 1; i <= n; i++) {
            cycles.add(getCycle(i, bffs));
        }
        // once we ID cycles, what do we have?
        // The graph is a collection of cycles, and various vertices
        // go into the cycle (but never out of it!)
        // There are "lines" entering each cycle and at most one
        // line is usable
        // ==> find the longest line!
        // ...except can only use line for 2-cycles
        // ...and can use any single line for that
        // MORE CASES
        // Any cycle of length >= 3 must be used in isolation or else
        // not all dependencies match
        // So, either take best cycle of length 3, or take best sum
        // of 2 cycles with tails
        // ANOTHER CASE
        // or, we can use 2 tails for one cycle
        // and also only if they are complementary
        // and also only at most one cycle can do this
        // ...aka longest ending at one vertex + longest ending at
        // other
        int biggest = 0;
        int totTwoCycLen = 0;
        int[] counted = new int[n+1];
        ArrayList<Integer> pairs = new ArrayList<Integer>();
        for (int i = 1; i <= n; i++) {
            if (counted[i] == 0 && cycles.get(i) != null) {
                int size = cycles.get(i).size();
                biggest = Math.max(biggest, size);
                for (int vert : cycles.get(i)) {
                    counted[vert] = size;
                }
                if (size == 2) {
                    totTwoCycLen += 2;
                    int a = cycles.get(i).get(0);
                    int b = cycles.get(i).get(1);
                    pairs.add(Math.min(a,b));
                    pairs.add(Math.max(a,b));
                }
            }
        }
        // Now id line
        //HashMap<Integer,Integer> best = new HashMap<>();
        int[] best = new int[n+1];
        for (int i = 1; i <= n; i++) {
            if (counted[i] == 0) {
                //not in cycle
                int curr = i;
                int le = 0;
                while (counted[curr] == 0) {
                    curr = bffs[curr];
                    le++;
                }
                if (counted[curr] == 2) {
                    //usable maybe
                    if (cycles.get(curr).size() != 2) {
                        System.err.println("BUG");
                        System.exit(1);
                    }
                    /*
                    int ke = key(n, cycles.get(curr));
                    if (!best.containsKey(ke)) {
                        best.put(ke, 0);
                    }
                    best.put(ke, Math.max(best.get(ke), le));
                    */
                    best[curr] = Math.max(best[curr], le);
                }
            }
        }
        int linelen = 0;
        int bestSec = 0;
        for (int i = 0; i < totTwoCycLen / 2; i++) {
            int a = pairs.get(2*i);
            int b = pairs.get(2*i+1);
            linelen += Math.max(best[a], best[b]);
            bestSec = Math.max(bestSec, Math.min(best[a], best[b]));
        }
        int finalscore = Math.max(biggest, totTwoCycLen + linelen + bestSec);
        println(" " + finalscore);
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        Scanner sc;
        int cases = Integer.parseInt(br.readLine());
        for (int i = 1; i <= cases; i++) {
            print(String.format("Case #%d:", i));
            doCase(br);
        }
    }
}
