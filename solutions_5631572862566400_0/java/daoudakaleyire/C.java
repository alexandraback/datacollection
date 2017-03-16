import java.io.*;
import java.util.*;

class Node
{
    public int x;
    public int color;
    public LinkedList<Integer> adj;
    public int dp, max;
    public Node(int x)
    {
        this.x = x;
        color = 0;
        adj = new LinkedList<>();
        dp = 0;
        max = 0;
    }
}

public class A {

    public static Node[] A = new Node[1001];
    public static int[] indeg = new int[1001];
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token;
        int t;
        t = Integer.parseInt(br.readLine());
        int N, u;
        for(int i = 1; i<=t;i++)
        {
            N = Integer.parseInt(br.readLine());
            for(int j = 1; j<=N;j++){
                A[j] = new Node(j);
                indeg[j] = 0;
            }
            token = new StringTokenizer(br.readLine());
            for(int j = 1; j<=N; j++){
                u = Integer.parseInt(token.nextToken());
                A[u].adj.add(j);
                indeg[j]++;
            }
            System.out.println("Case #"+i+": "+dfs(N));
        }
    }

    public static int dfs(int N){
        for(int i = 1; i<=N;i++){
            if(A[i].color == 0){
                if(indeg[i] == 0) dfs(i, N);
            }
        }
        for(int i = 1; i<=N;i++){
            if(A[i].color == 0){
                dfs(i, N);
            }
        }
        int ans = 0;
        for(int i = 1; i<=N;i++){
            ans = Math.max(ans, A[i].dp);
        }
        return ans;
    }

    public static void dfs(int u, int N){
        A[u].color = 1;
        int f = 0;
        int s = 0;
        for(Integer v:A[u].adj){
            if(A[v].color == 0)dfs(v, N);
            else if(A[v].color == 1) continue;

            if(A[v].max>=f){
                s = f;
                f = A[v].max;
            }
            else if(A[v].max>s){
                s = A[v].max;
            }
        }
        A[u].color = 2;
        A[u].dp = f+s+1;
        A[u].max = f+1;
    }
}