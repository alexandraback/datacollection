import java.util.*;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;

public class GettingDigits {
	
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
	
	public String calculate(String s) {
		counts.clear();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i<s.length(); i++) {
			char c = s.charAt(i);
			if (counts.containsKey(c)) {
				counts.put(c, counts.get(c) + 1);
			} else {
				counts.put(c,  1);
			}
		}
		Map<Integer, Integer> letterCounts = new HashMap<>(); //key = num, val = appearences
		letterCounts.put(4, get('U'));
		letterCounts.put(8, get('G'));
		letterCounts.put(2, get('W'));
		letterCounts.put(6, get('X'));
		letterCounts.put(0, get('Z'));
		letterCounts.put(3, get('H') - letterCounts.get(8));
		letterCounts.put(5, get('F') - letterCounts.get(4));
		letterCounts.put(7, get('V') - letterCounts.get(5));
		letterCounts.put(1, get('O') - (letterCounts.get(0) + letterCounts.get(2) + letterCounts.get(4)));
		letterCounts.put(9, get('I') - (letterCounts.get(5) + letterCounts.get(6) + letterCounts.get(8)));
		
		//System.out.println(counts);
		//System.out.println(letterCounts);
		for (int i = 0; i<10; i++) {
			for (int j = 0; j<letterCounts.get(i); j++) {
				sb.append(i);
			}
		}
		
		return sb.toString();
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
			ps = new PrintStream(new File("outAlarge.txt"));
		}
		catch (FileNotFoundException fx) {
			fx.printStackTrace();
		}
		
		
		GettingDigits s = new GettingDigits();
		
		s.readFile("A-large.in");
		
		String[] parsed = s.parsedInputs();
		
		for (int i = 0; i<parsed.length; i++) {
			ps.println("Case #" + (i+1) + ": " + s.calculate(parsed[i]));
		}
		
	}
}
