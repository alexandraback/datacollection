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

		long n = Long.parseLong(in.readLine());
		boolean hash[] = new boolean[10];
		long ans =0;
		long temp = 0;
		if(n == 0){
			out.write("Case #" + testCaseNumber+": "+"INSOMNIA"+"\n");
			return;
		}
		
		for(int i = 1;;i++){
			temp = i*n;
			updatehash(temp,hash);
			
			if(checkhash(hash))
			{
				out.write("Case #" + testCaseNumber+": "+temp+"\n");
				return;
			}
			
			
			
			
		}
		
		
		
		
		
		
	}
	
	private boolean checkhash(boolean[] hash){
		for (boolean b : hash) {
			if(!b) return false;
		}
		return true;
	}
	
	private void updatehash(long n , boolean[] hash){
		
		while(n>0){
			hash[(int)(n%10)] = true;
			n/=10;		
			
		}
		
	}

}
