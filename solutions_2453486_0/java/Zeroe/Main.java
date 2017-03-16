import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        String fileName = "A-small-attempt2";

        String inFile = fileName + ".in";
        String outFile = fileName + ".out";
                
        Scanner in = new Scanner(new FileInputStream(inFile));
        PrintStream out = new PrintStream(outFile);
        
        int T = in.nextInt();
       
        for (int i = 1;  i <= T;  i++) {
            out.print("Case #"+i+": ");
            solveCase(in, out);
            out.println();
        }
    }

    private static void solveCase(Scanner in, PrintStream out) {
        int[] XH = new int[4];
        int[] XV = new int[4];
        int[] OH = new int[4];
        int[] OV = new int[4];
        int XD1 = 0;
        int XD2 = 0;
        int OD1 = 0;
        int OD2 = 0;
        
        int empty = 0;
        
        int Tnum = 0;
        
        
        for (int y = 0; y < 4; y++) {
            String l = in.next();
            
            for (int x = 0; x < 4; x++) {
                boolean doX = false;
                boolean doO = false;
                
                switch (l.charAt(x)) {
                case 'X':
                    doX = true;
                    break;
                case 'O':
                    doO = true;
                    break;
                case 'T':
                    Tnum++;
                    doX = true;
                    doO = true;
                    break;
                case '.':
                    empty++;
                    break;
                }
                
                if (doX) {
                    XH[x]++;
                    XV[y]++;
                    if (x == y) XD1++;
                    if (x == 3-y) XD2++;
                }
                
                if (doO) {
                    OH[x]++;
                    OV[y]++;
                    if (x == y) OD1++;
                    if (x == 3-y) OD2++;
                }
            }
        }
        
        if (Tnum > 1) {
            throw new RuntimeException("Number of T too high.");
        }
        
        for (int i = 0; i < 4; i++) {
            if (XH[i] == 4 || XV[i] == 4 || XD1 == 4 || XD2 == 4) {
                out.print("X won");
                return;
            }
            
            if (OH[i] == 4 || OV[i] == 4 || OD1 == 4 || OD2 == 4) {
                out.print("O won");
                return;
            }
        }
        
        if (empty > 0) {
            out.print("Game has not completed");
        } else {
            out.print("Draw");
        }
    }
    
}
