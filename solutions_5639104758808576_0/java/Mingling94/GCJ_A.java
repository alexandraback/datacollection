import java.util.*;
import java.io.*;
import java.nio.file.*;
import java.util.stream.*;

public class GCJ_A {
	// Separates input into List<String> deliminated by spaces
	public static void main(String [] args) {
		if (args[0] == null)
			System.out.println("Error: No input file!");

		try {
			List<String> lines = Files.lines(Paths.get(args[0]))
			    .map(line -> line.split("\\s+")).flatMap(Arrays::stream)
			    .map(String::valueOf)
			    .collect(Collectors.toList());
			process(lines);
		}
		catch (IOException e) {
			System.exit(0);
		}
	}

	// t is number of test cases, then feeds cases into calculate
	private static void process(List<String> lines) {
		int t = Integer.parseInt(lines.get(0));
		for (int i = 1; i < t*2; i+=2) {
			System.out.println("Case #" + (i/2 + 1) + ": " + calculate(Integer.parseInt(lines.get(i)), lines.get(i+1)));
			//System.out.println("Needed: " + calculate(Integer.parseInt(lines.get(i)), lines.get(i+1)));
		}
	}

	private static int calculate(Integer shyness, String crowd) {
		// System.out.println("Shyness: " + shyness);
		// System.out.println("Crowd: " + crowd);
		
		int needed = 0;
		int clappers = 0;
		for (int i = 0; i <= shyness; i++) {
			clappers += Character.getNumericValue(crowd.charAt(i));
			if (clappers < i + 1) {
				int need = (i + 1) - clappers;
				needed += need;
				clappers += need;
			}

			// System.out.println("   needed: " + needed);
			// System.out.println("   clappers: " + clappers);
			// System.out.println("   i: " + i + '\n');
		}
		return needed;
	}
}