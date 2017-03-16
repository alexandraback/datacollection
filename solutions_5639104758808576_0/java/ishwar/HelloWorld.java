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

    Integer maxLevel;
    String pattern;

    List<Integer> list = null;
    List<Integer> list2 = null;

    void read() {
        maxLevel = sc.nextInt();
        list = new ArrayList<Integer>();
        list2 = new ArrayList<Integer>();
        int prev = 0;
        char shyness[] = sc.next().toCharArray();

        for (int i = 0; i <= maxLevel; i++) {
            list.add(Character.getNumericValue(shyness[i]));
            if (i > 0) {
                prev = list2.get(i - 1);
            }

            list2.add(prev + list.get(i));
        }
    }

    void solve() {
        int maxNeeded = 0;

        for(int i=1; i<list.size(); i++) {
            if((i - list2.get(i-1)) > maxNeeded) {
                maxNeeded = i - list2.get(i-1);
            }
        }

        out.println(maxNeeded);
        System.out.println(maxNeeded);
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
