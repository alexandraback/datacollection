
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author pulasthi
 */
public class QB12 {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter("b.txt");
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int result = 0;
            int N = sc.nextInt(); //no of googlers
            int S = sc.nextInt();   //surprising
            int p = sc.nextInt();   //max score
            int noSCutoff = p * 3 - 2;
            int sCutoff = p * 3 - 4;
            noSCutoff = Math.max(p, noSCutoff);
            sCutoff = Math.max(p, sCutoff);
            for (int j = 0; j < N; j++) {
                int number = sc.nextInt();
                if (number >= noSCutoff) {
                    result++;
                } else if (S > 0 && number >= sCutoff) {
                    S--;
                    result++;
                }
            }
            out.print("Case #" + (i + 1) + ": ");
            out.println(result);
        }
        out.flush();
        out.close();
    }
}
