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
		}
		out.flush();
	}
	void Solve(){
		int A = NextInt();
		int B = NextInt();
		int result = 0;
		TreeSet<Integer> treeSet = new TreeSet<Integer>();
		for(int i = A; i <=B; i++){
			if (i <= 10) continue;
			StringBuilder parse = new StringBuilder(String.valueOf(i));
			treeSet.clear();
			for(int j =0;j < parse.length(); j++){
				int val = Shift(parse);
				if (val > i && val <= B && !treeSet.contains(val)) { 
					result++;
					treeSet.add(val);
				}
			}
			treeSet.clear();
		}
		out.print(result);
	}
	int Shift(StringBuilder parse){
		char last = parse.charAt(parse.length()-1);
		parse = parse.deleteCharAt(parse.length()-1);
		parse = parse.insert(0, last);
		return Integer.valueOf(parse.toString());
	}
}
