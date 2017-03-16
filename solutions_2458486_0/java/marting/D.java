import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class D {
    static Scanner in;
    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("D.in"));
        PrintWriter out = new PrintWriter(new File("D.out"));
        int T = in.nextInt();
        for (int I = 0; I < T; I++) {
            out.printf("Case #%d: ", I+1);
            Collection<Integer> res = solve();
            if (res==null)
                out.println("IMPOSSIBLE");
            else {
                for (int a : res)
                    out.printf("%d ", a+1);
                out.println();
            }
            out.flush();
        }
        out.close();
    }
    static int N;
    static int hand[];
    static int T[];
    static int chest[][];
    static boolean opened[];
    static LinkedList<Integer> path;
    static Map<Integer, Map<String, Boolean>> cache;

    private static Collection<Integer> solve() {
        int K = in.nextInt();
        N = in.nextInt();
        hand = new int[23];
        chest = new int[N][];
        path = new LinkedList<>();
        opened = new boolean[N];
        T = new int[N];
        for (int i = 0; i < K; i++)
            hand[in.nextInt()-1]++;
        for (int i = 0; i < N; i++) {
            T[i] = in.nextInt()-1;
            int k = in.nextInt();
            chest[i] = new int[k];
            for (int j = 0; j < k; j++)
                chest[i][j] = in.nextInt()-1;
        }
        cache = new HashMap<>();
        if (step())
            return path;
        return null;
    }
    static String tos(int[] A) {
        //return Arrays.toString(A);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < A.length; i++) {
            if (A[i]>0)
                sb.append(i).append(':').append(A[i]).append('\n');
        }
        return sb.toString();
    }
    static boolean step() {
        int set = 0;
        for (int i = 0; i < N; i++)
            set = set*2 + (opened[i]?1:0);
        Map<String, Boolean> map = cache.get(set);
        if (map!=null) {
            if (map.get(tos(hand))==Boolean.FALSE)
                ;//return false;
        } else {
            map = new HashMap<>();
            cache.put(set, map);
        }
        for (int i = 0; i < N; i++) {
            if (!opened[i] && hand[T[i]]>0) {
                hand[T[i]]--;
                for (int j = 0; j < chest[i].length; j++)
                    hand[chest[i][j]]++;
                path.add(i);
                opened[i] = true;
                if (step()) return true;
                opened[i] = false;
                path.pollLast();
                for (int j = 0; j < chest[i].length; j++)
                    hand[chest[i][j]]--;
                hand[T[i]]++;
            }
        }
        for (int i = 0; i < N; i++)
            if (!opened[i]) {
                map.put(tos(hand), Boolean.FALSE);
                return false;
            }
        return true;
    }
}
