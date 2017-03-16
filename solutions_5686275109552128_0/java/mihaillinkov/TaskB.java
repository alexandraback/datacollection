import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class TaskB {
    private static TaskReader reader = new TaskReader(System.in);
    private static PrintWriter printer;

    private void solve(int testNumber, List<Integer> plates) {
        int answer = Integer.MAX_VALUE;
        for (int i = 1; i <= 1000; i++) {
            int currentAnswer = i;
            for (int plate : plates) {
                if (plate > i) {
                    if (plate % i != 0) {
                        currentAnswer += 1;
                    }
                    currentAnswer += plate / i - 1;
                }
            }
            answer = Math.min(answer, currentAnswer);
        }
        printer.println("Case #" + testNumber + ": " + answer);
    }

    public static void main(String[] args) throws IOException {
        printer = new PrintWriter("output");
        int testAmount = reader.nextInt();
        for (int test = 1; test <= testAmount; test++) {
            int plateAmount = reader.nextInt();
            List<Integer> plates = new ArrayList();
            for (int i = 0; i < plateAmount; i++) {
                plates.add(reader.nextInt());
            }
            new TaskB().solve(test, plates);
        }
        printer.close();
    }
}