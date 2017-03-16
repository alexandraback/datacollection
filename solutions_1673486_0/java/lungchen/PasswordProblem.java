import java.io.*;

public class PasswordProblem {
	private static final String IN_FILE = "A-small.in";
	private static final String OUT_FILE = "A-small_output.txt";
	
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(IN_FILE));
			BufferedWriter bw = new BufferedWriter(new FileWriter(OUT_FILE));
			String line = br.readLine();
			final int T_CASES = Integer.parseInt(line);
			
			for (int t = 1; t <= T_CASES; t++) {
				line = br.readLine();
				String parts[] = line.split(" ");
				final int A = Integer.parseInt(parts[0]);
				final int B = Integer.parseInt(parts[1]);
				
				line = br.readLine();
				parts = line.split(" ");
				double[] probabilities = new double[A];
				for (int i = 0; i < A; i++) {
					probabilities[i] = Double.parseDouble(parts[i]);
				}
								
				double result = processCase(A, B, probabilities);
				bw.write("Case #" + t + ": " + result);
				bw.newLine();
			}
			
			bw.close();
			br.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static double processCase(int a, int b, double[] probabilities) {
		double expectations[] = new double[a + 1];
		double allCorrectProbability = 1.0;
		
		//expectations[0] = a + b + 1 + (b + 1) * (1.0 - probabilities[0]);
		expectations[0] = a + b + 1;
		double minExpectation = expectations[0];
		for (int i = 1; i < a + 1; i++) {
			expectations[i] = expectations[i - 1] - 2 + (b + 1) * (1.0 - probabilities[i - 1]);
			if (expectations[i] < minExpectation) {
				minExpectation = expectations[i];
			}
		}

		// Handle the case that keeps on typing
		//double expectationKeepTyping = 
		// Handle the case that presses Enter striaght away
		double expactationEnterNow = b + 2;
		if (expactationEnterNow < minExpectation) {
			minExpectation = expactationEnterNow;
		}
		return minExpectation;
	}

}
