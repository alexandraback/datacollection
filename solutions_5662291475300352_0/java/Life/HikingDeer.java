package codejam2015.B1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class HikingDeer {
    public static void main(String[] args) throws IOException {
        String fileName;

//        fileName = "test3.in";
        fileName = "C-small-1-attempt0.in";
        // fileName = "C-large.in";

        try (BufferedReader r = new BufferedReader(new FileReader(fileName));
             BufferedWriter w = new BufferedWriter(new FileWriter(fileName.replace(".in", ".out")))) {
            Scanner sc = new Scanner(r);
            int T = sc.nextInt();
            long startTotal = System.currentTimeMillis();
            for (int i = 0; i < T; i++) {
                w.write("Case #" + (i + 1) + ": " + calc(sc) + "\n");
                System.out.println("case " + +(i + 1) + ". time: " + (System.currentTimeMillis() - startTotal));
            }
            System.out.println("Total time: " + (System.currentTimeMillis() - startTotal));
        }

    }

    private static String calc(Scanner sc) {

        int N = sc.nextInt();
        sc.nextLine();
        List<Integer> start = new ArrayList<>();
        List<Integer> time = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            String line = sc.nextLine();
            String[] ss = line.split(" ");

            int h = Integer.parseInt(ss[1]);
            int d = Integer.parseInt(ss[0]);
            int m = Integer.parseInt(ss[2]);

            for (int j = 0; j < h; j++) {
                start.add(d);
                time.add(m + j);
            }
        }

        int min = start.size();

        for (int i = 0; i < start.size(); i++) {
            double zerotime = (double) time.get(i) * (360 - start.get(i)) / 360;

            int sum = 0;
            for (int j = 0; j < start.size(); j++) {
                if (j == i)
                    continue;

                double jtime = (double) time.get(j) * (360 - start.get(j)) / 360;

                if (jtime > zerotime)
                    sum++;
                else {
                    sum += (int) Math.floor((zerotime - jtime) / time.get(j));
                }
            }

            if (sum < min)
                min = sum;
        }


        return "" + min;

    }


}
