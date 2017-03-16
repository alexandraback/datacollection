import java.util.*;
import java.io.*;
import java.math.*;

public class Consonants {
    
    private boolean isConsonant(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return false;
        } else {
            return true;
        }
    }
    
    public void solve(ContestReader cr, PrintWriter pw) throws Exception {
        String s = cr.next();
        int n = cr.nextInt();
        long count = 0;
        int prev = 0, consequtive = 0, len = s.length();
        for (int i = 0; i < len; i++) {
            char c = s.charAt(i);
            if (isConsonant(c)) {
                consequtive++;
                if (consequtive == n) {
                    count += (long) (i - n - prev + 2) * (long) (len - i);
                    consequtive--;
                    prev = i - n + 2;
                }
            } else {
                consequtive = 0;
            }
        }
        pw.println(count);
    }
    
    public static void main(String[] args) throws Exception {
		ContestReader cr = new ContestReader(new FileInputStream("A-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("A-small-attempt0.out"));
        Consonants solver = new Consonants();
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
