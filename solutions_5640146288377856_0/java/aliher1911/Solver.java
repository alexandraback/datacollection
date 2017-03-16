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

    private class Task {
        public int r;
        public int c;
        public int w;

        @Override
        public String toString() {
            return "Task{" +
                    "r=" + r +
                    ", c=" + c +
                    ", w=" + w +
                    '}';
        }
    }

    private class Solution {
        public int moves;

        public Solution(int moves) {
            this.moves = moves;
        }

        @Override
        public String toString() {
            return Integer.toString(moves);
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
        int t[] = parseIntArray(reader.readLine());
        task.r = t[0];
        task.c = t[1];
        task.w = t[2];
        return task;
    }

    private Solution solve(Task task) {
        // special cases first?
        if (task.c==task.w) return new Solution(task.r+task.w-1);
        if (task.w==1) return new Solution(task.r*task.c);

        // calculate
        int value = task.c/task.w; // horizontal search to localize
        value *= task.r; // repeat till last row
        // ship is now on the end of last row with one hit
        // one shot to find direction and then fill remaining squares
        if (task.c%task.w!=0) value += 1;
        // fill found interval
        value+=task.w-1;
        return new Solution(value);
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
