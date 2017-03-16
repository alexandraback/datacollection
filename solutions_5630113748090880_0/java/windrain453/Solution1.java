import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Scanner;

public class Solution1 {

	static boolean DEBUG = false;

	static int[] process(int[][] numbers, int row, int n) {
		HashMap<Integer, Integer> numberMap = new HashMap<Integer, Integer>();
		int[] result = new int[n];
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < n; k++) {
				Integer value = numberMap.get(numbers[j][k]);
				if (null == value) {
					numberMap.put(numbers[j][k], 1);
				} else {
					numberMap.put(numbers[j][k], value + 1);
				}
			}
		}
		int index = 0;
		for (Entry<Integer, Integer> entry : numberMap.entrySet()) {
			Integer key = entry.getKey();
			Integer value = entry.getValue();
			if ((value.intValue() & 1) > 0) {
				result[index++] = key;
			}
		}
		Arrays.sort(result);
		return result;
	}

	static void processTerminal() {
		int[][] numbers = new int[][] { { 1, 2, 3 }, { 2, 3, 5 }, { 3, 5, 6 }, { 2, 3, 4 }, { 3, 4, 6 } };
		System.out.println(Arrays.toString(process(numbers, 5, 3)));
	}

	static void processFile(String inputFile, String outputFile) {
		try (Scanner scanner = new Scanner(new FileInputStream(inputFile));
				PrintWriter pw = new PrintWriter(outputFile)) {
			int testCaseCount = scanner.nextInt();
			for (int i = 1; i <= testCaseCount; i++) {
				int n = scanner.nextInt();
				int row = 2 * n - 1;
				int[][] numbers = new int[row][n];
				for (int j = 0; j < row; j++) {
					for (int k = 0; k < n; k++) {
						numbers[j][k] = scanner.nextInt();
					}
				}
				int[] result = process(numbers, row, n);
				pw.print("Case #" + i + ":");
				for (int number : result) {
					pw.print(" " + number);
				}
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
