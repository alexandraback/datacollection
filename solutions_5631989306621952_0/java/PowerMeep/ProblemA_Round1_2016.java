import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Stack;

public class ProblemA_Round1_2016 {
	public static void main(String[] args) {
		try {
//			quickTest();
			compete();
		} catch (NumberFormatException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private static void quickTest() {
		String[] inputs = "CAB JAM CODE ABAAB CABCBBABC ABCABCABC ZXCASDQWE".split(" ");
		for (int i = 0; i < inputs.length; i++) {
			output(i+1, inputs[i]);
		}
		
	}
	
	private static void output(int i, String s) {
		System.out.println("Case #" + i + ": " + getOutput(s));
	}
	
	private static void compete() throws NumberFormatException, IOException {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		
		int n = Integer.parseInt(br.readLine());
		for (int i = 1; i <= n; i++) {
			output(i,br.readLine());
		}
		br.close();
	}
	
	private static String getOutput(String input) {
		char pivot = input.charAt(0);
		int pivotIndex = getIndex(pivot);
		Stack<Character> preLetters = new Stack<Character>();
		LinkedList<Character> postLetters = new LinkedList<Character>();
		char c;
		int index;
		for (int i = 1; i < input.length(); i++) {
			c = input.charAt(i);
			index = getIndex(c);
			if (index >= pivotIndex) {
				pivot = c;
				pivotIndex = index;
				preLetters.push(c);
			} else {
				postLetters.add(c);
			}
		}
		
		StringBuilder b = new StringBuilder();
		while (!preLetters.isEmpty())
			b.append(preLetters.pop());
		b.append(input.charAt(0));
		while (!postLetters.isEmpty())
			b.append(postLetters.poll());
		return b.toString();
	}
	
	private static int getIndex(Character c) {
		return (Character.toUpperCase(c) - 'A');
	}
}
