import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;


public class SolutionB {
	
	// For example, "B-small"
	private static final String FILENAME = "B-small-attempt1";
	
	private void solveCase(int caseNumber, BufferedReader rd, PrintWriter wr) throws Exception {
		String line = rd.readLine();
		String[] data = line.split(" ");
		int N = Integer.parseInt(data[0]);
		int X = Integer.parseInt(data[1]);
		int Y = Integer.parseInt(data[2]);
		
		X = Math.abs(X);
		
		double p = 0;
		
		int toAdd = 1;
		int minmin = 0;
		for(int i = 0; i < X + Y; i += 2) {
			minmin += toAdd;
			toAdd += 4;
		}
		
		if(X == 0) {
			minmin += toAdd;
			if(N >= minmin) {
				p = 1;
			}
		} else {
			int total = N - minmin;
			if(total < Y + 1) {
				p = 0;
			} else if(total >= X + Y + Y + 1) {
				p = 1;
			} else {
				long[] factorials = new long[total + 1];
				factorials[0] = 1;
				factorials[1] = 1;
				for(int i = 2; i <= total; i++) factorials[i] = factorials[i-1] * i;
				
				long sum = 0;
				for(int a = Y + 1; a <= total; a++) {
					sum += factorials[total] / (factorials[a] * factorials[total - a]);
				}
				
				p = Math.pow(0.5, total) * sum;
			}
		}

		System.out.println("Case #" + caseNumber + ": " + p);
		wr.println("Case #" + caseNumber + ": " + p);
	}
	
	public SolutionB() {
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
		new SolutionB();
	}
	
}
