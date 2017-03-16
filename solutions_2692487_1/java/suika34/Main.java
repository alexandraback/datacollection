import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;


public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String line = br.readLine();
			int T = Integer.parseInt(line);
			
			for (int i=1; i<=T; i++) {
				line = br.readLine();
				String[] a = line.split(" ");
				int A = Integer.parseInt(a[0]);
				int N = Integer.parseInt(a[1]);
				int[] size = new int[N];
				line = br.readLine();
				a = line.split(" ");
				for (int j=0; j<N; j++) {
					size[j] = Integer.parseInt(a[j]);
				}
				String sol = main.solve(A, N, size);
				System.out.println("Case #"+i+": "+sol);
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public String solve(int A, int N, int[] size) {
		int min = N;
		if (A == 1) {
			return ""+N;
		}
		int ret = 0;
		int a = A;
		Arrays.sort(size);
		
		for (int i=0; i<N; i++) {
			while (a <= size[i]) {
				min = Math.min(min, ret+N-i);
				a = a + a - 1;
				ret++;
			}
			a += size[i];
		}
		ret = Math.min(min, ret);
		return ""+ret;
	}

}
