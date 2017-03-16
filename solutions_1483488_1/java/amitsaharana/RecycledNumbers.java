import java.io.*;
import java.util.*;
public class RecycledNumbers {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for(int z=0; z<t; z++) {
            StringTokenizer st = new StringTokenizer(br.readLine()," ");
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            long ans  =0;
            for(int i=n; i<=m; i++) {
                ans+=(no(i,m));
            }
            
            System.out.println("Case #"+(z+1)+": "+ans);
        }   
    }
    public static int no(long n, long max) {
        String s = n+"";
        int p = s.length();
        HashSet<Integer> b = new HashSet<Integer>();
        //int ans = 0;
        for(int i=1; i<p; i++) {
            if(s.charAt(i)!='0') {
                String s1 = s.substring(i) + s.substring(0,i);
                int temp = Integer.parseInt(s1);
                if(temp>n && temp<=max && !b.contains(temp)) {
                    //System.out.println(n+" "+temp);
                    //ans++;
                    b.add(temp);
                }
            }
        }
        return b.size();
    }
}
