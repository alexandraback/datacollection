package jeffware.codejam;

import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.stream.IntStream;

/**
 * Created by Jeff on 4/15/2016.
 */
public class LastWord {

    public static void main(String[] args) {
        String problemSet = "A-Large";

        File inFile = new File("inputs/" + problemSet + ".in");
        File outFile = new File("outputs/" + problemSet + ".out");

        try (PrintStream out = new PrintStream(new FileOutputStream(outFile))) {
            outFile.createNewFile();
            Scanner sc = new Scanner(inFile);

            int numberOfTests = sc.nextInt();
            sc.nextLine();
            for (int t = 0; t < numberOfTests; t++) {

                String s = sc.nextLine();
                final LinkedList<Character> result = new LinkedList<Character>();

                for (char c : s.toCharArray()) {

                    if (result.size() > 0 && result.getFirst().compareTo(c) <= 0) {
                        result.addFirst(c);
                    } else {
                        result.addLast(c);
                    }
                }

                StringBuilder answer = new StringBuilder();
                result.stream().forEach(c -> answer.append(c));

                out.printf("Case #%d: %s\n", t+1, answer);
            }
        } catch (FileNotFoundException e1) {
            e1.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
