import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Q1 {
	public static Problem[] probs;

	static class Problem {
		public long r;
		public long t;
	}
				
	
	public static void main(String[] args) {
		String inputFile = args[0];
		parseFile(inputFile);
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(inputFile + ".out"));
			for (int i=0; i<probs.length; i++) {
				String output = solveProblem(probs[i]);
				System.out.println(output);
				bw.write("Case #" + (i+1) + ": " + output + "\n");
			}
			bw.flush();
			bw.close();
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}
			
	private static String solveProblem(Problem p) {
		long neg_b = -1*(2*p.r-1);
//		long det = (2*p.r-1)*(2*p.r-1)+8*p.t;
//		System.out.println(det);
//		System.out.println(Math.sqrt(det));
//		System.out.println(Math.sqrt(det)+neg_b);
//		System.out.println((Math.sqrt(det)+neg_b)/4.0);
//		return "" + (long)(Math.floor((double)(neg_b + Math.sqrt(det))/(4.0)));
//		long neg_b = -2*p.r-1;
		double sqrt1 = Math.sqrt(2*p.r-1);
		double sqrt2 = Math.sqrt(2*p.r-1 + ((double)p.t*8.0)/((double)(2*p.r-1)));
		System.out.println(sqrt1*sqrt2);
		double tmp = -2.0*(double)(p.r) + sqrt1*sqrt2;
		System.out.println(tmp);
		long guess_n = (long)(Math.floor((tmp + 1)/4.0));
		if (guess_n<0) {
			guess_n = 0;
		}
		long tot = 2*p.r*guess_n + 2*guess_n*guess_n - guess_n;

		while (tot<=p.t) {
			guess_n++;
			tot = 2*p.r*guess_n + 2*guess_n*guess_n - guess_n;
		}
		return "" + (guess_n-1);
	}

	public static void parseFile(String inputFile) {
		BufferedReader br;
		try {
			br = new BufferedReader(new FileReader(inputFile));
			String line = br.readLine();
			probs = new Problem[Integer.parseInt(line)];
			line = br.readLine();
			for (int i=0; i<probs.length; i++) {
				probs[i] = new Problem();
				String[] pieces = line.split(" ");
				probs[i].r = Long.parseLong(pieces[0]);
				probs[i].t = Long.parseLong(pieces[1]);
				line = br.readLine();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
