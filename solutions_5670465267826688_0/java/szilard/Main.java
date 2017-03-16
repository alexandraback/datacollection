import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.FilenameFilter;
import java.util.Locale;
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
    private static final int INVALID = -1000;
    private static final int I = 2;
    private static final int J = 3;
    private static final int K = 4;

    static class Pair{
        int periodsNr, index;

        public Pair(int periodsNr, int index) {
            this.periodsNr = periodsNr;
            this.index = index;
        }
    }

    private int[][] multTable;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        createMultTable();

        int n = in.nextInt();
        int x = in.nextInt();

        String s = in.next();

        if (possible(s, n, x)){
            out.println(String.format("Case #%d: YES", testNumber));
        } else {
            out.println(String.format("Case #%d: NO", testNumber));
        }
    }

    private boolean possible(String s, int n, int x) {
        int period;
        int curr = 1;
        int[] a = new int[n];

        for (int i=0; i<n; i++){
            curr = multiply(curr, s.charAt(i) - 'i' + 2);
            a[i] = curr;
        }

        period = curr;

        if (!isGoodMult(period, x)){
            return false;
        }

        Pair p = find(a, x, new Pair(-1, -1), I, period);

        if (p == null){
            return false;
        }

        Pair q = find(a, x, p, K, period);

        return q != null;
    }

    private Pair find(int[] a, int x, Pair p, int target, int period) {
        int nrPeriods = Integer.MAX_VALUE;
        int index = Integer.MAX_VALUE;

        for (int i=0; i<a.length; i++){
            int requiredMult = 0;

            if (a[i] == target){
                requiredMult = 1;
            } else {
                requiredMult = getRequired(a[i], target);
            }

            if (requiredMult != INVALID){
                int min = (p.index < i) ? p.periodsNr : p.periodsNr+1;
                int minPeriods = getMinPeriods(requiredMult, min, period);

                if (minPeriods != INVALID && minPeriods < x){
                    if (nrPeriods > minPeriods){
                        nrPeriods = minPeriods;
                        index = i;
                    }
                }
            }
        }

        if (index != Integer.MAX_VALUE){
            return new Pair(nrPeriods, index);
        }

        return null;
    }

    private int getMinPeriods(int required, int min, int period) {

        for (int i=0; i<4; i++){
            int base = Math.max(min, 0);
            int res = pow(period, base + i);

            if (res == required){
                return i;
            }
        }

        return INVALID;
    }


    private int getRequired(int ai, int target) {

        for (int i=-1; i<=1; i+=2){
            for (int j=1; j<=4; j++){
                if (multiply(i*j, ai) == target){
                    return i*j;
                }
            }
        }

        return INVALID;
    }


    private boolean isGoodMult(int period, int x) {
        int powSol = pow(period, x);

        return powSol == -1;
    }

    private int pow(int x, int exp) {
        if (exp ==0){
            return 1;
        }

        int mult = (x < 0 && (exp%2 == 1)) ? -1 : 1;
        x = Math.abs(x);

        if (x == 1){
            return mult;
        }

        exp--;
        int mod = exp % 4;

        switch (mod){
            case 0:
                return mult * x;
            case 1:
                return -mult;
            case 2:
                return -x * mult;
            default:
                return mult;
        }

    }

    private int multiply(int curr, int i) {
        boolean negative = curr * i < 0;
        int sol = multTable[Math.abs(curr)][Math.abs(i)];

        if (negative){
            return -sol;
        }
        return sol;
    }

    private void createMultTable() {
        multTable = new int[5][];

        multTable[1] = new int[]{0, 1, I, J, K};
        multTable[2] = new int[]{0, I, -1, K, -J};
        multTable[3] = new int[]{0, J, -K, -1, I};
        multTable[4] = new int[]{0, K, J, -I, -1};
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

