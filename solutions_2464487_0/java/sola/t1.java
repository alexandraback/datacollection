import java.io.*;
import java.util.*;


public class t1 {
    final static String WORK_DIR = "C:\\Users\\Sola\\Desktop\\";
    
    
    
    
    public static void main (String[] args) throws IOException {
        
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "t1.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "t1.out"));
        int tc = sc.nextInt();


        
        
        for (int tci=1;tci<=tc;tci++) {
            long r = sc.nextLong();
            long t = sc.nextLong();
            long lastArea = 0;
            long curArea = 0;
            // calculate pi*r^2
            
            for (int i=1;i<=r;i++) {
                lastArea = curArea;
                curArea = curArea + 2*(i-1) + 1; 
            }
            long u;
            long cnt=0;

            for (u=0;u<=t;cnt++) {
                r++;
                lastArea = curArea;
                curArea = curArea + 2*(r-1) + 1; 
                u += curArea - lastArea;
                r++;
                lastArea = curArea;
                curArea = curArea + 2*(r-1) + 1;
            }
            if (tci<tc)
            pw.println("Case #" + tci + ": "+ (cnt-1));
            else pw.print("Case #" + tci + ": "+ (cnt-1));
        }
        pw.close();
    }
}