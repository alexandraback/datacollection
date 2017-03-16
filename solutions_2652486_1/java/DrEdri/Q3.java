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
		int[] primes = new int[9];
		for (int i=0; i<9; i++) {
			primes[i] = 0;
		}
		while (n>1) {
			if (n%7==0) {
				primes[7]++;
				n = n/7;
			} else if (n%5==0) {
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
		int[] primes_per_row = new int[9];
		int[] fact_of_largest = null;
		int largest = 0;
		int[] independents = new int[9];
		//for each row, tally minimum # of primes
		for (int i=0; i<p.R; i++) {
			for (int j=0; j<9; j++) {
				primes_per_row[j] = 0;
				independents[j] = 0;
			}
			for (int j=0; j<p.K; j++) {
				int[] primes = getPrimeFactorization(p.products[i][j]);
				if (p.products[i][j]==2) {
					independents[2]++;
				} else {
					if (p.products[i][j]==3) {
						independents[3]++;
					}
				}
				for (int k=0; k<9; k++) {
					if (primes[k]>primes_per_row[k]) {
						primes_per_row[k] = primes[k];
					}
				}
				if (p.products[i][j]>largest) {
					largest = p.products[i][j];
					fact_of_largest = primes;
				}
			}
//			for (int j=0; j<9; j++) {
//				System.out.println(primes_per_row[j]);
//			}
			
			int[] digits = new int[p.N];
			int index = 0;
			for (int j=0; j<primes_per_row[7]; j++) {
				digits[index] = 7;
				index++;
			}
			for (int j=0; j<primes_per_row[5]; j++) {
				digits[index] = 5;
				index++;
			}
			if (index!=p.N) {
				//2s and 3s to deal with
				//start with indeps
				int slots_left = p.N - index;
				if (independents[2]==1) {
					primes_per_row[2]--;
					digits[index] = 2;
					slots_left--;
					index++;
				}
				if (independents[3]==1) {
					primes_per_row[3]--;
					digits[index] = 3;
					slots_left--;
					index++;
				}
				
				//Check largest - want to get to with 6 digits
				int num_left_for_largest = 6;
				num_left_for_largest -= fact_of_largest[7];
				num_left_for_largest -= fact_of_largest[5];
				while (fact_of_largest[3]>0 && fact_of_largest[2]>0 && 
						fact_of_largest[3]+fact_of_largest[2]>num_left_for_largest) {
					digits[index] = 6;
					slots_left--;
					index++;
					primes_per_row[2]--;
					primes_per_row[3]--;
					fact_of_largest[3]--;
					fact_of_largest[2]--;
					num_left_for_largest--;
				}
				while (fact_of_largest[2]>2 && fact_of_largest[2]>2*num_left_for_largest) {
					//add some 8s
					digits[index] = 8;
					slots_left--;
					index++;
					primes_per_row[2] -= 3;
					fact_of_largest[2] -= 3;
				}
				
				
				//if we fill slots with 3s, can we put enough 8s in the leftovers to fill?
				int slots_after_3s = slots_left - primes_per_row[3];
				while (primes_per_row[2]>3*slots_after_3s && primes_per_row[3]>0) {
					//put in a 6
					digits[index] = 6;
					slots_left--;
					index++;
					primes_per_row[2]--;
					primes_per_row[3]--;
				}
				
				//Finish with half 6, half 3s if you can
				while (primes_per_row[2]>0 && primes_per_row[3]>1) {
					//put in a 6
					digits[index] = 6;
					slots_left--;
					index++;
					primes_per_row[2]--;
					primes_per_row[3]--;
					//then a 3
					digits[index] = 3;
					slots_left--;
					index++;
					primes_per_row[3]--;
				}
				
				for (int j=0; j<primes_per_row[3]; j++) {
					digits[index] = 3;
					slots_left--;
					index++;
				}
				
				//any needed 8s
				while (primes_per_row[2]>2*slots_left) {
					primes_per_row[2] -= 3;
					digits[index] = 8;
					slots_left--;
					index++;
				}
				//alternate 1 8, 2 4s, 1 2
				while (primes_per_row[2]>7 && slots_left>3) {
					primes_per_row[2] -= 3;
					digits[index] = 8;
					slots_left--;
					index++;
					primes_per_row[2] -= 2;
					digits[index] = 4;
					slots_left--;
					index++;
					primes_per_row[2] -= 2;
					digits[index] = 4;
					slots_left--;
					index++;
					primes_per_row[2] -= 1;
					digits[index] = 2;
					slots_left--;
					index++;
				}
				
				//need 4s?
				while (primes_per_row[2]>slots_left) {
					primes_per_row[2] -= 2;
					digits[index] = 4;
					slots_left--;
					index++;
				}
				//finish with 2s
				for (int j=0; j<primes_per_row[2]; j++) {
					digits[index] = 2;
					index++;
				}
			}
			if (index!=p.N) {
				//fill undefined with 2s
				for (int j = index; j<p.N; j++) {
					digits[j] = 2;
				}
			}
			System.out.println(i + ":");
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
