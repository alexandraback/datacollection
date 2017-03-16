import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Problem2 {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new FileReader(new File("data/B-large.in")));
        PrintWriter out = new PrintWriter(new File("data/B-large.out"));
        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            String s = br.readLine();
            boolean[] b = new boolean[s.length()];
            for (int i = 0; i < s.length(); i++)
                b[i] = s.charAt(i) == '+';
            int result = fix(b);
            out.println("Case #" + t + ": " + result);
        }
        br.close();
        out.close();
    }

    private static int fix(boolean[] b) {
        int n = -1;
        for(int i=0;i<b.length;i++){
            if(!b[i])
                n = i+1;
        }
        if(n == -1)
            return 0;
        if(b[0]){
            int p = 0;
            for(int i=0;i<n;i++){
                if(b[i]){
                    p++;
                } else {
                    break;
                }
            }
            for(int i=0;i<p;i++)
                b[i] = false;
            return 1 + fix(b);
        } else {
            for(int i=0;i<n/2;i++){
                boolean tmp = b[i];
                b[i] = !b[n-1-i];
                b[n-i-1] = !tmp;
            }
            if(n%2 == 1){
                b[n/2] = !b[n/2];
            }
            return 1 + fix(b);
        }
    }
}
