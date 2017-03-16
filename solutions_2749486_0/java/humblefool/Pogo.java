import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Pogo {
    static Scanner sc;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        // sc = new Scanner(System.in);
        out = new PrintWriter(System.out);

        sc = new Scanner(new BufferedReader(new FileReader(
                "B-small-attempt1.in")));
        out = new PrintWriter(new FileWriter("B-small-attempt1.out"));

        int testCases = sc.nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            out.println(String.format("Case #%s: %s", testCase, solveCase()));
            out.flush();
        }
        out.close();
    }

    public static String solveCase() {
        int X = sc.nextInt(), Y = sc.nextInt();
        int steps = 1, sum = 1;
        while (true) {
            if (sum >= Math.abs(X) + Math.abs(Y)
                    && sum % 2 == (Math.abs(X) + Math.abs(Y)) % 2) {
                int difference = (sum - (Math.abs(X) + Math.abs(Y))) / 2;
                // System.err.println("Difference: " + difference + ", Steps: " + steps);

                Point[][] points = new Point[2][3];

                points[0][0] = new Point(X + sign(X) * difference, false);
                points[0][1] = new Point(Y, true);
                points[0][2] = new Point(-sign(X) * difference, false);

                points[1][0] = new Point(X, false);
                points[1][1] = new Point(Y + sign(Y) * difference, true);
                points[1][2] = new Point(-sign(Y) * difference, true);

                Arrays.sort(points[0]);
                Arrays.sort(points[1]);

                String result = solve(points[0], steps);
                if (result == null) {
                    result = solve(points[1], steps);
                }
                if (result != null) {
                    return result;
                }
            }
            sum += ++steps;
        }
    }

    static String solve(Point[] points, int steps) {
        char[] result = new char[steps];
        Arrays.fill(result, '-');

        try {
            // for(Point point: points) {
            // if (point.value <= steps && result[point.value-1] == '-')
            // point.evaluate(result);
            // }
            for (Point point : points) {
                if (point.value > 0)
                    point.evaluate(result);
            }
            return new String(result);
        } catch (Exception e) {

        }
        return null;
    }

    static int sign(int num) {
        return num >= 0 ? 1 : -1;
    }

    static class Point implements Comparable<Point> {
        int value;
        char direction;

        public Point(int value, boolean northSouth) {
            this.value = Math.abs(value);
            if (northSouth) {
                direction = value > 0 ? 'N' : 'S';
            } else {
                direction = value > 0 ? 'E' : 'W';
            }
        }

        public void evaluate(char[] result) {
            int temp = value;
            int index = Math.min(value, result.length);
            while (value > 0 && index > 0) {
                if (result[index - 1] == '-') {
                    result[index - 1] = direction;
                    value -= index;
                    index = Math.min(index, value);
                } else {
                    index--;
                }
            }
            if (value != 0) {
                // System.err.println("Unable to make " + temp + ", missed by "
                // + value);
                throw new RuntimeException("Unable to make " + temp);
            } else {
                // System.err.println("Made " + temp);
            }
            // System.err.flush();
        }

        @Override
        public int compareTo(Point other) {
            return other.value - this.value;
        }
    }
}
