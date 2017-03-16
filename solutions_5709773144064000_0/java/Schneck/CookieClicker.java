package qual;


import java.io.*;
import java.util.*;

// n < (FX - 2C)/FC

public class CookieClicker {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        double C = scan.nextDouble();
        double F = scan.nextDouble();
        double X = scan.nextDouble();
        int n = (int)((F*X - 2*C)/(F*C));
        if (n < 0) n = 0;
        double s = 0;
        for (int i = 0; i < n; i++) {
            s += C / (2.0 + i * F);
        }
        s += X / (2.0 + n * F);
        System.out.println(s);
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new CookieClicker().run();
    }

}
