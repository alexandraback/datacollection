import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Main {


	public static void main(String[] args) {
		Main main = new Main();
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			String line = bf.readLine();
			int T = Integer.parseInt(line);
			for (int testcaseIndex=0; testcaseIndex<T; testcaseIndex++) {
				String testCase = bf.readLine();
				String[] array = testCase.split(" ");
				int N = Integer.parseInt(array[0]);
				int S = Integer.parseInt(array[1]);
				int p = Integer.parseInt(array[2]);
				
				int[] scores = new int[N];
				for (int i=0; i<N; i++) {
					scores[i] = Integer.parseInt(array[3+i]);
				}
				
				int out  = main.solve(N, S, p, scores);
				
				System.out.print("Case #"+(testcaseIndex+1)+": ");
				System.out.println(out);
				
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

	}
	
	private int solve(int N, int S, int p, int[] scores) {
		int ret = 0;
		int numS = 0;
		//Arrays.sort(scores);
		for (int s : scores) {
			if (s >= Math.max(3*p-2, 0)) {
				//System.out.println("not");
				ret++;
			} else if (s >= Math.max(3*p-4, 0) && numS < S && s >= p) {
				//System.out.println("SUP");
				ret++;
				numS++;
			}
		}
		return ret;
	}
	
}
