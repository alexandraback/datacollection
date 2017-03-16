import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class A {

    private static final String IN_FILE = "A-small-attempt0.in";

    private static final char[] MAP = new char[128];

    static {
        MAP['a'] = 'y';
        MAP['b'] = 'h';
        MAP['c'] = 'e';
        MAP['d'] = 's';
        MAP['e'] = 'o';
        MAP['f'] = 'c';
        MAP['g'] = 'v';
        MAP['h'] = 'x';
        MAP['i'] = 'd';
        MAP['j'] = 'u';
        MAP['k'] = 'i';
        MAP['l'] = 'g';
        MAP['m'] = 'l';
        MAP['n'] = 'b';
        MAP['o'] = 'k';
        MAP['p'] = 'r';
        MAP['q'] = 'z';
        MAP['r'] = 't';
        MAP['s'] = 'n';
        MAP['t'] = 'w';
        MAP['u'] = 'j';
        MAP['v'] = 'p';
        MAP['w'] = 'f';
        MAP['x'] = 'm';
        MAP['y'] = 'a';
        MAP['z'] = 'q';
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = createReader();
        int n = Integer.parseInt(in.readLine());
        int c = 0;
        while (n-- > 0) {
            String read = in.readLine();
            System.out.println(String.format("Case #%d: %s", ++c, convert(read)));
        }
    }

    private static String convert(String read) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < read.length(); ++i) {
            char cc = read.charAt(i);
            if (cc == ' ') {
                sb.append(cc);
            } else {
                char c = convert(cc);
                if (c >= 'A' && c <= 'Z') {
                    System.out.println(String.format("char %c not found", c));
                }
                sb.append(c);
            }
        }
        return sb.toString();
    }

    private static char convert(char c) {
        return MAP[c];
    }

    private static BufferedReader createReader() throws FileNotFoundException {
        return new BufferedReader(new FileReader(IN_FILE));
    }
}
