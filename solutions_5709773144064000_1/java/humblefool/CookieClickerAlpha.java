import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;


public class CookieClickerAlpha {
    static Scanner input;
    static PrintWriter out;

    public static void main(String[] args) throws Exception {
        input = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        out = new PrintWriter(System.out);

        input = new Scanner(new BufferedReader(new FileReader("B-large.in")));
        out = new PrintWriter(new FileWriter("B-large.out"));

        int testCases = input.nextInt();
        for(int testCase = 1; testCase <= testCases; testCase++) {
            out.print("Case #" + testCase + ": ");
            solveCase();
        }
        out.close();
    }

    static void solveCase() {
        double C = input.nextDouble(), F = input.nextDouble(), X = input.nextDouble();
        double rate = 2.0, seconds = 0.0;
        while(true) {
            if(X / rate < X / (rate + F) + C / rate) {
                seconds += X / rate;
                break;
            } else {
                seconds += C / rate;
                rate += F;
            }
        }
        out.println(seconds);
    }
}
