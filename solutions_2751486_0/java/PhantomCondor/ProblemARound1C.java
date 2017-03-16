package Main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.PriorityQueue;

public class ProblemARound1C {

    static BufferedReader br;
    static BufferedWriter bw;

    public static void main(String[] args) {
        try {

            readInputFile();
            createOutputFile();

            String line1 = br.readLine();
            int testCases = Integer.parseInt(line1);

            int testIndex = 0;

            while (testCases != testIndex) {

                int answer = getModifications();
                bw.write("Case #" + ++testIndex + ": " + answer + "\n");

            }

            bw.close();
            br.close();
        } catch (FileNotFoundException e) {
            throw new RuntimeException("File not found.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static int getModifications() throws IOException {
        String[] info1 = br.readLine().split(" ");

        String temp = info1[0];
        StringBuilder y = new StringBuilder();
        for (char x : temp.toCharArray()) {

            if (isConsonant(x)) {
                y.append('c');
            } else {
                y.append('v');
            }

        }
        String word = y.toString();

        int n = Integer.parseInt(info1[1]);
        StringBuilder z = new StringBuilder();
        z.append(".*");
        for (int i = 0; i < n; i++) {
            z.append('c');
        }
        z.append(".*");
        String test = z.toString();

        return getAnswer(word, test);
    }

    private static int getAnswer(String word, String test) {
        
        int length = word.length();
        int counter = 0;
        for (int i = 0; i <= length; i++) {
            String temp = word.substring(0, i);
            if (temp.matches(test)) {
                counter++;
            }

        }

        if (length > 1) {
            return counter + getAnswer(word.substring(1), test);
        } else {
            return counter;
        }
    }

    private static boolean isConsonant(char x) {
        return !(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
    }

    private static void readInputFile() throws IOException {

        br = new BufferedReader(new FileReader("filesA1C/test.in"));
        //br = new BufferedReader(new FileReader("filesA1C/input.txt"));
    }

    private static void createOutputFile() throws IOException {

        int counter = 0;
        File outputFile;
        while ((outputFile = new File("filesA1C/output" + counter + ".txt"))
                .exists()) {
            counter++;
        }

        outputFile.createNewFile();

        FileWriter fw = new FileWriter(outputFile.getAbsoluteFile());
        bw = new BufferedWriter(fw);
    }

}
