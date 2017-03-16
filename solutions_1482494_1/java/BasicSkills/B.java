import java.io.*;


public class B {
	
	private static int N;
	private static int[] a;
	private static int[] b;
	private static int[] done;
	private static int stars;
	private static int ans;
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("B.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B.out")));
		
		int T = Integer.parseInt(in.readLine());
		for (int k = 0; k < T; ++ k) {
			N = Integer.parseInt(in.readLine());
			a = new int[N];
			b = new int[N];
			done = new int[N];
			stars = 0;
			ans = 0;
			
			for (int i = 0; i < N; ++ i) {
				String[] input = in.readLine().split(" ");
				a[i] = Integer.parseInt(input[0]);
				b[i] = Integer.parseInt(input[1]);
				done[i] = 0;
			}
			
			while (zeroToTwo() || oneToTwo() || zeroToOne());
			
			if (stars == 2 * N)
				out.println("Case #" + (k + 1) + ": " + ans);
			else
				out.println("Case #" + (k + 1) + ": " + "Too Bad");
		}
		
		in.close();
		out.close();
	}
	
	private static boolean zeroToOne() {
		int maxi = 0;
		int maxb = -1;
		
		for (int i = 0; i < N; ++ i) {
			if (done[i] == 0 && stars >= a[i]) {
				if (b[i] > maxb) {
					maxi = i;
					maxb = b[i];
				}
			}
		}
		
		if (maxb != -1) {
			done[maxi] = 1;
			++ stars;
			++ ans;
			return true;
		}
		else {
			return false;
		}
	}
	
	private static boolean zeroToTwo() {
		boolean progress = true;
		boolean flag = false;
		
		while (progress) {
			progress = false;
			
			for (int i = 0; i < N; ++ i) {
				if (done[i] == 0 && stars >= b[i]) {
					done[i] = 2;
					stars += 2;
					++ ans;
					progress = true;
					flag = true;
				}
			}
		}
		
		return flag;
	}
	
	private static boolean oneToTwo() {
		for (int i = 0; i < N; ++ i) {
			if (done[i] == 1 && stars >= b[i]) {
				done[i] = 2;
				++ stars;
				++ ans;
				return true;
			}
		}
		
		return false;
	}
	
}
