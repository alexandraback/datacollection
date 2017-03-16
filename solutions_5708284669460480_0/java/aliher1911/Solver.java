import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

/**
 * Template to read multiple tasks and solve them
 */
public class Solver {

    private Task task;

    private class Task {
        int len;
        String keys;
        String word;
    }

    private class Solution {
        double result;

        public Solution(double result) {
            this.result = result;
        }

        @Override
        public String toString() {
            return Double.toString(result);
        }
    }

    final InputStream in;
    final PrintStream out;

    public Solver(InputStream in, PrintStream out) {
        this.in = in;
        this.out = out;
    }

    /**
     * Read input.
     * First line is number of tasks.
     * Parse tasks and solve them.
     * @throws IOException if reading fails
     */
    public void solveAll() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(in));
        int cases = Integer.parseInt(reader.readLine());
        for(int i=0;i<cases;i++) {
            Task task = parseTask(reader);
            out.println("Case #" + (i + 1) + ": " + solve(task).toString());
        }
    }

    private Task parseTask(BufferedReader reader) throws IOException {
        Task task = new Task();
        int lens[] = parseIntArray(reader.readLine());
        task.len = lens[2];
        task.keys = reader.readLine();
        task.word = reader.readLine();
        return task;
    }

    long totalTexts = 0;
    long totalWords = 0;
    long maxWords = 0;
    private Solution solve(Task task) {
        this.task = task;
        totalTexts = 0;
        totalWords = 0;
        maxWords = 0;
        down("");
        return new Solution(maxWords - (double)totalWords/totalTexts);
    }

    private void down(String current) {
        if (current.length()==task.len) {
            updateWordStats(current);
        } else {
            for (int i = 0; i < task.keys.length(); i++) {
                down(current + task.keys.charAt(i));
            }
        }
    }

    private void updateWordStats(String current) {
        int words = countSubstrings(current, task.word);
        if (words>maxWords) {
//            System.out.println("MAXWORD:" + current);
            maxWords = words;
        }
        totalWords+=words;
        totalTexts++;
    }

    static int countSubstrings(String string, String sample) {
        int count = 0;
        int pos = 0;
        while((pos = string.indexOf(sample, pos))>=0) {
            count++;
            pos++;
        }
        return count;
    }

    // read descriptors (matrix sizes etc)
    public static int[] parseIntArray(String line) {
        String[] parts = line.trim().split(" +");
        int[] result = new int[parts.length];
        for(int i=0;i<parts.length;i++) {
            result[i] = Integer.parseInt(parts[i]);
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        InputStream in;
        PrintStream out;
        if (args.length>0) {
            in = new FileInputStream(args[0]);
        } else {
            in = System.in;
        }
        if (args.length>1) {
            out = new PrintStream(new FileOutputStream(args[1]));
        } else {
            out = System.out;
        }
        new Solver(in, out).solveAll();
    }
}
