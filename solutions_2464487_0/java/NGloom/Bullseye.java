import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Bullseye {
    
    public static double v(long r) {
        return (2*r+1);
    }
    
    
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("bulls_eye.txt"));
            int num = in.nextInt();
            for(int n = 1; n <= num; n++) {
                long r = in.nextLong();
                double t = in.nextLong();
                int cnt = 0;
//                System.out.println(r+" "+t);
                
                while(true) {
                    double v = v(r);
                    if(t >= v) {
                        t -= v;
                        cnt++;
                    }
                    else {
                        break;
                    }
                    r+=2;
                }
                
                System.out.println(String.format("Case #%d: %d",n,cnt));
                
            }
            
            
            
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}
