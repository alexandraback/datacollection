import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.BitSet;
import java.util.Scanner;

public class Bsmall {

	public static long count;
	public static final long MOD = 1000000007L;
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("B-small-attempt1.in"));
		PrintWriter out = new PrintWriter("bs1.out");

		int t = Integer.parseInt(in.nextLine().trim());
		
		for (int casen = 1; casen <= t; casen++) {
			out.printf("Case #%d: ", casen);
			
			int n = Integer.parseInt(in.nextLine().trim());
			
			String[] inp = new String[n];
			String[] tinp = in.nextLine().trim().split(" ");
			for (int i = 0; i < n; i++) {
				inp[i] = tinp[i].trim();
			}
			BitSet b = new BitSet();
			String[] res = new String[n];
			count = 0L;
			recurse(inp, 0, res, b);
			
			out.println(count);
			out.flush();
		}

		out.close();
		in.close();
	}

	private static void recurse(String[] inp, int cur, String[] res, BitSet b) {
		if (cur == inp.length) {
			if (valid(res)) {
				count = (count + 1) % MOD;
			}
			
			return;
		}
		
		for (int i = 0; i < inp.length; i++) {
			if (!b.get(i)) {
				res[cur] = inp[i];
				b.set(i);
				recurse(inp,cur+1,res,b);
				b.flip(i);
				res[cur] = "";
			}
		}
	}
	
	private static boolean valid(String[] arr) {
//		boolean t = false;
//		System.out.println("in");
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < arr.length; i++)
			sb.append(arr[i]);
		
		char[] a = sb.toString().toCharArray();
		int index = 0;
		
		while (index < a.length) {
			char cur = a[index];
			while (index + 1 < a.length && a[index+1] == cur) {
				index++;
			}
			index++;
			if (index != a.length) {	// not at end
				if (new String(a).indexOf(cur, index) >= 0)
					return false;
			}
//			System.out.println("working");
		}
//		System.out.println("out");
		return true;
	}

}
