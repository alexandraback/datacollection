package net.webcumo.codejam.c1.a;

import java.io.BufferedReader;
import java.io.IOException;

/**
 *
 * @author Cumo
 */
public class DataLoader {

    public static String checkSample(BufferedReader br) throws RuntimeException, IOException {
        int classesCount = Integer.parseInt(br.readLine());
        String[] classesStrings = new String[classesCount];
        for (int i = 0 ; i < classesCount ; i++) {
            classesStrings[i] = br.readLine();
        }
        return Worker.calculate(classesCount, classesStrings);
    }

}
