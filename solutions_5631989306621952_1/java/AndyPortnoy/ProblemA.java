package codejam.template;

import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class ProblemA {


    private void solve(PrintWriter pw, String line) {
        char[] input = line.toCharArray();
        String output = String.valueOf(input[0]);
        for (int k = 1; k < input.length; k++) {
            char test = output.charAt(0);
            if (input[k] >= test) {
                output = String.valueOf(input[k]) + output;
            } else {
                output = output +  String.valueOf(input[k]);
            }
        }

        pw.println(output);
    }

    private void run() throws Exception {
        String name = "A-large";
        String path = "";

        Locale.setDefault(Locale.US);

        Scanner sc = new Scanner(new File(path + name + ".in"));
        PrintWriter pw = new PrintWriter(path + name + ".out");
//		Scanner sc = new Scanner(System.in);
//		PrintWriter pw = new PrintWriter(System.out);

        int testCases = sc.nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            String testData = sc.next();
            pw.print("Case #" + testCase + ": ");
            solve(pw, testData);
            pw.flush();
        }

        pw.close();
        sc.close();
    }

    public static void main(String[] args) throws Exception {
        new ProblemA().run();
    }
}