import java.util.*;
import java.io.*;
import java.math.*;

public class Osmos {
    
    public void solve(ContestReader cr, PrintWriter pw) throws Exception {
        int A = cr.nextInt();
        int N = cr.nextInt();
        int[] other = new int[N];
        int op = 0, removeop = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            other[i] = cr.nextInt();
        }
        Arrays.sort(other);
        
        if (A == 1) {
            pw.println(N);
            return;
        }
        
        int i = 0;
        while (i < N) {
            if (A > other[i]) {
                A = A + other[i];
                i++;
            } else {
                removeop = Math.min(removeop, op + N - i);
                A = A + A - 1;
                op++;
            }
        }
        pw.println(Math.min(removeop, op));
    }
    
    public static void main(String[] args) throws Exception {
		ContestReader cr = new ContestReader(new FileInputStream("A-small-attempt1.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("A-small-attempt1.out"));
        Osmos solver = new Osmos();
        int T = cr.nextInt();
        for (int caseNum = 1; caseNum <= T; caseNum++) {
            System.out.println("Processing test case " + caseNum);
            pw.print("Case #" + caseNum + ": ");
            solver.solve(cr, pw);
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
