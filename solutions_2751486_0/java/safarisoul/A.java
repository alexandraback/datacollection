package gcj2013r1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
    public static void main(String[] args) throws IOException,
            FileNotFoundException {
        String input = "A-small-attempt0.in";
        String output = "A-small-attempt0.out";
        // String input = "A-large.in";
        // String output = "A-large.out";

        Scanner scan = new Scanner(new BufferedReader(new FileReader(input)));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(
                output)));

        int T = Integer.parseInt(scan.nextLine());
        for (int t = 1; t <= T; t++) {
            String[] info = scan.nextLine().split(" ");
            int value = value(info[0], Integer.parseInt(info[1]));

            pw.println("Case #" + t + ": " + value);
            System.out.println("Case #" + t + ": " + value);
        }

        scan.close();
        pw.close();
    }

    private static int value(String name, int n) {
        int count = 0;
        for (int i = 0; i < name.length(); i++)
            for (int j = i + 1; j <= name.length(); j++) {
                String sub = name.substring(i, j);
                int pre = -1, max = 0;
                for (int k = 0; k < sub.length(); k++)
                    if (isV(sub.charAt(k)))
                        pre = k;
                    else
                        max = Math.max(max, k - pre);
                if (max >= n)
                    count++;
            }
        return count;
    }

    private static boolean isV(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
}
