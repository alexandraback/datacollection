import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Q3 {
	public static Problem[] probs;

	static class Problem {
		public int R;
		public int N;
		public int M;
		public int K;
		int[][] products;
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
			
	private static int[] getPrimeFactorization(int n) {
		int[] primes = new int[6];
		for (int i=0; i<6; i++) {
			primes[i] = 0;
		}
		while (n>1) {
			if (n%5==0) {
				primes[5]++;
				n = n/5;
			} else if (n%3==0) {
				primes[3]++;
				n = n/3;
			} else if (n%2==0) {
				primes[2]++;
				n = n/2;
			}
		}
		return primes;
	}
	
	private static String solveProblem(Problem p) {
		StringBuffer response = new StringBuffer("\n");
		int[] primes_per_row = new int[6];
		//for each row, tally minimum # of primes
		for (int i=0; i<p.R; i++) {
			for (int j=0; j<6; j++) {
				primes_per_row[j] = 0;
			}
			for (int j=0; j<p.K; j++) {
				int[] primes = getPrimeFactorization(p.products[i][j]);
				for (int k=0; k<6; k++) {
					if (primes[k]>primes_per_row[k]) {
						primes_per_row[k] = primes[k];
					}
				}
			}
			int[] digits = new int[p.N];
			int index = 0;
			for (int j=0; j<primes_per_row[5]; j++) {
				digits[index] = 5;
				index++;
			}
			for (int j=0; j<primes_per_row[3]; j++) {
				digits[index] = 3;
				index++;
			}
			if (index!=p.N) {
				//2s to deal with
				//At this point, take 4s until just 2s left
				int slots_left = p.N - index;
				while (primes_per_row[2]>slots_left) {
					primes_per_row[2] -= 2;
					digits[index] = 4;
					slots_left--;
					index++;
				}
				for (int j=0; j<primes_per_row[2]; j++) {
					digits[index] = 2;
					index++;
				}
			}
			if (index!=p.N) {
				//fill with 2s
				for (int j = index; j<p.N; j++) {
					digits[j] = 2;
				}
			}
			for (int j=0; j<p.N; j++) {
				System.out.print(digits[j]);
				response.append(digits[j]);
			}
			response.append("\n");
			System.out.println();
		}
		return response.toString();
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
				probs[i].R = Integer.parseInt(pieces[0]);
				probs[i].N = Integer.parseInt(pieces[1]);
				probs[i].M = Integer.parseInt(pieces[2]);
				probs[i].K = Integer.parseInt(pieces[3]);
				probs[i].products = new int[probs[i].R][probs[i].K];
				line = br.readLine();
				for (int j=0; j<probs[i].R; j++) {
					pieces = line.split(" ");
					for (int k=0; k<probs[i].K; k++) {
						probs[i].products[j][k] = Integer.parseInt(pieces[k]);
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
