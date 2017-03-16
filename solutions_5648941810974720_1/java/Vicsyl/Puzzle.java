package gj;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.stream.Stream;

public class Puzzle {

    public static void main(String[] args) {

        try (Stream<String> ln = Files.lines(Paths.get(args[0]))) {

            String[] lines = ln.toArray(String[]::new);

            int cases = Integer.parseInt(lines[0].trim());
            for (int i = 1; i < cases + 1; i++) {
                solveFor(lines[i].trim(), i);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static void solveFor(String s, int cs) {
        int[] numberOfDigits = new int[10];

        int[] occurences = new int[128];

        for(int i = 0; i < s.length(); i++) {
            int index = s.charAt(i);
            if(index > 127) {
                throw new RuntimeException("unexpected value: " + (char)index);
            }
            occurences[index]++;
        }

        numberOfDigits[0] = occurences['Z'];
        numberOfDigits[8] = occurences['G'];
        numberOfDigits[6] = occurences['X'];
        numberOfDigits[2] = occurences['W'];
        numberOfDigits[4] = occurences['U'];
        numberOfDigits[3] = occurences['H'] - numberOfDigits[8];
        numberOfDigits[5] = occurences['F'] - numberOfDigits[4];
        numberOfDigits[7] = occurences['S'] - numberOfDigits[6];
        numberOfDigits[9] = occurences['I'] - numberOfDigits[5] - numberOfDigits[6] - numberOfDigits[8];
        numberOfDigits[1] = occurences['N'] - numberOfDigits[7] - 2*numberOfDigits[9];

        System.out.print("Case #" + cs + ": ");
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < numberOfDigits[i]; j++) {
                System.out.print((char)('0' + i));
            }
        }
        System.out.println();

    }

}
