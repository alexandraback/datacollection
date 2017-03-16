package com.vahid.contest.codejam.codejam2015.qualification;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class OminousOmino {

    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new File("input.txt"));
        BufferedWriter output = new BufferedWriter(new FileWriter("output.txt"));
        int n = input.nextInt();
        for (int counter = 1; counter <= n; counter++){
            int x = input.nextInt();
            int r = input.nextInt();
            int c = input.nextInt();
            output.write("Case #" + counter + ": " + (isPossible(x,r,c) ? "GABRIEL" : "RICHARD"));
            output.newLine();
        }
        input.close();
        output.close();
    }

    private static boolean isPossible(int x, int r, int c) {
        if ((r*c) % x != 0)
            return false;
        if (!((r>=x) || (c>=x)))
            return false;

        if (x>=7)
            return false;

        if (x<3)
            return true;

        if (x==3)
            return (r*c>3);

        if (x==4)
            return (r*c>8);

        if (x==5)
            return (r*c>10);

        if (x==6)
            return (r*c>18);

        throw new RuntimeException("I don't know");
    }

}
