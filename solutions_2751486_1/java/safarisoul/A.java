package gcj2013r1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class A {
    public static void main(String[] args) throws IOException,
            FileNotFoundException {
        // String input = "A-small-attempt0.in";
        // String output = "A-small-attempt0.out";
        String input = "A-large.in";
        String output = "A-large.out";

        Scanner scan = new Scanner(new BufferedReader(new FileReader(input)));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(
                output)));

        int T = Integer.parseInt(scan.nextLine());
        for (int t = 1; t <= T; t++) {
            String[] info = scan.nextLine().split(" ");
            long value = value(info[0], Integer.parseInt(info[1]));

            pw.println("Case #" + t + ": " + value);
            System.out.println("Case #" + t + ": " + value);
        }

        scan.close();
        pw.close();
    }

    private static ArrayList<Integer> ends = new ArrayList<Integer>();

    private static void getEnds(String name, int n) {
        ends.clear();
        int pre = -1;
        for (int i = 0; i < name.length(); i++)
            if (isV(name.charAt(i)))
                pre = i;
            else if (i - pre >= n)
                ends.add(i);
    }

    private static long value(String name, int n) {
        getEnds(name, n);
        long count = 0;
        for (int i = 0; i < name.length() && ends.size() > 0; i++) {
            while (ends.size() > 0 && ends.get(0) - i < n - 1)
                ends.remove(0);
            if (ends.size() > 0)
                count += name.length() - ends.get(0);
        }
        return count;
    }

    private static boolean isV(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
}
