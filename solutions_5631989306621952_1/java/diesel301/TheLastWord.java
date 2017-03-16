import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by russinko on 4/15/16.
 */
public class TheLastWord {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new File("A-large.in"));
        PrintWriter pw = new PrintWriter(new File("output.txt"));
        int caseCount = Integer.valueOf(sc.nextLine());
        for(int i = 0; i < caseCount; i++) {
            String b = sc.nextLine();
            pw.printf("Case #%d: %s\n", i + 1, build(b));

        }
        pw.close();
    }

    static String build(String input) {
        String out = input.substring(0, 1);
        String remaining = input.substring(1, input.length());
        while (remaining.length() > 0) {
            String first = remaining.substring(0, 1);
            remaining = remaining.substring(1, remaining.length());
            if(first.compareTo(out.substring(0, 1)) >= 0) {
                out = first + out;
            } else {
                out = out + first;
            }
        }
        return out;
    }
}
