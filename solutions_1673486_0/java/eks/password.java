import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;


public class password {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/test1")); 

        String line;
        StringBuilder bubs = new StringBuilder();


        int T = Integer.parseInt(""+in.readLine().charAt(0));

        int i=0;
        while ((line=in.readLine())!=null) {
            i++;
            String[] splitline = line.split("\\s+");          
            int A = Integer.parseInt(splitline[0]);
            int B = Integer.parseInt(splitline[1]);
            String[] prob = in.readLine().split("\\s+");
            float m = 1;
            for (String p:prob) {
                m = m*Float.parseFloat(p);
            }
            
            float min = Math.min(2+B, m*(B-A+1) + (1-m)*(B+1 + B-A+1));

            for (int x=1;x<prob.length;x++) {
                float tempmin = 1;
   
                for (int j=0;j<x;j++) {
                    tempmin = tempmin*Float.parseFloat(prob[j]);
                }
                
                float exp = (A-x)+(B-x+1)*tempmin + (1-tempmin)*(1+B+B-x+1);
                if (exp < min) {
                    min = exp;
                }
                
            }
            
            System.out.println("Case #" + i + ": " + min);

            //StringBuilder subs = new StringBuilder();
            //subs.append("Case #" + i + ": ");
 


        }
        

    }
}
