import java.util.*;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;

public class Technobabble {
	
	public String[] parsedInputs() {
		String[] parsed = new String[inputs.size()-1];
		for (int i = 1; i<inputs.size(); i++) {
			String realInput = inputs.get(i);
			parsed[i-1] = realInput;
		}
		return parsed;
	}
	
	public int[] toArray(String s) {
		int[] arr = new int[s.length()];
		for (int i = 0; i<s.length(); i++){
			arr[i] = s.charAt(i)-48;
		}
		return arr;
	}
	
	Map<Character, Integer> counts = new HashMap<>();
	
	public int calculate(int numRows, int lineStart) {
		int ret = 0;
		List<String> myInputs = new ArrayList<>();
		for (int i = lineStart; i<lineStart + numRows; i++) {
			myInputs.add(inputs.get(i+1));
		}
		
		int edges = myInputs.size();
		
		Set<String> a = new HashSet<>();
		Set<String> b = new HashSet<>();
		
		for (String s: myInputs) {
			String[] mine = s.split(" ");
			a.add(mine[0]);
			b.add(mine[1]);
		}
		//System.out.println(a);
		//System.out.println(b);
		
		
		int maxSet = Math.max(a.size(), b.size());
//		System.out.println(maxSet);
//		System.out.println(edges);
		ret = edges - maxSet;
		
		System.out.println(myInputs);
		
		
		return ret;
	}
	
	public int get(char c) {
		int ret = 0;
		if (counts.get(c) != null) {
			ret = counts.get(c);
		}
		return ret;
	}
	
	ArrayList<String> inputs = new ArrayList<String>();
	
	public boolean readFile(String filename) {
		try {
			FileReader dataFile = new FileReader(filename);
			BufferedReader bufferedReader = new BufferedReader(dataFile);
			String currentLine = bufferedReader.readLine();

			while(currentLine != null) {
				String trimmedWord = currentLine.trim();
				inputs.add(trimmedWord);
				currentLine = bufferedReader.readLine();
			}
			bufferedReader.close();
		} 
		catch (IOException e) {
			System.err.println("A error occured reading file: " + e);
			e.printStackTrace();
			return false;
		}
		//System.out.println(inputs);
		return true;
	}
	
	
	
	
	
	public static void main(String[] args) {
		
		PrintStream ps = null;
		
		try {
			ps = new PrintStream(new File("outCsmall1.txt"));
		}
		catch (FileNotFoundException fx) {
			fx.printStackTrace();
		}
		
		
		Technobabble s = new Technobabble();
		
		s.readFile("C-small-attempt1.in");
		
		String[] parsed = s.parsedInputs();
		
		//System.out.println(s.inputs);
		int printCounter = 1;
		for (int i = 0; i<parsed.length; i++) {
			try {
				//System.out.println("CURR LINE: " + parsed[i]);
				int numToFollow = Integer.parseInt(parsed[i]);
				ps.println("Case #" + (printCounter++) + ": " + s.calculate(numToFollow, i+1));
			} catch (Exception e) {
				
			}
		}
		
	}
}
