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
		in.readLine();
		//System.out.println("hello".substring(0, 0));
		//System.out.println("hi");
		out.write("Case #1:\n");
		for(int i =0;i<50;i++){
			String s = Long.toBinaryString(i);
			String jam = lengthSix(i, s);
			s =  jam;
			jam = jam+jam;
			
			out.write(jam);
			
			for(int j = 2;j<11;j++ ){
				long temp = Long.parseLong(s, j);
				out.write(" "+temp);
			}
			
			out.write("\n");
			
			
		}
		
		
		
		
	}
	
	
	private String lengthSix(long n,String s){
		
		String temp = "000000";
		
		int len = s.length();
		
		s= temp.substring(0,6-len) + s;
		s = "1" + s + "1";
		
		return s;
		
	}
	


}