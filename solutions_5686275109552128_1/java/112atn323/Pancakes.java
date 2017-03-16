package world2015.qualification_round;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.TreeMap;

public class Pancakes {

	public int solve(int[] P) {
		TreeMap<Integer, Integer> ps = new TreeMap<>();
		for (int i=0; i<P.length; i++) {
			Integer cnt = ps.get(P[i]);
			if (cnt==null)
				cnt = new Integer(0);
			ps.put(P[i], cnt+1);
		}
		int max = ps.lastKey();
		int res = max;
		for (int p=1; p<max-1; p++) {
			int cnt = 0;
			for (int pp : ps.keySet()) {
				if (pp<=p)
					continue;
				cnt += ((pp-1)/p)*ps.get(pp);
			}
			res = Math.min(res, cnt+p);
		}
		return res;
	}
	
	public static void main(String args[]) throws IOException {
		String inputPath = "file/world2015/qualification_round/B-large.in";
		String outputPath = inputPath.substring(0, inputPath.lastIndexOf('.')) + ".out";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));
		PrintWriter pw = new PrintWriter(outputPath);
		String line = br.readLine();
		int numProblems = Integer.parseInt(line);
		for (int i=0; i<numProblems; i++) {
			line = br.readLine().trim();
			int D = Integer.parseInt(line);
			int[] P = new int[D];
			line = br.readLine().trim();
			String[] tokens = line.split(" ");
			for (int j=0; j<D; j++)
				P[j] = Integer.parseInt(tokens[j]);
			int res = new Pancakes().solve(P);
			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + (i+1) + ": " + res);
			System.out.println(sb);
			pw.println(sb);
		}
		br.close();
		pw.close();
	}
}
