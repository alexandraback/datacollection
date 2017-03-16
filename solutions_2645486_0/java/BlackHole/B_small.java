import java.util.*;
import java.util.regex.*;
import java.io.*;
import java.math.*;

public class B_small {
    
    int E;
    int R;
    int N;
    int[] v;
    
    public int dfs(int i, int c) {
        if (i == v.length) return 0;
        int max = -1;
        for (int j = 0; j <= c; j++) {
            int nc = Math.min(E, c - j + R);
            int value = j * v[i] + dfs(i + 1, nc);
            if (value > max) max = value;
        }
        return max;
    }
    
    public void solve(ContestReader cr, PrintWriter pw) throws Exception {
        E = cr.nextInt();
        R = cr.nextInt();
        N = cr.nextInt();
        v = new int[N];
        //~ int acc = 0;
        //~ int max = -1;
        if (R > E) R = E;
        for (int i = 0; i < N; i++) {
            v[i] = cr.nextInt();
            //~ acc += v[i] * R;
            //~ if (v[i] > max) max = v[i];
        }
        //~ acc += (E - R) * max;
        pw.println(dfs(0, E));
    }
    
    public static void main(String[] args) throws Exception {
		ContestReader cr = new ContestReader(new FileInputStream("B-small-attempt2.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("B-small-attempt2.out"));
        int caseCnt = cr.nextInt();
        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new B_small().solve(cr, pw);
        }
        pw.flush();
        pw.close();
	}
}

class ContestReader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    public ContestReader(InputStream input) {
        reader = new BufferedReader(new InputStreamReader(input));
        tokenizer = new StringTokenizer("");
    }

    public String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
	
    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}

