// Code by PepeOfMath
//
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Problem4 {
    public static void main(String[] args) throws FileNotFoundException {
    
        //hard code the file location
        //open file
        //get number of test cases
        File f = new File("D-small-attempt0.in");
        Scanner s = new Scanner(f);
        String line = s.nextLine();
        int T = Integer.parseInt(line);
        
        //open output file
        File f2 = new File("smallresult.txt");
        PrintWriter p = new PrintWriter(f2);
        
        
        for ( int j = 1; j <= T; j++) {
            String[] parts = s.nextLine().split(" ");

            int X = Integer.parseInt(parts[0]);
            int R = Integer.parseInt(parts[1]);
            int C = Integer.parseInt(parts[2]);
            
            /**
             * For the small input, we can analyze by hand / cases:
             *
             *
             * X = 1: there is only 1 1omino (a square), which 
             * clearly tiles any grid.  Hence, Gabriel wins
             *
             * X = 2: there is again only a single 2omino.  The grid
             * can be tiled iff R*C is even (by tiling along the even dimension)
             * Hence, Gabriel wins iff R*C is even
             *
             * X = 3: there are two ominos: the L and ---.  By counting the omino
             * coverage, we see that Richard automatically wins if R*C is not
             * divisible by 3.  When RC is divisible by 3, one dimension is necessarily
             * divisible by 3.  Hence we can tile with lines of ---.  For the small dataset,
             * the only possible dimensions for RC = 0mod3 are {3x1, 3x2, 3x3, 3x4}
             * and images, of which {3x1} does not fit an L, and the rest can be tiled with 
             * at least 1 L
             *
             * X = 4: If R*C is not divisible by 4, counting shows that Richard wins.
             * For the small dataset, R*C divisible by 4 gives us only a small set
             * to consider: (RxC) in {2x2, 4x1, 4x2, 4x3, 4x4} and reflections
             *      4 4ominos don't fit in a 2x2 (Richard wins)
             *      4 4ominos don't fit in a 4x1 or 1x4 (Richard wins)
             *      Placing a T 4omino in a 4x2 of 2x4 does not allow other pieces (Richard wins)
             *      It is easily verified that a 3x4 or 4x4 tiling is possible using 1 of any
             *      4omino (Gabriel wins)
             *      
             *      
             * 
             * For X >= 7, Richard can choose a ring-like shape which isolates a central
             * piece, causing him to win automatically
             * 
             */
             
             //store the result in the output file
             if (X == 1) {
                p.println("Case #" + j + ": GABRIEL");
             } else if (X == 2) {
                if (R*C % 2 == 0) {
                    p.println("Case #" + j + ": GABRIEL");
                } else {
                    p.println("Case #" + j + ": RICHARD");
                }
             } else if (X == 3) {
                if (R*C % 3 != 0 || (R == 1 && C == 3) || (R == 3 && C == 1)) {
                    p.println("Case #" + j + ": RICHARD");
                } else {
                    p.println("Case #" + j + ": GABRIEL");
                }
             } else if (X == 4) {
                if (R*C % 4 != 0 || (R*C == 4) || (R*C == 8)) {
                    p.println("Case #" + j + ": RICHARD");
                } else {
                    p.println("Case #" + j + ": GABRIEL");
                }
             } else {
                System.err.println("This code is only for the small case");
             }
            
        }
        
        p.close();
        s.close();
    }
}
