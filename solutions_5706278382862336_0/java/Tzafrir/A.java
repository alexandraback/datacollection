package com.tzafrir.codeJam.contest2014.round1C;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * a solver interface for google contest riddles
 * @author tzafrir
 *
 */
public class A {

    public static void main(String[] args) throws Exception {

        //solve one case for test purpose
        //        String input = "5\n" +
        //                "1/2\n" +
        //                "3/4\n" +
        //                "1/4\n" +
        //                "2/23\n" +
        //                "123/31488";
        //        Scanner scanner = new Scanner(new ByteArrayInputStream(input.getBytes()));
        //        new A().solve(scanner);

        InputStream is = new BufferedInputStream(new FileInputStream(args[0]+".in"));
        System.setOut(new PrintStream(args[0]+".out"));
        Scanner scanner = new Scanner(is);
        new A().solve(scanner);

        scanner.close();
    }

    /**
     * solve the given riddle
     * first read the amount of riddles in the data, then solve each of it
     * @param scanner to read the input data from
     */
    public void solve(Scanner scanner) {
        int numCases = scanner.nextInt();
        scanner.nextLine();
        //        long time = System.currentTimeMillis();
        for (int i = 1; i <= numCases; i++) {
            System.out.print("Case #" + i + ": ");
            solveCase(scanner);
        }
        //        System.out.println("took "+(System.currentTimeMillis()-time));
    };

    /**
     * solve a given case of the underlying riddle
     * @param scanner to get the input data from
     */
    public void solveCase(Scanner scanner) {
        String line = scanner.nextLine();
        int p = Integer.valueOf(line.split("/")[0]);
        int q = Integer.valueOf(line.split("/")[1]);
        int count=0;
        int temp = q;
        while (temp>2) {
            if (temp%2!=0) {
                System.out.println("impossible");
                return;
            }
            temp=temp/2;
        }
        while (q>p) {
            if (q%2!=0) {
                System.out.println("impossible");
                return;
            }
            q=q/2;
            count++;
        }
        if (count>40)
            System.out.println("impossible");
        else
            System.out.println(count);
    }

}
