package idv.popcorny.jam2015;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class Ovation {

    public static int ovation(int[] audiences) {
        int extras   = 0;
        int ovations = 0;

        for(int i = 0; i<audiences.length; i++) {
            if(audiences[i] > 0) {
                int extra = 0;
                if (i > ovations) {
                    extra = i - ovations;
                }
                extras += extra;
                ovations = ovations + audiences[i] + extra;
            }
        }

        return extras;
    }


    public static void main(String[] args) throws Exception {
        Scanner scanner;
        PrintWriter writer;
        String input   = "quiz/ovation_large.in";
        String output  = "quiz/ovation_large.out";

        if (new File(input).exists()) {
            scanner = new Scanner(new File(input));
            //scanner = new Scanner(new File("InfiniteHouseofPancakes_small.txt"));
            //scanner = new Scanner(new File("InfiniteHouseofPancakes_large.txt"));
            writer = new PrintWriter(output);
        } else {
            scanner = new Scanner(System.in);
            writer = new PrintWriter(System.out);
        }


        int t = scanner.nextInt();

        for (int i = 0; i < t; i++) {
            int level = scanner.nextInt();
            String list = scanner.next();

            int[] audiences = list.chars().map(s -> s - 48).toArray();
            int extras = ovation(audiences);
            writer.printf("Case #%d: %d\n", i+1, extras);
        }
        writer.flush();
    }
}
