import java.io.InputStreamReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Locale;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Andrey Rechitsky (arechitsky@gmail.com)
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
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int l = in.nextInt();
        long x = in.nextLong();
        char[] s = in.next().toCharArray();
        int[] sb = new int[l];
        for (int i = 0; i < l; i++) {
            sb[i] = s[i]-'i'+1;
        }
        out.printLine("Case #%d: %s", testNumber, ans(l,x,sb)?"YES":"NO");
    }
    boolean ans(int l, long x, int[]sb){
        if (l*x<3){
            return false;
        }
        int []d1 = new int[l*4];
        d1[0] = sb[0];
        for (int i = 1; i < d1.length; i++) {
            d1[i] = mul(d1[i-1], sb[i%l]);
        }
        if (d1[l-1]==0 || (d1[l-1]==4 && x%2==0) || (d1[l-1]%4!=0 && x%4!=2)) return false;
        int []d2 = new int[l*4];
        d2[0] = sb[l-1];
        for (int i = 1; i < d2.length; i++) {
            d2[i] = mul(sb[l-1-(i%l)], d2[i-1] );
        }

        int ipos = -1;
        for (int i = 0; i < d1.length; i++) {
            if (d1[i]==1) {
                ipos = i;
                break;
            }
        }
        if (ipos==-1) return false;
        int kpos = -1;
        for (int i = 0; i < d2.length; i++) {
            if (d2[i]==3) {
                kpos = i;
                break;
            }
        }
        if (kpos==-1) return false;
        if (ipos+kpos+2>l*x) return false;
        return true;
    }
    int mul(int a, int b){
        boolean neg = false;
        if (a>=4){
            neg = !neg;
            a = negate(a);
        }
        if (b>=4){
            neg = !neg;
            b = negate(b);
        }
        int [][]table = {
                {0,1,2,3},
                {1,4,3,6},
                {2,7,4,1},
                {3,2,5,4}
        };
        int ans = table[a][b];
        return neg?negate(ans):ans;
    }
    int negate(int a){
        return (a+4)%8;
    }
}

class FastScanner {

    private BufferedReader reader;
    private StringTokenizer st;

    public FastScanner(InputStream stream) {
        this.reader = new BufferedReader(new InputStreamReader(stream));
        this.st = new StringTokenizer("");
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public String next(){
        while (!st.hasMoreTokens()){
            st = new StringTokenizer(readLine());
        }
        return st.nextToken();
    }

    private String readLine() {
        try {
            String line = reader.readLine();
            if (line==null) throw new InputMismatchException();
            return line;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

}

class FastPrinter {
    private final PrintWriter writer;

    public FastPrinter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public void close() {
        writer.close();
    }

    public void printLine(String s) {
        writer.println(s);
    }

    public void printLine(String format, Object ... args) {
        printLine(String.format(format, args));
    }

}

