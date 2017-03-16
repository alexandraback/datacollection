import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by vitalii on 30.04.2016.
 */
public class A {
    PrintWriter out;
    Scanner in;

    String[] digs = new String[]{"ZERO", "TWO", "FOUR", "ONE", "SIX", "EIGHT", "SEVEN", "FIVE", "NINE", "THREE"};
    char[] imp = new char[]{'Z','W','U','O','X','G','S','F','I','T'};
    int[] indexes = new int[]{0,2,4,1,6,8,7,5,9,3};


    public void solve() {
        String str = in.next();
        int[] ans = new int[10];
        char[] balance = new char[256];
        for (int i = 0; i < str.length(); i++) {
            balance[str.charAt(i)]++;
        }
        for (int i = 0; i < digs.length; i++) {
            int cur = balance[imp[i]];
            ans[indexes[i]] += cur;
            for (int j = 0; j < digs[i].length(); j++) {
                balance[digs[i].charAt(j)] -= cur;
            }
        }
        String res = "";
        for (int i = 0; i < ans.length; i++) {
            for (int j = 0; j < ans[i]; j++) {
                res += i;
            }
        }
        out.println(res);
    }

    public void run() throws IOException {
        in = new Scanner(new File("A.in"));
        out = new PrintWriter("A.out");
        int t = in.nextInt();
        for (int i = 1; i<= t; i++) {
            out.print("Case #"+i+": ");
            solve();
        }
        in.close();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new A().run();
    }
}
