import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Enumeration;
import java.util.Iterator;
import java.util.Properties;

/**
 * Works good for CF
 * @author cykeltillsalu
 */
public class B {

	//some local config
	static boolean test = true;
	static String testDataFile = "B-small-attempt1.in";
	//static String testDataFile = "testdata.txt";
	static String feedFile = "feed.txt";
	CompetitionType type = CompetitionType.CF;
	private static String ENDL = "\n";

	// solution
	private void solve() throws Throwable {
		int n = iread();
		out = new BufferedWriter(new FileWriter(this.getClass().getCanonicalName() + "-res.txt")); 
		for (int i = 0; i < n; i++) {
			solveIt(i+1);
		}
		out.flush();
	}

	private void solveIt(int case_nr) throws Throwable {
		long cnt = 0;
		
		long e = lread(), r = lread();
		long max = e;
		int n = iread();
		long[] val = new long[n];
		for (int j = 0; j < n; j++) {
			val[j] = iread();
		}
		long res = 0;
		for (int i = 0; i < n; i++) {
			int steps = -1;
			for (int j = i+1; j < n; j++) {
				if(val[j] > val[i]){
					steps = j-i;
					break;
				}
			}
			
			
			
			long target = e + steps * r;
			long use = Math.max(0, Math.min(e, target - max));
			
			if(steps == -1){
				use = e;
			}
			
			res += (use) * val[i];
			e -= use;
			e += r;
		}
		
		
		String ans = "Case #" + case_nr +": " + res;
		System.out.println(ans);
		out.write(ans + "\n");
	}

	public int iread() throws Exception {
		return Integer.parseInt(wread());
	}

	public double dread() throws Exception {
		return Double.parseDouble(wread());
	}

	public long lread() throws Exception {
		return Long.parseLong(wread());
	}

	public String wread() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) throws Throwable {
		
		if(test){ //run all cases from testfile:
			new B().solve();
		}
		out.close();
	}

	public B() throws Throwable {
		if (test) {
			in = new BufferedReader(new FileReader(new File(testDataFile)));
		}
	}

	InputStreamReader inp = new InputStreamReader(System.in);
	BufferedReader in = new BufferedReader(inp);
	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	
	enum CompetitionType {CF, OTHER};
}