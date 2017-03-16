import java.io.Console;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

/**
 * User: Sasha
 * Date: 09.04.12
 * Time: 19:13
 */
public class Main {

    private void solve() throws Exception {
        int arr[] = new int[255];
        arr['a'] = 'y';
        arr['b'] = 'h';
        arr['c'] = 'e';
        arr['d'] = 's';
        arr['e'] = 'o';
        arr['f'] = 'c';
        arr['g'] = 'v';
        arr['h'] = 'x';
        arr['i'] = 'd';
        arr['j'] = 'u';
        arr['k'] = 'i';
        arr['l'] = 'g';
        arr['m'] = 'l';
        arr['n'] = 'b';
        arr['o'] = 'k';
        arr['p'] = 'r';
        arr['q'] = 'z';
        arr['r'] = 't';
        arr['s'] = 'n';
        arr['t'] = 'w';
        arr['u'] = 'j';
        arr['v'] = 'p';
        arr['w'] = 'f';
        arr['x'] = 'm';
        arr['y'] = 'a';
        arr['z'] = 'q';
        arr[' '] = ' ';
        
        int arr2[] = new int[255];
        for (int i = 0; i < arr.length; ++i) {
            if (arr[i] > 0)
                arr2[i]++;
        }
        for (int i = 0; i < arr2.length; ++i)
            if (i >= 'a' && i <= 'z') {
                if (arr2[i] != 1)
                    System.out.println((char)('a' + i));
            }

        Scanner sc = new Scanner(new File("C:\\Projects\\A-small-attempt0.in"));
        File file = new File("C:\\Projects\\out.txt");
        PrintWriter wr = new PrintWriter(file);
        
        int n = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < n; ++i) {
            String s = sc.nextLine();
            wr.print(String.format("Case #%d: ", (i + 1)));
            for (int j = 0; j < s.length(); ++j) {
                wr.print((char)arr[s.charAt(j)]);
            }
            wr.println();
        }
        wr.flush();
    }

    public static void main(String args[]) throws Exception {
        new Main().solve();
    }
}
