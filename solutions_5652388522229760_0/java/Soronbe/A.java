import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;

public class A {
    public static void main(String[] args) throws FileNotFoundException {
        new A();
    }

    public A() throws FileNotFoundException {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        PrintStream writer = new PrintStream(new FileOutputStream("solution.txt"));
        for(int i = 1; i <= testCases; ++i) {
            writer.print(String.format("Case #%d: ", i));
            run(scanner, writer);
        }
        writer.close();
    }

    public void run(Scanner scanner, PrintStream writer) {
        int N = scanner.nextInt();
        if(N == 0) {
            writer.println("INSOMNIA");
            return;
        }

        boolean[] seen = new boolean[10];
        int i = 0;
        int current = 0;
        while(! allSeen(seen)) {
            ++i;
            current = N*i;
            for(Integer digit: digits(current))
                seen[digit] = true;
        }

        writer.println(current);

    }


    List<Integer> digits(int i) {
        List<Integer> digits = new ArrayList<Integer>();
        while(i > 0) {
            digits.add(i % 10);
            i /= 10;
        }
        return digits;
    }



    public boolean allSeen(boolean[] seen) {
        for(int i = 0; i < 10; ++i) {
            if(! seen[i])
                return false;
        }
        return true;
    }
}
