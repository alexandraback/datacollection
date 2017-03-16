package razhan.codejam.or1.problem1;

import org.apache.commons.lang3.StringUtils;

import java.io.*;
import java.util.LinkedList;

/**
 * Solution for CodeJam problem OR1-1
 *
 * Makes use of Apache Commons Lang3 from:
 * https://commons.apache.org/proper/commons-lang/
 *
 *
 */
public class Main {
    private static final String PATH = "D:\\";
    private static final String FILE = "Codejam1-2.in";
    private static final boolean OUTPUT = true;

    private static BufferedReader in;
    private static PrintWriter out;

    public static void main(String[] args) throws Exception {
        initialize();
        int numberOfProblems = parseNumberOfProblems();
        for (int i = 1; i <= numberOfProblems; i++) {
            String[] problemArguments = parseArguments();

            solveProblem(i, problemArguments);

        }
        end();
    }

    private static void solveProblem(int testNumber, String[] problemArguments) {
        String word = problemArguments[0];
        LinkedList<Byte> finalCharacters = new LinkedList<>();
        byte[] original = word.getBytes();
        finalCharacters.add(original[0]);
        for(int i = 1; i < original.length; i++) {
            if (original[i] >= finalCharacters.getFirst()) {
                finalCharacters.addFirst(original[i]);
            } else {
                finalCharacters.addLast(original[i]);
            }
        }
        char[] charArray = new char[finalCharacters.size()];
        int i = 0;
        for (byte character : finalCharacters) {
            charArray[i] = (char)character;
            i++;
        }
        String result = new String(charArray);
        out.println("Case #" + testNumber + ": " + result);
    }

    private static String[] parseArguments() throws Exception {
        String line = in.readLine();
        return StringUtils.split(line, " ");
    }

    private static int parseNumberOfProblems() throws Exception {
        String stringNumber = in.readLine();
        return Integer.parseInt(stringNumber);
    }

    private static void end() throws Exception {
        if (OUTPUT) {
            out.close();
        }
        in.close();
    }

    private static void initialize() throws Exception {
        if (OUTPUT) {
            out = new PrintWriter(new BufferedWriter(new FileWriter(PATH + FILE + ".out")));
        } else {
            out = new PrintWriter(System.out, true);
        }
        in = new BufferedReader(new InputStreamReader(new FileInputStream(new File(PATH + FILE))));
    }
}