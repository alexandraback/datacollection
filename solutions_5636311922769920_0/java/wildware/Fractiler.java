package software.wild.qualification.fractile;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

import static java.lang.Integer.parseInt;

public class Fractiler {

    public static void main(String[] args) throws Exception {
        String base = args[0];
        String inputFile = "fractile_small.in";
        processInputFile(base, inputFile);

    }

    private static void processInputFile(String baseURL, String inFileName) throws Exception {
        String outFileNAme = inFileName.split("\\.")[0] + ".out";
        try (
                BufferedReader reader = new BufferedReader(new FileReader(new File(baseURL, inFileName)));
                PrintWriter writer = new PrintWriter(new File(baseURL, outFileNAme))
        ) {
            Integer numTests = parseInt(reader.readLine());
            for(int i=0; i<numTests; i++) {
                String[] stack = reader.readLine().split(" ");
                Integer k = Integer.parseInt(stack[0]);
                Integer c = Integer.parseInt(stack[1]);
                Integer s = Integer.parseInt(stack[2]);
                String solution = solve(k, c, s);
                writer.println(String.format("Case #%d: %s", i+1, solution));
            }
        }
    }

    private static String solve(Integer k, Integer c, Integer s) {
        Collection<Integer> guesses = determineGuesses(k, c, s);
        if(guesses == null || guesses.isEmpty())
            return "IMPOSSIBLE";

        String solution = "";
        String del = "";
        for(Integer guess : guesses) {
            solution += del + guess;
            del = " ";
        }
        return solution;
    }

    private static Collection<Integer> determineGuesses(Integer originalLength, Integer complexity, Integer numGuesses) {
        List<Integer> guesses = new ArrayList<>();

        if(numGuesses >= originalLength) {
            for(int i=1; i<=numGuesses; i++) {
                guesses.add(i);
            }
            return guesses;
        }

        return null;
    }



}
