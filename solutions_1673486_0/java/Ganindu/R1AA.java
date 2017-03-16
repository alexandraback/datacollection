
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;


public class R1AA {    
    public static void main(String[] args){
        try{
            Scanner sc = new Scanner(new File("A-small-attempt0.in"));    
            BufferedWriter bw = new BufferedWriter(new FileWriter(new File("output.out")));
            int t = sc.nextInt();
            
            for(int i=0;i<t;i++){
                int a = sc.nextInt();
                int b = sc.nextInt();
                double m = b+2;
                double prob = 1;
                for(int j=1;j<=a;j++){
                    double f = sc.nextFloat();
                    prob = prob*f;
                    double h = prob*(a+b-j-j+1)+(1-prob)*(a+b-j-j+b+2);
                    if(h<m) m = h;
                }
                bw.write("Case #"+String.valueOf(i+1)+": ");
                bw.write(String.valueOf((float)m));
                bw.newLine();
                bw.flush();
            }
            bw.close();
        
        } catch (Exception ex) {
            Logger.getLogger(QA.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
