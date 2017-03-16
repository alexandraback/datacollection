
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

public class D {
    
    static int K, N;
    static int initialKeys[];
    static int T[];
    static int total[];
    static int c[][];
    
    static boolean taken[];
    static int counter[];
    static int ordering[];
    
    static int base[];
    static HashSet<Integer> hs;
    
    static boolean generate(int d, int level, int mask) {
        
        int i,j,k;
        boolean temp;
        
        if (counter[T[d]] == 0) {
            return false;
        }
        
        if (hs.contains(mask^base[d]))
            return false;
        
        ordering[level] = d + 1;
        counter[T[d]]--;
        taken[d] = true; 
        for (i=0;i<total[d];i++) {
            counter[c[d][i]]++;
        }
        
        if (level == N - 1) {
            return true;
        }
        
        int nm = mask^base[d];
        hs.add(nm);
        
        for (i=0;i<N;i++) {
            if ((!taken[i])&&(counter[T[i]] > 0)) {
                temp = generate(i, level + 1, nm);
                if (temp == true)
                    return true;
            }
        }
        
        for (i=0;i<total[d];i++) {
            counter[c[d][i]]--;
        }
        taken[d] = false; 
        counter[T[d]]++;
        
        return false;
    }
    
    public static void main(String[] args) throws Exception {
        int i,j,k;
        
        BufferedReader br = new BufferedReader(new FileReader("D-small-attempt1.in"));
        PrintWriter out = new PrintWriter("D-small-attempt1.out");
        
        int TestCases = Integer.parseInt(br.readLine());
        
        for (k=1;k<=TestCases;k++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            K = Integer.parseInt(st.nextToken());
            N = Integer.parseInt(st.nextToken());
            initialKeys = new int[K];
            st = new StringTokenizer(br.readLine());
            for (i=0;i<K;i++) {
                initialKeys[i] = Integer.parseInt(st.nextToken());
            }
            
            T = new int[N];
            total = new int[N];
            c = new int[N][500];
            
            for (i=0;i<N;i++) {
                st = new StringTokenizer(br.readLine());
                T[i] = Integer.parseInt(st.nextToken());
                total[i] = Integer.parseInt(st.nextToken());
                for (j=0;j<total[i];j++) {
                    c[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            
            counter = new int[200];
            for (i=0;i<initialKeys.length;i++) {
                counter[initialKeys[i]]++;
            }
            
            boolean foundSolution = false;
            taken = new boolean[N];
            ordering = new int[N];
            
            base = new int[100];
            
            base[0] = 1;
            for (i=1;i<20;i++) {
                base[i] = base[i-1] * 2;
            }
            
            hs = new HashSet<Integer>();
            hs.add(0);
            
            for (i=0;i<N;i++) {
                if (generate(i, 0, 0)) {
                    foundSolution = true;
                    break;
                }
            }
            
            if (foundSolution) {
                out.print("Case #" + k + ": ");
                for (i=0;i<N-1;i++) {
                    out.print(ordering[i]+" ");
                }
                out.println(ordering[N-1]);
            } else {
                out.println("Case #" + k + ": IMPOSSIBLE");
            }
            
        }
        
        br.close();
        out.close();
    }
}