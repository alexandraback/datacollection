package com.example;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

import static java.util.Arrays.deepToString;

public class HelloWorld {


    static PrintWriter out = null;
    static FileInputStream in = null;
    Scanner sc;

    Integer modulo, length, width;

    void read() {
        modulo = sc.nextInt();
        length = sc.nextInt();
        width = sc.nextInt();
        if (length < width) {
            length = length + width;
            width = length - width;
            length = length - width;
        }
    }

    void solve() {
        if (length * width % modulo != 0) {
            out.println("RICHARD");
            System.out.println("RICHARD");
            return;
        }

        for (int i = 1; i <= (modulo + 1) / 2; i++) {
            if ((i > width) || (modulo + 1 - i > length)) {
                out.println("RICHARD");
                System.out.println("RICHARD");
                return;
            }
        }

        if (width == 2 && modulo == 4) {
            out.println("RICHARD");
            System.out.println("RICHARD");
            return;
        }

        out.println("GABRIEL");
        System.out.println("GABRIEL");
    }

    void run() {
        try {
            in = new FileInputStream("src/com/resources/smallInput.txt");
            out = new PrintWriter("src/com/resources/output.txt");
        } catch (FileNotFoundException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
        sc = new Scanner(in);
        int caseN = sc.nextInt();
        for (int caseID = 1; caseID <= caseN; caseID++) {
            read();
            out.printf("Case #%d: ", caseID);
            System.out.printf("Case #%d: ", caseID);
            solve();
            System.out.flush();
        }
        out.close();
    }

    void debug(Object... os) {
        System.err.println(deepToString(os));
    }

    public static void main(String[] args) {
        try {
            System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (HelloWorld.class.getName() + ".in"))));
        } catch (Exception e) {
        }
        new HelloWorld().run();
    }
}
