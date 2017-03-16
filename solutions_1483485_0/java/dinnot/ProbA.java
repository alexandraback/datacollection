import java.io.*;
import java.util.*;

public class ProbA {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        ProbA p = new ProbA();
        p.solveAll();
    }
    int tests = 0;
    int sol[] = new int[260];
    Scanner in;
    BufferedWriter out;
    public ProbA() throws FileNotFoundException, IOException {
        out = new BufferedWriter(new FileWriter("a.out"));
        in = new Scanner(new File("a.in"));
        tests = in.nextInt();
        in.nextLine();
        //System.out.println(tests);
    }

    public void solveAll() throws IOException {
        presolve();
        for(int i = 0; i < tests; i++) {
            solve(i+1);
        }
        out.close();
        in.close();
    }
    public void solve(int casenr) throws IOException {
        String line = in.nextLine();
        out.write("Case #"+casenr+": ");
        for(int i = 0; i < line.length();i++) {
            out.write(sol[line.charAt(i)]);
        }
        out.write('\n');
    }

    public void presolve() {
        String from = "zyeqejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
        String to   = "qaozour language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
        for(int i = 0; i < from.length(); i++) {
            sol[from.charAt(i)] = to.charAt(i);
        }
    }
}