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
        int target;
    }

    private class Solution {
        int steps;

        public Solution(int steps) {
            this.steps = steps;
        }

        @Override
        public String toString() {
            return Integer.toString(steps);
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
            Solution s1 = solve(task);
            out.println("Case #" + (i + 1) + ": " + s1.toString());
//            Solution s2 = solve1(task);
//            System.out.println((i+1) + ": " + (s2.steps-s1.steps));
//            if (s1.steps>s2.steps) System.out.println("BAD");
//            out.println("Case #" + (i + 1) + ": " + s1.toString() + " ? " + s2.toString());
        }
    }

    private Task parseTask(BufferedReader reader) throws IOException {
        Task task = new Task();
        task.target = Integer.parseInt(reader.readLine());
        return task;
    }

    private Solution solve(Task task) {
        int number = task.target;
        int moves = 1;
        while(number>1) {
            if (number%10==1) {
                int newNumber = swap2(number);
                if (newNumber<number) {
                    number = newNumber;
                } else {
                    number--;
                }
            } else {
                number--;
            }
            moves++;
        }
        return new Solution(moves);
    }

    private Solution solve1(Task task) {
        int number = 1;
        int moves = 1;
        while(number<task.target) {
            int newNumber = swap(number);
            if (newNumber>number && newNumber<task.target) {
                number = newNumber;
            } else {
                number++;
            }
            moves++;
        }
        return new Solution(moves);
    }

    private void printTest(int number) {
        System.out.println(number + " = " + swap(number));
    }

    int digits[] = new int[7];
    private int swap(int number) {
        int pos = 0;
        // disassemble
        while(number>0) {
            int digit = number % 10;
            number /= 10;
            if (digit>0) digits[pos++] = digit;
        }
        // assemble
        int result = 0;
        for(int i=0;i<pos;i++) {
            result *= 10;
            result += digits[i];
        }
        return result;
    }

    private int swap2(final int number) {
        int pos = 0;
        // disassemble
        int reminder = number;
        while(reminder>0) {
            int digit = reminder % 10;
            reminder /= 10;
            if (digit>0) {
                digits[pos++] = digit;
            } else {
                return number; // can't swap if we have zeroes
            }
        }
        // assemble
        int result = 0;
        for(int i=0;i<pos;i++) {
            result *= 10;
            result += digits[i];
        }
        return result;
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
