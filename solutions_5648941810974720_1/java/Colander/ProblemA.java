import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by colander on 4/9/16.
 */
public class ProblemA {
    public static void main(String[] args) {
        new ProblemA();
    }

    public ProblemA() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            int tests = Integer.parseInt(br.readLine());
            for (int i = 0; i < tests; i++) {
                String s = br.readLine();
                int[] numbers = new int[10];
                while (s.contains("Z")) {
                    numbers[0]++;
                    s = s.replaceFirst("Z", "");
                    s = s.replaceFirst("E", "");
                    s = s.replaceFirst("R", "");
                    s = s.replaceFirst("O", "");
                }
                while (s.contains("W")) {
                    numbers[2]++;
                    s = s.replaceFirst("T", "");
                    s = s.replaceFirst("W", "");
                    s = s.replaceFirst("O", "");
                }
                while (s.contains("X")) {
                    numbers[6]++;
                    s = s.replaceFirst("S", "");
                    s = s.replaceFirst("I", "");
                    s = s.replaceFirst("X", "");
                }
                while (s.contains("U")) {
                    numbers[4]++;
                    s = s.replaceFirst("F", "");
                    s = s.replaceFirst("O", "");
                    s = s.replaceFirst("U", "");
                    s = s.replaceFirst("R", "");
                }
                while (s.contains("O")) {
                    numbers[1]++;
                    s = s.replaceFirst("O", "");
                    s = s.replaceFirst("N", "");
                    s = s.replaceFirst("E", "");
                }
                while (s.contains("F")) {
                    numbers[5]++;
                    s = s.replaceFirst("F", "");
                    s = s.replaceFirst("I", "");
                    s = s.replaceFirst("V", "");
                    s = s.replaceFirst("E", "");
                }
                while (s.contains("S")) {
                    numbers[7]++;
                    s = s.replaceFirst("S", "");
                    s = s.replaceFirst("E", "");
                    s = s.replaceFirst("V", "");
                    s = s.replaceFirst("E", "");
                    s = s.replaceFirst("N", "");
                }
                while (s.contains("G")) {
                    numbers[8]++;
                    s = s.replaceFirst("E", "");
                    s = s.replaceFirst("I", "");
                    s = s.replaceFirst("G", "");
                    s = s.replaceFirst("H", "");
                    s = s.replaceFirst("T", "");
                }
                while (s.contains("N")) {
                    numbers[9]++;
                    s = s.replaceFirst("N", "");
                    s = s.replaceFirst("I", "");
                    s = s.replaceFirst("N", "");
                    s = s.replaceFirst("E", "");
                }
                while (s.contains("T")) {
                    numbers[3]++;
                    s = s.replaceFirst("T", "");
                    s = s.replaceFirst("H", "");
                    s = s.replaceFirst("R", "");
                    s = s.replaceFirst("E", "");
                    s = s.replaceFirst("E", "");
                }
                String fin = "";
                for (int j = 0; j < numbers.length; j++) {
                    for (int k = 0; k < numbers[j]; k++) {
                        fin += j;
                    }
                }
                System.out.println("Case #" + (i+1) + ": " + fin);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
