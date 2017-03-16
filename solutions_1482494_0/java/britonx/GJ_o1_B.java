import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Hashtable;


public class GJ_o1_B {

    public static void solve(final int[][] s, int N, int cur, int[] visited, int numVisited, int steps, int[] minStep){
        if (steps+N-numVisited>=minStep[0])
            return;
        if (numVisited == N){
            //System.out.println(steps);
            minStep[0] = Math.min(minStep[0], steps);
        }
        ArrayList<Integer> togo = new ArrayList<Integer>();
        int res = 0;
        int[] cand = new int[N];
        for (int i=0; i<N; i++) if(visited[i]<2)
            if (s[i][1]<=cur){
                // visit as 2-rating
                togo.add(i);
                cand[i] = 1;
            }
        ArrayList<Integer> togo1r = new ArrayList<Integer>();
        for (int i=0; i<N; i++) if(visited[i]<2)
            if (cand[i] ==0 && visited[i]==0 && s[i][0]<=cur){
                // visit as 1-rating
                togo1r.add(i);
                cand[i] = 1;
            }
        //sort togo1r by s[?][1]
        Integer[] tmp = (Integer[]) togo1r.toArray(new Integer[togo1r.size()]);
        Arrays.sort(tmp, new Comparator<Integer>() {
            @Override public int compare(final Integer o1, final Integer o2) {
                return Float.compare(s[o1][1], s[o2][1]);
            }
        });
        for (int i=0; i<tmp.length; i++){
            togo.add(tmp[i]);
            //System.out.print(tmp[i] + " ");
        }
        //if (tmp.length>0) System.out.println(" : "+ cur + " [ "+ minStep[0]);
        
        for (int i=0; i<N; i++) if(visited[i]<2)
            if (cand[i] ==0 && visited[i]==1 && s[i][1]<=cur){
                // visit as 1-rating
                togo.add(i);
                cand[i] = 1;
            }
        //System.out.println(togo.toString());
        for (int j=0; j<togo.size(); j++) {
            int i = togo.get(j);
            if (visited[i]==0 && s[i][1]<=cur){
                // visit as 2-rating
                visited[i] = 2;
                solve(s, N, cur+2, visited, numVisited+1, steps+1, minStep);
                visited[i] = 0;
            }
            else if (visited[i]==1 && s[i][1]<=cur){
                // visit as 1-rating
                visited[i] = 2;
                solve(s, N, cur+1, visited, numVisited+1, steps+1, minStep);
                visited[i] = 1;
            }
            else if (visited[i]==0 && s[i][0]<=cur){
                // visit as 1-rating
                visited[i] = 1;
                solve(s, N, cur+1, visited, numVisited, steps+1, minStep);
                visited[i] = 0;
            }
        }
    }


    public static void main(String[] args) throws NumberFormatException, IOException  {
        java.io.BufferedReader stdin = new java.io.BufferedReader(new java.io.InputStreamReader(new FileInputStream("B-small-attempt3.in")));
        java.io.BufferedWriter stdout = new java.io.BufferedWriter(new OutputStreamWriter(new FileOutputStream("1bout3.txt")));
        int T = Integer.parseInt(stdin.readLine());
        //T = 1;
        for (int ii=0; ii<T; ii++){
            String str = stdin.readLine();
            int N = Integer.parseInt(str);
            int[][] s = new int[N][2];
            for (int i=0; i<N; i++){
                str = stdin.readLine();
                String[] words = str.split(" ");
                s[i][0]  = Integer.parseInt(words[0]);
                s[i][1]  = Integer.parseInt(words[1]);
            }
            int[] visited = new int[N];
            int[] res = new int[1];
            res[0] = 3*N;
            //System.out.println(String.format("Case #%d: N=%d\n", (1+ii),N ));
            solve(s, N, 0, visited, 0, 0, res);

            //stdout.write(String.format("Case #%d: %.6f\n", (1+ii) ,res));
            if (res[0] == 3*N)
                System.out.println(String.format("Case #%d: Too Bad\n", (1+ii) ));
            else
                System.out.println(String.format("Case #%d: %d\n", (1+ii) , res[0]));
            if (res[0] == 3*N)
                stdout.write(String.format("Case #%d: Too Bad\n", (1+ii) ));
            else
                stdout.write(String.format("Case #%d: %d\n", (1+ii) , res[0]));
        }
        stdout.close();
    }

}
