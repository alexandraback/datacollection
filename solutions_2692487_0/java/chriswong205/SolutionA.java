import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;


public class SolutionA {
	
	// For example, "B-small"
	private static final String FILENAME = "A-small-attempt3";
	
	private void solveCase(int caseNumber, BufferedReader rd, PrintWriter wr) throws Exception {
		String line = rd.readLine();
		String[] data = line.split(" ");
		long armin = Integer.parseInt(data[0]);
		long N = Integer.parseInt(data[1]);
		line = rd.readLine();
		data = line.split(" ");
		long[] motes = new long[(int) N];
		for(int i = 0; i < N; i++) motes[i] = Integer.parseInt(data[i]);
		
		long numOperations = 0;
		
		Arrays.sort(motes);
		
		if(armin == 1) {
			System.out.println("Case #" + caseNumber + ": " + N);
			wr.println("Case #" + caseNumber + ": " + N);
			return;
		}
		
		long possibleMin = N;
		for(int moteNum = 0; moteNum < N; moteNum++) {
			possibleMin = Math.min(possibleMin, numOperations + N - moteNum);
			if(armin > motes[moteNum]) {
				armin += motes[moteNum];
			} else {
				long required = 0;
				while(true) {
					armin += armin - 1;
					required++;
					if(armin > motes[moteNum]) break;
				}
				if(N - moteNum < required) {
					numOperations += (N - moteNum);
					break;
				} else {
					numOperations += required;
				}
				armin += motes[moteNum];
			}
			
		}
		
		numOperations = Math.min(possibleMin, numOperations);
		
		System.out.println("Case #" + caseNumber + ": " + numOperations);
		wr.println("Case #" + caseNumber + ": " + numOperations);
	}
	
	public SolutionA() {
		BufferedReader rd = null;
		PrintWriter wr = null;
		int numCases = 0;
		try {
			rd = new BufferedReader(new FileReader(FILENAME + ".in"));
			wr = new PrintWriter(new FileWriter(FILENAME + ".out"));
			numCases = Integer.parseInt(rd.readLine());
		} catch (Exception e) {
			System.out.println("Error reading file");
			e.printStackTrace();
			return;
		}
		
		for(int i = 1; i <= numCases; i++) {
			try {
				solveCase(i, rd, wr);
			} catch (Exception e) {
				System.out.println("Exception in Case " + i + ". Stack trace:");
				e.printStackTrace();
				break;
			}
		}
		
		try {
			rd.close();
			wr.close();
		} catch (Exception e) {
			System.out.println("Error closing file");
			e.printStackTrace();
			return;
		}
	}
	
	public static void main(String[] args) {
		new SolutionA();
	}
	
}
