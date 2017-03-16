package org.virutor;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.stream.Stream;

public class Pancakes {

    public static void main(String[] args) {

        try (Stream<String> ln = Files.lines(Paths.get(args[0]))) {

            String[] lines = ln.toArray(String[]::new);

            int cases = Integer.parseInt(lines[0].trim());
            for (int i = 1; i < cases + 1; i++) {
                solveAndPrint(lines[i], i);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static String flip(String cakes, int upTo) {
        StringBuilder sb = new StringBuilder();
        for (int i = upTo - 1; i >= 0; i--) {
            char c = cakes.charAt(i);
            sb.append(c == '+' ? '-' : '+');
        }
        sb.append(cakes.substring(upTo));
        return sb.toString();
    }

    private static void solveAndPrint(String cakes, int cs) {

        boolean flipped;
        char currentRun;
        int steps = 0;

        do {

            flipped = false;
            currentRun = cakes.charAt(0);

            for (int i = 1; i < cakes.length(); i++) {
                if (cakes.charAt(i) != currentRun) {
                    cakes = flip(cakes, i);
                    flipped = true;
                    steps++;
                    break;
                }
            }

        } while (flipped);

        if (currentRun == '-') {
            steps++;
        }

        System.out.println("Case #" + cs + ": " + steps);

    }

}
