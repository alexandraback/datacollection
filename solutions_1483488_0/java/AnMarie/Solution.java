import java.io.*;
import java.util.HashSet;

public class Solution {
	public static void main(String[] args) throws IOException {
		StreamTokenizer in = new StreamTokenizer(new BufferedReader (new FileReader("input.in")));
		PrintWriter out = new PrintWriter(new File("output.out"));
		
		in.nextToken();
		int t = (int)in.nval;
		for (int i = 0; i<t; i++){
			out.print("Case #" + (i+1) + ": ");
			int ans = 0;
			in.nextToken();
			int a = (int)in.nval;
			in.nextToken();
			int b = (int)in.nval;
			for (int j = a; j<=b; j++){
				int n = j;
				HashSet<Integer> set = new HashSet<Integer>();
				StringBuilder sN = new StringBuilder((new Integer(j)).toString());
				for (int k = 0; k<sN.length()-1; k++){
					sN.insert(0, sN.charAt(sN.length()-1));
					sN.deleteCharAt(sN.length()-1);
					if (sN.charAt(0) != '0') {
						int m = Integer.valueOf(sN.toString());
						if (n<m && m>=a && m<=b && !set.contains(new Integer(m))) {
							ans++;
							set.add(m);
						}
					}
				}
			}
			out.println(ans);
		}
		out.close();
	}
}
