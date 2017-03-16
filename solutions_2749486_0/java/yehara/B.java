package gcj2013.r1c;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
    
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        String name = "gcj2013/r1c/B-small";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        // out = new PrintWriter(System.out);
        for (int i = 1; i <= count; i++) {
            out.print("Case #" + i + ": ");            
            String res = solve(s.nextInt(), s.nextInt());
            out.print(res);
            out.println();          
        }
        out.close();
    }

    static String solve(int x, int y) {
        StringBuilder sb = new StringBuilder();
        String xu = "WE";
        String yu = "SN";
        if(x < 0) {
            xu = "EW";
            x = -x;
        }
        if(y < 0) {
            yu = "NS";
            y = -y;
        }
        for(int i=0; i<x; i++) {
            sb.append(xu);
        }
        for(int i=0; i<y; i++) {
            sb.append(yu);
        }
        return sb.toString();
    }
    
}
