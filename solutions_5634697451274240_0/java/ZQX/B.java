/**
 * Created by qixinzhu on 4/8/16.
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

    public static void genLargeP () throws FileNotFoundException {
        //File inputFile = new File("B-small-attempt0.in");
        File inputFile = new File("test.txt");
        PrintWriter out = new PrintWriter("test_large.txt");
        Scanner in = new Scanner(inputFile);
        int T = in.nextInt();
        in.nextLine();
        out.println(T);
        for (int i=0; i<T; i++) {
            String S = in.nextLine();
            String repeated = new String(new char[10]).replace("\0", S);
            out.printf("%s\n",repeated);
        }
        in.close();
        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException{
        // test case
//        genLargeP();
//        File inputFile = new File("test.txt");
//        PrintWriter out = new PrintWriter("test_out.txt");

        // real case
        File inputFile = new File("B-small-attempt0.in");
        PrintWriter out = new PrintWriter("B_out.txt");

        Scanner in = new Scanner(inputFile);

        int T = in.nextInt();
        in.nextLine();
        for (int i=0; i<T; i++) {
            String S = in.nextLine();
            char[] pies = S.toCharArray();
            //System.out.println(pies[pies.length-1]);
            int flipNum = 0;
            for (int j=pies.length-1; j>=0; j--) {
                if (j == pies.length-1) {
                    if (pies[j] == '-') {
                        flipNum++;
                    }
                } else {
                    if (pies[j] != pies[j+1]) {
                        flipNum++;
                    }
                }
            }
            out.printf("Case #%d: %d\n",i+1,flipNum);
        }

        in.close();
        out.close();
    }
}
