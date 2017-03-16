package spikemf.googlecodejam.rounds;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.FileWriter;
import java.io.BufferedWriter;


public class QB {
	static String infilename = "B-large.in";
	static String outfilename = "qb.out";
	static BufferedWriter out;
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new FileReader(infilename));
		int cases = Integer.parseInt(br.readLine());
		for (int i=0;i<cases;i++) {
			handleLine(br.readLine());
		}
		br.close();
		if (out != null) out.close();
	}
	static int caseNumber = 1;
	public static void writeLine(String line) throws IOException {
		if (out == null) {
			out = new BufferedWriter(new FileWriter(outfilename));
		}
		if (line == null) return;
		line = line.trim();
		if (line == "") return;
		out.write("Case #" + (caseNumber++) + ": ");
		out.write(line);
		out.write("\n");
	}
	public static void handleLine(String line) throws IOException {
		String[] strings = line.split(" ");
		double C = Double.parseDouble(strings[0]);
		double F = Double.parseDouble(strings[1]);
		double X = Double.parseDouble(strings[2]);
		
		double currentRate = 2.0;
		double curTime = 0;
		while(true) {
			double timeOfNextFarm = curTime + (C/(currentRate));
			double timeWithNextFarm = timeOfNextFarm + (X/(currentRate + F));
			double timeWithoutNextFarm = curTime + (X/currentRate);
			if (timeWithNextFarm >= timeWithoutNextFarm) {
				curTime = timeWithoutNextFarm; break;
			} else {
				curTime = timeOfNextFarm;
				currentRate += F;
			}
		}
		
		writeLine("" + curTime);
	}
}
