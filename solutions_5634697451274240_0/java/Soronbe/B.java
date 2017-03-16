import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class B {
    public static void main(String[] args) throws FileNotFoundException {
        new B();
    }

    public B() throws FileNotFoundException {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        scanner.nextLine();
        PrintStream writer = new PrintStream(new FileOutputStream("solution.txt"));
        for(int i = 1; i <= testCases; ++i) {
            writer.print(String.format("Case #%d: ", i));
            run(scanner, writer);
        }
        writer.close();
    }

    public void run(Scanner scanner, PrintStream writer) {
        String stack = scanner.nextLine();
        boolean correct =  true;
        int flips = 0;
        for(int i = stack.length() - 1; i >= 0; --i)  {
            boolean happy = stack.charAt(i) == '+';
            if(happy != correct) {
                ++flips;
                correct = happy;
            }
        }

        writer.println(flips);
    }
}
