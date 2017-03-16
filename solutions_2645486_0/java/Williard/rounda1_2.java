import java.io.*;

public class rounda1_2 {
	public static PrintStream out = new PrintStream(new BufferedOutputStream(System.out));
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static int value[];
	public static int E;
	public static int R;
	public static int N;
	public static int dfsCases(int activity, int energy) {
		int currValue = -1;
		int dfsvalue = 0;
		if (activity == N-1) {
			return energy*value[N-1];
		}
		for (int i = energy; i >= 0; i--) {
			
			dfsvalue = dfsCases(activity+1, Math.min(energy-i+R, E));
			currValue = Math.max(currValue, dfsvalue+i*value[activity]);
		}
		return currValue;
	}
	public static void main(String[] args) throws Exception {
		int T = 0;
		int maxValue = 0;
		String[] input;
		
		T = Integer.parseInt(br.readLine());
		
		for (int ctr = 1; ctr <= T; ctr++) {
			input = br.readLine().split(" ");
			E = Integer.parseInt(input[0]);
			R = Integer.parseInt(input[1]);
			N = Integer.parseInt(input[2]);
			input = br.readLine().split(" ");
			maxValue = 0;
			value = new int[N];
			for (int i = 0; i < N; i++) {
				value[i] = Integer.parseInt(input[i]);
			}
			
			maxValue = dfsCases(0, E);
			
			out.printf("Case #%d: %d\n", ctr, maxValue);
		}
		out.flush();
	}
	
}
