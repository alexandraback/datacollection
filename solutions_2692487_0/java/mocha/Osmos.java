import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class Osmos {
	public static int fun(int a, List<Integer> ms, int p) {
		if (p >= ms.size()) {
			return 0;
		}
		
		int first = ms.get(p);
		if (a > first) {
			return fun(a + first, ms, p + 1);
		} else if (first < 2 * a - 1) {
			return 1 + fun(2 * a - 1 + first, ms, p + 1);			
		} else if (a == 1) {
			return 1 + fun(a, ms, p + 1);
		} else {
			int min = 1 + fun(a, ms, p + 1);
			
			int min1 = 1 + fun(2 * a - 1, ms, p);
			
			return Math.min(min, min1);
			
		}
	}
	
	public static void main(String[] args) throws IOException {
		String filename = args[0];
		BufferedReader in = new BufferedReader(new FileReader(filename));

		PrintStream out = new PrintStream(filename + ".out");

		int stages = Integer.parseInt(in.readLine());
		
		for (int stage = 1; stage <= stages; ++stage) {
			String[] tokens;
			
			tokens = in.readLine().split("\\s+");
			int A = Integer.parseInt(tokens[0]);
			int N = Integer.parseInt(tokens[1]);
			
			List<Integer> ms = new ArrayList();
			tokens = in.readLine().split("\\s+");
			for (String m : tokens) {
				ms.add(Integer.parseInt(m));
			}
			
			Collections.sort(ms);
			out.printf("Case #%d: %d\n", stage, fun(A, ms, 0));
		}
	}

}
