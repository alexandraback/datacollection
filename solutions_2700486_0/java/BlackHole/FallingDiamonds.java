import java.util.*;
import java.io.*;
import java.math.*;

public class FallingDiamonds {
    int d = 1001;
    double[][] prob;
    
    public FallingDiamonds() {
        prob = new double[d][d];
        prob[0][0] = 0;
        for (int i = 1; i < d; i++) {
            prob[i][0] = 0;
            prob[0][i] = 1;
        }
        for (int i = 1; i < d; i++) {
            for (int j = 1; j < d; j++) {
                prob[i][j] = (prob[i - 1][j - 1] + prob[i - 1][j]) / 2.0;
            }
        }
    }
    
    int sqrt(int n) {
        int low = 1, high = n;
        while (low < high) {
            int mid = (high + low + 1) / 2;
            int p = mid * mid + mid;
            if (p == n) {
                low = mid;
                break;
            } else if (p > n) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }
        return low;
    }
    
    public void solve(ContestReader cr, PrintWriter pw) throws Exception {
        int N = cr.nextInt();
        int X = cr.nextInt();
        if (X < 0) X = -X;
        int Y = cr.nextInt();
        int base = sqrt(N * 2);
        if (base % 2 == 0) base--;
        int half = base - 1;
        int side = N - base * (base + 1) / 2;
        int out = half + 2;
        int extra = 0;
        if (side > base + 1) {
            extra = side - base - 1;
        }
        
        if (X + Y <= half) {
            pw.println(1.0);
        } else if (X + Y > out) {
            pw.println(0.0);
        } else {
            if (Y < extra) {
                pw.println(1.0);
            } else if (Y >= side) {
                pw.println(0.0);
            } else {
                int a = 0;
                if (extra == 0) {
                    a = side;
                } else {
                    a = base + 1 - extra;
                }
                int b = 0;
                if (extra == 0) {
                    b = side - Y;
                } else {
                    b = base + 1 - Y;
                }
                System.out.println(a + " " + b);
                pw.println(prob[a][b]);
            }
        }
        
    }
    
    public static void main(String[] args) throws Exception {
		ContestReader cr = new ContestReader(new FileInputStream("B-small-attempt1.in")); // B-small-attempt0
        PrintWriter pw = new PrintWriter(new FileWriter("B-small-attempt1.out"));
        FallingDiamonds solver = new FallingDiamonds();
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
