import java.util.*;
import java.io.*;
import java.math.*;

public class Osmos {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws IOException {
		int T = Integer.parseInt(in.readLine());
		int testCase = 1;
		while(testCase <= T) {
			String[] toks = in.readLine().split(" ");
			int A, N;
			A = Integer.parseInt(toks[0]);
			N = Integer.parseInt(toks[1]);
			int[] B = new int[N];
			toks = in.readLine().split(" ");
			for(int i=0;i<N;i++){
				B[i] = Integer.parseInt(toks[i]);
			}
			if(A==1){
				System.out.println("Case #" + testCase + ": " + N);
				testCase++;
				continue;
			}
			Arrays.sort(B);
			int res = Integer.MAX_VALUE;
			for(int to=0; to<N; to++){
				res = Math.min(res, calc(B, A, 0, to) + (N-to-1));
			}
			res = Math.min(res, N);
			System.out.println("Case #" + testCase + ": " + res);
			testCase++;
		}
	}
	
	static int calc(int[] B, int A, int pos, int to){
		if(pos>to) return 0;
		if(A>B[pos]){
			return calc(B, A+B[pos], pos+1, to);
		}else{
			return 1 + calc(B, 2*A-1, pos, to);
		}
	}
}
