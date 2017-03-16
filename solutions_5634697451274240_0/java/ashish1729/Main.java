import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {
	private BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws Exception {
		new Main().solve();
	}

	private void solve() throws Exception {
		int testCases = 1;
		testCases = Integer.parseInt(in.readLine().trim());
		for (int i = 1; i <= testCases; i++) {
			solve(i);
		}

		out.flush();
		out.close();
	}

	private void solve(int testCaseNumber) throws Exception {
		String s = in.readLine();
		int len = s.length();
		int i ;
		for( i = len-1;i>=0;i--){
			if(s.charAt(i) == '-')
				break;
		}
		
		if(i==-1){
			out.write("Case #" + testCaseNumber+": "+0+"\n");
			return;
		}
		int ans = 1;
		
		for(;i>0;i--){
			if(s.charAt(i) != s.charAt(i-1)){
				ans++;
			}
		}
		
		out.write("Case #" + testCaseNumber+": "+ans+"\n");
		
		
	}
	


}
