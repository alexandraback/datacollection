import java.io.*;
import java.util.*;
import java.text.*;

public class Main implements Runnable{

	/**
	 * @param args
	 */
	private StringTokenizer stReader;
	private BufferedReader bufReader;
	private PrintWriter out;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		(new Main()).run();
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		bufReader = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new OutputStreamWriter(System.out));
		stReader = null;
		Solves();
		out.flush();
	}
	public String ReadLine() {
		String result = null;

		try {
			result = bufReader.readLine();
		} catch (IOException e) {
		}
		return result;
	}
	public String NextString(){
		if (stReader == null || !stReader.hasMoreTokens()){
			stReader = new StringTokenizer(ReadLine(),"\n\r ");
		}
		return stReader.nextToken();
	}
	public int NextInt(){
		return Integer.parseInt(NextString());
	}
	public long NextLong(){
		return Long.parseLong(NextString());
	}
	public double NextDouble(){
		return Double.parseDouble(NextString());
	}
	void Solves(){
		int n = NextInt();
		for(int i =0; i < n; i++){
			out.print("Case #"  +(i + 1) + ": ");
			Solve();
			out.println();
			//out.flush();
		}
		out.flush();
	}
	void Solve(){
		int N = NextInt();
		int S = NextInt();
		int p = NextInt();
		int result = 0;
		for(int i =0; i < N; i++){
			int val = NextInt();
			if (val < p) continue;
			int n = val /3;
			int k = val % 3;
			if (n >= p || (k > 0 && n + 1 >= p)) result++;
			else {
				if ((k == 2 && n + 2 >= p && S > 0) || (k == 0 && n + 1 >= p && S > 0)) {
					result++;
					S--;
				}
			}
		}
		out.print(result);
	}
	
}
