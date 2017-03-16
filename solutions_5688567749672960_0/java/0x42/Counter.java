import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

public class Counter {

	public static void main(String[] args) throws Exception {
		Counter object = new Counter();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase() + ".in"));
		Scanner scanner = new Scanner(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		int testCases = scanner.nextInt();
		
		for (int tc = 1; tc <= testCases; tc++) {

			long input = scanner.nextLong();

			long result = object.solve(input);

			wr.write("Case #" + tc + ": " + result + "\r\n");
		}

		scanner.close();
		wr.close();
	}
	
	private long solve(long input) throws Exception {
		Map<Long, Long> seen = new HashMap<>();
		Queue<Long> q = new LinkedList<>();
		
		q.add(1L);
		seen.put(1L, 1L);
		
		while (!q.isEmpty()) {
			long current = q.poll();
			long steps = seen.get(current);
			
			if (current == input)
				return steps;
			
			long next1 = current + 1;
			long next2 = reverse(current);
			
			if (!seen.containsKey(next1)) {
				q.add(next1);
				seen.put(next1, steps + 1);
			}
			
			if (!seen.containsKey(next2)) {
				q.add(next2);
				seen.put(next2, steps + 1);
			}
		}
		
		return -1;
	}

	private long reverse(long current) {
		long output = 0;
		
		while (current > 0) {
			output *= 10;
			
			output += current % 10;
			current /= 10;
		}
		
		return output;
	}
	
}
