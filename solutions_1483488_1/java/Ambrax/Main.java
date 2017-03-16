import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

class Input {
	int a;
	int b;
	
	public Input(String line) {
		String [] arr = line.split(" ");
		a = Integer.parseInt(arr[0]);
		b = Integer.parseInt(arr[1]);
	}
	
	public String Rotate(String str) {
		char last = str.charAt(str.length()-1);
		return (last + str.substring(0,str.length()-1));
	}
	
	public int Solve() {
		int count=0;
		int numDigits = Integer.toString(a).length();
		for(int curr=a;curr<=b;curr++) {
			// For each number
			String strCurr = Integer.toString(curr);
			HashMap<String, Integer> checker = new HashMap<String, Integer>();
			
			for(int rot=1;rot<numDigits;rot++) {
				// Rotate it
				strCurr = Rotate(strCurr);
				int newNum = Integer.parseInt(strCurr);
				if(newNum > curr && newNum <= b) {
					String str = curr + "," + newNum;
					if(!checker.containsKey(str)) count++;
					checker.put(str, 0);
				}
			}
		}
		return count;
	}
}

public class Main {
	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		// Setup console
		BufferedReader c = new BufferedReader(new InputStreamReader(System.in));
		
		// Read number of test cases
		int numCases = Integer.parseInt(c.readLine());
		// Input
		Input [] testCases = new Input[numCases];
		for(int i=0;i<numCases;i++) {
			testCases[i] = new Input(c.readLine());
		}
		// Solve
		for(int i=0;i<numCases;i++) {
			int soln = testCases[i].Solve();
			System.out.println("Case #" + (i+1) + ": " + soln);
		}
	}
}

