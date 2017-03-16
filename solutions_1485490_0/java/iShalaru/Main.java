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
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		(new Main()).run();
	}

	@Override
	public void run(){
		// TODO Auto-generated method stub
		try {
			bufReader = new BufferedReader(new FileReader("input.txt"));
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		try {
			out = new PrintWriter(new FileWriter("output.txt"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
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
	long [][] A,B;
	long F(int i,int j){
		long ans = 0;
		if (i == A[0].length || j == B[0].length) return ans;
		if (A[1][i] == B[1][j])
		{
			long tA = A[0][i];
			long tB = B[0][j];
			if (tA > tB){
				ans = tB;
				A[0][i] -= tB;
				ans += F(i,j+1);
				A[0][i] += tB;
			}else if (tB > tA){
				ans = tA;
				B[0][j] -= tA;
				ans += F(i+1,j);
				B[0][j] += tA;
			}else {
				ans = tA;
				ans += F(i+1,j+1);
			}
		}else {
			long aAns = F(i+1,j);
			long bAns = F(i,j+1);
			ans = Math.max(aAns, bAns);
		}
		return ans;
	}
	void Solve(){
		int N = NextInt();
		int M = NextInt();
		A = new long[2][N];
		B = new long[2][M];
		for(int i =0; i < N; i++){
			A[0][i] = NextLong();
			A[1][i] = NextLong();
		}
		for(int i =0;i < M; i++){
			B[0][i] = NextLong();
			B[1][i] = NextLong();
		}
		long ans = F(0,0);
		out.print(ans);
	}
}
