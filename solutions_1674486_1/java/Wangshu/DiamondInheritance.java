import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

public class DiamondInheritance {

	static final String input_path = "data/input.txt";
		
	/**
	 * Good luck, Wash :)
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(input_path)); 
		String intext = in.readLine();
		int T = Integer.parseInt(intext);
		for (int caseIter = 0; caseIter < T; caseIter ++) {
			intext = in.readLine();
			int N = Integer.parseInt(intext);
			int[][] inherits = new int[N][];
			for (int i = 0; i < N; i ++) {
				intext = in.readLine();
				String[] parts = intext.split(" ");
				int M = Integer.parseInt(parts[0]);
				inherits[i] = new int[M];
				for (int j = 0; j < M ; j ++) 
					inherits[i][j] = Integer.parseInt(parts[j + 1]) - 1;
			}
			
			if (solve(inherits))
				System.out.println(String.format("Case #%d: Yes", caseIter + 1));
			else 
				System.out.println(String.format("Case #%d: No", caseIter + 1));
		}
		in.close();
	}

	private static boolean solve(int[][] inherits) {
		int N = inherits.length;
		for (int i = 0; i < N; i ++) {
			Set<Integer> current = new HashSet<Integer>();
			Set<Integer> expand = new HashSet<Integer>();
			expand.add(i);
			while (true) {
				Set<Integer> new_expand = new HashSet<Integer>();
				boolean flag = false;
				for (Integer e : expand) {
					int M = inherits[e].length;
					for (int j = 0; j < M; j ++)
						if (current.contains(inherits[e][j]))
							return true;
						else {
							if (inherits[e][j] == i)
								continue;
							new_expand.add(inherits[e][j]);
							flag = true;
							current.add(inherits[e][j]);
						}
				}
				expand = new_expand;
				if (!flag)
					break;
			}
		}
		return false;
	}
}
