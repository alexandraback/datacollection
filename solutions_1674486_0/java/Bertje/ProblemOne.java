package nl.bertjesapps.googlecodejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

public class ProblemOne {
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		if (args.length == 1) {
			String fileName = args[0];
			ProblemOne problemOne = new ProblemOne();
			try {
				problemOne.solveFile(fileName);
			} catch (FileNotFoundException fnf) {
				System.out.println("File not found!");
				System.out.println(fnf.getMessage());
			} catch (IOException e) {
				System.out.println("Could not read file!");
			}
		} else {
			System.out.println("Need 1 argument!");
		}
	}

	private void solveFile(String fileName) throws IOException {
		StringBuilder output = new StringBuilder();
		File file = new File(fileName);
		FileReader fileReader = new FileReader(file);
		BufferedReader reader = new BufferedReader(fileReader);
		String numberOfCasesString = reader.readLine();
		int numberOfCases = Integer.parseInt(numberOfCasesString);
		for (int i = 1; i <= numberOfCases; i++) {
			output.append("Case #" + i + ": ");
			output.append(solveLine(reader.readLine(),reader));
			output.append("\r\n");
		}
		//output.append(results.size());
		FileWriter writer = new FileWriter(fileName.replace(".in", ".out"));
		writer.write(output.toString());
		writer.close();
	}
	
	private String solveLine(String lineToBeSolved, BufferedReader reader) throws IOException{
		String result = "No";
		Map<Integer, List<Integer>> classWithDirectInheritances = new HashMap<Integer, List<Integer>>(); 
		String numberOfClassesString = lineToBeSolved;
		int numberOfClasses = Integer.parseInt(numberOfClassesString);
		for (int i = 1; i <= numberOfClasses; i++) {
			String[] parts = reader.readLine().split(" ");
			String numberOfInheritancesString = parts[0];
			int numberOfInheritances = Integer.parseInt(numberOfInheritancesString);
			List<Integer> directInheritances = new ArrayList<Integer>();
			for (int j = 1; j <= numberOfInheritances;j++) {
				directInheritances.add(Integer.parseInt(parts[j]));
			}
			classWithDirectInheritances.put(i, directInheritances);
		}
		for (Entry<Integer, List<Integer>> entry : classWithDirectInheritances.entrySet()) {
			if (entry.getValue().size() > 1) {
				for (int j = 0; j < entry.getValue().size();j++) {
					Set<Integer> possibleEndPoints = getEndPoints(classWithDirectInheritances, entry.getValue().get(j));
					for (int i = j+1; i < entry.getValue().size();i++) {
						Set<Integer> secondPossibleEndpoints = getEndPoints(classWithDirectInheritances, entry.getValue().get(i));
						for (Integer secondClass : secondPossibleEndpoints) {
							if (possibleEndPoints.contains(secondClass)) {
								return "Yes";
							}
						}
					}
				}
			}
		}
		return result;
	}
	
	private Set<Integer> getEndPoints(Map<Integer, List<Integer>> map, Integer startPosition) {
		Set<Integer> result = new HashSet<>();
		List<Integer> inheritances = map.get(startPosition);
		if (inheritances != null && !inheritances.isEmpty()) {
			for (Integer inheritance : inheritances) {
				result.addAll(getEndPoints(map, inheritance));
			}
		} else {
			result.add(startPosition);
		}
		return result;
	}

}
