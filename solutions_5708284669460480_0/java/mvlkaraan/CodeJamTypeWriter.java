import java.util.*;
import java.io.*;

public class CodeJamTypeWriter{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        for(int casenum = 1; casenum <= t; casenum++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());
            String kk = br.readLine();
            int s = Integer.parseInt(st.nextToken());
            char[] key = kk.toCharArray();
            String ll = br.readLine();
            int lim = (int)Math.pow(k,s);
            int max = 0;
            int tot = 0;
            for(int i = 0; i < lim; i++){
                StringBuilder sb = new StringBuilder();
                int ii = i;
                for(int ctr = 0; ctr < s; ctr++){
                    sb.append(key[ii%k]);
                    ii /= k;
                }
                String ss = sb.toString();
                int count = 0;
                for(int j = 0; j < s-l+1; j++) if(ss.substring(j,j+l).equals(ll)) count++;
                max = Math.max(max,count);
                tot += count;
            }
            out.append(String.format("Case #%d: %f\n",casenum,max-(1.0*tot/lim)));
        }
        System.out.print(out);
    }
}