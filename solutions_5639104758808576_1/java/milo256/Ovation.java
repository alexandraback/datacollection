import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Ovation {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("A-large.in"));
        PrintWriter out = new PrintWriter(new File("Ovation.out"));
        int loops = in.nextInt();
        in.nextLine();
        for (int loop = 1; loop <= loops; loop++) {
            int ans = 0;
            String[] spl = in.nextLine().split(" ");
            int max = Integer.parseInt(spl[0]) + 1;
            int people = 0;
            for (int i = 0; i < max; i++) {
                if(people < i) {
                    ans += (i - people);
                    people += (i - people);
                }
                people += Integer.parseInt("" + spl[1].charAt(i));
            }

            out.printf("Case #%d: %d%n", loop, ans);
        }

        in.close();
        out.close();
    }
}
