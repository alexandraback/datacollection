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
    char i = 'i', j = 'j', k = 'k', one = '1';

    int Iterations, numChars;
    String pattern;

    List<Integer> list = null;
    Boolean parity = false;
    Pojo pojo;

    void read() {
        parity = false;
        pojo = new Pojo();

        numChars = sc.nextInt();
        Iterations = sc.nextInt();

        pattern = sc.next();

        for (char c : pattern.toCharArray()) {
            pojo.setC(getMultiplication(pojo.getC(), c));
        }
        pojo.setParity(parity);
        parity = false;
    }

    void solve() {
        char finalPattern[] = new char[3];
        finalPattern[0] = one;
        finalPattern[1] = one;
        finalPattern[2] = one;
        Boolean parityI = false;
        Boolean parityJ = false;
        Boolean flagK = false;

        int counter = 0;

        for (; (counter < Iterations && !flagK); counter++) {
            for (char c : pattern.toCharArray()) {
                if ((finalPattern[0] != i) || parityI) {
                    finalPattern[0] = getMultiplication(finalPattern[0], c);
                    parityI = parity;
                } else {
                    if ((finalPattern[1] != j) || parityJ) {
                        finalPattern[1] = getMultiplication(finalPattern[1], c);
                        parityJ = parity;
                    } else {
                        flagK = true;
                        finalPattern[2] = getMultiplication(finalPattern[2], c);
                    }
                }
            }
        }

        for (; counter < Iterations; counter++) {
            if ((finalPattern[0] != i) || parityI) {
                finalPattern[0] = getMultiplication(finalPattern[0], pojo.getC());
                if (pojo.getParity()) {
                    parity = !parity;
                }
                parityI = parity;
            } else {
                if ((finalPattern[1] != j) || parityJ) {
                    finalPattern[1] = getMultiplication(finalPattern[1], pojo.getC());
                    if (pojo.getParity()) {
                        parity = !parity;
                    }
                    parityJ = parity;
                } else {
                    finalPattern[2] = getMultiplication(finalPattern[2], pojo.getC());
                    if (pojo.getParity()) {
                        parity = !parity;
                    }
                }
            }
        }

        if (!parity && finalPattern[0] == i && finalPattern[1] == j && finalPattern[2] == k) {
            out.println("YES");
            System.out.println("YES");
        } else {
            out.println("NO");
            System.out.println("NO");
        }
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

    public class Pojo {
        char c = '1';
        Boolean parity = false;

        public char getC() {
            return c;
        }

        public void setC(char c) {
            this.c = c;
        }

        public Boolean getParity() {
            return parity;
        }

        public void setParity(Boolean parity) {
            this.parity = parity;
        }
    }

    char getMultiplication(char inp1, char inp2) {

        if (inp1 == one) {
            return inp2;
        }
        if (inp2 == one) {
            return inp1;
        }

        if (inp1 == i) {
            switch (inp2) {
                case 'i':
                    parity = !parity;
                    return one;
                case 'j':
                    return k;
                case 'k':
                    parity = !parity;
                    return j;

            }
        }
        if (inp1 == j) {
            switch (inp2) {
                case 'i':
                    parity = !parity;
                    return k;
                case 'j':
                    parity = !parity;
                    return one;
                case 'k':
                    return i;

            }
        }
        if (inp1 == k) {
            switch (inp2) {
                case 'i':
                    return j;
                case 'j':
                    parity = !parity;
                    return i;
                case 'k':
                    parity = !parity;
                    return one;

            }
        }
        System.out.println("ERROR");
        return 'f';
    }
}
