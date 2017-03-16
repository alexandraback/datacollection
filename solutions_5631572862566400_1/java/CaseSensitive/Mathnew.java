import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Mathnew {
	
	static PrintWriter writer = null;
	static int n;
	
	public static void main(String[] args) {
		
		Scanner console = null;
		try {
			console = new Scanner(new File("input.txt"));
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
		try {
			writer = new PrintWriter("output.txt", "UTF-8");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (UnsupportedEncodingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		int t = console.nextInt();
		for (int ti = 0; ti < t; ti++) {
			n = console.nextInt();
			
			int[] a = new int[n];
			int[] status = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = console.nextInt() - 1;
			}
			
			System.out.println(Arrays.toString(a));
			int resA = 0;
			int resB = 0;
			for (int i = 0; i < n; i++) {
				resA = Math.max(resA, solveA(i, status, a));
			}
			
			int[] resultB = new int[n];
			for (int i = 0; i < n; i++) {
				solveB(i, status, a, resultB);
			}
			
			int xB = 0;
			for (int i = 0; i < n; i++) {
				if (status[i] == 3) {
					xB += resultB[i];
				}
			}
			

			System.out.println(Arrays.toString(status));

			System.out.println(resA);
			writer.printf("Case #%d: %s\n", ti + 1, Math.max(xB, resA));
		}
		writer.close();
	}

	public static void solveB(int cur, int[] status, int[] a, int[] result) {
		if (status[cur] == 2) {
			return;
		}
		
		int count = 1;
		while (status[cur] != 3) {
			if (status[cur] == 2) {
				return;
			}
			cur = a[cur];
			count++;
		}
		result[cur] = Math.max(result[cur], count);
		System.out.println("result for " + cur + ": " + count);
	}
	
	public static int solveA(int cur, int[] status, int[] a) {
		
		//System.out.println("trying: " + cur);
		
		int origin = cur;
		
		int count = 1;
		int[] seq = new int[n];
		while (true) {
			
			//System.out.println("now: " + cur + " count: " + count);
			if (status[cur] > 0) {
				{
					int c = origin;
					while (c != cur) {
						status[c] = 1;
						c = a[c];
					}
				}
				return 0;
			}
			if (seq[cur] != 0) {
				{
					int c = origin;
					while (c != cur) {
						status[c] = 1;
						c = a[c];
					}
					status[c] = 2;
					c = a[c];
					while (c != cur) {
						status[c] = 2;
						c = a[c];
					}
					if (count - seq[cur] == 2) {
						status[c] = 3;
						status[a[c]] = 3;
					}
				}
				return count - seq[cur];
			}

			seq[cur] = count;
			count++;
			cur = a[cur];
		}
	}
	
}