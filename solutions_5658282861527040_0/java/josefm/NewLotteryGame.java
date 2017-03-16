package jam2014.r1b;

import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

/**
 * Title: 
 * 
 * Link: 
 */
public class NewLotteryGame {
    public static void main(String[] args) throws Exception {
        //resolve("txt/2014/r1b/lottery-tiny");
        resolve("txt/2014/r1b/lottery-small");
        //resolve("txt/2014/r1b/lottery-large");
    }
    
    private static void resolve(String dataFile) throws Exception {
        // Initialize input and output.
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(new File(dataFile + ".in"));
        PrintWriter printer = new PrintWriter(dataFile + ".out");
        
        // Read number of test cases.
        int T = scanner.nextInt();
        
        // Evaluate each test case.
        for(int t=0; t<T; t++) {
            // Read input.
            int A = scanner.nextInt();
            int B = scanner.nextInt();
            int K = scanner.nextInt();

            // Verify that always A < B
            if(A > B) {
                int C = B;
                B = A;
                A = C;
            }
            
            // Calculate result.
            int result = resolveTestCase(A, B, K);
            
            // Print output.
            String message = "Case #" + (t+1) + ": " + (result) + "\n";
            System.out.print(message);
            printer.append(message);
        }
        
        printer.flush();
        printer.close();
    }
    
    private static int resolveTestCase(int A, int B, int K) {
        return forceBrute(A, B, K);
    }
    
    private static int forceBrute(int A, int B, int K) {
        int res = 0;
        
        for(int i=0; i<A; i++) {
            for(int j=0; j<B; j++) {
                int x = i & j;
                if(x <= (K-1)) {
                    res++;
                    //System.out.println("<" + i + "," + j +">: " + x + " <= " + (K-1));
                }
            }
        }
        
        return res;
    }
}
