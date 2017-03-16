import java.util.*;
import java.io.*;

public class CodeJamMoney{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        for(int l = 1; l <= t; l++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int c = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            boolean[] nice = new boolean[v+1];
            ArrayList<Integer> good = new ArrayList<Integer>();
            int[] num = new int[d];
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < d; i++){
                num[i] = Integer.parseInt(st.nextToken());
            }
            for(int i = 1; i < (1<<d); i++){
                int k = 0;
                for(int j = 0; j < d; j++){
                    if((i & (1<<j)) > 0) k += num[j];
                }
                if(k <= v){
                    nice[k] = true;
                    good.add(k);
                }
            }
            int ans = 0;
            for(int i = 1; i <= v; i++){
                if(!nice[i]){
                    ans++;
                    int s = good.size();
                    good.add(i);
                    nice[i] = true;
                    for(int j = 0; j < s; j++){
                        int k = i + good.get(j);
                        if(k <= v){
                            nice[k] = true;
                            good.add(k);
                        }
                    }
                }
            }
            out.append("Case #" + l + ": " + ans + "\n");
        }
        System.out.print(out);
    }
}