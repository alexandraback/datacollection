import java.io.*;
import java.util.*;

public class Main {
    
    public static void main(String args[]) throws FileNotFoundException {
        
        final Scanner in = new Scanner(new File("/home/mikel/Desktop/codejam/Round1C/input.txt"));
        final PrintWriter out = new PrintWriter(new File("/home/mikel/Desktop/codejam/Round1C/output.txt"));
        
        final int t = in.nextInt(); in.nextLine();
        for (int it = 1; it <= t; it++) {
            
            final String s[] = in.nextLine().split("/");
            
            long p = Long.parseLong(s[0]);
            long q = Long.parseLong(s[1]);
            
            long result = 0;
            boolean found = false, possible = false;
            if (p > 0 && p < q) {
                
                while (p%2 == 0 && q%2 == 0) {
                    p /= 2;
                    q /= 2;
                }
                
                while (q % 2 == 0 && !found) {
                    q = q/2;
                    result++;
                    if (p >= q) {
                        found = true;
                        
                        p = p - q;
                        while (p > 0 && q % 2 == 0) {
                            q = q/2;
                            if (p >= q) {
                                p -= q;
                            }
                        }
                        if (p == 0) possible = true;
                        break;
                    }
                }
            }
            
            out.print("Case #" + it + ": ");
            out.println(!possible ? "impossible" : result);
        }
        
        out.close();
    }
    
}