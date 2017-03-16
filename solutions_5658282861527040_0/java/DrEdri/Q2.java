import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Q2 {
	public static Problem[] probs;

	static class Problem {
		public int A;
		public int B;
		public int K;
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
			
	private static String solveSmall(Problem p) {
		int wins = 0;
		for (int i=0; i<p.A; i++) {
			for (int j=0; j<p.B; j++) {
				int winning = i&j;
				if (winning<p.K) {
					wins++;
				}
			}
		}
		return "" + wins;
	}
	
	private static String solveProblem(Problem p) {
		return solveSmall(p);
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
				probs[i].A = Integer.parseInt(pieces[0]);
				probs[i].B = Integer.parseInt(pieces[1]);
				probs[i].K = Integer.parseInt(pieces[2]);
				line = br.readLine();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}