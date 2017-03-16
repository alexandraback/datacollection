package round0;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class ProblemB {
	
	// Workaround for not being able to pipe a file to stdin in Eclipse.
	private static final String IN_FILE = "text/B-small-attempt0.in";
	
	public static void main(String[] args) throws Exception {
		try (Scanner in = new Scanner(new BufferedReader(new FileReader(IN_FILE)))) {
			int numCases = in.nextInt();
			for (int i = 0; i < numCases; i++) {
				String stackStr = in.next();
				List<Boolean> stackLst = stackStr.chars().mapToObj(val -> val == '+')
						.collect(Collectors.toList());
				boolean[] stack = new boolean[stackLst.size()];
				for (int j = 0; j < stackLst.size(); j++) {
					stack[j] = stackLst.get(j);
				}
				
				int result = solve(stack);
				String resultStr = ""+result;
				
				System.out.println(String.format("Case #%s: %s", i+1, resultStr));
			}
		}
	}

	private static int solve(boolean[] stack) {
		// Divide stack into segments.
		List<Boolean> segments = new ArrayList<>();
		Boolean prev = null;
		for (boolean pancake : stack) {
			if (prev == null || prev != pancake) {
				segments.add(pancake);
				prev = pancake;
			}
		}
		
		return solveRecur(segments, true);
	}
	
	private static int solveRecur(List<Boolean> segments, boolean goal) {
		if (segments.isEmpty()) {
			return 0;
		}
		
		if (segments.get(segments.size()-1) == goal) {
			return solveRecur(segments.subList(0, segments.size()-1), goal);
		}
		
		return 1 + solveRecur(segments.subList(0, segments.size()-1), !goal);
	}
}
