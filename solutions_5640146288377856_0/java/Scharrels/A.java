import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Locale;
import java.util.Scanner;

public class A {
    Scanner input;
    PrintWriter output;

    public A(Scanner input, PrintWriter output){
        this.input = input;
        this.output = output;
    }

    public void solveProblem(int testCase){
        int r = input.nextInt();
        int c = input.nextInt();
        int w = input.nextInt();
        output.println("Case #" + testCase + ": " + (c / w + w - 1));
    }

    public static void main(String[] args){
        final long startTime = System.currentTimeMillis();
        File file = new File("A.in");
        Scanner input = null;
        try {
            input = new Scanner(file).useLocale(Locale.US);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        PrintWriter output = null;
        try {
            output = new PrintWriter("A.out", "UTF-8");
        } catch (FileNotFoundException | UnsupportedEncodingException e) {
            e.printStackTrace();
        }

        int problems = input.nextInt();
        for(int i = 1; i <= problems; i++){
            System.out.println("processing problem" + i);
            new A(input, output).solveProblem(i);
        }
        output.close();
        final long endTime = System.currentTimeMillis();
        System.out.println("Total execution time: " + (endTime - startTime) + " ms");
    }
}
