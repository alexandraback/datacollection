import java.io.*;
import java.util.*;

public class RankAndFile {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        int N = scan.nextInt();
        int[] count = new int[2501];
        for (int i = 0; i < 2 * N - 1; i++) {
            line = in.readLine();
            scan = new Scanner(line);
            for (int j = 0; j < N; j++) {
                int height = scan.nextInt();
                count[height]++;
            }
        }
        for (int i = 0; i < 2501; i++) {
            if (count[i] % 2 == 1) {
                System.out.print(" " + i);
            }
        }
        System.out.println();
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ":");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new RankAndFile().run();
    }

}
