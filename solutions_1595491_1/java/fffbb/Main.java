import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;


public class Main {

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
        if(args.length != 1) {
            return;
        }
        FileInputStream inputStream = new FileInputStream(args[0]);
        InputStreamReader istReader = new InputStreamReader(inputStream);
        BufferedReader buffReader = new BufferedReader(istReader);
        
        // T
        int T = Integer.valueOf(buffReader.readLine());
        
        for(int i = 1; i <= T; i++) {
            String[] caseStrs = buffReader.readLine().split(" ");
            int n = Integer.valueOf(caseStrs[0]);// N
            int s = Integer.valueOf(caseStrs[1]);// S
            int p = Integer.valueOf(caseStrs[2]);// p
            int p_possible, p_certain;
            switch(p) {
            case 0:
            case 1:
                p_possible = p_certain = p;
                break;
            default:
                p_possible = (p * 3) - 4;
                p_certain = (p * 3) - 2;
            }
            
            int y = 0, py = 0;
            for(int j = 0; j < n; j++) {
                int t = Integer.valueOf(caseStrs[3 + j]);
                
                if(t >= p_certain) {
                    y++;
                    continue;
                }
                
                if(t >= p_possible) {
                    py++;
                    continue;
                }
            }
            
            if(s > py) {
                y += py;
            } else {
                y += s;
            }
            
            StringBuilder resultBuilder = new StringBuilder("Case #");
            resultBuilder.append(i);
            resultBuilder.append(": ");
            resultBuilder.append(y);
            System.out.print(resultBuilder.toString());
            if(i != T)
                System.out.println();
        }
    }

}
