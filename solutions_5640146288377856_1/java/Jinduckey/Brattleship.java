package codejam;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;


public class Brattleship {

    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        
        Scanner in = new Scanner(new FileReader("A-large (3).in"));
        PrintWriter out = new PrintWriter("output.txt", "UTF-8");

        int T = in.nextInt();

        for (int t = 1; t <= T; t++) {
            int R = in.nextInt();
            int C = in.nextInt();
            int W = in.nextInt();
            int ans = answer(R, C, W);
            out.println("Case #" + t + ": " + ans);
            System.out.println(ans);
        }
        in.close();
        out.close();
    }

    public static int answer(int R, int C, int W) {
        return C / W * (R - 1) + (C - 1) / W + W;
    }

}
