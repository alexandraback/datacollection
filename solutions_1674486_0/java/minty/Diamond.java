package round1C;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Diamond {

    Scanner in;
    BufferedWriter out;

    Diamond(String input, String output) throws Exception {
        in = new Scanner(new File(input));
        FileWriter fstream = new FileWriter(output);
        out = new BufferedWriter(fstream);
    }

    public void solveAll() throws IOException {
        int T = in.nextInt();

        for (int test = 1; test <= T; test++) {
            int N = in.nextInt();
            boolean[][] a = new boolean[N][N];

            for (int x = 0; x < N; x++) {
                int m = in.nextInt();
                for (int j = 0; j < m; j++) {
                    int y = in.nextInt();
                    y--;
                    a[x][y] = true;
                }
            }

            out.write("Case #" + test + ": " + solve(N, a));
            out.newLine();
        }

    }

    public String solve(int N, boolean[][] a) {
        for (int x = 0; x < N; x++) {
            if (bfs(N, x, a)) {
                return "Yes";
            }
        }
        return "No";
    }
    
    private boolean bfs(int N, int x, boolean[][] a) {
        Queue<Integer> q = new LinkedList<Integer>();
        boolean[] viz = new boolean[N];
        q.add(x);
        viz[x] = true;
        int el;
        
        while(!q.isEmpty()) {
            el = q.poll();
            for(int y = 0; y < N;y ++ ){
                if(a[el][y]){
                    if(!viz[y]) {
                        viz[y] = true;
                        q.add(y);
                    } else {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }

    public void close() throws IOException {
        in.close();
        out.close();
    }

    public static void main(String[] args) throws Exception {
        Diamond pb = new Diamond("input.txt", "output.txt");

        pb.solveAll();

        pb.close();
    }

    
}
