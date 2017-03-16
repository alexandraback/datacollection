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
public class C {

    public static void main(String[] args) throws Exception {

        //solve one case for test purpose
        //        String input = "2\n" +
        //                "4 5 8\n" +
        //                "3 5 11";
        //        Scanner scanner = new Scanner(new ByteArrayInputStream(input.getBytes()));
        //        new C().solve(scanner);

        InputStream is = new BufferedInputStream(new FileInputStream(args[0]+".in"));
        System.setOut(new PrintStream(args[0]+".out"));
        Scanner scanner = new Scanner(is);
        new C().solve(scanner);

        scanner.close();
    }

    /**
     * solve the given riddle
     * first read the amount of riddles in the data, then solve each of it
     * @param scanner to read the input data from
     */
    public void solve(Scanner scanner) {
        int numCases = scanner.nextInt();
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
        long maxWidth = scanner.nextInt();
        long maxheight = scanner.nextInt();
        long size = scanner.nextInt()+4;
        if (size<=8) {
            System.out.println(size-4);
            return;
        }
        long diff = 0;
        if (size>maxWidth*maxheight-4) {
            diff = maxWidth*maxheight - size;
            size = maxWidth*maxheight;
        }
        long max = Math.max(maxWidth,maxheight);
        long sqrt = (long) Math.floor(Math.sqrt(size));
        for (long i=sqrt;i>0;i--) {
            if (size % i ==0) {
                long w = i;
                long h = size /i;
                if (w>max || h>max)
                    continue;
                long around = 2*(w-2)+2*(h-2)-diff;
                System.out.println(around);
                return;
            }
        }
        System.out.println("ERROR");
    }

}
