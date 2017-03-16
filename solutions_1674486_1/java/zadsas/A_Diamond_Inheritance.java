package R1C_2012;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;

import Utils.IOStreams;

public class A_Diamond_Inheritance {

	private static Set<Integer> clashes = new HashSet<Integer>();
	private static Set<Integer> visited = new HashSet<Integer>();
	
	public static void main(String[] args) throws IOException {

		IOStreams streams = new IOStreams(args[0]);
		System.setIn(new FileInputStream(args[0]));

		Scanner sc = new Scanner(System.in);
		sc.nextLine();

		int caseNum = 1;

		while (sc.hasNextInt()) {
			int numberOfClasses = sc.nextInt();
			
			HashMap<Integer, List<Integer>> inheritances = new HashMap<Integer, List<Integer>>();
			ArrayList<Integer> possibleDiamond = new ArrayList<Integer>();
			
			for (int c = 0 ; c < numberOfClasses ; c++){
				
				int inheritancesClassI = sc.nextInt();
				
				if(inheritancesClassI>1) possibleDiamond.add(c+1);
				
				for (int i = 0 ; i < inheritancesClassI ; i++){
					int fromClass = sc.nextInt();
					List<Integer> list = inheritances.get(c+1);
					if(list==null){
						list = new ArrayList<Integer>();
					}
					list.add(fromClass);
					inheritances.put(c+1, list);
				}
				
				
			}
			
			streams.printLine("Case #" + (caseNum++) + ": " + calculateDiamond(inheritances, possibleDiamond, numberOfClasses) + "\n");
		}
		
		streams.closeStreams();

	}

	private static String calculateDiamond(HashMap<Integer, List<Integer>> inheritances, ArrayList<Integer> possibleDiamond, int numberOfClasses) {

		
		for (Integer i : possibleDiamond) {

			visited.clear();
			clashes.clear();
			Stack<Integer> toUnravel = new Stack<Integer>();
			visited.add(i);
			
			List<Integer> inheritancesFromI = inheritances.get(i);
			for (Integer integer : inheritancesFromI) {
				if(!visited.contains(integer)){
					clashes.add(integer);
					toUnravel.add(integer);
				}
			}
			boolean isDiamond = calculate(toUnravel, inheritances);
			if(isDiamond) return "Yes";
			
		}
		return "No";
	
	}

	private static boolean calculate(Stack<Integer> toUnravel, HashMap<Integer, List<Integer>> inheritances) {

		while(!toUnravel.empty()){
			Integer newClass = toUnravel.pop();
			List<Integer> newList = inheritances.get(newClass);
			if(newList!=null){
				for (Integer integer : newList) {
					if(!visited.contains(integer)){
						if(clashes.contains(integer)){
							return true;
						}
						clashes.add(integer);
						toUnravel.push(integer);
					}
				}
			}
		}
		return false;
	}

}
