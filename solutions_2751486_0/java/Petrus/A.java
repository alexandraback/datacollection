package net.axisk.codejam.round1c;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class A {

    private int solve(String name, int n) {
        int result = 0;
        List<String> subStrings = new ArrayList<String>();
        for (int i=0; i <= name.length()-n; i++) {
            for (int j = name.length(); j >= i+n; j--) {
                String sub = name.substring(i, j);
                String[] subs = sub.split("[aeiou]");
                for (String s : subs) {
                    if (s.length() >= n) {
                        result++;
                        break;
                    }
                }
            }
        }
        return result;
    }

    public void solve(Scanner sc, PrintWriter pw) {
        int tests = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < tests; i++) {
            int result = 0;
            String name = sc.next();
            int n = sc.nextInt();

            result = solve(name, n);

            pw.println("Case #" + (i + 1) + ": " + result);
            pw.flush();
            if (sc.hasNext())
                sc.nextLine();
        }
    }

    public static void main(String[] args) throws Exception {
        String fileName = "C:\\Users\\axisK\\Downloads\\A-small-attempt0.in";
        //String fileName = "A-practice.in";
        //Scanner sc = new Scanner(new FileReader("C:\\Users\\axisK\\Downloads\\A-large (1).in"));
        Scanner sc = new Scanner(new FileReader(fileName));

        PrintWriter pw = new PrintWriter(new FileWriter("A-small-attempt0.out"));
        new A().solve(sc, pw);
        pw.close();
        sc.close();
    }
}