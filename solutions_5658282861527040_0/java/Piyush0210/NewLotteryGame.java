import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class NewLotteryGame {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner s = new Scanner(new File("/home/piyushk/codejam/B-small-attempt0.in"));
        PrintWriter pw = new PrintWriter("/home/piyushk/codejam/B-small-attempt0.out");

        int T = s.nextInt();
        

        for(int i = 0; i < T; i++) {
            int A = s.nextInt();
            int B = s.nextInt();
            int K = s.nextInt();
            int cnt = 0;
            for(int a = 0; a < A; a++) {
                for(int b = 0; b < B; b++) {
                    if((a & b) < K) {
                        cnt++;
                    }
                }
            }
            pw.println(String.format("Case #%s: %s", i + 1, cnt));
        }
        pw.close();
        s.close();
        System.out.println("Done");
    }
}
