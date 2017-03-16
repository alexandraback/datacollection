import java.util.*;
import java.io.*;
import java.math.*;

public class PogoSmall {
    
    public void solve(ContestReader cr, PrintWriter pw) throws Exception {
        int X = cr.nextInt();
        int Y = cr.nextInt();
        StringBuilder sb = new StringBuilder();
        int i = 0;
        if (X < 0) {
            for (i = 0; i < -X; i++) {
                sb.append("EW");
            }
        }
        if (X > 0) {
            for (i = 0; i < X; i++) {
                sb.append("WE");
            }
        }
        if (Y < 0) {
            for (i = 0; i < -Y; i++) {
                sb.append("NS");
            }
        }
        if (Y > 0) {
            for (i = 0; i < Y; i++) {
                sb.append("SN");
            }
        }
        
        pw.println(sb.toString());
    }
    
    public static void main(String[] args) throws Exception {
		ContestReader cr = new ContestReader(new FileInputStream("B-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("B-small-attempt0.out"));
        PogoSmall solver = new PogoSmall();
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
