import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class B {
	
	static int worstCase = 0;
	static long all = 0;
	static long countAll = 0;
	
	static void check(char[] target, char[] cur) {
		String curStr = new String(cur);
		String targetStr = new String(target);
	    int count = 0;
	    for (int i = 0; i <= cur.length - target.length; i++) {
	    	if (targetStr.equals(curStr.subSequence(i, i + target.length))) {
	    		count++;
	    	}
	    }
	    
	    worstCase = Math.max(worstCase, count);
	    all += count;
	    countAll++;
	}
	
	
	static void solve(int k, int l, int s, char[] keys, char[] target, char[] cur) {
		
		if (cur[s - 1] > 0) {
//			System.out.println(Arrays.toString(cur));
			check(target, cur);
			return;
		}
		int last = 0;
		for (int i = 0; i < cur.length; i++) {
			if (cur[i] == 0) {
				last = i;
				break;
			}
		}
		for (int i = 0; i < keys.length; i++) {
			cur[last] = keys[i];
			solve(k, l, s, keys, target, cur);
		}
		cur[last] = 0;
	}

	public static void main(String[] args) throws IOException {
//		BufferedReader in = new BufferedReader(new FileReader("B-large.in"));
		BufferedReader in = new BufferedReader(new FileReader("B-small-attempt0.in"));
//		BufferedReader in = new BufferedReader(new FileReader("b_test.in"));
		PrintWriter pw = new PrintWriter(System.out);
		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			String[] kls = in.readLine().split(" ");
			int k = Integer.parseInt(kls[0]);
			int l = Integer.parseInt(kls[1]);
			int s = Integer.parseInt(kls[2]);
			worstCase = 0;
			all = 0;
			countAll = 0;
			
			char[] keyboard = in.readLine().toCharArray();
			char[] target = in.readLine().toCharArray();
			
			solve(k, l, s, keyboard, target, new char[s]);
			double diff = worstCase;
			diff -= ((double) all) / countAll;
//			System.out.println("wc = " + worstCase + " all = " + all + " count = " + countAll);
			pw.format("Case #%d: %.7f\n", t, diff);
			pw.flush();
		}
		pw.close();
		in.close();
	}

}
