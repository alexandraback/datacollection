
import java.util.Scanner;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class B {

    static Scanner in;
    static String path = "src/";
    static String taskname = "B-large";

    public static String solve() {
        long A = in.nextLong();
        long B = in.nextLong();
        long K = in.nextLong();
        long z = 0;
        
        long min_AB = Math.min(A, B);
        if (K > min_AB ) {
        	return "" + A*B;       	
        } 
        	
        
        z = K* (A+B) - (K*K); 
        
        for (long i=K; i<A ;i++) {
        	for(long j=K; j<B;j++) {
        		long current_win_number = i&j;
        		
        		if ( K > current_win_number ) {
        			z++;     			
        		}
        	}
        }
       // System.out.println(z);
        return "" + z;
    }
      
    public static void main(String[] args) {
        PrintWriter pW = null;

        try {
            pW = new PrintWriter(new FileOutputStream(path
                    + taskname + ".out"));
            try {
                in = new Scanner(new FileInputStream(path
                        + taskname + ".in"));
                int T = in.nextInt();
                for (int caseNumber = 1; caseNumber <= T; caseNumber++) {
                    pW.println("Case #" + caseNumber + ": " + solve());
                }
                in.close();
                pW.close();
            } catch (IOException e) {
                System.out.println("Can not find file " + taskname + ".in");
            }
        } catch (IOException e) {
            System.out.println("Open or create exception with "
                    + taskname + ".out");
        }
    }
}
