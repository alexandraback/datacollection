import java.util.*;
import java.util.regex.*;
import java.io.*;
import java.math.*;

public class C {
    
    public void solve(ContestReader cr, PrintWriter pw) throws Exception {
        int R = cr.nextInt();
        int N = cr.nextInt();
        int M = cr.nextInt();
        int K = cr.nextInt();
        HashMap<Integer, ArrayList<Integer> > product = new HashMap<Integer, ArrayList<Integer> >();
        for (int i = 2; i <= M; i++) {
            for (int j = i; j <= M; j++) {
                for (int k = j; k <= M; k++) {
                    ArrayList<Integer> array = new ArrayList<Integer>();
                    array.add(i);array.add(j);array.add(k);
                    product.put(i * j * k, array);
                }
            }
        }
        
        for (int i = 0; i < R; i++) {
            int[] p = new int[K];
            int max = -1;
            for (int j = 0; j < K; j++) {
                p[j] = cr.nextInt();
                if (p[j] > max) max = p[j];
                
            }
            Arrays.sort(p);
            if (product.containsKey(max)) {
                ArrayList<Integer> array = product.get(max);
                pw.print(array.get(0));
                pw.print(array.get(1));
                pw.println(array.get(2));
            } else {
                int j = 0, c = 0;
                while (j < K && p[j] == 1) j++;
                if (j == K) {
                    pw.print(2);
                    pw.print(2);
                    pw.println(2);
                } else {
                    for (;j < K && c < 3;j++, c++) {
                        pw.print(p[j]);
                    }
                    for (;c < 3; c++) {
                        pw.print(p[j - 1]);
                    }
                    pw.println("");
                }
            }
        }
        
        //~ pw.println(K);
    }
    
    public static void main(String[] args) throws Exception {
		ContestReader cr = new ContestReader(new FileInputStream("C-small-1-attempt1.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("C-small-1-attempt1.out"));
        int caseCnt = cr.nextInt();
        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.println("Case #" + (caseNum+1) + ": ");
            new C().solve(cr, pw);
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

