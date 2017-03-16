import java.io.*;

public class Solution {
	public static void main(String[] args) throws IOException {
		StreamTokenizer in = new StreamTokenizer(new BufferedReader (new FileReader("input.in")));
		PrintWriter out = new PrintWriter(new File("output.out"));
		
		in.nextToken();
		int t = (int)in.nval;
		for (int i = 0; i<t; i++){
			out.print("Case #" + (i+1) + ": ");
			in.nextToken();
			int n = (int)in.nval;
			in.nextToken();
			int s = (int)in.nval;
			in.nextToken();
			int p = (int)in.nval;
			int[] points = new int[n];
			int ans = 0;
			for (int j = 0; j<n; j++){
				in.nextToken();
				points[j] = (int)in.nval;
				int ost = points[j]%3;
				if (ost == 0) ans += (points[j]/3 >= p) ? 1 : 0;
				else ans += (points[j]/3+1 >= p) ? 1 : 0;
			}
			for (int j = 0; j<n && s>0; j++){
				if (points[j]<2 || points[j]>28) continue;
				int ost = points[j]%3;
				if (ost != 1) {
					int current = points[j]/3;
					if (ost == 2) current++;
					if (current == p-1) {
						s--;
						ans++;
					}
				}
			}
			out.println(ans);
		}
		out.close();
	}
}
