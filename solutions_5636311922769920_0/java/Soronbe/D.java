import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class D {
    public static void main(String[] args) throws FileNotFoundException {
        new D();
    }

    public D() throws FileNotFoundException {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        scanner.nextLine();
        PrintStream writer = new PrintStream(new FileOutputStream("solution.txt"));
        for(int i = 1; i <= testCases; ++i) {
            writer.print(String.format("Case #%d:", i));
            run(scanner, writer);
        }
        writer.close();
    }

    public void run(Scanner scanner, PrintStream writer) {
        int K = scanner.nextInt();
        int C = scanner.nextInt();
        int S = scanner.nextInt();
        for(int i = 1; i<= S; ++i) {
            writer.print(" "+i);
        }
        writer.println();
    }
}
