package idv.popcorny.jam2015;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by popcorny on 4/11/15.
 */
public class Pancake {
    public static int pancake(int[] plates) {
        int min = Integer.MAX_VALUE;

        int minuteEat = 1;

        while(true) {
            int minuteCut = 0;

            for (int i = 0; i <plates.length; i++) {
                if(plates[i] > minuteEat) {
                    int cut = (int)Math.ceil((plates[i] - minuteEat) / (double)minuteEat);
                    minuteCut += cut;
                }
            }

            min = Math.min(min, minuteCut + minuteEat);
            if(minuteCut == 0) {
                break;
            }

            minuteEat++;
        }


        return min;
    }

    public static void main(String[] args) throws Exception {
        Scanner scanner;
        PrintWriter writer;
        String input   = "quiz/pancake_large.in";
        String output  = "quiz/pancake_large.out";

        if (new File(input).exists()) {
            scanner = new Scanner(new File(input));
            writer = new PrintWriter(output);
            //writer = new PrintWriter(System.out);
        } else {
            scanner = new Scanner(System.in);
            writer = new PrintWriter(System.out);
        }


        int t = scanner.nextInt();

        for (int i = 0; i < t; i++) {
            int plates = scanner.nextInt();

            int[] pancakes = new int[plates];

            for(int j=0; j<plates; j++) {
                pancakes[j] = scanner.nextInt();
            }


            int minutes = pancake(pancakes);
            writer.printf("Case #%d: %d\n", i+1, minutes);
        }
        writer.flush();
    }
}
