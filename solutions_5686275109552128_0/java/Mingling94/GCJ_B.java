import java.util.*;
import java.io.*;
import java.nio.file.*;
import java.util.stream.*;

public class GCJ_B {
	// Separates input into List<String> deliminated by spaces
	public static void main(String [] args) {
		if (args[0] == null)
			System.out.println("Error: No input file!");

		try {
			List<String> lines = Files.lines(Paths.get(args[0]))
			    .map(line -> line.split("\\r?\\n")).flatMap(Arrays::stream)
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
		for (int i = 1; i <= t; i++) {
			System.out.println("Case #" + i + ": " + calculate(Integer.parseInt(lines.get(i * 2 - 1)), lines.get(i*2)));
			//System.out.println(Integer.parseInt(lines.get(i * 2 - 1)) + " : " + lines.get(i * 2));
		}
	}

	private static int calculate(int d, String stacks) {
		// System.out.println("Diners: " + d);
		// System.out.println("Stacks: " + stacks);
		List<Integer> pancakes = new ArrayList<Integer>();
		for (String stack : stacks.split("\\s+"))
			pancakes.add(Integer.parseInt(stack));
		int time = 0;

		Collections.sort(pancakes);
		Collections.reverse(pancakes);
		// System.out.println(Arrays.toString(pancakes.toArray()));
		while (toCut(pancakes)) {
			// System.out.println("   Going to cut");
			cut(pancakes);
			time += 1;
			Collections.sort(pancakes);
			Collections.reverse(pancakes);
			// System.out.println("   After cut :" + Arrays.toString(pancakes.toArray()));
		}
		time += pancakes.get(0);
		return time;
	}

	private static boolean toCut(List<Integer> pancakes) {
		int[] save_array = new int[pancakes.size()];

		for(int i = 0; i < pancakes.size(); i++) {
			int j = pancakes.get(i);
			int next = (i < pancakes.size() - 1) ? pancakes.get(i+1) : 0;
			save_array[i] = j - Math.max(next, (j + 1) / 2) - 1;
			if (i != 0)
				save_array[i] += save_array[i - 1];
			if (save_array[i] > 0)
				return true;
		}
		return false;
	}

	private static void cut(List<Integer> pancakes) {
		Integer first = pancakes.get(0);
		pancakes.set(0, (first + 1)/2);
		pancakes.add(0, first/2);
	}
}