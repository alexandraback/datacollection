import java.io.*;
import java.util.*;

public class LastWord {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        String S = scan.next();
        String res = "" + S.charAt(0);
        for (int i = 1; i < S.length(); i++) {
            char ch = S.charAt(i);
            if (ch >= res.charAt(0)) {
                res = ch + res;
            } else {
                res = res + ch;
            }
        }
        System.out.println(res);
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new LastWord().run();
    }

}
