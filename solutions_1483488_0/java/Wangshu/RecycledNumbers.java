import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;


public class RecycledNumbers {

	static final String input_path = "data/input.c.txt";
	
	private static Set<String> ans = new HashSet<String>();
	
	private static Integer[] getBits(int n) {
		List<Integer> lst = new ArrayList<Integer>();
		while (n != 0) {
			lst.add(n % 10);
			n /= 10;
		}
		
		Integer ans[] = new Integer[lst.size()];
		return lst.toArray(ans);
	}
	
	private static int getInteger(Integer[] bits) {
		int ans = 0;
		int power = 1;
		
		for (int i = 0; i < bits.length; i ++) {
			ans += power * bits[i];
			power *= 10;
		}
		
		return ans;
	}
	
	private static int judge(int n, int b) {
		Integer[] bits = getBits(n);
		if (bits.length == 1)
			return 0;
		int ret = 0;
		
		int len = bits.length;
		for (int pos = 0; pos < len - 1; pos ++) {
			if (bits[pos] == 0)
				continue;
			int new_bits_len = 0;
			Integer[] new_bits = new Integer[len];
			for (int i = pos + 1; i < len; i++) 
				new_bits[new_bits_len ++] = bits[i];
			for (int i = 0; i <= pos; i++) 
				new_bits[new_bits_len ++] = bits[i];
			int new_int = getInteger(new_bits);
			if (new_int <= b && new_int > n) {
				String ans_str = String.format("%d_%d", n, new_int);
				if (!ans.contains(ans_str))
					ans.add(ans_str);
				ret += 1;
			}
				
		}
		return ret;
	}
	
	private static int solve(int a, int b) {
		if (a == b)
			return 0;
		for (int i = a; i < b; i ++) {
			int tmp = judge(i, b);
		}
		return ans.size();
	}
	
	/**
	 * Good luck, Wash!
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(input_path)); 
		String intext = in.readLine();
		int T = Integer.parseInt(intext);
		for (int caseIter = 0; caseIter < T; caseIter ++) {
			intext = in.readLine();
			System.out.print(String.format("Case #%d: ", caseIter + 1));
			
			String[] parts = intext.split(" ");
			int A = Integer.parseInt(parts[0]);
			int B = Integer.parseInt(parts[1]);
			
			System.out.println(solve(A, B));
			ans.clear();
		}
		in.close();
	}
}
