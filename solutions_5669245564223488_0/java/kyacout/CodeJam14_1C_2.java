import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.io.PrintWriter;


public class CodeJam14_1C_2 {
	private static String[] line;
	private static int n;
	private static int counter;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new File("output2"));
		int t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			n = Integer.parseInt(br.readLine());
			line = br.readLine().split("\\s+");
			counter = 0;
			
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = i;
			
			permutations(a, new int[n], 0, new boolean[n]);
			out.print("Case #" + tc + ": ");
			out.println(counter);
		}
		out.close();
	}
	
	static void permutations(int[] a, int[] ans, int p, boolean[] v) {
		if (p == a.length) {
			boolean f = true, finish = false;
			boolean[] chars = new boolean['z' - 'a' + 1];
			char cur = line[ans[0]].charAt(0);
			chars[cur - 'a'] = true;
			
			for (int i = 0; i < ans.length; i++) {
				int c = ans[i];
				for (int j = 0; j < line[c].length(); j++) {
					if (line[c].charAt(j) != cur) {
						if (chars[line[c].charAt(j) - 'a'] == true) {
							f = false;
							finish = true;
							break;
						} else {
							cur = line[ans[i]].charAt(j);
							chars[cur - 'a'] = true;
						}
					}
				}
				if (finish)
					break;
			}
			if (f)
				counter++;
		}
		
		for (int i = 0; i < a.length; i++) {
			 if (v[i])
				 continue;
			 
			 ans[p] = a[i];
			 v[i] = true;
			 permutations(a, ans, p + 1, v);
			 v[i] = false;
		}
	}
}
