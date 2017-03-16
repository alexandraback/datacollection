import java.io.*;
import java.util.*;

public class ProbC {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        ProbC p = new ProbC();
        p.solveAll();
    }
    int tests = 0;
    Scanner in;
    BufferedWriter out;
    public ProbC() throws FileNotFoundException, IOException {
        out = new BufferedWriter(new FileWriter("c.out"));
        in = new Scanner(new File("c.in"));
        tests = in.nextInt();
        in.nextLine();
        //System.out.println(tests);
    }

    public void solveAll() throws IOException {
        //System.out.println(move(11, 1));
        ///*
        for(int i = 0; i < tests; i++) {
            solve(i+1);
        }
        out.close();
        in.close();//*/
    }
    public void solve(int casenr) throws IOException {
        int A, B, res = 0;
        A = in.nextInt();
        B = in.nextInt();
        int[] perm = new int[100];
        for(int i = A; i <= B; i++) {
            int d = digits(i);
            for(int j = 1; j < d; j++) {
                int m = move(i, j);
                boolean found = false;
                for(int k = 1; k < j; k++) {
                    if(perm[k] == m)
                        found = true;
                }
                perm[j] = m;
                if(!found && valid(A, B, i, m))
                    res++;
            }
        }
        out.write("Case #"+casenr+": ");
        out.write(new Integer(res).toString());
        out.write('\n');
    }
    public int digits(int nr) {
        int d = 0;
        while(nr > 0) {
            nr /= 10;
            d++;
        }
        return d;
    }

    public int move(int nr, int pos) {
        String nrs = new Integer(nr).toString();
        String rs = nrs.substring(nrs.length()-pos);
        rs = rs + nrs.substring(0, nrs.length()-pos);
        return new Integer(rs).intValue();
    }

    public boolean valid(int A, int B, int n, int m) throws IOException {
        /*if(A <= n && n < m && m <= B)
            out.write(n+" "+m+" "+'\n');//*/
        return A <= n && n < m && m <= B;
    }
}