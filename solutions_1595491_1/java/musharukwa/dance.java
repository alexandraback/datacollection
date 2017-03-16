package codejam;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Gedion Moyo
 */
public class dance {

    /**
     * @param args the command line arguments
     */
    
    static Scanner in;
    static PrintWriter out;
    
    public static void main(String[] args) {
        try {
            in = new Scanner(new FileReader("src/codejam/input.txt"));
            out = new PrintWriter(new FileWriter("src/codejam/output.txt"));
           solve();
        } catch (Exception ex) {
            Logger.getLogger(CodeJam.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public static void solve() throws Exception {
        

        int caseCount = Integer.valueOf(in.nextLine());
        for (int caseNum = 0; caseNum < caseCount; caseNum++) {
            System.out.println("solving case " + caseNum);
            
            out.print("Case #" + (caseNum + 1) + ":");
            out.print(" ");
            int N = in.nextInt();
            int S = in.nextInt();
            int p = in.nextInt();
            int[] t = getScores(N);
            int count = 0;
            int suprises = 0;
            for (int j=0; j<t.length;j++){
                if (t[j] >= p){
                    if ((t[j]/3 >= p)||((t[j]+2)/3>=p)){
                        count++;
                    }else if (((t[j]+4)/3 >= p) && suprises < S){
                        count++;
                        suprises++;
                    }
                }
            }
            out.print(count);
            out.print("\n");
        }
        out.flush();
        out.close();
        in.close();

    }
    
    public static int[] getScores(int N){
        int[] scores = new int[N];
        for (int i =0; i < N;i++){
            scores[i] = in.nextInt();
        }
        
        return scores;
    }
}
