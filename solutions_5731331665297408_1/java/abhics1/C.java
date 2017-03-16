
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @author Abhimanyu Singh
 *
 */
public class C {

    private InputStream input;
    private PrintStream output;
    private Scanner inputSc;
    int n;
    int m;
    Zip z[];
    boolean edge[][];
    Node node[];
    final int INIT = 0;
    final int COVERED = 1;
    final int DONE = 2;
    int pos;
    int temp[];
    boolean dfsCovered[];

    class Node {

        int status;
        int par;
        int i;

        public Node(int i) {
            status = INIT;
            par = -1;
            this.i = i;
        }
    }

    class Zip implements Comparable<Zip> {

        int value;
        int i;

        public Zip(int value, int i) {
            this.value = value;
            this.i = i;
        }

        @Override
        public int compareTo(Zip o) {
            return this.value - o.value;
        }
    }

    public C(InputStream input, PrintStream output) {
        this.input = input;
        this.output = output;
        init();
    }

    private void init() {
        inputSc = new Scanner(input);
    }

    static int lineToInt(String line) {
        return Integer.parseInt(line);
    }

    public void solve() {
        int testCaseCount = lineToInt(inputSc.nextLine());
        for (int testN = 1; testN <= testCaseCount; testN++) {
            solveTestCase(testN);
        }
    }

    void dfs(int u) {
        dfsCovered[u] = true;
        for (int v = 0; v < n; v++) {
            if (!dfsCovered[v] && edge[u][v]) {
                dfs(v);
            }
        }
    }

    boolean canTake(int ni) {
        if (node[ni].status != INIT) {
            throw new RuntimeException("Impossible1");
        }
        int c = 0;
        temp[c] = pos;
        c++;
        boolean found = false;
        while (true) {
            int u = temp[c - 1];
            if (node[u].status != COVERED) {
                throw new RuntimeException("Impossible2");
            }
            if (edge[u][ni]) {
                found = true;
                break;
            }
            if (node[u].par != -1) {
                temp[c] = node[u].par;
                c++;
            } else {
                break;
            }
        }
        if (!found) {
            return false;
        }

        // make temporary covered
        for (int i = 0; i < c - 1; i++) {
            node[temp[i]].status = DONE;
        }
        //check reachability of other node
        dfsCovered = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (node[i].status == DONE) {
                dfsCovered[i] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!dfsCovered[i] && node[i].status == COVERED) {
                dfs(i);
            }
        }
        int dfsCount = 0;
        for (int i = 0; i < n; i++) {
            if (dfsCovered[i]) {
                dfsCount++;
            }
        }
        if (dfsCount < n) {
            //Not osssible
            //undo status done
            for (int i = 0; i < c; i++) {
                node[temp[i]].status = COVERED;
            }
            return false;
        } else {
            //update parent
            if (node[ni].par != -1) {
                throw new RuntimeException("Impossible3");
            }

            node[ni].par = temp[c - 1];
            node[ni].status = COVERED;
            pos = ni;
            return true;
        }
    }

    int makeSelection() {
        for (int i = 0; i < n; i++) {
            int ui = z[i].i;
            if (node[ui].status == INIT) {
                if (canTake(ui)) {
                    return z[i].value;
                }
            }
        }
        throw new RuntimeException("Impossible4");
    }

    private void solveTestCase(int testN) {
        Scanner tempSc = new Scanner(inputSc.nextLine());
        n = tempSc.nextInt();
        m = tempSc.nextInt();
        temp = new int[n];
        edge = new boolean[n][n];
        z = new Zip[n];
        node = new Node[n];
        for (int i = 0; i < n; i++) {
            tempSc = new Scanner(inputSc.nextLine());
            z[i] = new Zip(tempSc.nextInt(), i);
            node[i] = new Node(i);
        }
        for (int i = 0; i < m; i++) {
            tempSc = new Scanner(inputSc.nextLine());
            int u = tempSc.nextInt() - 1;
            int v = tempSc.nextInt() - 1;
            edge[u][v] = edge[v][u] = true;
        }
        Arrays.sort(z);
        int startI = z[0].i;
        String ans = "";
        ans += z[0].value;
        node[startI].status = COVERED;
        pos = startI;
        for (int i = 1; i < n; i++) {
            int zz = makeSelection();
            ans += zz;
        }
        output.println("Case #" + testN + ": " + ans);
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        C c = new C(System.in, System.out);
        c.solve();
    }
}
