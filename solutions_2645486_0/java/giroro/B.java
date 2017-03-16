import java.io.*;
import java.util.*;

public class B {
    public final static String FILE_IN = "B-small-attempt0.in";
    public final static String FILE_OUT = "B-small-attempt0.out";

    public static class Case {
        public int e, r;
        public int[] t;
    }

    public static Case readCase(BufferedReader r) throws IOException {
        Case c = new Case();

        String[] x = r.readLine().split(" ");
        c.e = Integer.parseInt(x[0]);
        c.r = Integer.parseInt(x[1]);
        if (c.r > c.e) {
            c.r = c.e;
        }

        int n = Integer.parseInt(x[2]);
        c.t = new int[n];
        String[] tk = r.readLine().split(" ");
        for (int j=0; j<n; j++) {
            c.t[j] = Integer.parseInt(tk[j]);
        }

        return c;
    }


    public static void solveCase(Case c, BufferedWriter w, int index) throws IOException {
        int m = 0;
        int s = 0;
        for (int i=0; i<c.t.length; i++) {
            s += c.t[i] * c.r;
            if (c.t[i] > m) {
                m = c.t[i];
            }
        }
        s += m * (c.e - c.r);

        w.write("Case #" + (index+1) + ": " + s);
        w.newLine();
    }

    public static void main(String[] args) throws Exception {
        BufferedReader r = new BufferedReader(new FileReader(FILE_IN));
        BufferedWriter w = new BufferedWriter(new FileWriter(FILE_OUT));
        int num = Integer.parseInt(r.readLine());
        for (int i=0; i<num; i++) {
            Case c = readCase(r);
            solveCase(c, w, i);
        }

        w.close();
        r.close();
    }
}