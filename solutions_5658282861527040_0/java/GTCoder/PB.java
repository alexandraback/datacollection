import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Map.*;
import java.math.*;
public class PB {
     public static void main(String[] args) throws Exception {
            solveProblem();
        }
        static String readLine(BufferedReader br) throws Exception {
            String line = br.readLine();
            while(line != null && line.trim().length() == 0) 
                   line = br.readLine();
            if(line != null) return line.trim();
            return line;
            
        }

        public static void solveProblem() throws Exception {
            final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringBuffer sb = new StringBuffer();
            String line = readLine(br);
            int T = Integer.parseInt(line);
            for(int i = 1; i<=T; i++) {
               String[] comps = readLine(br).split("\\s+");
               int A = Integer.parseInt(comps[0]);
               int B = Integer.parseInt(comps[1]);
               int K = Integer.parseInt(comps[2]);
               int count  = 0;
               for(int p = 0; p<A; p++) {
                 for(int q = 0; q<B; q++) {
                    if(( p & q ) < K) count++;
                 }
               }
               sb.append("Case #" + i + ": " + count + "\n");
            }
            System.out.print(sb.toString());
        }
}
