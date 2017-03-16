import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Fractiles {
    private static final String CASE = "Case #";
    private static final String IMPOSSIBLE = "IMPOSSIBLE";
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));

        int tcs = Integer.parseInt(br.readLine());
        for (int t = 1; t <= tcs; ++t) {
         
            String opFormat = CASE + t + ":";
            //if C = 1, we need K checks to figure out a gold tile, i.e., we need S=K
            //For K =1, we need just one check at index 1
            //For K=2, we need just one check at index 2 for C>=2
            //For K=3, we need two checks at indices 2, 3 for C>=2
            //For K=4, we need three checks at indices 2, 3, 4 for C>=2
            //For K=5, we need four checks at indices 2, 3, 4, 5 for C>=2
            //I think i get the pattern
            
            StringTokenizer st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken()), s = Integer.parseInt(st.nextToken());
            pw.print(opFormat);
            if(k==1){
                //I just hope S != 0, lol
             pw.println(" "+1);   
            }
            else{
            if(c==1){
                if(s>=k){
                    for(int i=1;i<=k;++i){
                        pw.print(" "+i);
                    }
                    pw.println();
                }else{
                    pw.println(" "+IMPOSSIBLE);
                }
            }else{
                if(s>=(k-1)){
                    for(int i=2;i<=k;++i){
                        pw.print(" "+i);
                    }
                    pw.println();
                }else{
                    pw.println(" "+IMPOSSIBLE);
                }
            }
            }   
            
        }
        pw.flush();
        pw.close();
        br.close();
    }
}

