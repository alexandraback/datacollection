/**
 * Created by qixinzhu on 4/8/16.
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

    public static void genLargeP () throws FileNotFoundException {
        File inputFile = new File("A-small-attempt0.in");
        PrintWriter out = new PrintWriter("test_b.txt");
        Scanner in = new Scanner(inputFile);
        int T = in.nextInt();
        out.println(T);
        for (int i=0; i<T; i++) {
            out.printf("%d\n",(int) (Math.random()*100000));
        }
        in.close();
        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException{
        // test case
//        genLargeP();
//        File inputFile = new File("test_b.txt");
//        PrintWriter out = new PrintWriter("test_out.txt");

        // real case
        File inputFile = new File("A-large.in");
        PrintWriter out = new PrintWriter("A_out_b.txt");

        Scanner in = new Scanner(inputFile);

        int T = in.nextInt();
        int N;
        int lastNum;
        for (int i=0; i<T; i++) {
            N = in.nextInt();
            if (N == 0) {
                out.printf("Case #%d: INSOMNIA\n", i+1);
                continue;
            }
            boolean[] digits = new boolean[10];
            int digitSum = 55;
            lastNum = 0;
            do {
                lastNum += N;
                int curNum = lastNum;
                while(curNum > 0) {
                    int lastDigit = curNum % 10;
                    if (!digits[lastDigit]) {
                        digits[lastDigit] = true;
                        digitSum = digitSum - lastDigit - 1;
                    }
                    curNum = curNum / 10;
                }
            }
            while (digitSum > 0);

            out.printf("Case #%d: %d\n", i+1, lastNum);
        }

        in.close();
        out.close();
    }
}
