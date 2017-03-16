import java.io.*;
import java.util.*;

/**
 * Created by szeyiu on 5/10/15.
 */
public class C1C {

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(new FileInputStream(new File("C-small-attempt0.in"))));
        BufferedWriter w = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File("C.out"))));
        int T = Integer.valueOf(r.readLine());
        C1C c1C = new C1C();
        for(int i=0; i<T; ++i) {
            String line = r.readLine();
            String[] splt = line.split(" ");
            int C = Integer.valueOf(splt[0]);
            int D = Integer.valueOf(splt[1]);
            int V = Integer.valueOf(splt[2]);
            line = r.readLine();
            splt = line.split(" ");
            List<Integer> coins = new ArrayList<Integer>();
            for(int ii=0; ii<splt.length; ++ii){
                coins.add(Integer.valueOf(splt[ii]));
            }
            int rst = c1C.solve(coins, V);
            int c = i+1;
            w.write("Case #" + c + ": " + rst + "\n");
        }
        w.flush();
        w.close();
        r.close();
    }

    int solve(List<Integer> coins, int max){
        int count = 0;
        int sum = 0;
        boolean[] bmap = new boolean[max+1];
        Set<Integer> canSet = new HashSet<Integer>();
        boolean solved = false;
        while(!solved) {
            for (int i = 1; i <= coins.size(); ++i) {
                dfs(coins, i, 0, 0, 0, canSet, max);
            }
            for (int v : canSet) {
                //System.out.println(v);
                if(v<=max) bmap[v] = true;
            }
            solved = true;
            int newc = 0;
            for (int i = 1; i < bmap.length; ++i) {
                if (!bmap[i]) {
                    solved = false;
                    newc = i;
                    count++;
                    break;
                }
            }
            coins.add(newc);
            //System.out.println("add coin");
        }
        return count;
    }

    public void dfs(List<Integer> coins, int num, int curnum, int start, int curSum, Set<Integer> canSet, int max){
        if(curSum>max) return;
        if(curnum == num){
            canSet.add(curSum);
            return;
        }

        for(int i=start; i<coins.size(); ++i){
            dfs(coins, num, curnum+1, i+1, curSum+coins.get(i), canSet, max);
        }
    }
}
