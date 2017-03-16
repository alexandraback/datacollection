package codejam.qual_2012;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class MainC {
static boolean[] seen;
    public static void main(String[] args) throws Exception {

        String f = "/home/floris/dev/java/Test/src/codejam/qual_2012/C-large.in";
        Scanner sc = new Scanner(new File(f));
        System.setOut(new PrintStream(new File(f+".out")));
        int T = sc.nextInt();
        for (int i=1; T-- > 0; i++) {
            System.out.printf("Case #%d: %d%n", i, solve(sc.nextInt(), sc.nextInt()));
        }
    }
    
    private static long solve(int A, int B) {
        long result = 0;
        int pos = 1;
        int t = A/10;
        while (t != 0) {t/=10; pos++;}
        int cutoff = 1;
        for (int i = 1; i < pos; i++) cutoff *=10;
        seen = new boolean[cutoff*10];
        fillSeen();
        
        for (int i = A; i<=B; i++) {
            if (seen[i]) continue;
            result += roll(A, B, i, pos, cutoff);
        }
        return result;

    }
    
    private static long roll(int A, int B, int v, int pos, int cutoff)
    {
        pos--; pos--;
        int result = 0;
        if (A<=v && v <= B) result++;
        seen[v] = true;
        int n = (v%cutoff)* 10 + v/cutoff;
        
        switch (pos) {
            case 6: 
                if (!seen[n ]&& A<=n && n <= B) result++;
                seen[n] = true; n = (n%cutoff)* 10 + n/cutoff;
            case 5: 
                if (!seen[n ]&& A<=n && n <= B) result++;
                seen[n] = true; n = (n%cutoff)* 10 + n/cutoff;
            case 4: 
                if (!seen[n ]&& A<=n && n <= B) result++;
                seen[n] = true; n = (n%cutoff)* 10 + n/cutoff;
            case 3: 
                if (!seen[n ]&& A<=n && n <= B) result++;
                seen[n] = true; n = (n%cutoff)* 10 + n/cutoff;
            case 2: 
                if (!seen[n ]&& A<=n && n <= B) result++;
                seen[n] = true; n = (n%cutoff)* 10 + n/cutoff;
            case 1: 
                if (!seen[n ]&& A<=n && n <= B) result++;
                seen[n] = true; n = (n%cutoff)* 10 + n/cutoff;
            case 0: 
                if (!seen[n ]&& A<=n && n <= B) result++;
                seen[n] = true; 
        }
        return ((long)result)*(result-1)/2;
    }

    private static boolean allDigitsSame(int c) {
        int d = c%10;
        c /= 10;
        while (c != 0) {
            if (c%10 != d) return false;
            c /= 10;
        }
        return true;
    }
    
    private static void fillSeen() {
        seen[0] = true;
        for (int i = 1; i < 10; i++) {
            int j = i;
            while (j < seen.length) {
                seen[j]=true;
                j = j * 10 + i;
            }
        }
    }
}
