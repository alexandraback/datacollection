package jam2012.r1c;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.regex.Pattern;

public class AClass {

    static int[][] inh;
    static boolean[] visited;
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
                new InputStreamReader(
                        new FileInputStream(
                                "E:\\google_code_jam\\2012\\r1c\\A_input_small.txt")));
        PrintStream out = new PrintStream(new FileOutputStream(
                "E:\\google_code_jam\\2012\\r1c\\A_output_small.txt"));
        
        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            int N = Integer.parseInt(br.readLine());
            inh = new int[N + 1][N + 1];
            for (int i = 1; i <= N; i++) {
                String[] line = br.readLine().split(Pattern.quote(" "));
                int Mi = Integer.parseInt(line[0]);
                for (int j = 1; j <= Mi; j++) {
                    inh[i][j] = Integer.parseInt(line[j]);
                }
            }
            visited = new boolean[N + 1];
            boolean b = solve(N);
            if (b) {
                out.println("Case #" + t + ": Yes");
                System.out.println("Case #" + t + ": Yes");
            } else {
                out.println("Case #" + t + ": No");
                System.out.println("Case #" + t + ": No");
            }
        }
    }

    private static boolean solve(int N) {
        boolean[] tried = new boolean[N + 1];
        for (int i = 1; i <= N; i++) {
            if (tried[i])
                continue;
            clearVisited();
            boolean ri = go(i, tried);
            if (ri)
                return true;
        }
        return false;
    }

    private static void clearVisited() {
        for (int i = 0; i < visited.length; i++)
            visited[i] = false;
    }

    private static boolean go(int i, boolean[] tried) {
        if(visited[i])
            return true;
        visited[i] = true;
        tried[i] = true;
        for (int j = 1; inh[i][j] != 0; j++) {
            boolean res = go(inh[i][j], tried);
            if (res)
                return true;
        }
        return false;
    }

}
