
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
    
    public static void main(String[] args) throws Exception {
        int i,j,k;
        
        BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
        PrintWriter out = new PrintWriter("B-large.out");
        
        int T = Integer.parseInt(br.readLine());
        
        for (k=1;k<=T;k++) {
            
            StringTokenizer st = new StringTokenizer(br.readLine());
            int R = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());
            
            int nums[][] = new int[R][C];
            
            for (i=0;i<R;i++) {
                st = new StringTokenizer(br.readLine());
                for (j=0;j<C;j++) {
                    nums[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            
            int m[][] = new int[R][C];
            
            for (i=0;i<R;i++) {
                for (j=0;j<C;j++) {
                    m[i][j] = 100;
                }
            }
            
            boolean changeHappened = true;
            
            while (changeHappened) {
                
                changeHappened = false;
                
                // for each row
                for (i=0;i<R;i++) {
                    
                    int maxAllowed = -1000;
                    
                    for (j=0;j<C;j++) {
                        maxAllowed = Math.max(maxAllowed, nums[i][j]);
                    }
                    
                    for (j=0;j<C;j++) {
                        if (m[i][j] > maxAllowed) {
                            changeHappened = true;
                        }
                        m[i][j] = Math.min(m[i][j], maxAllowed);
                    }
                }
                
                // for each column
                for (j=0;j<C;j++) {
                    
                    int maxAllowed = -1000;
                    
                    for (i=0;i<R;i++) {
                        maxAllowed = Math.max(maxAllowed, nums[i][j]);
                    }
                    
                    for (i=0;i<R;i++) {
                        if (m[i][j] > maxAllowed) {
                            changeHappened = true;
                        }
                        m[i][j] = Math.min(m[i][j], maxAllowed);
                    }
                }
                
            }
            
            boolean yes = true;
            
            for (i=0;i<R;i++) {
                for (j=0;j<C;j++) {
                    if (m[i][j] > nums[i][j]) {
                        yes = false;
                    }
                }
            }
            
            if (yes) {
                out.println("Case #" + k + ": YES");
            } else {
                out.println("Case #" + k + ": NO");
            }
            
        }
        
        br.close();
        out.close();
        
    }
    
}
