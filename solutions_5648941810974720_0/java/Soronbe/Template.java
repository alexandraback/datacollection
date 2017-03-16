import java.io.*;
import java.util.Scanner;

public abstract class Template {
    public Template() {
        try {
        Scanner sc = new Scanner(System.in);
            PrintWriter pw = new PrintWriter("solution.txt", "UTF-8");

            int T = sc.nextInt();
            sc.nextLine();
            for (int i = 1; i <= T; ++i) {
                pw.print(String.format("Case #%d: ", i));
                run(sc, pw);
            }
            pw.close();
        } catch (FileNotFoundException | UnsupportedEncodingException e) {
            e.printStackTrace();
        }
    }

    protected abstract void run(Scanner scanner, PrintWriter writer);
}
