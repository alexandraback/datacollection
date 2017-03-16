import java.util.*;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;

public class CloseMatch {
	
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
	
	int minDiff = Integer.MAX_VALUE;
	int minA = Integer.MAX_VALUE;
	int minB = Integer.MAX_VALUE;
	String minStr = "";
	
	public String calculate(String s) {
		System.out.println(s);
		minDiff = Integer.MAX_VALUE;
		minA = Integer.MAX_VALUE;
		minB = Integer.MAX_VALUE;
		minStr = "";
		String[] nums = s.split(" ");
		calcHelp(nums[0], nums[1]);
		return minStr;
	}
	
	public void calcHelp(String a, String b) {
		//System.out.println(a + " "+ b);
		if (a.contains("?")) {
			int loc = a.indexOf('?');
			for (int i = 0; i<10; i++) {
				String aNew = a.substring(0,  loc) + i;
				if (loc+1<a.length()) {
					aNew += a.substring(loc+1);
				}
				calcHelp(aNew, b);
			}
		}
		if (b.contains("?")) {
			int loc = b.indexOf('?');
			for (int i = 0; i<10; i++) {
				String bNew = b.substring(0,  loc) + i;
				if (loc+1<b.length()) {
					bNew += b.substring(loc+1);
				}
				calcHelp(a, bNew);
			}
			
		}
		try {
			int numA = Integer.parseInt(a);
			int numB = Integer.parseInt(b);
			int diff = Math.abs(numA - numB);
			boolean replace = false;
			if (diff < minDiff) {
				replace = true;
			} else if (diff == minDiff) {
				if (numA < minA) {
					replace = true;
				} else if (numA == minA) {
					if (numB < minB) {
						replace = true;
					}
				}
			}
			if (replace) {
				minA = numA;
				minB = numB;
				minDiff = diff;
				minStr = a + " " + b;
			}
		} catch (NumberFormatException e) {
			//
		}
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
			ps = new PrintStream(new File("outBsmall.txt"));
		}
		catch (FileNotFoundException fx) {
			fx.printStackTrace();
		}
		
		
		CloseMatch s = new CloseMatch();
		
		s.readFile("B-small-attempt0.in");
		
		String[] parsed = s.parsedInputs();
		for (int i = 0; i<parsed.length; i++) {
			ps.println("Case #" + (i+1) + ": " + s.calculate(parsed[i]));
		}
		
	}
}
