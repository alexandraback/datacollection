package ProblemC;

import java.io.*;
import java.util.*;

public class Dijkstra {

	private static HashMap <Character, HashMap <Character, Character>> map;
	private static HashMap <Character, HashMap <Character, Character>> reverseMap;
	
	public static void main(String[] args) throws Exception {
		//BufferedReader br = new BufferedReader(new FileReader("C-sample.in"));
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt1.in"));
		//BufferedReader br = new BufferedReader(new FileReader("C-large.in"));
		
		//File file = new File("C-sample.out");
		File file = new File("C-small.out");
		//File file = new File("C-large.out");
		
		if(!file.exists()) file.createNewFile();
		FileWriter fw = new FileWriter(file.getAbsolutePath());
		BufferedWriter bw = new BufferedWriter(fw);

		map = buildMap();
		reverseMap = buildReverseMap();
		
		int numberOfCases = Integer.parseInt(br.readLine());
		for(int caseNum = 1; caseNum <= numberOfCases; caseNum++) {
			
			String[] setup = br.readLine().split(" ");
			String template = br.readLine();
			StringBuffer input = new StringBuffer();
			
			for(int i = 0; i < Integer.parseInt(setup[1]); i++) {
				input.append(template);
			}
			
			boolean solvable = false;
			
			if(input.length() >= 3) {
				char initialI = input.charAt(0);
				char initialJ = input.charAt(1);
				char initialK = buildInitialK(input.substring(2, input.length()));
				
				char curI = initialI;
				char curJ = initialJ;
				char curK = initialK;
				
				for(int i = 0; i < input.length()-2; i++) {
					for(int j = i + 1; j < input.length()-1; j++) {
						if(curI == 'i' && curJ == 'j' && curK == 'k') {
							System.out.println("CASE NUM: " + caseNum);
							solvable = true;
							break;
						}
						if(j == input.length() - 2) break;
						
						char nextChar = input.charAt(j + 1);
						curJ = decodeCharacters(curJ, nextChar);
						curK = divideCharacters(curK, nextChar);
					}
					if(solvable) break;
					
					curI = decodeCharacters(curI, input.charAt(i + 1));
					curJ = input.charAt(i + 2);
					initialK = divideCharacters(initialK, curJ);
					curK = initialK;
				}
			}
				
			String output = "Case #" + caseNum + ": " + (solvable ? "YES" : "NO") + "\n";
			bw.write(output);
		}
		bw.close();
		System.out.println("DONE");

	}
	
	private static char decodeCharacters(char valOne, char valTwo) {
		return map.get(valOne).get(valTwo);
	}
	
	private static char divideCharacters(char product, char val) {
		return reverseMap.get(val).get(product);
	}
	
	private static char buildInitialK(String in) {
		char last = in.charAt(0);
		for(int i = 1; i < in.length(); i++) {
			last = map.get(last).get(in.charAt(i));
		}
		return last;
	}
	
	private static HashMap <Character, HashMap <Character, Character>> buildMap() {
		HashMap <Character, HashMap <Character, Character>> map = new HashMap <Character, HashMap <Character, Character>> ();
		
		HashMap <Character, Character> oMap = new HashMap <Character, Character> ();
		oMap.put('i', 'i');
		oMap.put('j', 'j');
		oMap.put('k', 'k');
		map.put('o', oMap);
		
		HashMap <Character, Character> noMap = new HashMap <Character, Character> ();
		noMap.put('i', 'I');
		noMap.put('j', 'J');
		noMap.put('k', 'K');
		map.put('O', noMap);
		
		HashMap <Character, Character> iMap = new HashMap <Character, Character> ();
		iMap.put('i', 'O');
		iMap.put('j', 'k');
		iMap.put('k', 'J');
		map.put('i', iMap);
		
		HashMap <Character, Character> niMap = new HashMap <Character, Character> ();
		niMap.put('i', 'o');
		niMap.put('j', 'K');
		niMap.put('k', 'j');
		map.put('I', niMap);
		
		HashMap <Character, Character> jMap = new HashMap <Character, Character> ();
		jMap.put('i', 'K');
		jMap.put('j', 'O');
		jMap.put('k', 'i');
		map.put('j', jMap);
		
		HashMap <Character, Character> njMap = new HashMap <Character, Character> ();
		njMap.put('i', 'k');
		njMap.put('j', 'o');
		njMap.put('k', 'I');
		map.put('J', njMap);
		
		HashMap <Character, Character> kMap = new HashMap <Character, Character> ();
		kMap.put('i', 'j');
		kMap.put('j', 'I');
		kMap.put('k', 'O');
		map.put('k', kMap);
		
		HashMap <Character, Character> nkMap = new HashMap <Character, Character> ();
		nkMap.put('i', 'J');
		nkMap.put('j', 'i');
		nkMap.put('k', 'o');
		map.put('K', nkMap);
		
		return map;
	}
	
	private static HashMap <Character, HashMap <Character, Character>> buildReverseMap() {
		HashMap <Character, HashMap <Character, Character>> map = new HashMap <Character, HashMap <Character, Character>> ();
		
		HashMap <Character, Character> oMap = new HashMap <Character, Character> ();
		oMap.put('o', 'o');
		oMap.put('i', 'i');
		oMap.put('j', 'j');
		oMap.put('k', 'k');
		oMap.put('O', 'O');
		oMap.put('I', 'I');
		oMap.put('J', 'J');
		oMap.put('K', 'K');
		map.put('o', oMap);
		
		HashMap <Character, Character> iMap = new HashMap <Character, Character> ();
		iMap.put('i', 'o');
		iMap.put('O', 'i');
		iMap.put('k', 'j');
		iMap.put('J', 'k');
		iMap.put('I', 'O');
		iMap.put('o', 'I');
		iMap.put('K', 'J');
		iMap.put('j', 'K');
		map.put('i', iMap);
		
		HashMap <Character, Character> jMap = new HashMap <Character, Character> ();
		jMap.put('j', 'o');
		jMap.put('K', 'i');
		jMap.put('O', 'j');
		jMap.put('i', 'k');
		jMap.put('J', 'O');
		jMap.put('k', 'I');
		jMap.put('o', 'J');
		jMap.put('I', 'K');
		map.put('j', jMap);
		
		HashMap <Character, Character> kMap = new HashMap <Character, Character> ();
		kMap.put('k', 'o');
		kMap.put('j', 'i');
		kMap.put('I', 'j');
		kMap.put('O', 'k');
		kMap.put('K', 'O');
		kMap.put('J', 'I');
		kMap.put('i', 'J');
		kMap.put('o', 'K');
		map.put('k', kMap);
		
		return map;
	}
}
