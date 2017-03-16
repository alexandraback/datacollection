import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Enumeration;
import java.util.Iterator;
import java.util.List;
import java.util.Properties;

/**
 * Works good for CF
 * @author cykeltillsalu
 */
public class CopyOfA {

	//some local config
	static boolean test = true;
	static String testDataFile = "C-large.in";
	static String feedFile = "feed.txt";
	CompetitionType type = CompetitionType.CF;
	private static String ENDL = "\n";

	// solution
	String[] dict = new String[521196];
	private void solve() throws Throwable {
		out = new BufferedWriter(new FileWriter(this.getClass().getCanonicalName() + "-res.txt"));
		
		BufferedReader r = new BufferedReader(new FileReader("garbled_email_dictionary.txt"));
		int maxlen = 0;
		
		for (int i = 0; i < 521196; i++) {
			dict[i] = r.readLine();
			maxlen = Math.max(dict[i].length(), maxlen);
			
		}
		System.out.println("Maxlen: " + maxlen);
		int n = iread();
		for (int i = 0; i < n; i++) {
			solveIt(i+1);
		}
		out.flush();
	}

	private void solveIt(int casenr) throws Throwable {
		int cnt = 0;
		String target = wread();
		int[][] dp = new int[target.length() + 1][5];
		
		for (int j = 0; j < dp.length; j++) {
			Arrays.fill(dp[j], Integer.MAX_VALUE/2);
		}
		
		dp[0][0] = 0;
//		List<Integer> incorrectIdx = new ArrayList<Integer>();
//		boolean[] 
		for (int i = 0; i < target.length(); i++) {
			out1:for (int j = 0; j < dict.length; j++) {
//				incorrectIdx.clear();
				String cand = dict[j];
				if(i + cand.length() > target.length()){
					continue;
				}
				int lasterror = -5;
				int error1 = -1;
				int error2 = -1;
				
				for (int k = 0; k < cand.length(); k++) {
					if(target.charAt(k + i) != cand.charAt(k)){
						if(error1 == -1){
							error1 = k;
						} else if(k - error1 >= 5 && error2 == -1){
							error2 = k;
						} else {
							continue out1;
						}
					}
				}
				out:for (int from = 0; from < 5; from++) {
					int fromstate = from;// dp[i][from];
					if(error1 != -1 && error1 < fromstate){
						continue out;
					}
					if(error1 != -1){
						fromstate = error1 + 5;
					}
					if(error2 != -1){
						fromstate = error2 + 5;
					}
					int numerror = 0;
					if(error1 != -1){
						numerror ++;
					}
					if(error2 != -1){
						numerror ++;
					}
					
					int nexterror = fromstate - cand.length();
					nexterror = Math.max(0, nexterror);
					dp[i + cand.length()][nexterror] = Math.min(dp[i + cand.length()][nexterror], dp[i][from] + numerror);
				}
			}
		}
		cnt = Integer.MAX_VALUE;
		for (int i = 0; i < dp[dp.length-1].length; i++) {
			cnt = Math.min(cnt, dp[dp.length-1][i]);
		}
		String ans = "Case #" + casenr +": " + cnt;
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
			long t0 = System.currentTimeMillis();
			new CopyOfA().solve();
			System.out.println("Time in ms: " + (System.currentTimeMillis() - t0));
		}
		out.close();
	}

	public CopyOfA() throws Throwable {
		if (test) {
			in = new BufferedReader(new FileReader(new File(testDataFile)));
		}
	}

	InputStreamReader inp = new InputStreamReader(System.in);
	BufferedReader in = new BufferedReader(inp);
	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	
	enum CompetitionType {CF, OTHER};
}