import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;


public class CookieClicker {
	
	static String infile = "G:/Dev/workspace/CodeJam14/ProblemB/input.in", outfile = "G:/Dev/workspace/CodeJam14/ProblemB/output.out";
	static String prefix = "Case #";
	static BufferedReader br;
	static BufferedWriter bw;
	
	static DecimalFormat df = new DecimalFormat("#.#######");
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(infile));
		bw = new BufferedWriter(new FileWriter(outfile));
		solve();
		bw.flush();
		bw.close();
		br.close();
	}
	
	static void solve() throws IOException {
		int T = Integer.parseInt(getNextLine());
		for(int i=1;i<=T;i++) {
			double currRate = 2.0, time = 0.0;
			String[] next = getNextLine().split(" ");
			double C = Double.parseDouble(next[0]), F = Double.parseDouble(next[1]), X = Double.parseDouble(next[2]);
			while(X>0) {
				double time1 = X/currRate;
				double acqTime = C/currRate, time2 = acqTime + (X/(currRate+F));
				if(time1<time2) {
					time += time1;
					break;
				} else {
					time += acqTime;
					currRate += F;
				}
			}
			writeLine(prefix + i + ": " + df.format(time));
		}
	}

	static void writeLine(String next) throws IOException {
		bw.write(next);
		bw.write("\n");
	}
	
	static String getNextLine() throws IOException {
		String next = br.readLine();
		if(next==null) return null;
 		while(next!=null && next.trim().isEmpty()) {
			next = br.readLine();
		}
 		return next;
	}
}
