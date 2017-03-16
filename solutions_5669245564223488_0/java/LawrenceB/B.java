import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;


public class B {

	static long validCount;
	public static void main(String[] args) {
		Scanner s = null;
		int t;
		List<String> outputLines = new ArrayList<String>();

		try {
			s = new Scanner(new File("input.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			return;
		}
		t = s.nextInt();
		s.nextLine();
		
		for (int i = 0; i < t; i++) {
			int n = s.nextInt();
			s.nextLine();
			String str = s.nextLine();
			
//			System.out.println("Solving " + i + "...");
			solve(n, str);
			outputLines.add("Case #" + (i+1) + ": " + validCount);

		}
		try {
			writeOutput(outputLines);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		s.close();
	}
	
	public static long solve(int n, String s) {
		String[] cars = s.split(" ");
		System.out.println("Solving instance: " + Arrays.toString(cars));
		validCount = 0;
		
		List<String> carList = new ArrayList<String>();
		for (String car : cars) {
			carList.add(car);
		}
		
		permutate(carList, new Stack<String>(), carList.size());
		
		
		return 0;
	}
	

	public static void permutate(List<String> set, Stack<String> permutation, int size) {
        String [] array = permutation.toArray(new String[0]);
        String longString = "";
        for (String s : array) {
        	longString += s;
        }
        
        if (longString.length() > 1 && !isValidString(longString))
        	return;
        
		
	    if (permutation.size() == size) {
	        /* print the permutation */
//	        System.out.println(Arrays.toString(permutation.toArray(new String[0])));
	        
	        if (isValidString(longString))
	        	validCount++;
	    }
	    
	    String[] cars = set.toArray(new String[0]);
	    for(String i : cars) {
	        /* add current item */
	        permutation.push(i);

	        /* remove item from available item set */
	        set.remove(i);
	        /* pass it on for next permutation */
	        permutate(set, permutation, size);

	        /* pop and put the removed item back */
	        set.add(permutation.pop());
	    }
	}

	public static void writeOutput(List<String> lines) throws IOException {
		if (lines == null)
			return;
		PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
		for (String line : lines) {
			writer.println(line);
		}
		writer.close();
	}
	
	public static boolean isValidString(String s) {
//		System.out.print("Checking String: " + s + "...");
		List<Character> used = new ArrayList<Character>();
		char prevChar = s.charAt(0);
		used.add(prevChar);
		
		for (int i = 1; i < s.length(); i++) {
			char c = s.charAt(i);
			if (c == prevChar)
				continue;
			else {
				if (used.contains(c)) {
//					System.out.println("Invalid!");
					return false;
				}
				prevChar = c;
				used.add(prevChar);
			}
		}
//		System.out.println("Valid!");
		return true;
	}
}
