import java.io.*;
import java.util.HashSet;

/**
 * @author vilmantas baranauskas
 */
public class ReorderingTrainCars {


    public static void main(String[] args) throws IOException {

        BufferedReader in = new BufferedReader(new FileReader("in.txt"));
        BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));

        // number of test cases
        int t = Integer.parseInt(in.readLine());

        for (int i = 0; i < t; i++) {
            CharSequence solution = "Case #" + (i + 1) + ": " + solveTestCase(in);
            System.out.println(solution);
            out.write(solution.toString());
            out.newLine();
        }

        in.close();
        out.close();

    }

    private static long solveTestCase(BufferedReader in) throws IOException {

        int n = Integer.parseInt(in.readLine());

        String[] cars = readLineOfStringsAsChars(in);

//        long multiplier = 1;
//        HashSet<String> carSet = new HashSet<String>(cars.length);
//        for (String car : cars) {
//            if (carSet.contains(car)) {
//                multiplier = multiplier * 2;
//            } else {
//                carSet.add(car);
//            }
//        }

//        n = carSet.size();
//        cars = carSet.toArray(new String[n]);

        boolean[] used = new boolean[n];

        long solution = 0;
        for (int i = 0; i < used.length; i++) {
            solution = (solution + findSolution(cars, used, i, "")) % 1000000007;
        }
        return solution % 1000000007;

    }

    private static long findSolution(String[] cars, boolean[] used, int i, String line) {

        used[i] = true;

        long solution = 0;
        String line2 = line + cars[i];

        if (isCorrectLine(line2)) {
            boolean allUsed = true;
            for (int j = 0; j < cars.length; j++) {
                if (!used[j]) {
                    allUsed = false;
                    solution = (solution + findSolution(cars, used, j, line2)) % 1000000007;
                }
            }

            used[i] = false;

            if (allUsed) {
                if (isCorrectLine(line2)) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                return solution;
            }
        } else {
            used[i] = false;
            return 0;
        }

    }

    private static boolean isCorrectLine(String line) {
        HashSet<Character> used = new HashSet<Character>();

        char[] chars = line.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            char c = chars[i];
            if (used.contains(c)) {
                return false;
            } else {
                used.add(c);
                while (i + 1 < chars.length && chars[i + 1] == c) {
                    i++;
                }
            }
        }

        return true;
    }


    private static String[] readLineOfStringsAsChars(BufferedReader in) throws IOException {
        String[] v1Str = in.readLine().split(" ");
        String[] items = new String[v1Str.length];
        for (int i = 0; i < v1Str.length; i++) {
            String str = v1Str[i];
            StringBuilder s = new StringBuilder();

            char lastChar = 0;

            char[] chars = str.toCharArray();
            for (char aChar : chars) {
                if (aChar != lastChar) {
                    lastChar = aChar;
                    s.append(aChar);
                }
            }

            items[i] = s.toString();
        }
        return items;
    }

}
