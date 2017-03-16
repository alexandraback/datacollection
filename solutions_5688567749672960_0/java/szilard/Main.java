import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.FilenameFilter;
import java.util.*;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "A-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("a.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        long n = in.nextLong();
        long sol = solve(n);

        //long sol2 = solveBrute(n);

        out.println(String.format("Case #%d: %d", testNumber, sol));
    }

    static class Pair{
        long val, nr;

        public Pair(long val, long nr) {
            this.val = val;
            this.nr = nr;
        }
    }

    private long solveBrute(long n) {
        Map<Long, Long> visited = new HashMap<Long, Long>();
        Queue<Pair> q = new LinkedList<Pair>();

        q.add(new Pair(1L, 1L));

        while (!q.isEmpty()){
            Pair p = q.poll();

            if (p.val == n){
                return p.nr;
            }

            if (!visited.containsKey(p.val)){
                visited.put(p.val, p.nr);
                q.add(new Pair(p.val+1, p.nr+1));
                q.add(new Pair(reverse(p.val), p.nr+1));
            }
        }

        return 0;
    }

    private long solve(long n) {
        if (n <= 10){
            return n;
        }

        int nr = ("" + n).length();

        long curr = 10;
        long cost = 10;

        long target = 100;

        for (int i=0; i<nr-2; i++){
            long contr = calc(curr, target-1);

            cost+= contr+1L;
            curr = target;
            target *= 10L;
        }

        return cost + calc(curr, n);
    }

    private long calc(long curr, long n) {
        if (curr == n){
            return 0;
        }

        long cost = 0;
        int size = ("" + n).length();
        long val1 = get("" + n, 0, size / 2 + size % 2);
        long val2 = get("" + n, size/2+ size%2, size);

        if (val2 == 0){
            long rev = reverse(val1-1);
            cost += rev;
            cost++;

            long v = 1;
            for (int i=0; i<size/2; i++){
                v *= 10L;
            }

            cost += v-1L;
        } else {
            if (reverse(val1) == 1){
                cost += val2;
            } else {
                long rev = reverse(val1);
                cost += rev;
                cost++; 
                cost += val2 - 1;
            }
        }

        return Math.min(cost, n-curr);
    }

    private long get(String s, int start, int end) {
        long sol = 0;

        for (int i=start; i<end; i++){
            sol = sol * 10L + (s.charAt(i) - '0');
        }

        return sol;
    }

    private Long reverse(long curr) {
        return Long.valueOf(new StringBuilder("" + curr).reverse().toString());
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

    public long nextLong(){
        return Long.valueOf(next());
    }
}

