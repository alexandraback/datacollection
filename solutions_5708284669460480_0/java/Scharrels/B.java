import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Locale;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class B {
    Scanner input;
    PrintWriter output;
    private int[] pancakes;

    int maxBananas;
    int totalBananas;
    int totalPermutations;
    String target;

    public B(Scanner input, PrintWriter output){
        this.input = input;
        this.output = output;
    }

    public int matches (String text){
        int matches = 0;
        int index = text.indexOf(target);
        while(index >= 0) {
            matches++;
            index = text.indexOf(target, index+1);
        }
        return matches;
    }

    public void combinations(String lettersToUse, int lengthToType) {
        combinations("", lettersToUse, lengthToType);
    }

    private void combinations(String prefix, String lettersToUse, int lengthToType) {
        int n = lettersToUse.length();
        if (prefix.length() == lengthToType) {
            int matches = matches(prefix);
            totalPermutations++;
            totalBananas += matches;
            maxBananas = Math.max(maxBananas, matches);
        }
        else {
            for (int i = 0; i < n; i++)
                combinations(prefix + lettersToUse.charAt(i), lettersToUse, lengthToType);
        }
    }

    public void solveProblem(int testCase){
        maxBananas = 0;
        input.next();
        input.next();
        int lengthToType = input.nextInt();
        String lettersToUse = input.next();
        target = input.next();
        combinations(lettersToUse, lengthToType);

        double average = maxBananas == 0 ? 0 : totalBananas / (totalPermutations * 1.0);
        output.println("Case #" + testCase + ": " + (maxBananas - average));
    }

    public static void main(String[] args){
        final long startTime = System.currentTimeMillis();
        File file = new File("B.in");
        Scanner input = null;
        try {
            input = new Scanner(file).useLocale(Locale.US);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        PrintWriter output = null;
        try {
            output = new PrintWriter("B.out", "UTF-8");
        } catch (FileNotFoundException | UnsupportedEncodingException e) {
            e.printStackTrace();
        }

        int problems = input.nextInt();
        for(int i = 1; i <= problems; i++){
            System.out.println("processing problem" + i);
            new B(input, output).solveProblem(i);
        }
        output.close();
        final long endTime = System.currentTimeMillis();
        System.out.println("Total execution time: " + (endTime - startTime) + " ms");
    }
}
