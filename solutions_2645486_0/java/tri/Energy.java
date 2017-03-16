import java.util.*;
import java.io.*;
import java.math.*;

public class Energy {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws IOException {
		int T = Integer.parseInt(in.readLine());
		int testCase = 1;
		while(testCase <= T) {
			String[] toks = in.readLine().split(" ");
			int E, R, N;
			E = Integer.parseInt(toks[0]);
			R = Integer.parseInt(toks[1]);
			N = Integer.parseInt(toks[2]);
			int[] v = new int[N];
			toks = in.readLine().split(" ");
			for(int i=0;i<N;i++){
				v[i] = Integer.parseInt(toks[i]);
			}
			int pos=0, gain=0;
			int res = solve(E, R, N, v, E, pos, gain);
			System.out.println("Case #" + testCase + ": " + res);
			testCase++;
		}
	}
	
	static int solve(int E, int R, int N, int[] v, int amount, int pos, int gain){
		if(pos==N-1)	//last task, use all remain energy
			return gain + amount*v[pos];
		//Else, use all possible calculation at this step
		int max = 0;
		for(int use=0; use<=amount; use++){
			max = Math.max(max, solve(E, R, N, v, Math.min(amount-use+R, E), pos+1, gain + use*v[pos]));
		}
		return max;
	}
}
