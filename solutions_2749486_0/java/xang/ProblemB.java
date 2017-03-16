package com.forthgo.contest.g2013r1c;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class ProblemB {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("B.in"));
            PrintWriter out = new PrintWriter(new FileWriter("B.out"));
//            PrintWriter out = new PrintWriter(System.out);
            int n = in.nextInt();
            in.nextLine();
            for (int i = 0; i < n; i++) {
                out.printf("Case #%d: ", i + 1);
                solve(in, out);
                out.println();
                out.flush();
            }
        } catch (IOException e) {
            throw new RuntimeException();
        }

    }

    private static void solve(Scanner in, PrintWriter out) {
        int X = in.nextInt();
        int Y = in.nextInt();
        StringBuilder path = new StringBuilder();
        if (X > 0) {
            for (int i = 0; i < X; i++) {
                path.append("WE");
            }
        }
        else {
            for (int i = 0; i < -X; i++) {
                path.append("EW");
            }
        }
        if (Y > 0) {
            for (int i = 0; i < Y; i++) {
                path.append("SN");
            }
        }
        else {
            for (int i = 0; i < -Y; i++) {
                path.append("NS");
            }
        }
        out.print(path.toString());
    }

}

