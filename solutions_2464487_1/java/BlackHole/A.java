import java.util.*;
import java.util.regex.*;
import java.io.*;
import java.math.*;

public class A{
    ContestReader cr;
    BigInteger r, t;
    
    public void solve(Scanner sc, PrintWriter pw) {
        String rs = sc.next();
        String ts = sc.next();

        r = new BigInteger(rs);
        t = new BigInteger(ts);
        
        BigInteger low = new BigInteger("0");
        BigInteger high = new BigInteger(ts);
        BigInteger one = new BigInteger("1");
        BigInteger two = new BigInteger("2");
        while (low.compareTo(high) == -1) {
            BigInteger mid = low.add(high).add(one).divide(two);
            BigInteger p = mid.multiply(mid).multiply(two).add(mid.multiply(r.multiply(two).subtract(one)));
            if (p.compareTo(t) == 0) {
                low = mid;
                break;
            } else if (p.compareTo(t) == 1) {
                high = mid.subtract(one);
            } else {
                low = mid;
            }
        }
        pw.println(low.toString());
    }
    
    public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader("A-large.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("A-large.out"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum < caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new A().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
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
