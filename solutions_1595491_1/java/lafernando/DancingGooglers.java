
public class DancingGooglers {

	private static int sc;

	private static int result = 0;
	
	private static int p;
	
	private static void check(int val) {
		int x = val % 3;
		int n = val / 3;
		if (x == 0) {
			if (n >= p) {
				result++;
			} else if (n > 0 && sc > 0 && n + 1 >= p) {
				result++;
				sc--;
			}
		} else {
			if (n + 1 >= p) {
				result++;
			} else if (x == 2 && n + 2 >= p && sc > 0) {
				result++;
				sc--;
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		String[] in = ProblemUtils.readInput("/home/laf/Downloads/B-large.in");
		String[] out = new String[in.length];
		for (int i = 0; i < in.length; i++) {
			String[] vals = in[i].split(" ");
			int n = Integer.parseInt(vals[0]);
			sc = Integer.parseInt(vals[1]);
			p = Integer.parseInt(vals[2]);
			result = 0;
			for (int j = 3; j < 3 + n; j++) {
				check(Integer.parseInt(vals[j]));
				out[i] = "" + result;
			}
		}
		ProblemUtils.writeOutput("/home/laf/Desktop/out.txt", out);
	}
	
}
