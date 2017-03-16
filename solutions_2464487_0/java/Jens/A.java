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
public class A {

	//some local config
	static boolean test = true;
	static String testDataFile = "A-small-attempt0(1).in";
	static String feedFile = "feed.txt";
	CompetitionType type = CompetitionType.CF;
	private static String ENDL = "\n";

	// solution
	private void solve() throws Throwable {
		out = new BufferedWriter(new FileWriter(this.getClass().getCanonicalName() + "-res.txt")); 
		int n = iread();
		for (int i = 0; i < n; i++) {
			solveIt(i+1);
		}
		out.flush();
	}

	private void solveIt(int i) throws Throwable {
		
		long r = lread();
		long t = lread();
		int cnt = 0;
		while(true){
			long inner = r * r;
			long outer = (r + 1) * (r+1);
			if(t >= outer-inner){
				t -= outer-inner;
				cnt ++;
				r += 2;
			} else {
				break;
			}
		}
	
		
		String ans = "Case #" + i +": " + cnt;
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
			new A().solve();
		}
		out.close();
	}

	public A() throws Throwable {
		if (test) {
			in = new BufferedReader(new FileReader(new File(testDataFile)));
		}
	}

	InputStreamReader inp = new InputStreamReader(System.in);
	BufferedReader in = new BufferedReader(inp);
	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	
	enum CompetitionType {CF, OTHER};
}