package gcj2013r1b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Osmos {
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
            int A = Integer.parseInt(info[0]);
            int N = Integer.parseInt(info[1]);
            info = scan.nextLine().split(" ");
            int[] balls = new int[N];
            for (int i = 0; i < N; i++)
                balls[i] = Integer.parseInt(info[i]);

            Arrays.sort(balls);
            int min = N;
            int add = 0;
            next: for (int i = 0; i < N; i++) {
                if (A <= balls[i]) {
                    min = Math.min(min, add + N - i);
                    while (A <= balls[i]) {
                        if (A == 1) {
                            add = N;
                            i = N;
                            continue next;
                        }
                        A += (A - 1);
                        add++;
                    }
                }
                A += balls[i];
            }
            min = Math.min(min, add);

            pw.println("Case #" + t + ": " + min);
            System.out.println("Case #" + t + ": " + min);
        }

        scan.close();
        pw.close();
    }
}
