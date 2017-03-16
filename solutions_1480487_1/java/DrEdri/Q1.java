import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Q1 {
	public static Problem[] probs;

	static class Problem {
		public int N;
		public int[] scores;
		public int sum;
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
		double[] neededPercents = new double[p.N];
		StringBuffer returnString = new StringBuffer("");
		int netCount = p.N;
		double max = 100.0;
		for (int i=0; i<p.N; i++) {
			if (((double)p.scores[i]*100.0)/(2*p.sum)>100.0/p.N) {
				netCount--;
				max -= ((double)p.scores[i]*100.0)/(2*p.sum);
				neededPercents[i] = 0.0;
				p.scores[i] = -1;
			}
		}
		
		//2nd pass
		for (int i=0; i<p.N; i++) {
			if (p.scores[i]==-1) {
				continue;
			}
			neededPercents[i] = (max/netCount - ((double)p.scores[i]*100.0)/(2*p.sum)) * 2.0;
		}

		for (int i=0; i<p.N; i++) {
			returnString.append(neededPercents[i] + " ");
		}
		
		return returnString.toString();
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
				probs[i].scores = new int[probs[i].N];
				probs[i].sum = 0;
				for (int j=0; j<probs[i].N; j++) {
					probs[i].scores[j] = Integer.parseInt(pieces[j+1]);
					probs[i].sum += probs[i].scores[j];
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
