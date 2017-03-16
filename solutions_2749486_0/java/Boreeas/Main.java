/*
 * This file is public domain
 */
package net.boreeas.gcj;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author malte
 */
public class Main {

    static long casenum = 1;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {

        BufferedReader reader =
                       new BufferedReader(new InputStreamReader(new FileInputStream("in")));

        String in = reader.readLine();
        while ((in = reader.readLine()) != null) {
            if (in.trim().isEmpty()) {
                continue;
            }

            String[] parts = in.split(" ");
            int x = Integer.parseInt(parts[0]);
            int y = Integer.parseInt(parts[1]);
            findPath(x, y);
        }
    }

    public static void findPath(int x, int y) {
        List<Character> path = new ArrayList<Character>();
        int units = 1;
        int currX = 0;
        int currY = 0;

        while (Math.abs(x - currX) > units) {
            if (currX < x) {
                currX += units;
                path.add('E');
            } else {
                currX -= units;
                path.add('W');
            }
            units++;
        }

        while (Math.abs(y - currY) > units) {
            if (currY < y) {
                currY += units;
                path.add('N');
            } else {
                currY -= units;
                path.add('S');
            }
            units++;
        }

        if (currX < x) {
            for (int i = 0; i < (x - currX); i++) {
                path.add('W');
                path.add('E');
            }
        } else if (currX > x) {
            for (int i = 0; i < (currX - x); i++) {
                path.add('E');
                path.add('W');
            }
        }


        if (currY < y) {
            for (int i = 0; i < (y - currY); i++) {
                path.add('S');
                path.add('N');
            }
        } else if (currY > y) {
            for (int i = 0; i < (currY - y); i++) {
                path.add('N');
                path.add('S');
            }
        }

        char[] arr = new char[path.size()];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = path.get(i);
        }
        printCase(new String(arr));
    }

    static void printCase(String solution) {
        System.out.println("Case #" + casenum + ": " + solution);
        casenum++;
    }
}