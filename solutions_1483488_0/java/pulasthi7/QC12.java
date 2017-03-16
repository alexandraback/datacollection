import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

/**
 *
 * @author pulasthi
 */
public class QC12 {
    
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter("c.txt");
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            HashSet<String> hs = new HashSet<String>();
            int min = sc.nextInt();
            int max = sc.nextInt();
            for (int j = min; j <= max; j++) {
                String s = j+"";
                for(int k =1; k<s.length();k++){
                    String compS = s.substring(k)+s.substring(0, k);
                    int compI = Integer.parseInt(compS);
                    if(compI>j && compI<=max){
                        hs.add(j+""+compI);
                    }
                }
            }            
            out.print("Case #"+(i+1)+": ");
            out.println(hs.size());
            System.out.println(hs.size());
        }
        out.flush();
        out.close();
    }
    
}
