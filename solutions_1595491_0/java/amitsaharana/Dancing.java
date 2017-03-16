import java.io.*;
import java.util.*;
public class Dancing {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for(int z=1; z<=t; z++) {
            StringTokenizer st = new StringTokenizer(br.readLine()," ");
            int n = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());
            int ans = 0;
            int temp = 0;
            int[] a = new int[n];
            for(int i=0; i<n; i++) {
                a[i] = Integer.parseInt(st.nextToken());
                if(a[i]>(3*p-3)) ans++;
                if(a[i]==(3*p-3)||a[i]==(3*p-4)) temp++;
            }
            if(temp>s) temp = s;
            if(p==1) temp = 0;
            System.out.println("Case #"+z+": "+(ans+temp));
        }
    }
}
