import java.io.*;
import java.math.BigInteger;
import java.util.*;

/**
 * Template to read multiple tasks and solve them
 */
public class Solver {

    private Task task;

    private class Task {
        // TODO: write initial conditions here (in public fields)
        int limitCoins;
        int maxPurchase;
        int denoms[];
    }

    private class Solution {
        int newDenoms;

        public Solution(int newDenoms) {
            this.newDenoms = newDenoms;
        }

        @Override
        public String toString() {
            return Integer.toString(newDenoms);
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
        int i[] = parseIntArray(reader.readLine());
        task.limitCoins = i[0];
        task.maxPurchase = i[2];
        task.denoms = parseIntArray(reader.readLine());
        return task;
    }

    List<Integer> addThis;
    boolean canbuild[] = new boolean[31];

    private Solution solve(Task task) {
        this.task = task;
        this.addThis = new ArrayList<Integer>();
        Arrays.fill(canbuild, false);
        down(0, 0);
        int sol = 0;
        for(int i=0;i<=task.maxPurchase;i++)
            if (!canbuild[i]) sol++;
        return new Solution(sol);
    }

    private void down(int current, int sum) {
        // current denom is greater than remainder
        if (sum>task.maxPurchase) {
            return;
        }
        // we've reached the goal
        if (current==task.denoms.length) {
            canbuild[sum] = true;
            return;
        }
        // try variants
        down(current+1, sum+task.denoms[current]);
        down(current+1, sum);
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

    public static double[] parseDoubleArray(String line) {
        String[] parts = line.trim().split(" +");
        double [] result = new double[parts.length];
        for(int i=0;i<parts.length;i++) {
            result[i] = Double.parseDouble(parts[i]);
        }
        return result;
    }

    public static BigInteger[] parseBigIntArray(String line) {
        String[] parts = line.trim().split(" +");
        BigInteger [] result = new BigInteger[parts.length];
        for(int i=0;i<parts.length;i++) {
            result[i] = new BigInteger(parts[i]);
        }
        return result;
    }

    // <id> <size> <elements>
    // data: s, i, d, b, c,  - string integer double bigint char
    // size: nnn - number of elements
    //       @nn - backreference to tuple for size
    //       +   - read till the end of line
    // returns: list of arrays. each array corresponds to format specifier
    //          arrays contain specified number of elements and of the format primitive type
    //
    // example:
    //   format:  i s@0 b2 i+   = string array size, array of strings, array of ints till the end of line
    //   data:    2 a b 1 2 3 4 5
    //   result:  List<Object> [0] = Integer(2)
    //                         [1] = String[] {"a", "b"}
    //                         [2] = BigInteger[] {1, 2}
    //                         [3] = int[] {3, 4, 5}
    public static List<Object> parseFormat(String format, String line) {
        String[] parts = line.trim().split(" +");
        String[] types = format.trim().split(" +");
        int partCount = 0;
        List<Object> result = new ArrayList<Object>(types.length);
        for(String type : types) {
            char valueType = type.charAt(0);
            if (type.length()==1) {
                // read single value
                result.add(parseType(valueType, parts[partCount]));
                partCount++;
            } else {
                int size;
                if (type.charAt(1)=='@') {
                    // read array with backref size
                    int ptr = Integer.parseInt(type.substring(2));
                    size = (Integer)result.get(ptr);
                } else if (type.charAt(1)=='+') {
                    // read reminder of arguments
                    size = parts.length - partCount;
                } else {
                    // read array with immediate size
                    size = Integer.parseInt(type.substring(1));
                }
                result.add(parseArray(valueType, size, parts, partCount));
                partCount+=size;
            }
        }
        return result;
    }

    private static Object parseArray(char type, int count, String[] parts, int from) {
        switch (type) {
            case 's':
                String[] resStr = new String[count];
                System.arraycopy(parts, from, resStr, 0, count);
                return resStr;
            case 'i':
                int[] resInt = new int[count];
                for(int i=0;i<count;i++) {
                    resInt[i] = Integer.parseInt(parts[i+from]);
                }
                return resInt;
            case 'd':
                double[] resDouble = new double[count];
                for(int i=0;i<count;i++) {
                    resDouble[i] = Double.parseDouble(parts[i+from]);
                }
                return resDouble;
            case 'b':
                BigInteger[] resBigInt = new BigInteger[count];
                for(int i=0;i<count;i++) {
                    resBigInt[i] = new BigInteger(parts[i+from]);
                }
                return resBigInt;
            default:
                throw new IllegalArgumentException("Unknown type " + type);
        }
    }

    private static Object parseType(char type, String value) {
        switch(type) {
            case 's':
                return value;
            case 'i':
                return Integer.parseInt(value);
            case 'd':
                return Double.parseDouble(value);
            case 'b':
                return new BigInteger(value);
            default:
                throw new IllegalArgumentException("Unknown type " + type);
        }
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
