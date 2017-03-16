import java.util.*;
import java.io.*;

public class osmos {
    
    public static void main(String ... args) throws IOException {
        Scanner input = new Scanner(System.in);
        int t = Integer.parseInt(input.nextLine());
        for(int i=1;i<=t;i++) {
            StringTokenizer st = new StringTokenizer(input.nextLine());
            int a = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            int[] motes = new int[n];
            st = new StringTokenizer(input.nextLine());
            for(int u=0;u<n;u++) {
                motes[u] = Integer.parseInt(st.nextToken()); 
            }
            Arrays.sort(motes);
            int length = 1000002;
            long[] dyn = new long[length];
            for(int j=0;j<dyn.length;j++)
                dyn[j]=Long.MAX_VALUE;
            dyn[a] = 0;//-1
//            System.out.println(Arrays.toString(motes));
            for(int k=0;k<n;k++) {
                long[] temp = new long[length];
                for(int j=0;j<temp.length;j++)
                    temp[j]=Long.MAX_VALUE;
                for(int z=0;z<length;z++) {
                    if(dyn[z]==Long.MAX_VALUE)
                        continue;
                    if(z>motes[k]) {
                        int key = Math.min(z+motes[k],length-1);
                        temp[key]=Math.min(temp[key],dyn[z]);
                    }
                    if(z<=motes[k]) {
                        int key = z;
                        temp[z] = Math.min(temp[z],dyn[z]+1);
                    }
                    if(z>1) {
                        long key = z;
                        int count = 0;
                        while(key<=motes[k]) {
                            key+=key-1;
                            key = Math.min(key,length-1);
                            count++;
                        }
                        key = Math.min(key+motes[k],length-1);
                        int ikey = (int)key;
                        temp[ikey] = Math.min(temp[ikey],dyn[z]+count);
                    }
                }
//                System.out.println(Arrays.toString(temp));
                dyn = temp;
            }
            long min = Long.MAX_VALUE;
            for(int k=0;k<length;k++) {
                if(dyn[k]<min)
                    min = dyn[k];
            }
            System.out.println("Case #"+i+": "+min);
        }
    
    }
}
