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
public class C {

	//some local config
	static boolean test = true;
	static String testDataFile = "C-small-1-attempt0.in";
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
		
		int r = iread(), n = iread(), m = iread(), k = iread();
		
		String ans = "Case #" + case_nr +": ";
		System.out.println(ans);
		out.write(ans + "\n");
		for (int i = 0; i < r; i++) {
			int[] nums = new int[k]; 
			for (int j = 0; j < k; j++) {
				nums[j] = iread();
			}
			guess(nums, n, m);
			System.out.println(ret);
			out.write(ret + "\n");
		}
		
	}
	boolean done;
	String ret = "";
	private String guess(int[] nums, int n, int m) {
		done = false;
		ret = "";
		go(nums, n, m, new int[n], 0);
		if(ret.equals("")){
			System.out.println("error");
			for (int i = 0; i < n; i++) {
				ret += "1";
			}
		}
		return ret;
	}

	private void go(int[] nums, int n, int m, int[] values, int pos) {
		if(done){
			return;
		}
		if(pos == values.length){
			
			if(values[0] == 3 && values[1] == 3 && values[2] == 4){
//				System.out.println("");
			}
			
			out:for (int numId = 0; numId < nums.length; numId++) {
				int num = nums[numId];
				for (int i = 0; i <= 1<<values.length; i++) {
					int prod = 1;
					for (int j = 0; j < values.length; j++) {
						if((i & (1 << j)) > 0){
							prod *= values[j];
						}
					}
					if(prod == num){
						continue out;
					}
				}
				return;
			}
			ret = "";
			for (int i = 0; i < values.length; i++) {
				ret+= values[i];
			}
			done = true;
			return;
		}
		
		for (int i = 2; i <= m; i++) {
			values[pos] = i;
			go(nums, n, m, values, pos + 1);
		}
		
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
			new C().solve();
		}
		out.close();
	}

	public C() throws Throwable {
		if (test) {
			in = new BufferedReader(new FileReader(new File(testDataFile)));
		}
	}

	InputStreamReader inp = new InputStreamReader(System.in);
	BufferedReader in = new BufferedReader(inp);
	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	
	enum CompetitionType {CF, OTHER};
}