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

    int Credit, numItems;
    List<Integer> list = null;
    Map<Integer, Integer> map = null;

    void read() {
        numItems = sc.nextInt();
        list = new ArrayList<Integer>();

        for (Integer i = 1; i <= numItems; i++) {
            list.add(sc.nextInt());
        }
    }

    int solveHelper(int pivot) {


        Integer highest = 0;
        Integer score = 0;

        for (int i = 0; i < list.size(); i++) {
            int item = list.get(i);

            int pieces = (int) Math.ceil(item*1.0/pivot);
            int high = (int) Math.ceil(item*1.0/pieces);
            if(high > highest) highest = high;

            score += pieces - 1;
        }

        return highest + score;
    }

    void solve() {
        Comparator<Integer> cmp = Collections.reverseOrder();
        Collections.sort(list, cmp);
        int bestScore = list.get(0);

        for ( int i = 1; i < list.get(0); i++) {
            int score = solveHelper(i);
            if(score < bestScore) bestScore = score;
        }
        out.println(bestScore);
        System.out.println(bestScore);
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
