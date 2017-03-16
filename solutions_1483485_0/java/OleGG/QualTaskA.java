import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @author OleGG
 */
public class QualTaskA {
    public static void main(String[] args) throws Throwable {
        //char[] code = "ynficwlbkuomxsevzpdrjgthaq".toCharArray();
        char[] code = "yhesocvxduiglbkrztnwjpfmaq".toCharArray();
        Scanner sc = new Scanner(new FileReader("A-small-attempt0.in.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("A-small-attempt0.out.txt"));
        //PrintWriter pw = new PrintWriter(System.out);
        int t = sc.nextInt();
        sc.nextLine();
        for (int test = 1; test <= t; ++test) {
            char[] curr = sc.nextLine().toCharArray();
            for (int i = 0; i < curr.length; ++i) {
                if (curr[i] != ' ') {
                    curr[i] = code[curr[i] - 'a'];
                }
            }
            pw.printf("Case #%d: %s\n", test, new String(curr));
        }
        pw.close();
    }
}
