import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;

public class Osmos2{
	
	public static void main(String[] args) throws Exception{
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter("A-large.out"));
		//PrintStream out = System.out;
	
		String line = br.readLine();
		int T = Integer.parseInt(line);		
		
		for(int i=1; i<=T; i++){
			line = br.readLine();
			String[] splitLine = line.split(" ");
			int A = Integer.parseInt(splitLine[0]);
			int N = Integer.parseInt(splitLine[1]);

			int[] motes = new int[N];
			line = br.readLine();
			splitLine = line.split(" ");
			
			for(int j=0; j<N; j++){
				motes[j] = Integer.parseInt(splitLine[j]);
			}
			
			out.println("Case #" + i + ": " + solve(A, N, motes));
		}
		
		br.close();
		out.close();
	}
	
	static int solve(int A, int N, int[] motes){
		Arrays.sort(motes);
		
		return solveHelper(A, N, motes, 0);
	}
	
	static int solveHelper(int A, int N, int[] motes, int start){
		if(start == N){
			return 0;
		}
		
		if(A > motes[start]){
			return solveHelper(A + motes[start], N, motes, start+1);
		}
		
		if(A == 1){
			return N-start;
		}
		
		return Math.min(N-start, 
						1+solveHelper(A+A-1, N, motes, start));
	}
}