package codejam;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Gedion Moyo
 */
public class recycler {

    /**
     * @param args the command line arguments
     */
    
    public static void main(String[] args) {
        try {
           solve();
        } catch (Exception ex) {
            Logger.getLogger(recycler.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public static void solve() throws Exception {
        Scanner in = new Scanner(new FileReader("src/codejam/input.txt"));
        PrintWriter out = new PrintWriter(new FileWriter("src/codejam/output.txt"));

        int caseCount = Integer.valueOf(in.nextLine());
        for (int caseNum = 0; caseNum < caseCount; caseNum++) {
            //System.out.println("solving case " + caseNum);
            
            out.print("Case #" + (caseNum + 1) + ":");
            out.print(" ");
            int A = in.nextInt();
            int B = in.nextInt();
            out.print(permute(A,B));
            out.print("\n");
        }
        out.flush();
        out.close();
        in.close();

    }
    
    public static int permute(int A, int B){
        int count = 0;
        HashMap<String,Integer>  map = new HashMap<>();
         
        for(int n = A;n <=B;n++){
            String N[] = (n+"").split("");
            int base = (int) (Math.floor(Math.log10(n) + 1.0));
            String[] num = new String[base];

            
            for(int j=0;j<base;j++){
                num[j] = "";
                for(int i =0; i < base; i++){
                    num[j] = num[j] + N[(i+j)%base+1];
                }
                if (A<=n && n < Integer.valueOf(num[j]) && Integer.valueOf(num[j]) <= B){
                    //System.out.print(n+"\t"+ num[j] +"\n");
                    map.put(n+","+num[j], 1);
                    count++;
                }
            }
        }
            
       return map.size();
    }
}
