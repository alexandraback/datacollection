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
		
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		int k = Integer.parseInt(st.nextToken());
		out.write("Case #"+testCaseNumber+":");
		for(int i=0;i<k;i++){
			out.write(" " +(i+1));
		}
		out.write("\n");
		
	}
	
	

}