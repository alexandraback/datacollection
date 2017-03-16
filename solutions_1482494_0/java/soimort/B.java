import java.util.*;
import java.io.*;

public class B {
    public static int rush(int n, int []a, int []b) {
        boolean [] ma = new boolean[1000], mb = new boolean[1000];
        boolean changed;
        int score = 0, bs = 0, s = 0;
        do {
            changed = false;
            for (int i = 0; i < n; i++) {
                if (!mb[i] && score >= b[i]) {
                    score += 2;
                    changed = mb[i] = true;
                    s++;
                    bs++;
                    //
                    System.out.println(i + ": 2*");
                }
            }
            
            if (bs == n) {
                //
                System.out.println();
                
                return s;
            }
            
            if (!changed) {
                int bmax = -1, bmax_i = -1;
                for (int i = 0; i < n; i++) {
                    if (!mb[i] && !ma[i] && score >= a[i] && b[i] > bmax) {
                        bmax = b[i];
                        bmax_i = i;
                    }
                }
                if (bmax >= 0) {
                    score += 1;
                    changed = ma[bmax_i] = true;
                    s++;
                    //
                    System.out.println(bmax_i + ": 1*");
                }
            }
            
        } while (changed);
        
        return -1;
    }
    
    public static void main(String[] args) throws IOException {
        Scanner inFile = new Scanner(new FileReader("b.in"));
        PrintWriter outFile = new PrintWriter(new FileWriter("b.out"));
        
        int caseAmount = Integer.parseInt(inFile.nextLine());
        for (int caseNum = 1; caseNum <= caseAmount; caseNum++) {
            int n = Integer.parseInt(inFile.nextLine());
            int [] a = new int[1000], b = new int[1000];
            for (int i = 0; i < n; i++) {
                String line = inFile.nextLine();
                a[i] = Integer.parseInt(line.split(" ")[0]);
                b[i] = Integer.parseInt(line.split(" ")[1]);
            }
            
            int result = rush(n, a, b);
            outFile.println("Case #" + caseNum + ": " + (result < 0 ? "Too Bad" : Integer.toString(result)));
            outFile.flush();
        }
        
        inFile.close();
        outFile.close();
    }
}
