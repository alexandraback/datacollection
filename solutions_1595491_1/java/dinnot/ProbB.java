import java.io.*;
import java.util.*;

public class ProbB {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        ProbB p = new ProbB();
        p.solveAll();
    }
    int tests = 0;
    Scanner in;
    BufferedWriter out;
    public ProbB() throws FileNotFoundException, IOException {
        out = new BufferedWriter(new FileWriter("b.out"));
        in = new Scanner(new File("b.in"));
        tests = in.nextInt();
        in.nextLine();
        //System.out.println(tests);
    }

    public void solveAll() throws IOException {
        for(int i = 0; i < tests; i++) {
            solve(i+1);
        }
        out.close();
        in.close();
    }
    public void solve(int casenr) throws IOException {
        int n, s, p, gar = 0, may = 0;
        n = in.nextInt();
        s = in.nextInt();
        p = in.nextInt();
        for(int i = 0; i < n; i++) {
            int tot = in.nextInt();
            int tmay = 3*p-4;
            int tgar = 3*p-2;
            if(tmay < 0)
                tmay = p;
            if(tot >= tgar) {
                gar++;
            } else if(tot >= tmay) {
                may++;
            }
        }
        out.write("Case #"+casenr+": ");
        out.write(new Integer(gar+Math.min(s, may)).toString());
        out.write('\n');
    }
}