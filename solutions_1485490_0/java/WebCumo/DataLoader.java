package net.webcumo.codejam.c1.c;

import java.io.BufferedReader;
import java.io.IOException;

/**
 *
 * @author Cumo
 */
public class DataLoader {

    public static String checkSample(BufferedReader br) throws RuntimeException, IOException {
        String[] counts = br.readLine().split(" ");
        int boxesCount = Integer.parseInt(counts[0]);
        int toysCount = Integer.parseInt(counts[1]);

        String[] boxesString = br.readLine().split(" ");
        String[] toysString = br.readLine().split(" ");

        long[] boxes = new long[boxesCount];
        long[] toys = new long[toysCount];
        int[] boxesTypes = new int[boxesCount];
        int[] toysTypes = new int[toysCount];

        for (int i = 0 ; i < boxesCount ; i++) {
            boxes[i] = Long.parseLong(boxesString[i * 2]);
            boxesTypes[i] = Integer.parseInt(boxesString[i * 2 + 1]);
        }

        for (int i = 0 ; i < toysCount ; i++) {
            toys[i] = Long.parseLong(toysString[i * 2]);
            toysTypes[i] = Integer.parseInt(toysString[i * 2 + 1]);
        }

        return Worker.calculate(boxesCount, toysCount, boxes, boxesTypes, toys, toysTypes);
    }

}
