import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class SafetyInNumbers {

	public static void main(String[] args) throws Exception{
		char problem = 'A';
		boolean smallCase = false;
		boolean practice = false;
		BufferedReader br = new BufferedReader(new FileReader(problem + "-" + (smallCase ? "small" : "large") + (practice ? "-practice" : "") + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(problem + "-" + (smallCase ? "small" : "large") + (practice ? "-practice" : "") + ".out"));
		int t = Integer.parseInt(br.readLine());
		for(int i = 1; i <= t; i++) {
			out.println("Case #" + i + ": " + solve(br.readLine()));
		}
		out.close();
		System.exit(0);
	}

	public static String solve(String in) {
		StringTokenizer st = new StringTokenizer(in);
		int n = Integer.parseInt(st.nextToken());
		Contestant[] cons = new Contestant[n];
		int tot = 0;
		double[] out = new double[n];
		for(int i = 0; i < n; i++) {
			cons[i] = new Contestant(i, Integer.parseInt(st.nextToken()));
			tot += cons[i].judgeScore;
		}
		for(Contestant c : cons) c.judgeScore /= tot;
		Arrays.sort(cons);
		double pointsLeft = 2;
		int autoWin = 0;
		for(; autoWin < n; autoWin++) {
			if(cons[autoWin].judgeScore >= pointsLeft / (n - autoWin)) pointsLeft -= cons[autoWin].judgeScore;
			else break;
		}
		pointsLeft /= (n - autoWin);
		for(; autoWin < n; autoWin++) {
			out[cons[autoWin].num] = pointsLeft - cons[autoWin].judgeScore;
		}
		String output = "";
		for(double i : out) output = output + (i * 100) + " ";
		return output;
	}
	
	static class Contestant implements Comparable<Contestant>{
		public int num;
		public double judgeScore;
		
		public Contestant(int num, double score) {
			this.num = num;
			this.judgeScore = score;
		}

		@Override
		public int compareTo(Contestant arg0) {
			return (this.judgeScore > arg0.judgeScore) ? -1 : 1;
		}
		
		
	}

}
