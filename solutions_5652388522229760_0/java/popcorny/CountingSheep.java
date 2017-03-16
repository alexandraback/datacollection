package idv.popcorny.jam2016;

import java.io.File;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class CountingSheep {

    public static int countSheep(int n) {

        HashSet<Integer> digits = new HashSet<>();

        int out = 0;


        do{
            out += n;
            int d, r = out;

            for (r = out, d = r % 10;
                 r != 0;
                 r = r / 10, d = r % 10)
            {
                digits.add(d);
            }
        } while(digits.size() < 10);

        return out;
    }



    public static void main(String[] args) throws Exception {
        Scanner scanner;
        PrintWriter writer;
        String input   = "quiz/countingsheep/small.in";
        String output  = "quiz/countingsheep/small.out";

        if (new File(input).exists()) {
            scanner = new Scanner(new File(input));
            writer = new PrintWriter(output);
//            writer = new PrintWriter(System.out);
        } else {
            scanner = new Scanner(System.in);
            writer = new PrintWriter(System.out);
        }


        int t = scanner.nextInt();

        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();

            if (n == 0) {
                writer.printf("Case #%d: INSOMNIA\n", i+1);
            } else {
                writer.printf("Case #%d: %d\n", i+1, countSheep(n));
            }

        }
        writer.flush();
    }
}
