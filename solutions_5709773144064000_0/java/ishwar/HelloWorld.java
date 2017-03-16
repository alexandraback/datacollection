package com.example;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.Scanner;

public class HelloWorld {
    static PrintWriter out = null;
    static FileInputStream in = null;
    static Scanner inp;

    public static void main(String[] args) throws IOException {

        try {
            in = new FileInputStream("src/com/resources/smallInput.txt");
            out = new PrintWriter("src/com/resources/output.txt");
            inp = new Scanner(in);

            int tc = inp.nextInt();
            //            inp.nextLine();
            for (int i = 0; i < tc; i++) {
                solveTest(i + 1, inp.nextFloat(), inp.nextFloat(), inp.nextFloat());
            }
        } finally {
            if (in != null) {
                in.close();
            }
            if (out != null) {
                out.close();
            }
        }
    }

    private static void solveTest(int tc, double c, double f, double x) throws IOException {
        DecimalFormat df = new DecimalFormat(".#######");
        boolean debug = false;
        double crate = 2-f;
        double time1, time2;
        double totalTime = 0;
        String output;

        if (x < c) {
            totalTime = x / 2;
            output = "Case #" + tc + ": " + df.format(totalTime);
            System.out.println(output);
            out.println(output);
            return;
        }

        do {
            crate += f;
            totalTime += c / crate;
            if(debug)
                System.out.println(c/crate + " " + totalTime);
            time1 = (x - c) / crate;
            time2 = (x) / (crate + f);
        } while (time2 < time1);

        totalTime += (x - c) / crate;

        output = "Case #" + tc + ": " + df.format(totalTime);
        System.out.println(output);
        out.println(output);
    }
}
