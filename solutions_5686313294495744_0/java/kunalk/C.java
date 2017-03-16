import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class C {

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("C-small-attempt0.in"));
		PrintWriter out = new PrintWriter("C-small-attempt0.out");

		int T = Integer.parseInt(in.nextLine());
		for (int cn = 1; cn <= T; cn++) {
			int n = Integer.parseInt(in.nextLine());
			TreeMap<String, Integer> left = new TreeMap<>();
			TreeMap<String, Integer> right = new TreeMap<>();
			for (int i = 0; i < n; i++) {
				String l = in.next().trim(), r = in.nextLine().trim(); 
				if (!left.containsKey(l))
					left.put(l, 0);
				if (!right.containsKey(r))
					right.put(r, 0);
				left.put(l, left.get(l) + 1);
				right.put(r, right.get(r) + 1);
			}
			int cl = 0, cr = 0;
			for (Map.Entry<String, Integer> e : left.entrySet()) {
				cl += e.getValue().intValue() - 1;
			}
			for (Map.Entry<String, Integer> e : right.entrySet()) {
				cr += e.getValue().intValue() - 1;
			}
			out.printf("Case #%d: %d\n", cn, Math.min(cl, cr));
		}
		
		out.close();
		in.close();
	}

}
