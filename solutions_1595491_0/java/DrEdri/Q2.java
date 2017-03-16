import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Q2 {
	public static Problem[] probs;

	static class Problem {
		public int N;
		public int S;
		public int p;
		public int[] t;
	}
			
	public static void main(String[] args) {
		String inputFile = args[0];
		parseFile(inputFile);
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(inputFile + ".out"));
			for (int i=0; i<probs.length; i++) {
				String output = solveProblem(probs[i]);
				bw.write("Case #" + (i+1) + ": " + output + "\n");
			}
			bw.flush();
			bw.close();
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}
			
	private static String solveProblem(Problem p) {
		int count = 0;
		if (p.p==0) {
			count = p.N;
		} else if (p.p==1) {
			for (int i=0; i<p.N; i++) {
				if (p.t[i]>0) {
					count++;
				}
			}
		} else {
			int minWithS = 3*p.p-4;
			int min = 3*p.p-2;
			int maybe = 0;
			for (int i=0; i<p.N; i++) {
				if (p.t[i]>=min) {
					count++;
				} else if (p.t[i]>=minWithS) {
					maybe++;
				}
			}
			count += Math.min(maybe, p.S);
		}
		return "" + count;
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
				probs[i].N = Integer.parseInt(pieces[0]);
				probs[i].S = Integer.parseInt(pieces[1]);
				probs[i].p = Integer.parseInt(pieces[2]);
				probs[i].t = new int[probs[i].N];
				for (int j=0; j<probs[i].N; j++) {
					probs[i].t[j] = Integer.parseInt(pieces[3+j]);
				}
				line = br.readLine();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
