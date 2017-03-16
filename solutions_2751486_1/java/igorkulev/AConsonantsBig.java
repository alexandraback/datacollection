
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class AConsonantsBig {
    
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
    
    static long solve(String s, int N) {
        int i,j,k = 0;
        int L = s.length();
        int a = 0;
        long res = 0;
        
        for (i=0;i<L;i++) {
            
            if (isConsonant(s.charAt(i))) {
                k++;
            } else {
                k = 0;
            }
            
            if (k >= N) {
                a = i + 2 - N; 
            }
            
            res += a;
            
        }
        
        return res;
    }
    
    public static void main(String[] args) throws Exception {
        int i,j,k;
        
        BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
        PrintWriter out = new PrintWriter(new File("A-large.out"));
        
        int T = Integer.parseInt(br.readLine());
        
        for (k=1;k<=T;k++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String word = st.nextToken();
            int N = Integer.parseInt(st.nextToken());
            long res = solve(word, N);
            
            System.out.println("Case #"+k+": "+res);
            out.println("Case #"+k+": "+res);
        }
        
        out.close();
    }
    
}
