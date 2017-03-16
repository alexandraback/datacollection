package gcj2013r1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Scanner;

public class B {
    public static void main(String[] args) throws IOException,
            FileNotFoundException {
        String input = "B-small-attempt1.in";
        String output = "B-small-attempt1.out";
        // String input = "B-large.in";
        // String output = "B-large.out";

        Scanner scan = new Scanner(new BufferedReader(new FileReader(input)));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(
                output)));

        int T = Integer.parseInt(scan.nextLine());
        for (int t = 1; t <= T; t++) {
            String[] info = scan.nextLine().split(" ");
            int X = Integer.parseInt(info[0]);
            int Y = Integer.parseInt(info[1]);

            String result = "";
            if (X > 0)
                for (int i = 1; i <= Math.abs(X); i++)
                    result += "WE";
            if (X < 0)
                for (int i = 1; i <= Math.abs(X); i++)
                    result += "EW";
            if (Y > 0)
                for (int i = 1; i <= Math.abs(Y); i++)
                    result += "SN";
            if (Y < 0)
                for (int i = 1; i <= Math.abs(Y); i++)
                    result += "NS";

            pw.println("Case #" + t + ": " + result);
            System.out.println("Case #" + t + ": " + result);
        }

        scan.close();
        pw.close();
    }
}
