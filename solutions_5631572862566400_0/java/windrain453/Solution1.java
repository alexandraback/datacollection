
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Solution1 {

	static boolean DEBUG = false;

	static int process(int[] kidsBff, int n) {
		Set<Integer> processedSet = new TreeSet<Integer>();
		int start = 1;
		int maxCount = 0;
		int number = n - 1;
		while (processedSet.size() < number) {
			for (int i = start; i < n; i++) {
				if (!processedSet.contains(i)) {
					start = i;
					break;
				}
			}
			Set<Integer> cache = new HashSet<Integer>();
			LinkedList<Integer> circle = new LinkedList<Integer>();
			int current = start;
			while (!cache.contains(current)) {
				circle.add(current);
				cache.add(current);
				processedSet.add(current);
				current = kidsBff[current];
			}
			for (int i = start; i < n; i++) {
				if (!cache.contains(i)) {
					if (kidsBff[i] == circle.peekFirst()) {
						circle.offerFirst(i);
						cache.add(i);
						processedSet.add(i);
						i = start;

					}
					if (kidsBff[i] == circle.peekLast()) {
						circle.offerLast(i);
						cache.add(i);
						processedSet.add(i);
						i = start;
					}

				}
			}

			if (circle.size() > maxCount) {
				maxCount = circle.size();
			}
		}
		return maxCount;
	}

	static void processTerminal() {
		int[] numbers = new int[] { 0, 3, 3, 4, 1 };
		System.out.println(process(numbers, 5));
	}

	static void processFile(String inputFile, String outputFile) {
		try (Scanner scanner = new Scanner(new FileInputStream(inputFile));
				PrintWriter pw = new PrintWriter(outputFile)) {
			int testCaseCount = scanner.nextInt();
			for (int i = 1; i <= testCaseCount; i++) {
				int n = scanner.nextInt();
				int[] kidsBff = new int[n + 1];
				for (int j = 1; j < n + 1; j++) {
					kidsBff[j] = scanner.nextInt();
				}
				int result = process(kidsBff, n + 1);
				pw.print("Case #" + i + ": " + result);
				pw.println();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		if (DEBUG) {
			processTerminal();
		} else {
			processFile(args[0], args[1]);
		}
	}
}
