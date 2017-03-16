
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class ClassD {
    
    static BufferedWriter bw;
    
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(new File("C-small-2-attempt1.in"));
        bw = new BufferedWriter(new FileWriter(new File("output.out")));
            
        int tc = sc.nextInt();
        for(int d=1;d<=tc;d++){
            bw.write("Case #"+String.valueOf(d)+": ");
            
            int[] start = new int[10];
            double[] speed = new double[10];
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
            else{
                hits = 10;
                for(int i=0;i<index;i++){
                    int temp = 0;
                    double ft = (360-start[i])/speed[i];
                    for(int j=0;j<index;j++){
                        if(i==j)continue;
                        double fast = start[j] + speed[j]*ft;
                        if(fast<360.0) temp += 1;
                        else if(fast>=720.0) temp += (int)(fast/360)-1;
                    }
                    if(temp<hits) hits = temp;
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
