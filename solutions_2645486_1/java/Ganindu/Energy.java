
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class Energy {
    
    static BufferedWriter bw;
    
    static int en,r,n;
    static long[] v,ce;
    
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(new File("B-large.in"));
        bw = new BufferedWriter(new FileWriter(new File("output.txt")));
            
        int tc = sc.nextInt();
        for(int d=1;d<=tc;d++){
            bw.write("Case #"+String.valueOf(d)+": ");
            
            en = sc.nextInt();
            r = sc.nextInt();
            n = sc.nextInt();
            
            v = new long[n];
            ce = new long[n+1];
            for(int i=0;i<n;i++){
                v[i] = sc.nextInt();
                ce[i] = en;
            }
            ce[n] = r;
            
            long gain = 0;
            update(0,n);
            
            for(int i=0;i<n;i++) gain += (ce[i]+r-ce[i+1])*v[i];
            
            bw.write(String.valueOf(gain));
            bw.newLine();
            bw.flush();
                
        }
        sc.close();
        bw.close();
    }
    
    static void update(int s, int e){
        if(e-s<2)return;
        int max = s;
        for(int i=max+1;i<e;i++) if(v[i]>v[max]) max = i; 
        for(int i=s+1;i<=max;i++){
            ce[i] = ce[i-1]+r;
            if(ce[i]>en) ce[i] = en;
        }
        for(int i=e-1;i>max;i--){
            ce[i] = ce[i+1]-r;
            if(ce[i]<r) ce[i] = r;
        }
        update(s,max);
        update(max+1,e);
    }
    
}
