package gcj2013q;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class FairandSquare {
    public static void main(String[] args) throws IOException,
            FileNotFoundException {
        String input = "C-small-attempt0.in";
        String output = "C-small-attempt0.out";
        // String input = "C-large.in";
        // String output = "C-large.out";

        Scanner scan = new Scanner(new BufferedReader(new FileReader(input)));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(
                output)));

        HashSet<Long> nums = new HashSet<Long>();
        for (long num = 1; num <= 10000000; num++) {
            String numstring = "" + num;
            boolean ok1 = true;
            for (int j1 = 0, j2 = numstring.length() - 1; j1 < j2; j1++, j2--)
                if (numstring.charAt(j1) != numstring.charAt(j2))
                    ok1 = false;
            if (!ok1)
                continue;
            long num2 = num * num;
            String numstring2 = "" + num2;
            boolean ok2 = true;
            for (int j1 = 0, j2 = numstring2.length() - 1; j1 < j2; j1++, j2--)
                if (numstring2.charAt(j1) != numstring2.charAt(j2))
                    ok2 = false;
            if (ok2)
                nums.add(num2);
        }

        int T = Integer.parseInt(scan.nextLine());
        for (int t = 1; t <= T; t++) {
            String[] info = scan.nextLine().split(" ");
            long A = Long.parseLong(info[0]);
            long B = Long.parseLong(info[1]);
            int result = 0;
            for (Long num : nums)
                if (num >= A && num <= B)
                    result++;
            pw.println("Case #" + t + ": " + result);
        }

        scan.close();
        pw.close();
    }

}
