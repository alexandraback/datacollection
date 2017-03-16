import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class C{
    public static void main(String[] args) throws Exception{
        new C().run();
    }

    public static boolean nextPermutation(int[] a) {
        for (int i = a.length - 1; i > 0; --i) {
            if (a[i - 1] < a[i]) {
                int swapIndex = find(a[i - 1], a, i, a.length - 1);
                int temp = a[swapIndex];
                a[swapIndex] = a[i - 1];
                a[i - 1] = temp;
                Arrays.sort(a, i, a.length);
                return true;
            }
        }
        return false;
    }
 
    private static int find(int dest, int[] a, int s, int e) {
        if (s == e) {
            return s;
        }
        int m = (s + e + 1) / 2;
        return a[m] <= dest ? find(dest, a, s, m - 1) : find(dest, a, m, e);
    }

    int N, M;
    String[] zip;
    boolean[][] g;

    ArrayList<Integer> search(int cur, int target, boolean[] u, boolean[][] out){
        ArrayList<Integer> ret = new ArrayList<Integer>();
        ret.add(cur);
        u[cur] = true;
        if(cur == target)
            return ret;
        for(int i = 0; i < N; i++)
            if(g[cur][i] && !u[i]){
                if(out[cur][i])
                    continue;
                ArrayList<Integer> res = search(i, target, u, out);
                if(res != null){
                    ret.addAll(res);
                    return ret;
                }
            }
        return null;
    }

    boolean ok(int[] a){
        boolean[] visited = new boolean[N];
        int[][] num = new int[N][N];
        boolean[][] out = new boolean[N][N];
        visited[a[0]] = true;
        int cur = a[0];
        for(int i = 1; i < N; i++){
            int next = a[i];
            boolean[] u = new boolean[N];
            ArrayList<Integer> path = search(cur, next, u, out);
            if(path == null)return false;
            for(int j = 1; j < path.size()-1; j++)
                if(!visited[path.get(j)])
                    return false;
            for(int j = 1; j < path.size(); j++){
                int x = path.get(j-1), y = path.get(j);
                if(!out[x][y] && !out[y][x])
                    out[x][y] = true;
                num[x][y]++;
            }
            visited[next] = true;
            cur = next;
        }
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(g[i][j] && (out[i][j]?num[i][j]:num[j][i]) > 1)
                    return false;
        return true;
    }

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int o = 1; o <= T; o++){
            System.out.printf("Case #%d: ", o);
            N = sc.nextInt();
            M = sc.nextInt();
            zip = new String[N];
            for(int i = 0; i < N; i++)
                zip[i] = sc.next();
            g = new boolean[N][N];
            for(int i = 0; i < M; i++){
                int a = sc.nextInt()-1;
                int b = sc.nextInt()-1;
                g[a][b] = g[b][a] = true;
            }
            int[] a = new int[N];
            for(int i = 0; i < N; i++)a[i] = i;
            String ans = null;
            do{
                if(ok(a)){
                    String s = "";
                    for(int i = 0; i < N; i++)
                        s += zip[a[i]];
                    if(ans == null || s.compareTo(ans) < 0)
                        ans = s;
                }
            }while(nextPermutation(a));
            System.out.println(ans);
        }
    }
}
