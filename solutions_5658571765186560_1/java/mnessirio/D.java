package gcj2015_Qualification;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class D {

    static Scanner in;
//    static String taskname = "D-small";
//    static String taskname = "D-small-attempt0";
//    static String taskname = "D-small-attempt1";
    static String taskname = "D-large";
//    static String taskname = "D-small-practice";

    public static String solve(int X, int R, int C) {
        // R-by-C grid must have number of cells that evenly divided by X
        if ( R * C % X != 0) return "RICHARD"; //(0)

        /* Richard can chose X-omino with one empty cell inside
         e.g. X = 7; X-omino :
         xxx
         x x
         xx
         There is no way to choose X-omino to fill this empty cell inside
        */
        if ( X > 6 ) return "RICHARD";

        // suppouse width <= length
        int width = Math.min(R,C);
        int length = Math.max(R, C);

        // if we can't make empty cell and each side of grid >= X
        if ( width >= X ) return "GABRIEL"; // (1)

        // happy Gabriel case =)
        if ( X == 1) return "GABRIEL"; //(2)

        // there is enough place for xx 2-omino , because R * C % X == 0 from check (0)
        if ( X == 2 ) return "GABRIEL"; // (3)

        // in this point X > 2
        // Richard can choose L-omino which min width = (X+1)/2
        /*
        e.g. X = 3; X - omino with minimum width = 2
        xx
        x
        if X = 4; (4 + 1) / 2 = 2 :
        xxx
        x
        if X = 5; (5 + 1) / 2 = 3;
        xxx
        x
        x
        */
        if ( width < (X + 1)/2 ) return "RICHARD"; // (4)

        // in other cases if X == 3 and min width is >= (3+1)/2 = 2 from check (4)
        if ( X == 3 ) return "GABRIEL"; // (5)

        // in this point X > 3
        // if the max length of the grid is less than X, Richard can choose straight X-omino
        if ( length < X) return "RICHARD"; // (6)

        // in this point X > 3 and length >=X
        // if min grid width is 2, all cases where X > 4 checked in (4)
        /*
        Richard choice:
        xx
         xx
        it will separate two sides with odd numbers on each side; which make impossible for Gabriel to win
        */
        if ( width == 2 ) return "RICHARD"; //(7)

        // in this point X > 3
        // width > 2 from (4), X>3, and (7)
        if ( X == 4 ) return "GABRIEL"; // (8)

        /*
        .x...
        .xx..
        ..xx.
         */
        if ( X == 5 && width == 3 && length == 5) return "RICHARD";
        if ( X == 5 ) return "GABRIEL";

        // X = 6 ; width = 3,4,5
        if ( width == 3 ) return "RICHARD";

        // X = 6 ; width = 4,5

        return "GABRIEL";
    }

    public static void main(String[] args) {

        try {
            PrintWriter pW = new PrintWriter(new FileOutputStream("output/"
                    + taskname + ".out"));
            try {
                in = new Scanner(new FileInputStream("input/"
                        + taskname + ".in"));

                int T = in.nextInt();
                for (int caseNumber = 1; caseNumber <= T; caseNumber++) {
                    int X = in.nextInt();
                    int R = in.nextInt();
                    int C = in.nextInt();
                    pW.println("Case #" + caseNumber + ": " + solve(X,R,C));
                }
                in.close();
                pW.close();
            } catch (IOException e) {
                System.out.println("Can not find file " + taskname + ".in");
            }
        } catch (IOException e) {
            System.out.println("Open or create exception with "
                    + taskname + ".out");
        }
    }
}

