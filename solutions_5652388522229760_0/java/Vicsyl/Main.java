package org.virutor;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.stream.Stream;

public class Main {

    public static void main(String[] args) {


        try (Stream<String> ln = Files.lines(Paths.get(args[0]))) {

            String[] lines = ln.toArray(String[]::new);

            int cases = Integer.parseInt(lines[0].trim());
            for(int i = 1; i < cases + 1; i++) {
                long sheep = Long.parseLong(lines[i]);
                solveAndPrint(sheep, i);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

        // write your code here
    }

    private static void solveAndPrint(long sheeps, int cs) {

        if(sheeps == 0) {
            System.out.println("Case #" + cs + ": INSOMNIA");
            return;
        }

        long currentSheep = sheeps;

        boolean flags[] = new boolean[10];
        int flagCount = 0;

        while (true) {

            String str = Long.toString(currentSheep);
            for (int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);
                int index = (c - '0');
                if (!flags[index]) {
                    flags[index] = true;
                    flagCount++;
                    if (flagCount == 10) {
                        System.out.println("Case #" + cs + ": " + currentSheep);
                        return;
                    }
                }
            }

            currentSheep += sheeps;
        }

    }
}
