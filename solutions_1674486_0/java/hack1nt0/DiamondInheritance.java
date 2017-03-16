import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.Vector;

/**
 * Created with IntelliJ IDEA.
 * User: DaiYang
 * Date: 12-5-6
 * Time: 下午5:30
 * To change this template use File | Settings | File Templates.
 */
public class DiamondInheritance {
    static Vector<Integer>[] v = new Vector[1000+1];
    static int[] outD=new int[1000+1];
//    static int[] inD=new int[1000+1];
    static boolean[] vis=new boolean[1000+1];

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new FileReader("test.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("module\\src\\test.out")));
        StringTokenizer st = new StringTokenizer(f.readLine());
        int T = Integer.parseInt(st.nextToken());
        for (int i = 0; i < 1000+1; i++) {
             v[i]=new Vector<Integer>();
        }
        for (int t = 1; t <= T; t++) {
            st = new StringTokenizer(f.readLine());
            int N = Integer.parseInt(st.nextToken());
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(f.readLine());
                int M = Integer.parseInt(st.nextToken());
                vis[i]=false;
                outD[i]=M;
                v[i].clear();
                for (int j = 0; j < M; j++) {
                    v[i].add(Integer.parseInt(st.nextToken()));
                }
            }
            out.print("Case #"+t+": ");
            int find=0;
            for (int i = 0; i < N; i++) {

                if(outD[i]<2)continue;
                Arrays.fill(vis,false);//2
                if(dfs(i)){find=1;out.println("Yes");break;}

            }
            if(find==0) out.println("No");

        }
        out.close();
        System.exit(0);
}
    private static boolean dfs(int u){
        if(vis[u]) return true;
        vis[u]=true;
        int m=v[u].size();
        for (int i = 0; i < m; i++) {
            int j=v[u].elementAt(i)-1;

            if(dfs(j))return true;
        }
        return false;
    }
}
