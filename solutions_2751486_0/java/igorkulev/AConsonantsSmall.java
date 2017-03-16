
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class AConsonantsSmall {
    
    static boolean isVowel(char c) {
        if (c == 'a')
            return true;
        if (c == 'e')
            return true;
        if (c == 'i')
            return true;
        if (c == 'o')
            return true;
        if (c == 'u')
            return true;
        return false;
    }
    
    static boolean isConsonant(char c) {
        return !isVowel(c);
    }
    
    static boolean solve(String s, int N) {
        int i,j,k = 0;
        
        for (i=0;i<s.length();i++) {
            if (isConsonant(s.charAt(i))) {
                k++;
                if (k == N)
                    return true;
            } else {
                k = 0;
            }
        }
        
        return false;
    }
    
    public static void main(String[] args) throws Exception {
        int i,j,k;
        
        BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new File("A-small-attempt0.out"));
        
        int T = Integer.parseInt(br.readLine());
        
        for (k=1;k<=T;k++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String word = st.nextToken();
            int N = Integer.parseInt(st.nextToken());
            int res = 0;
            
            for (i=0;i<word.length();i++) {
                for (j=i+1;j<=word.length();j++) {
                    if (solve(word.substring(i, j), N)) {
                        res++;
                    }
                }
            }
            
            System.out.println("Case #"+k+": "+res);
            out.println("Case #"+k+": "+res);
        }
        
        out.close();
    }
    
}
