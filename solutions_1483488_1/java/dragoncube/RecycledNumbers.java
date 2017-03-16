import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

public class RecycledNumbers {

    public static void main(String[] args) throws IOException {
        new RecycledNumbers().solveAll();
    }

    BufferedReader reader;

    int T;

    int[] POW10 = new int[]{1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

    int A, B;

    private void solveAll() throws IOException {
        //reader = new BufferedReader(new InputStreamReader(System.in));
        reader = new BufferedReader(new InputStreamReader(new FileInputStream("C-large.in")));
        T = Integer.parseInt(reader.readLine());
        for (int i = 0; i < T; i++) {
            solve(i + 1);
        }
    }

    private void solve(int caseNumber) throws IOException {
        String line = reader.readLine();
        String[] strings = line.split(" ");
        A = Integer.parseInt(strings[0]);
        B = Integer.parseInt(strings[1]);

        HashSet<Pair> distinctPairs = new HashSet<Pair>();
        for (int number = A; number <= B; number++) {
            List<Pair> pairs = generatePairsFromNumber(number, numDigits(number));
            distinctPairs.addAll(pairs);
        }

        int result = distinctPairs.size();
        //System.out.println(distinctPairs);
        System.out.println("Case #" + caseNumber + ": " + result);
    }

    private List<Pair> generatePairsFromNumber(int number, int digits) {
        List<Pair> result = new ArrayList<Pair>(digits);
        for (int pow = 1; pow < digits; pow++) {
            int xnumber = (number % POW10[pow]) * POW10[digits - pow] + number / POW10[pow];

            if (xnumber < A || xnumber > B
                    || xnumber == number
                    || xnumber < POW10[digits - 1]) {
                continue;
            }

            Pair pair = new Pair(number, xnumber);
            result.add(pair);
        }
        return result;
    }

    private int numDigits(int number) {
        int digits = 0;
        while (number >= POW10[digits]) {
            digits++;
        }
        return digits;
    }

    class Pair {
        int x, y;

        Pair(int x, int y) {
            if (x < y) {
                this.x = x;
                this.y = y;
            } else {
                this.x = y;
                this.y = x;
            }
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pair pair = (Pair) o;

            if (x != pair.x) return false;
            if (y != pair.y) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            return result;
        }

        @Override
        public String toString() {
            return "{" +
                    x +
                    ", " + y +
                    '}';
        }
    }

}
