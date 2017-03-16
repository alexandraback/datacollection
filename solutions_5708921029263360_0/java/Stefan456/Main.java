import java.util.Scanner;
import java.io.FileInputStream;
import java.io.PrintStream;

public class Main {
    public static void main(String[] args) throws Exception {
        // set up scanner and iterate over test cases
        Scanner scanner = new Scanner(new FileInputStream(
            "C:\\Users\\Stefan\\Downloads\\C-small-attempt1.in"));
        PrintStream output = new PrintStream(
            "C:\\Users\\Stefan\\Downloads\\C-small-attempt1.out");
        int T = scanner.nextInt();
        for (int t = 1; t <= T; ++t) {
            // get parameters
            int J = scanner.nextInt();
            int P = scanner.nextInt();
            int S = scanner.nextInt();
            int K = scanner.nextInt();
            // solve problem
            output.print("Case #" + t + ":");
            String outputS = "";
            int days = 0;
            int[][] jp = new int[J][P];
            int[][] ps = new int[P][S];
            int[][] js = new int[J][S];
            for (int j = 0; j < J; ++j)
                for (int p = 0; p < P; ++p)
                    for (int s = 0; s < S; ++s)
                    	if (jp[j][p] < K && ps[p][s] < K && js[j][s] < K) {
	                    	outputS += (j + 1) + " " + (p + 1) + " " + (s + 1) + "\n";
	                    	++jp[j][p];
	                    	++ps[p][s];
	                    	++js[j][s];
	                    	++days;
                    	}
           	output.print(" " + days + "\n" + outputS);
        }
        output.close();
        System.out.println("finished");
    }
}
