import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Dijkstra{
	static int[][] multiplication = new int[][]{
		{1, 2,  3, 4}, 
		{2, -1, 4, -3}, 
		{3, -4, -1, 2}, 
		{4, 3,  -2, -1}
	};
	static int[] l2r = new int[40001];
	static boolean[] negative = new boolean[40001];
	static char[] x;
	static int L;
	static long X;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine().trim());
		for(int i = 1; i <= T; i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			L = Integer.parseInt(st.nextToken());
			X = Long.parseLong(st.nextToken());
			x = br.readLine().trim().toCharArray();
			sb.append(String.format("Case #%d: %s\n", i, solve()? "YES":"NO"));
		}

		System.out.print(sb);
		br.close();
	}
	private static int charToIdx(char c){
		return c - 'i' + 2;
	}
	private static boolean solve(){
		int length = L*((X < 4)? (int)X : 4);
		l2r[0] = charToIdx(x[0]);
		for(int i = 1; i < length; i++){
			int r = multiplication[l2r[i-1] - 1][charToIdx(x[i % L]) - 1];
			l2r[i] = Math.abs(r);
			if(negative[i-1])    negative[i] = (r < 0)? false : true;
			else negative[i] = (r < 0)? true : false;
		}	
		int idx = length-1;
		if(X > 4 && X % 4 != 0)
			idx = L * (int)(X % 4) -1;
		
		if(!(negative[idx] && l2r[idx] == 1))	return false;
		if(X < 4){
			for(int i = 0; i < length-2; i++){
				for(int j = i + 1; j < length - 1; j++){
					if(!negative[i] && l2r[i] == 2 &&
						!negative[j] && l2r[j] == 4)	return true;
				}
			}
			return false;
		}
		else{
			for(int i = 0; i < length-1; i++){
				for(int j = i + 1; j < length; j++){
					if(!negative[i] && l2r[i] == 2 &&
						!negative[j] && l2r[j] == 4)	return true;
					if(!negative[j] && l2r[j] == 2 && 
						(long)(i + 4 * L) < X * L &&
						!negative[i] && l2r[i] == 4)	return true;
				}
			}
			return false;
		}	
	}

}
