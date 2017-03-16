import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class onec_beta {
	public static void main(String[] args) {
		try {
			process();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private static void process()
	throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		int testCases = Integer.parseInt(reader.readLine());
		
		for (int i = 0; i < testCases; ++i) {
			processTestCase(reader, i);
		}
		
		reader.close();
	}
	
	private static void processTestCase(BufferedReader reader, int index)
	throws IOException {
		String[] sarr = reader.readLine().split(" ");
		int B = Integer.parseInt(sarr[0]);
		int M = Integer.parseInt(sarr[1]);
		
		// System.out.println("Trial: " + B + ", " + M);
		
		String s = "";
		for (int j = 0; j < B; ++j) s += "0";
		
		String[] answer = new String[B];
		for (int i = 0; i < B; ++i) {
			answer[i] = s;
		}
		
		addLink(answer, 1, B);
		M--;
		
		int building = B-1;
		boolean possible = true;
		
		while (M > 0) {
			if (building == 1) {
				possible = false;
				break;
			}
			
			addLink(answer, 1, building);
			
			for (int i = building+1; i < B; ++i) {
				int value = (int) Math.pow(2, B-i-1);
				if (M >= value) {
					// System.out.println("  adding link " + building + "-->" + i + " for value " + value);
					addLink(answer, building, i);
					M -= value;
				}
				if (M == 0) break;
			}
			
			if (M > 0) {
				// System.out.println("  adding link " + building + "-->" + B);
				addLink(answer, building, B);
				M--;
			}
			
			building--;
		}
		
		System.out.print("Case #" + (index+1) + ": ");
		System.out.println(possible ? "POSSIBLE" : "IMPOSSIBLE");
		
		if (possible) {
			for (int i = 0; i < B; ++i) System.out.println(answer[i]);
		}
	}
	
	private static void addLink(String[] sarr, int val1, int val2) {
		StringBuilder builder = new StringBuilder(sarr[val1-1]);
		builder.setCharAt(val2-1, '1');
		sarr[val1-1] = builder.toString();
	}
}