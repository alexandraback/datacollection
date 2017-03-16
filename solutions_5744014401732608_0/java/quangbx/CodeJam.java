
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class CodeJam {
    static Scanner scan;
    static PrintWriter out;
    public static void main(String[] arg) {
        try {
            File file = new File("E:\\B-small-attempt1.in");
            scan = new Scanner(file);
            out = new PrintWriter("E:\\data.out");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        int c = scan.nextInt();
        for(int i = 0; i < c; i++) {
//            out.println("Case #" + (i+1) + ": " + testcase());
			out.print("Case #" + (i+1) + ": ");
			testcase();
        }
        scan.close();
        out.close();
    }

    static int[][] N = new int[][]{
            {1,2},
            {1,3,1,2,3},
            {1,4,1,2,4,1,3,4,1,2,3,4},
            {1,5,1,2,5,1,3,5,1,4,5,1,2,3,5,1,2,4,5,1,3,4,5,1,2,3,4,5},
            {1,6,1,2,6,1,3,6,1,4,6,1,5,6,1,2,3,6,1,2,4,6,1,2,5,6,1,3,4,6,1,3,5,6,1,4,5,6,1,2,3,4,6,1,2,3,5,6,1,2,4,5,6,1,3,4,5,6,1,2,3,4,5,6}
    };

    static void testcase() {
        int a = scan.nextInt();
        int b = scan.nextInt();
        int n = (int)Math.pow(2, a-2);
        if(b>n) {
            out.println("IMPOSSIBLE");
        } else {
            out.println("POSSIBLE");
            for(int i = 1;i < a; i++) {
                int[] A = new int[a];
                int dem = 0;
                for(int k=0;k<N[a-2].length;k++) {
                    if(N[a - 2][k] == 1) {
                        dem++;
                        if(dem>b)
                            break;
                    }
                    if (N[a - 2][k] == i)
                        A[N[a - 2][k + 1] - 1] = 1;
                }
                for(int j=0;j<a;j++)
                    out.print(A[j]);
                out.println();
            }
            for(int j=0;j<a;j++)
                out.print("0");
            out.println();
        }
    }
}
