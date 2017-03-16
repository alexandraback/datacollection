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
        File f = new File("D-large.in");
        Scanner s = new Scanner(f);
        String line = s.nextLine();
        int T = Integer.parseInt(line);
        
        //open output file
        File f2 = new File("bigresult.txt");
        PrintWriter p = new PrintWriter(f2);
        
        
        for ( int j = 1; j <= T; j++) {
            String[] parts = s.nextLine().split(" ");

            int X = Integer.parseInt(parts[0]);
            int R = Integer.parseInt(parts[1]);
            int C = Integer.parseInt(parts[2]);
            
            /**
             * With enough patience, we can analyze by hand / cases: (Since X >= 7 is easy)
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
             *      More generally, Richard wins for R=0mod3, C=1
             *      For R=0mod3, C>1, Gabriel can place 2 Ls in a 3x2 corner and tile the remainder
             *
             * X = 4: If R*C is not divisible by 4, counting shows that Richard wins.
             * For the small dataset, R*C divisible by 4 gives us only a small set
             * to consider: (RxC) in {2x2, 4x1, 4x2, 4x3, 4x4} and reflections
             *      4 4ominos don't fit in a 2x2 (Richard wins)
             *      4 4ominos don't fit in a 4x1 or 1x4 (Richard wins)
             *      Placing a T 4omino in a 4x2 of 2x4 does not allow other pieces (Richard wins)
             *      It is easily verified that a 3x4 or 4x4 tiling is possible using 1 of any
             *      4omino (Gabriel wins)
             *      Generalizing,
             *           1x4k does not fit the 4/5 4ominos (Richard wins)
             *           2x2k does fits the T 4omino, but divides the remaining squares into sections
             *           of odd parity (Richard wins)
             *           Any larger RC=0mod4 region can be handled via the cases previously described
             *           and adding squares and lines to fill out the remaining region (Gabriel wins)
             *      
             * X = 5: R*C != 0mod 5 -> Richard wins
             * If one dimension is <= 2, the C shape either does not fit or isolates a square,
             * so Richard wins.If both R,C <= 4, at least ----- does not fit (Richard wins)
             * For R,C>=3 and at least 1 is >=5, and RC=0mod5, some geometric handwork shows
             * that a tiling can always be made which accomodates Richard's choice (Gabriel wins)
             *
             * X = 6: R*C !=0mod6 -> Richard wins
             * If both R,C<= 5, some 6omino will not fit (Richard wins) 
             * There are pieces which do not fit when one dimension is <= 2 (Richard)
             * Hence, Gabriel may only win when both dimensions are >=3, at least 1 is >= 6 and 
             * RC=0mod6.
             *      When the smaller dimension is >= 4, no piece can isolate or divide-off vertices,
             *      since rings or pieces of min width > 3 are not possible.
             *      Hence, Gabriel can always provide a tiling. (Gabriel wins)
             *      When the smaller dimension is exactly 3, we must consider pieces with a minimum
             *      width of 3.
             *          The piece
             *                x x
             *                  x x
             *                  x x
             *      will always split the remaining squares so that one section has n vertices,
             *      for which n != 0mod6.  Hence, Richard wins.
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
                if ((R*C % 3 != 0) || (R == 1 && C % 3 == 0) || (R % 3 == 0 && C == 1)) {
                    p.println("Case #" + j + ": RICHARD");
                } else {
                    p.println("Case #" + j + ": GABRIEL");
                }
             } else if (X == 4) {
                if ((R*C % 4 != 0) || (R <= 2) || (C <= 2)) {
                    p.println("Case #" + j + ": RICHARD");
                } else {
                    p.println("Case #" + j + ": GABRIEL");
                }
             } else if (X == 5) {
                if ((R*C % 5 != 0) || (R <= 2) || (C <= 2) || (R <= 4 && C <= 4)) {
                    p.println("Case #" + j + ": RICHARD");
                } else {
                    p.println("Case #" + j + ": GABRIEL");
                }
             } else if (X == 6) {
                if ((R*C % 6 != 0) || (R <= 5 && C <= 5) || (R <= 3) || (C <= 3)) {
                    p.println("Case #" + j + ": RICHARD");
                } else {
                    p.println("Case #" + j + ": GABRIEL");
                }
             } else if (X >= 7) {
                p.println("Case #" + j + ": RICHARD");
             } else {
                System.err.println("This code is only for the small case");
             }
            
        }
        
        p.close();
        s.close();
    }
}
