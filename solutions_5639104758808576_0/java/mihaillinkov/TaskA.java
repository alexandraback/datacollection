import java.io.*;

public class TaskA {
    private static TaskReader reader = new TaskReader(System.in);
    private static PrintWriter printer;

    private void solve(int testNumber, String audience) {
        int answer = 0;
        int clappingAmount = 0;
        for (int i = 0; i < audience.length(); i++) {
            if (i > clappingAmount) {
                int additional = i - clappingAmount;
                clappingAmount += additional;
                answer += additional;
            }
            clappingAmount += audience.charAt(i) - '0';
        }
        printer.println("Case #" + testNumber + ": " + answer);
    }

    public static void main(String[] args) throws IOException {
        printer = new PrintWriter("output");
        int testAmount = reader.nextInt();
        for (int test = 1; test <= testAmount; test++) {
            reader.nextInt();
            new TaskA().solve(test, reader.next());
        }
        printer.close();
    }
}

