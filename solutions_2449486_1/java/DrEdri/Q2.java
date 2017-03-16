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
		public int N;
		public int M;
		int[][] lawn;
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
		int [][] check = new int[p.N][p.M];
		
		//rows
		for (int i=0; i<p.N; i++) {
			//Find highest in row - you can get all those
			int rowHighest = 0;
			for (int j=0; j<p.M; j++) {
				if (p.lawn[i][j]>rowHighest) {
					rowHighest = p.lawn[i][j];
				}
			}
			for (int j=0; j<p.M; j++) {
				if (p.lawn[i][j]<rowHighest) {
					check[i][j] = 1;
				}
			}
		}

		//cols
		for (int i=0; i<p.M; i++) {
			int colHighest = 0;
			for (int j=0; j<p.N; j++) {
				if (p.lawn[j][i]>colHighest) {
					colHighest = p.lawn[j][i];
				}
			}
			for (int j=0; j<p.N; j++) {
				if (check[j][i]==1 && p.lawn[j][i]<colHighest) {
					return "NO";
				}
			}
		}
		return "YES";
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
				probs[i].M = Integer.parseInt(pieces[1]);
				probs[i].lawn = new int[probs[i].N][probs[i].M];
				line = br.readLine();
				for (int j=0; j<probs[i].N; j++) {
					pieces = line.split(" ");
					for (int k=0; k<probs[i].M; k++) {
						probs[i].lawn[j][k] = Integer.parseInt(pieces[k]);
					}
					line = br.readLine();
				}
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
