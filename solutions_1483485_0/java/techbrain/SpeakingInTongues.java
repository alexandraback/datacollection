import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * User: TCSDEVELOPER
 * Date: 4/14/12
 * Time: 9:00 AM
 */
public class SpeakingInTongues {
    private PrintWriter pw;
    private Scanner scanner;

    private class Loader {

        public void run() {
            String input = scanner.nextLine() + scanner.nextLine() + scanner.nextLine();
            String output = scanner.nextLine() + scanner.nextLine() + scanner.nextLine();

            char []map = new char[256];
            for (int i = 0; i < input.length(); i++) {
                map[input.charAt(i)] = output.charAt(i);
            }
            for (char i = 0; i < map.length; i++) {
                if (map[i] == 0) continue;
                pw.println("map['" + i + "']" + " = '" + map[i] + "';");
            }
        }
    }

    char []map = new char[256];

    private void init() {
        map['a'] = 'y';
        map['b'] = 'h';
        map['c'] = 'e';
        map['d'] = 's';
        map['e'] = 'o';
        map['f'] = 'c';
        map['g'] = 'v';
        map['h'] = 'x';
        map['i'] = 'd';
        map['j'] = 'u';
        map['k'] = 'i';
        map['l'] = 'g';
        map['m'] = 'l';
        map['n'] = 'b';
        map['o'] = 'k';
        map['p'] = 'r';
        map['q'] = 'z';
        map['r'] = 't';
        map['s'] = 'n';
        map['t'] = 'w';
        map['u'] = 'j';
        map['v'] = 'p';
        map['w'] = 'f';
        map['x'] = 'm';
        map['y'] = 'a';
        map['z'] = 'q';
    }

    private void solve() {
        char []chars = scanner.nextLine().toCharArray();
        for (int i = 0; i < chars.length; i++) {
            char aChar = chars[i];
            char mappedChar = map[aChar];
            if (mappedChar == 0) continue;
            chars[i] = mappedChar;
        }
        pw.println(new String(chars));
    }

    private void runTests() {
        init();

        //new Loader().run();
        int T = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < T; i++) {
            pw.print("Case #" + (i + 1) + ": ");
            solve();
        }
    }

    private void run() {
        try {
            runTests();
        } finally {
            close();
        }
    }

    private void close() {
        pw.close();
        scanner.close();
    }

    public SpeakingInTongues() throws FileNotFoundException {
        this.scanner = new Scanner(new File("A-small-attempt0.in"));
        this.pw = new PrintWriter(new File("A-small-attempt0.out"));
    }

    public static void main(String[] args) throws FileNotFoundException {
        new SpeakingInTongues().run();
    }
}
