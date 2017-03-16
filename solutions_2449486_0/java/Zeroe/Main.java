import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        String fileName = "B-small-attempt0";
        //String fileName = "test";

        String inFile = fileName + ".in";
        String outFile = fileName + ".out";
                
        Scanner in = new Scanner(new FileInputStream(inFile));
        PrintStream out = new PrintStream(outFile);
        
        int T = in.nextInt();
       
        long time = System.currentTimeMillis();
        for (int i = 1;  i <= T;  i++) {
            System.out.println("Solving case #" + i);
            
            out.print("Case #"+i+": ");
            solveCase(in, out);
            out.println();
        }
        
        float timePerCase = (System.currentTimeMillis() - time) / 1000f;
        System.out.println(String.format("Speed: %.3f second per case", timePerCase));
    }

    private static void solveCase(Scanner in, PrintStream out) {
        int N = in.nextInt();
        int M = in.nextInt();
        
        int[][] h = new int[N][M];
        
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                h[x][y] = in.nextInt();
            }
        }
        
        int[] maxV = new int[N];
        int[] maxH = new int[M];
        
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                int hh = h[x][y];
                
                if (maxV[x] < hh) maxV[x] = hh;
                if (maxH[y] < hh) maxH[y] = hh;
            }
        }
        
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                int hh = h[x][y];
                
                if (hh < maxV[x] && hh < maxH[y]) {
                    out.print("NO");
                    return;
                }
            }
        }
        
        out.print("YES");
    }
    
}
