import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;


public class SolutionA {
	
	// For example, "B-small"
	private static final String FILENAME = "A-small-attempt0";
	
	private void solveCase(int caseNumber, BufferedReader rd, PrintWriter wr) throws Exception {
		String line = rd.readLine();
		String[] data = line.split(" ");
		long startR = Long.parseLong(data[0]);
		long mlPaint = Long.parseLong(data[1]);
		
		long numRings = 0;
		while(true) {
			long paintNeeded = (startR + 1)*(startR + 1) - (startR) * (startR);
			if(paintNeeded > mlPaint) break;
			mlPaint -= paintNeeded;
			startR += 2;
			numRings++;
		}
		
		System.out.println("Case #" + caseNumber + ": " + numRings);
		wr.println("Case #" + caseNumber + ": " + numRings);
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
