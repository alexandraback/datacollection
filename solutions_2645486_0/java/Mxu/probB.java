import java.util.*;
import java.io.*;

public class probB {
    
    public static void main(String ... args) throws IOException {
        Scanner input = new Scanner(System.in);
        int t = Integer.parseInt(input.nextLine());
        PrintWriter out = new PrintWriter("probB.out");
        for(int i=1;i<=t;i++) {
            int e = input.nextInt();
            int r = input.nextInt();
            int n = input.nextInt();
            int[] values= new int[n];
            for(int u=0;u<n;u++)
                values[u] = input.nextInt();
            int[] dyn = new int[e+1];
            for(int u=0;u<n;u++) {
                int[] temp = new int[e+1];
                for(int k=0;k<e+1;k++) {
                    for(int c=0;c<=k;c++) {
                        int added = c*values[u];
                        int remaining = Math.min(k-c+r,e);
                        temp[remaining] = Math.max(temp[remaining],dyn[k]+added);
                    }
                }
                dyn = temp;
            }
            int max =0;
            for(int u=0;u<dyn.length;u++) {
                if(dyn[u]>max)
                    max = dyn[u];
            }
            out.println("Case #"+i+": "+max);
            System.out.println("Case #"+i+": "+max);
        }

    out.close();
    }
}
