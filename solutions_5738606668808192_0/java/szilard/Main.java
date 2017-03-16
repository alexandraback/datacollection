import java.io.FileInputStream;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.io.FilenameFilter;
import java.util.Locale;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "C-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    List<Long> primes;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int j = in.nextInt();

        primes = readPrimes();
        List<List<String>> sol = new ArrayList<List<String>>();

        for (int i = 0; i < (1 << (n - 2)) && sol.size() < j; i++) {
            List<String> s1 = find(i, n);

            if (s1 != null) {
                sol.add(s1);
            }
        }

        out.println(String.format("Case #%d:", testNumber));

        for (int i = 0; i < j; i++) {
            for (String s : sol.get(i)) {
                out.print(s + " ");
            }

            out.println();
        }
    }

    private List<String> find(int i, int n) {
        List<String> sol = new ArrayList<String>();
        String s = findString(i, n);
        sol.add(s);

        for (int base = 2; base <= 10; base++) {
            BigInteger val = new BigInteger("1");

            for (int j = 0; j < n - 2; j++) {
                int mod = (i & (1 << j)) != 0 ? 1 : 0;

                val = val.multiply(new BigInteger("" + base)).add(new BigInteger("" + mod));
            }

            val = val.multiply(new BigInteger("" + base)).add(new BigInteger("1"));

            String div = findDiv(val);

            if (div == null) {
                return null;
            }

            sol.add(div);
        }

        return sol;
    }

    private String findDiv(BigInteger x) {

        for (int i = 0; i < 100; i++) {
            if (x.mod(new BigInteger(""+primes.get(i))).equals(new BigInteger("0"))){
                return "" + primes.get(i);
            }
        }

        return null;
    }

    private String findString(int cfg, int n) {
        StringBuilder builder = new StringBuilder();
        builder.append("1");

        for (int i = 0; i < n - 2; i++) {
            if ((cfg & (1 << i)) != 0) {
                builder.append("1");
            } else {
                builder.append("0");
            }
        }

        builder.append("1");

        return builder.toString();
    }

    private List<Long> readPrimes() {
        List<Long> primes = new ArrayList<Long>();
        /*Scanner scanner = null;
        try {
            scanner = new Scanner(new FileInputStream("primes.txt"));
        } catch (FileNotFoundException e) {
            throw new RuntimeException();
        }

        while (scanner.hasNext()) {
            primes.add(scanner.nextLong());
        }*/

        int MAX_VAL = 1000000;
        boolean[] a = new boolean[MAX_VAL];

        for (int i=2; i<MAX_VAL; i++){
            if (!a[i]){
                primes.add((long)i);
                int j=2;

                while (j*i < MAX_VAL){
                    a[j*i] = true;
                    j++;
                }
            }
        }


        return primes;
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;


    public InputReader(InputStream stream){
        reader = new BufferedReader(new InputStreamReader(stream));
    }

    public String next(){
        while (tokenizer == null || !tokenizer.hasMoreTokens()){
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException("FATAL ERROR", e);
            }
        }

        return tokenizer.nextToken();
    }

    public int nextInt(){
        return Integer.valueOf(next());
    }

}

