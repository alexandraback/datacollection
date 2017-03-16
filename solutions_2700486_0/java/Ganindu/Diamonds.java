
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class Diamonds {
    
    static BufferedWriter bw;
    
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(new File("B-small-attempt2.in"));
        bw = new BufferedWriter(new FileWriter(new File("output.txt")));
                    
        int tc = sc.nextInt();
        for(int d=1;d<=tc;d++){
            bw.write("Case #"+String.valueOf(d)+": ");
            
            long n = sc.nextInt();
            int x = sc.nextInt();
            int y = sc.nextInt();
            
            if(x<0) x = -x;
            
            long m = ((x+y)/2)+1;
            long m1 = 2*m*m-5*m+3;          
            
            if(n<=m1){
                bw.write("0.0");
            }
            else{
                ++m;
                long m2 = 2*m*m-5*m+3;
                if(n>=m2){
                    bw.write("1.0");
                }
                else{
                    if(x==0){
                        bw.write("0.0");
                    }
                    else{
                        long rest = n-m1; 
                        ++y;
                        if(rest<y){
                            bw.write("0.0");
                        }
                        else{
                            double p = 0D; 
                            for(long i=0;i<y;i++) p += ncr(rest,i);
                            for(int i=0;i<rest;i++) p /= 2.0;
                            float pf = 1F - (float)p;
                            float rf = Float.parseFloat(String.format("%.6f", pf));
                            bw.write(String.valueOf(rf));
                            //bw.write(String.valueOf(pf));
                        }
                    }
                }
            }
        
            bw.newLine();
            bw.flush();            
        }
        sc.close();
        bw.close();
    }
    
    static long ncr(long n, long r){
        long d = 1;
        for(long i=n-r+1;i<=n;i++) d *= i;
        for(long i=2;i<=r;i++) d /= i;
        return d;
    }
    
}
