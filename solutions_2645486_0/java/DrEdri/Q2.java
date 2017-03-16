import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Q2 {
	public static Problem[] probs;

	static class Problem {
		public int E;
		public int R;
		public int N;
		public int[] v;
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
		int best_act_index = -1;
		int best_imp = -1;
		for (int i=0; i<p.N; i++) {
			if (p.v[i]>best_imp) {
				best_imp = p.v[i];
				best_act_index = i;
			}
		}
		//want most energy for this
		int[] expend = new int[p.N];

		int energy = p.E;
		for (int i=0; i<p.N; i++) {
			if (energy>p.E) {
				energy = p.E;
			}
			//always spend R
			expend[i] = p.R;
			//if the next isn't better, spend R+1
			if (i==p.N-1) {
				expend[i] = energy;
				energy = p.R;
			} else if (i==best_act_index) {
				expend[i] = energy;
				energy = p.R;
			} else if (p.v[i]>p.v[i+1] && energy>=1) {
				expend[i] = Math.min(p.E, p.R + 1);
				energy += p.R-1;
			} else if (p.v[i]<p.v[i+1] && energy<p.E) {
				expend[i] = Math.max(p.R - 1, 0);
				energy += p.R+1;
			}
		}
		
		int tot_gain = 0;
		for (int i=0; i<p.N; i++) {
			System.out.println(expend[i]);
			tot_gain += expend[i]*p.v[i];
		}
		
		return "" + tot_gain;
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
				probs[i].E = Integer.parseInt(pieces[0]);
				probs[i].R = Integer.parseInt(pieces[1]);
				probs[i].N = Integer.parseInt(pieces[2]);
				line = br.readLine();
				probs[i].v = new int[probs[i].N];
				for (int j=0; j<probs[i].N; j++) {
					pieces = line.split(" ");
					probs[i].v[j] = Integer.parseInt(pieces[j]);
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
