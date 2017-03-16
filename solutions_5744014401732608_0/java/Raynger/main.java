import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;

public class main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static PrintWriter pw = new PrintWriter(System.out);
    public static String line;
    public static StringTokenizer st;
    public static ArrayList<ArrayList<Integer>> adjList;
    public static int[] dr = {-1, 0, 1, 0, -1, 1, 1, -1};
    public static int[] dc = {0, 1, 0, -1, 1, 1, -1, -1};

    public static long test(int[][] grid, int N){
        long[] num = new long[N];
        num[0] = 1;
        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                if(grid[i][j] == 1){
                    num[j] += num[i];
                }
            }
        }
        return num[N-1];
    }

    public static void main(String[] args) throws Exception{
        int T = Integer.parseInt(br.readLine());
        int cases = 0;
        while(T-- != 0){
            pw.format("Case #%d: ", ++cases);
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            long M = Long.parseLong(st.nextToken());

            long target = (1L << (N-2));
            if(target < M){
                pw.print("IMPOSSIBLE\n");
                continue;
            }

            pw.print("POSSIBLE\n");

            int[][] grid = new int[N][N];
            for(int i = 0; i < N; i++){
                for(int j = i+1; j < N; j++){
                    grid[i][j] = 1;
                }
            }

            for(int i = 1; i < N; i++){
                if(((1L << (i-1)) & (target-M)) != 0){
                    // System.out.println(i+1);
                    grid[i][N-1] = 0;
                }
            }
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    pw.print(grid[i][j]);
                }
                pw.print("\n");
            }

            // pw.print(test(grid, N)+"\n");
        }

        pw.close();
        br.close();
    }
}

class Party implements Comparable<Party>{
    public int n;
    public char c;

    Party(int n, char c){
        this.n = n;
        this.c = c;
    }

    @Override
    public int compareTo(Party P){
        if(P.n != this.n){
            return P.n - this.n;
        } else{
            return (int)c - (int)P.c;
        }
    }

    public String toString(){
        return String.valueOf(c) + " " + String.valueOf(n);
    }
}
