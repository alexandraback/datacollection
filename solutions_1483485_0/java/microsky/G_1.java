import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class G_1 {
    static char[][] cc = { { 'a', 'y' }, { 'b', 'n' }, { 'c', 'f' }, { 'd', 'i' }, { 'e', 'c' }, { 'f', 'w' }, { 'g', 'l' }, { 'h', 'b' },
            { 'i', 'k' }, { 'j', 'u' }, { 'k', 'o' }, { 'l', 'm' }, { 'm', 'x' }, { 'n', 's' }, { 'o', 'e' }, { 'p', 'v' }, { 'q', 'z' },
            { 'r', 'p' }, { 's', 'd' }, { 't', 'r' }, { 'u', 'j' }, { 'v', 'g' }, { 'w', 't' }, { 'x', 'h' }, { 'y', 'a' }, { 'z', 'q' } };

    static char do_char(char c) {
        int off = 0;
        if (c < 97) {
            off = 65 - 97;
        }
        // System.out.print(c);
        for (int i = 0; i < cc.length; ++i) {
            // System.out.print(cc[i][1]);
            if (c == cc[i][1]) {
                c = cc[i][0];
                break;
            }
        }
        return c ;
    }

    static String func(String line) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < line.length(); i++) {
            sb.append(do_char(line.charAt(i)));
        }
        return sb.toString();
    }

    public static void main(String[] args) throws IOException {
        PrintWriter bw = new PrintWriter(new FileWriter("1.txt"));
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.nextLine();
        for (int i = 0; i < n; i++) {
            String line = scan.nextLine();
            System.out.println(String.format("Case #%d: %s", (i + 1), func(line)));
            //bw.write("1\r\n");
            bw.write(String.format("Case #%d: %s\n", (i + 1), func(line)));
        }
        bw.flush();
        bw.close();
    }
}
