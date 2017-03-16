import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class R1ProblemA {
	public static final boolean Debug = true;
	
	public static void main(String[] args) {
		try {
			//Configuration variables
			final String round = "R1";
			final char problem = 'A';
			final boolean isSmall = false;
			final int attempt = 0;
			
			//Setup of input and output streams
			String filename = "C:/Users/Ben Harwood/Desktop/CodeJam/" + round + "/" + problem;
			if (isSmall) {
				filename += "-small";
				if (attempt >= 0) filename += "-attempt" + attempt;
			}
			else filename += "-large";
			BufferedReader input = new BufferedReader(new FileReader(filename + ".in"));
			BufferedWriter output = new BufferedWriter(new FileWriter(filename + ".out"));
			
			//Parse input
			int lines = Integer.parseInt(input.readLine());
			for (int i = 0; i < lines; i++) {
				String out = ProcessInput(input, i);
				out = "Case #" + (i + 1) + ": " + out.trim();
				if (Debug) System.out.println(out);
				output.append(out);
				if (i < lines - 1) output.append("\n");
			}
			input.close();
			output.close();
		}
		catch (Exception e) {
			System.err.println(e.getMessage());
			e.printStackTrace();
		}
	}
	
	public static String ProcessInput(BufferedReader input, int caseNo) throws Exception {
		String in = input.readLine();
		if (Debug) System.out.println("Input#" + (caseNo + 1) + ": " + in);
		String out = "";
		//Code goes here...
		String[] charCount = in.split(" ");
		int current = Integer.parseInt(charCount[0]);
		int total = Integer.parseInt(charCount[1]);
		in = input.readLine();
		if (Debug) System.out.println("Input#" + (caseNo + 1) + ": " + in);
		String[] probString = in.split(" ");
		float[] probs = new float[current];
		float product = 1;
		for (int i = 0; i < current; i++) {
			probs[i] = Float.parseFloat(probString[i]);
			product *= probs[i];
		}
		float[] exp = new float[current + 1];
		//Case 1
		exp[0] = product * (total - current + 1) + (1 - product) * (2 * total - current + 2);
		//Case 2
		for (int i = 1; i <= current; i++) {
			product = 1;
			for (int j = 0; j < current - i; j++)
				product *= probs[j];
			exp[i] = product * (2 * i + total - current + 1) + (1 - product) * (2 * i + 2 * total - current + 2);
		}
		//Case 3
		float min = total + 2;
		for (int i = 0; i <= current; i++)
			if (exp[i] < min) min = exp[i];
		out = String.format("%.6f", min); 
		return out;
	}
}
