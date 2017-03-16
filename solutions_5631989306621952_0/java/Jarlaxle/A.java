import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
    public static void main(String[] args) throws FileNotFoundException {
        FileInputStream fin = new FileInputStream("A-small-attempt0.in-2.txt");
        Scanner scanner = new Scanner(fin);
        FileOutputStream fout = new FileOutputStream("A-small-attempt0.out.txt");
        PrintWriter writer = new PrintWriter(fout);
        int testCount = scanner.nextInt();
        for (int testCase = 1; testCase <= testCount; ++testCase) {
            String input = scanner.next();
            String res = solve(input);
            writer.printf("Case #%d: %s\n", testCase, res);
        }
        writer.close();
    }

    private static String solve(String input) {
        String res = "";
        for (int i = 0; i < input.length(); ++i) {
            char c = input.charAt(i);
            String s1 = res + c;
            String s2 = c + res;
            if (s1.compareTo(s2) > 0) {
                res = s1;
            } else {
                res = s2;
            }
        }
        return res;
    }
}
