
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class ClassD {
    
    static BufferedWriter bw;
    
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(new File("C-small-1-attempt1.in"));
        bw = new BufferedWriter(new FileWriter(new File("output.out")));
            
        int tc = sc.nextInt();
        for(int d=1;d<=tc;d++){
            bw.write("Case #"+String.valueOf(d)+": ");
            
            int[] start = new int[2];
            double[] speed = new double[2];
            int index = 0;
            
            int hits = 0;
            
            int n = sc.nextInt();
            for(int i=0;i<n;i++){
                int di = sc.nextInt();
                int hi = sc.nextInt();
                int mi = sc.nextInt();
                
                for(int j=0;j<hi;j++){
                    start[index] = di;
                    speed[index] = 360.0/mi;
                    mi++;
                    index++;
                }
            }

            if(index<=1) hits = 0;
            else if(index==2){
                if(speed[0]>speed[1]){
                    double ft = (360-start[1])/speed[1];
                    double fast = start[0] + speed[0]*ft;
                    if(fast>720) hits = 1;
                }
                else{
                    double ft = (360-start[0])/speed[0];
                    double fast = start[1] + speed[1]*ft;
                    if(fast>=720.0) hits = 1;
                }
            }

            bw.write(String.valueOf(hits));
            bw.newLine();
            bw.flush();   
        }
        
        sc.close();
        bw.close();
    }
    
}
