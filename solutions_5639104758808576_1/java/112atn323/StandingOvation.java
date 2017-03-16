package world2015.qualification_round;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class StandingOvation {

	public int solve(int[] audience) {
		int res = 0;
		int numStandings = 0;
		for (int i=0; i<audience.length; i++) {
			if (audience[i]==0)
				continue;
			if (i>numStandings) {
				res += i-numStandings;
				numStandings = i;
			}
			numStandings += audience[i];
		}
		return res;
	}
	
	public static void main(String args[]) throws IOException {
		String inputPath = "file/world2015/qualification_round/A-large.in";
		String outputPath = inputPath.substring(0, inputPath.lastIndexOf('.')) + ".out";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));
		PrintWriter pw = new PrintWriter(outputPath);
		String line = br.readLine();
		int numProblems = Integer.parseInt(line);
		for (int i=0; i<numProblems; i++) {
			line = br.readLine().trim();
			String[] split = line.split(" ");
			int SMAX = Integer.parseInt(split[0]);
			int[] audience = new int[SMAX+1];
			for (int j=0; j<SMAX+1; j++)
				audience[j] = split[1].charAt(j)-'0';
			int res = new StandingOvation().solve(audience);
			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + (i+1) + ": " + res);
			System.out.println(sb);
			pw.println(sb);
		}
		br.close();
		pw.close();
	}
}
