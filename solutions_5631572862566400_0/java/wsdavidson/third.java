import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class third {
	public static void main(String[] args) {
		try {
			process();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private static void process()
	throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		int testCases = Integer.parseInt(reader.readLine());
		
		for (int i = 0; i < testCases; ++i) {
			System.out.println("Case #" + (i+1) + ":" + processTestCase(reader));
		}
		
		reader.close();
	}
	
	private static String processTestCase(BufferedReader reader)
	throws IOException {
		int N = Integer.parseInt(reader.readLine());
		int[] bffs = new int[N];
		
		for (int l = 2; l <= N; ++l) {
			
		}
		
		String[] a = reader.readLine().split(" ");
		for (int i = 0; i < a.length; ++i) {
			bffs[i] = Integer.parseInt(a[i]) - 1;
		}
		
		int[] circle = new int[bffs.length];
		boolean[] used = new boolean[bffs.length];
		
		int best = solve(circle, 0, used, bffs);
		
		return " " + best;
	}
	
	private static int solve(int[] circle, int pos, boolean[] used, int[] bffs) {
		int best = 0;
		
		for (int i = 0; i < bffs.length; ++i) {
			if (!used[i]) {
				circle[pos] = i;
				used[i] = true;
				
				if (pos > 0 && works(circle, pos+1, bffs)) {
					best = Math.max(best, pos+1);
				}
				
				best = Math.max(best, solve(circle, pos+1, used, bffs));
				
				used[i] = false;
			}
		}
		
		return best;
	}
	
	private static boolean works(int[] circle, int len, int[] bffs) {
		for (int i = 0; i < len; ++i) {
			if (bffs[circle[i]] == circle[(i+1) % len] || bffs[circle[i]] == circle[(i+len-1) % len]) {
			}
			else {
				return false;
			}
		}
		
		return true;
	}
}