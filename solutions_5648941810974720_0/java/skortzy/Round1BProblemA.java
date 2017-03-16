import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Round1BProblemA {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(
                new InputStreamReader(new FileInputStream("A-small-attempt0.in")));
        String line = br.readLine();
        int T = Integer.parseInt(line);
        PrintWriter pw = new PrintWriter("A-small.out");

        for (int test = 0; test < T; test++) {
            line = br.readLine();
            pw.println("Case #" + (test + 1) + ": " + solve(line));
        }
        pw.close();
        br.close();
    }

    private static String solve(String line) {
        int[] freq = new int[26];
        for (int i = 0; i < line.length(); i++) {
            freq[(int) line.charAt(i) - (int) 'A']++;
        }

        int[] results = new int[10];

        String[] numbers = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
        int order[] = {0, 2, 8, 6, 4, 5, 3, 1, 7, 9};
        char letters[] = {'Z', 'O', 'W', 'H', 'U', 'F', 'X', 'S', 'G', 'I'};

        for (int i = 0; i < 10; i++) {
            int number = order[i];
            char c = letters[number];
            int count = freq[(int) c - (int) 'A'];
            results[number] += count;
            String no = numbers[number];
            for (int j = 0; j < no.length(); j++) {
                freq[(int) no.charAt(j) - (int) 'A'] -= count;

            }
        }

        String result = "";
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < results[i]; j++) {
                result += i;
            }
        }

        return result;


    }
}
