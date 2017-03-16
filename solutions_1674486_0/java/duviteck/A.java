import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A implements Runnable {
    private static BufferedReader reader;
    private static StringTokenizer st;
    private static byte[][] table;
    private static boolean[] visited;
    private static int[] parent;
    private static int[] components;
    private static int n;


    public static void main(String[] args) {
        new Thread(new A()).start();
    }

    @Override
    public void run() {
        try {
            solve();
        } catch (IOException e) {}
    }

    private void solve() throws IOException {
        reader = new BufferedReader(new FileReader("a.in"));
        PrintWriter writer = new PrintWriter(new FileWriter("a.out"));

        int n = nextInt();
        for (int i = 1; i <= n; i++) {
            boolean ans = calcAns();
            if (ans) {
                writer.println("Case #" + i + ": Yes");
            } else {
                writer.println("Case #" + i + ": No");
            }
        }

        writer.close();
    }

    static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(reader.readLine());
        }
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    static boolean calcAns() throws IOException {
        n = nextInt();
        table = new byte[n][n];
        visited = new boolean[n];
        parent = new int[n];
        Arrays.fill(visited, false);
        Arrays.fill(parent, -1);

        for (int i = 0; i < n; i++) {
            int m = nextInt();
            for (int j = 0; j < m; j++) {
                table[i][nextInt() - 1] = 1;
            }
        }       // reading is finished

        components = new int[n];
        int componentCnt = 1;
        for (int i = 0 ; i < n; i++) {
            if (components[i] == 0) {
                components[i] = componentCnt;
                componentCnt++;
                componentDfs(i);
            }
        }

        for (int i = 0; i < n; i++) {
            int curComp = components[i];
            for (int j = 0; j < n; j++) {
                if (i != j && components[j] == curComp) {
                    if (checkXY(i, j)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    static int dfs(int cur, int par, int finish) {
        visited[cur] = true;
        parent[cur] = par;

        if (cur == finish) return -1;

        for (int i = 0; i < n; i++) {
            if (table[cur][i] == 1 && !visited[i]) {
                if (dfs(i, cur, finish) == -1) {
                    return -1;
                }
            }
        }
        return 0;
    }

    static void componentDfs(int cur) {
        for (int i = 0; i < n; i++) {
            if (components[i] == 0) {
                if (table[cur][i] == 1 || table[i][cur] == 1) {
                    components[i] = components[cur];
                    componentDfs(i);
                }
            }
        }

    }

    static boolean checkXY(int x, int y) {
        Arrays.fill(visited, false);
        if (table[x][y] == 1) {
            boolean ans = false;
            table[x][y] = 0;
//            if (x == 0 && y == 2 ) {
//                System.out.println("There");
//                for (byte[] a : table) {
//                    for (byte b : a) {
//                        System.out.print(b + " ");
//                    }
//                    System.out.println();
//                }
//                for (boolean b : visited) {
//                    System.out.print(b + " ");
//                }
//                System.out.println();
//            }
            if (dfs(x, -1, y) == -1) {
                ans = true;
            }
            table[x][y] = 1;
            return ans;
        }

        int temp = dfs(x, -1, y);
        if (temp != -1) {
            return false;
        }

        Arrays.fill(visited, false);
        int cur = y;
        while (parent[cur] != -1) {
            visited[cur] = true;
            cur = parent[cur];
        }

        visited[y] = false;
        temp = dfs(x, -1, y);
        return temp == -1;
    }
}