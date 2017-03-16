import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

class Input {
	String sentence;
	public static HashMap<Character, String> googleMap = new HashMap<Character, String>();
	
	public Input(String s) {
		sentence = s;
		
		if(!googleMap.containsKey('a')) {
			googleMap.put(' ', " ");
			googleMap.put('a', "y");
			googleMap.put('b', "h");
			googleMap.put('c', "e");
			
			googleMap.put('d', "s");
			googleMap.put('e', "o");
			googleMap.put('f', "c");
			
			googleMap.put('g', "v");
			googleMap.put('h', "x");
			googleMap.put('i', "d");
			
			googleMap.put('j', "u");
			googleMap.put('k', "i");
			googleMap.put('l', "g");
			
			googleMap.put('m', "l");
			googleMap.put('n', "b");
			googleMap.put('o', "k");
			
			googleMap.put('p', "r");
			googleMap.put('q', "z");
			googleMap.put('r', "t");
			googleMap.put('s', "n");
			
			googleMap.put('t', "w");
			googleMap.put('u', "j");
			googleMap.put('v', "p");
			
			googleMap.put('w', "f");
			googleMap.put('x', "m");
			googleMap.put('y', "a");
			googleMap.put('z', "q");
		}
	}
	
	public String Solve() {
		String result = "";
		char [] arr = sentence.toCharArray();
		for(char c:arr) {
			result += googleMap.get(c);
		}
		return result;
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
			String soln = testCases[i].Solve();
			System.out.println("Case #" + (i+1) + ": " + soln);
		}
	}
}

