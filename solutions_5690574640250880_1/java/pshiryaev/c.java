/*
 Qualification Round 2014
 C. Minesweeper Master
 */
package jam.y2014.q;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

/**
 *
 * @author shiryap
 */
public class c {

    static Scanner in;
    static PrintStream out;
    static final String filepath = System.getProperty("user.dir") + "//src//jam//y2014//q//C-large.in";
    //static final String filepath = System.getProperty("user.dir") + "//src//jam//y2014//q//C-small-attempt2.in";
    //static final String filepath = System.getProperty("user.dir") + "//src//jam//y2014//q//C-test-50x50.in";

    static int rectX1 = 0;
    static int rectY1 = 0;
    static int rectX2 = 0;
    static int rectY2 = 0;
    static int rectX3 = 0;
    static int rectY3 = 0;

    public static void main(String[] args) throws FileNotFoundException {

        System.out.println(filepath);
        in = new Scanner(new File(filepath));
        out = new PrintStream(new File(filepath + ".out"));

        int T = Integer.parseInt(in.nextLine()); // The first line of the input gives the number of test cases, T. T test cases follow. 
        for (int t = 1; t <= T; t++) {

            int R = in.nextInt();
            int C = in.nextInt();
            int M = in.nextInt();

            System.out.println("Case #" + t + ": " + R + " " + C + " " + M);

            if (C * R <= M) {
                throw new RuntimeException("Limit violation: 0 ≤ " + M + " < " + R + " * " + C);
            }

            out.println("Case #" + t + ":");
            if (testOneClick(R, C, M) == true) {
                display(R, C, M);
            } else {
                System.out.println("Impossible");
                out.println("Impossible");
            }
        }

    }

    public static boolean testOneClick(int R, int C, int M) {

        // reset
        rectX1 = 0;
        rectY1 = 0;
        rectX2 = 0;
        rectY2 = 0;
        rectX3 = 0;
        rectY3 = 0;

        int S = C * R - M; // count of spaces not occupied by mines

        // if 1 free space only then win
        if (S == 1) {
            rectX1 = 1;
            rectY1 = 1;
            return true;
        }

        // if 1 row or 1 column then 1 click will win
        if (S > 0 && (C == 1 || R == 1)) {
            rectX1 = C;
            rectY1 = R;
            if (C == 1) {
                rectY1 = S;
            } else {
                rectX1 = S;
            }
            return true;
        }

        // a simple rectangle/square general case: find 2 integer divisors x, y where (x <= R && y <= C) || (..)
        if (testRectangle3(S, R, C)) {
            return true;
        }

        return false;
    }

    public static boolean testRectangle3(int S, int R, int C) {

        for (int ir = 2; ir <= R; ir++) {
            for (int ic = 2; ic <= C; ic++) {
                int testS = ir * ic;
                if (testS == S) // can fit in one rectangle
                {
                    rectX1 = ic;
                    rectY1 = ir;
                    return true;
                } else if (testS > S) {
                    break; // skip iteration
                } else // still fits; try a second rectangle
                {
                    for (int ir2 = ir + 1; ir2 <= R; ir2++) {
                        for (int ic2 = 2; ic2 < ic; ic2++) {
                            int testS2 = (ir2 - ir) * ic2;
                            if (testS + testS2 == S) // 2 rectangles fit
                            {
                                rectX1 = ic;
                                rectY1 = ir;
                                rectX2 = ic2;
                                rectY2 = ir2;
                                return true;
                            } else if (testS + testS2 > S) {
                                break; // skip iteration
                            } else // still has space; try 3rd rectangle
                            {
                                for (int ir3 = ir + 1; ir3 < ir2; ir3++) {
                                    for (int ic3 = ic2 + 1; ic3 < ic; ic3++) {
                                        int testS3 = (ic3 - ic2) * (ir3 - ir);
                                        if (testS + testS2 + testS3 == S) // 3 rectangles fit
                                        {
                                            rectX1 = ic;
                                            rectY1 = ir;
                                            rectX2 = ic2;
                                            rectY2 = ir2;
                                            rectX3 = ic3;
                                            rectY3 = ir3;
                                            return true;
                                        } else if (testS + testS2 + testS3 > S) {
                                            break; // out of free space
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        return false;
    }

    public static void display(int R, int C, int M) {

        int S = C * R - M; // count of spaces not occupied by mines\
        int testM = M;

        if (rectX1 == 0 || rectY1 == 0) {
            throw new RuntimeException("Program error: rectX = " + rectX1 + "; rectY = " + rectY1);
        }

        for (int ir = 1; ir <= R; ir++) {
            String row = "";
            for (int ic = 1; ic <= C; ic++) {
                if (ir == 1 && ic == 1) {
                    row += "c";
                } // else if (ir <= rectY && ic <= rectX) { row += ".";
                else if ((ir <= rectY1 && ic <= rectX1) // first rectangle
                        ) {
                    row += ".";
                } else if (ir > rectY1 && ir <= rectY2 && ic <= rectX2) // second rectangle
                {
                    row += ".";
                } else if (ir > rectY1 && ir <= rectY3 && ic > rectX2 && ic <= rectX3) // 3rd triangle
                {
                    row += ".";
                } else {
                    {
                        row += "*";
                        testM--;
                    }
                }

            }
            System.out.println(row);
            out.println(row);
        }

        if (testM != 0) {
            throw new RuntimeException("Display error: not all mines are displayed: " + R + " " + C + " " + M);
        }
    }
}
