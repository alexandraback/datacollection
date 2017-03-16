import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.*;

public class A {
    Scanner input;
    PrintWriter output;
    public static int MAXIMUM = 1000000;

    private static int[] lookup = new int[MAXIMUM + 1];

    public A(Scanner input, PrintWriter output){
        this.input = input;
        this.output = output;
    }

    public static Integer flip(Integer number){
        return Integer.parseInt(new StringBuilder(number.toString()).reverse().toString());
    }

    public static void fillLookupTable(int number){
        lookup[number + 1] = lookup[number + 1] == 0 ? lookup[number] + 1 : Math.min(lookup[number + 1], lookup[number] + 1);
        int flipped = flip(number);
        if(flipped > number){
            if(flipped <= MAXIMUM)
            lookup[flipped] = lookup[flipped] == 0 ? lookup[number] + 1 : Math.min(lookup[flipped], lookup[number] + 1);
        } else if(lookup[flipped] > lookup[number] + 1) {
            System.out.println("we have to recalculate the past!");
        }
    }

    public void solveProblem(int testCase){
        int number = input.nextInt();
        output.println("Case #" + testCase + ": " + lookup[number]);
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
        lookup[1] = 1;
        for(int i = 1; i < MAXIMUM; i++){
            fillLookupTable(i);
        }
        try {
            output = new PrintWriter("A.out", "UTF-8");
        } catch (FileNotFoundException | UnsupportedEncodingException e) {
            e.printStackTrace();
        }

        int problems = input.nextInt();
        for(int i = 1; i <= problems; i++){
            new A(input, output).solveProblem(i);
        }
        output.close();
        final long endTime = System.currentTimeMillis();
        System.out.println("Total execution time: " + (endTime - startTime) + " ms");
    }
}
