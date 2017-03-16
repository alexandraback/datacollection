import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;


public class SolutionB {
	
	// For example, "B-small"
	private static final String FILENAME = "B-small-attempt2";
	
	private long maxGain = 0;
	long[] v;
	long E;
	long R;
	
	private void solveCase(int caseNumber, BufferedReader rd, PrintWriter wr) throws Exception {
		String line = rd.readLine();
		String[] data = line.split(" ");
		E = Long.parseLong(data[0]);
		R = Long.parseLong(data[1]);
		int N = Integer.parseInt(data[2]);
		if(R > E) R = E;
		
		line = rd.readLine();
		data = line.split(" ");
		v = new long[N];
		for(int i = 0; i < N; i++) v[i] = Integer.parseInt(data[i]);
		maxGain = 0;
		
		recurse(0, E, 0);
		
		System.out.println("Case #" + caseNumber + ": " + maxGain);
		wr.println("Case #" + caseNumber + ": " + maxGain);
	}
	
	private void recurse(int index, long curEnergy, long curGain) {
		if(index == v.length - 1) {
			curGain += v[index] * curEnergy;
			maxGain = Math.max(curGain, maxGain);
			return;
		}
		if(curEnergy == E) {
			recurse(index + 1, R, curGain + v[index]*E);
			recurse(index + 1, E, curGain + v[index]*R);
		} else {
			recurse(index + 1, curEnergy + 2, curGain);
			recurse(index + 1, curEnergy, curGain + v[index]*R);
			recurse(index + 1, R, curGain + v[index]*curEnergy);
		}
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
