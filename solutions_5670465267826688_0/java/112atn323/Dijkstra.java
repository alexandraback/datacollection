package world2015.qualification_round;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Dijkstra {

	private static final int[][] TABLE = {
		{0, 0, 0, 0, 0},
		{0, 1, 2, 3, 4},
		{0, 2, -1, 4, -3},
		{0, 3, -4, -1, 2},
		{0, 4, 3, -2, -1}
	};
	
	public String solve(String str, long n) {
		long offset = 0;
		offset = create(2, str, n, offset);
		if (offset<0)
			return "NO";
		offset = create(3, str, n, offset);
		if (offset<0)
			return "NO";
		offset = create(4, str, n, offset);
		if (offset<0)
			return "NO";
		if (offset==str.length()*n)
			return "YES";
		while (offset%str.length()!=0) {
			offset = create(1, str, n, offset);
			if (offset<0)
				return "NO";
		}
		if (offset==str.length()*n)
			return "YES";
		long offset2 = offset;
		do {
			offset2 = create(1, str, n, offset2);
			if (offset2<0)
				return "NO";
		} while (offset2%str.length()!=0);
		if ((n*str.length()-offset)%(offset2-offset)==0)
			return "YES";
		else
			return "NO";
	}
	
	private int multiply(int a, int b) {
		int code = a*b<0 ? -1 : 1;
		a = Math.abs(a); b = Math.abs(b);
		return code*TABLE[a][b];
	}
	
	private long create(int target, String str, long n, long offset) {
		if (offset>n*str.length())
			return -1;
		else if (offset==n*str.length()) {
			if (target==1)
				return offset;
			else
				return -1;
		}
		n--;
		n -= offset/str.length();
		long res = offset;
		int idx = (int)(offset%str.length());
		int cur = 1;
		boolean[] used = new boolean[9];
		if (offset==0)
			used[cur+4] = true;
		while (idx<str.length()) {
			res++;
			cur = multiply(cur, str.charAt(idx)-'i'+2);
			if (cur==target)
				break;
			idx++;
			if (idx==str.length() && n>0 && !used[cur+4]) {
				idx = 0;
				n--;
				used[cur+4] = true;
			}
		}
		if (cur==target)
			return res;
		else
			return -1;
	}
	
	public static void main(String args[]) throws IOException {
		String inputPath = "file/world2015/qualification_round/C-small-attempt2.in";
		String outputPath = inputPath.substring(0, inputPath.lastIndexOf('.')) + ".out";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));
		PrintWriter pw = new PrintWriter(outputPath);
		String line = br.readLine();
		int numProblems = Integer.parseInt(line);
		for (int i=0; i<numProblems; i++) {
			line = br.readLine().trim();
			String[] tokens = line.split(" ");
			long n = Long.parseLong(tokens[1]);
			String str = br.readLine().trim();
			String res = new Dijkstra().solve(str, n);
			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + (i+1) + ": " + res);
			System.out.println(sb);
			pw.println(sb);
		}
		br.close();
		pw.close();
	}
}
