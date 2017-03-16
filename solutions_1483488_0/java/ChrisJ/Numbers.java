import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;


public class Numbers {
	
	private static int[] pow10 = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
	/*                            0  1   2    3     4      5       6        7         8 */
	
	/* n: number, s: total number of digits, i: rotation amount */
	private static int rotate(int n, int s, int i) {
		int right = n % pow10[i];
		
		if(right < pow10[i-1]) {
			// leading zeroes => forbidden
			return -1;
		}
		
		int left = n / pow10[i];

		return right * pow10[s-i] + left;
	}
	
	
	private static int process(String l) {
		String[] parts = l.split(" ");
		int A = Integer.parseInt(parts[0]);
		int B = Integer.parseInt(parts[1]);
		HashSet<Integer> set = new HashSet<Integer>();
		int count = 0;
		
		for(int n=A; n<B; n++) {  // strict here because n < m <= B
			int size = 1 + (int)Math.log10(n);
			//System.out.println(n + ": " + size + " digits");
			
			set.clear();
			for(int i=1; i<size; i++) {
				int m = rotate(n, size, i);
				if(m > n && m <= B) set.add(m);
				//System.out.println(n + ", " + m);
			}
			count += set.size();
		}
		
		return count;
	}
	
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		PrintWriter out = new PrintWriter(args[1]);
		
		// number of testcases
		String sCount = in.readLine();
		int count = Integer.parseInt(sCount);

		for(int idx=1; idx<=count; idx++) {
			String l = in.readLine();
			out.println("Case #" + idx + ": " + process(l));
		}
		
		out.close();
	}

}
