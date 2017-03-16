import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Dancing_With_Googlers {
	public static void main(String[] args) {
		try {
			// Initialize
			InputStreamReader converter = new InputStreamReader(System.in);
			BufferedReader in = new BufferedReader(converter);
			String curLine = in.readLine();
			String[] googlers;
			
			// Find number of cases
			int N = Integer.parseInt(curLine);
			
			// Read line by line
			for (int line = 0; line < N; line++) {
				curLine = in.readLine();
				googlers = curLine.split(" ");
				int numGooglers = Integer.parseInt(googlers[0]);
				int numSurprising = Integer.parseInt(googlers[1]);
				int p = Integer.parseInt(googlers[2]);
				int curSurprising = 0;
				int maxGooglers = 0;
				
				for (int googler = 3; googler < googlers.length; googler++) {
					if (Integer.parseInt(googlers[googler]) >= 3*p-4
						&& Integer.parseInt(googlers[googler]) <= 3*p-3
						&& Integer.parseInt(googlers[googler]) > 0) {
						curSurprising++;
					}
					else if (Integer.parseInt(googlers[googler]) >= 3*p-2) {
						maxGooglers++;
					}
				}
				maxGooglers += Math.min(curSurprising, numSurprising);
					
				System.out.println("Case #" + (line+1) + ": " + maxGooglers);
			}
		} catch(Exception e) {
			System.out.println("Error: " + e.getMessage());
		}
	}
}
