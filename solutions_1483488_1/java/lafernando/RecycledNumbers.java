import java.util.HashSet;
import java.util.Set;


public class RecycledNumbers {
		
	private static int doit(int n, int low) {
		Set<Integer> result = new HashSet<Integer>();
		String val = "" + n;
		int tmpN;
		for (int i = 1; i < val.length(); i++) {
			tmpN = Integer.parseInt(val.substring(i) + val.substring(0, i));
			if (tmpN >= low && tmpN < n && (String.valueOf(tmpN).length() == String.valueOf(n).length())) {
				result.add(tmpN);
			}
		}
		return result.size();
	}
	
	private static int solve(int a, int b) {
		int result = 0;
		for (int i = a; i <= b; i++) {
			result += doit(i, a);
		}
		return result;
	}
	
	public static void main(String[] args) throws Exception {
		String[] in = ProblemUtils.readInput("/home/laf/Downloads/C-large.in");
		//String[] in = ProblemUtils.readInput("/home/laf/Desktop/in.txt");
		String[] out = new String[in.length];
		String[] tokens;
		for (int i = 0; i < out.length; i++) {
			tokens = in[i].split(" ");
			out[i] = "" + solve(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]));
		}
		ProblemUtils.writeOutput("/home/laf/Desktop/out.txt", out);
	}
	
}
