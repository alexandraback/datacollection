import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * @author Max Loewenthal
 */
public class B {
    private static int fact(int i) {
        int result = 1;
        for (int j = 1; j <= i; j++) {
            result = result * j;
        }

        return result;
    }

    private static double combinations(double singleprob, int n, int p) {
        int count = fact(n) / fact(p) / fact(n-p);

        double result = singleprob;

        for (int i = 1; i < count; i++) {
            result = result * (1 - singleprob)  + singleprob;
        }

        return result;

    }
    public void solve(Scanner input, StringBuilder buffer) {
        int alfabetsize = input.nextInt();
        int targetLength = input.nextInt();
        int keysTyped = input.nextInt();
        input.nextLine();

        String letters = input.nextLine();
        String target = input.nextLine();

        Set<Character> available = new HashSet<>();
        Set<Character> needed = new HashSet<>();

        for (char c : letters.toCharArray()) {
            available.add(c);
        }
        for (char c : target.toCharArray()) {
            needed.add(c);
        }

        needed.removeAll(available);
        if (!needed.isEmpty()) {
            buffer.append("0.000000");
        }
        else {
            int minimalWidth = target.length();

            for (int i = 1; i < minimalWidth; i++) {
                if (target.substring(i).equals(target.substring(0, target.length() - i))) {
                    minimalWidth = i;
                    break;
                }
            }

            int possible = ((keysTyped - target.length() + minimalWidth) / minimalWidth);

            int[] frequencies = new int['z'];

            int distinctAlfabetSize = 0;
            for (char c: letters.toCharArray()) {
                if (frequencies[c] == 0) {
                    distinctAlfabetSize++;
                }
                frequencies[c] ++;
            }


            double singleprob = 1;
            double optimumprob = 1;
            int w = 0;

            for (char c: target.toCharArray()) {
                if (w < minimalWidth) {
                    optimumprob = optimumprob * frequencies[c] / alfabetsize;
                }
                w = w + 1;
                singleprob = singleprob * frequencies[c] / alfabetsize;
            }

            if (singleprob < 0.0000001d) {
                buffer.append(String.format("%.6f", (double) possible));
            }
            else {
                MonkeyTester test = new MonkeyTester(letters, target, keysTyped, frequencies);


                double reasonable =
                        (keysTyped / targetLength) * combinations(singleprob, keysTyped / targetLength + keysTyped % targetLength, keysTyped % targetLength)
                        * Math.pow(distinctAlfabetSize, keysTyped & targetLength);

                double optimal = singleprob;
                for (int i = 1 ; i < possible; i ++) {
                    optimal = optimal + singleprob * Math.pow(optimumprob, i);
                }

                int left = keysTyped - targetLength - (possible - 1) * minimalWidth;

                optimal = optimal * (left + 1);

                double exp = test.getResult();

                buffer.append(String.format("%.6f", (double) possible - test.getResult()));
            }

        }
    }


    public static class MonkeyTester {
        private long total;
        private long count;
        private String alfa;
        private String target;
        private int size;

        public MonkeyTester(String alfa, String target, int size, int[] frequencies) {
            this.alfa = alfa;
            this.target = target;
            this.size = size;
        }

        public double getResult() {
            total = 0;
            count = 0;
            tryit("");

            return total / Math.pow(alfa.length(), size);
        }

        public void tryit(String base) {
            if (base.length() < size) {
                for (int i = 0; i < alfa.length(); i++) {
                    tryit(base + alfa.charAt(i));
                }
            }
            else {
                count = count + 1;
                for (int i = 0; i < size- target.length() + 1; i++) {
                    if (base.substring(i, target.length() + i).equals(target)) {
                        total = total + 1;
                    }
                }
            }
        }

    }


    public static void main(String[] args) {
        try {
            InputStream input = System.in;
            OutputStream output = System.out;

            if (args.length > 0) {
                input = new FileInputStream(new File(args[0]));
            }

            if (args.length > 1) {
                File outputFile = new File(args[1]);

                if (outputFile.exists()) {
                    throw new Exception("Output file already exists");
                }

                output = new FileOutputStream(new File(args[1]));
            }

            Scanner scanner = new Scanner(input);
            PrintWriter writer = new PrintWriter(output);

            B a = new B();

            int count = scanner.nextInt();
            scanner.nextLine();

            for (int i = 0; i < count; i++) {
                StringBuilder result = new StringBuilder();
                a.solve(scanner, result);


                writer.println("Case #" + (i + 1) + ": " + result.toString());
            }

            writer.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

}
