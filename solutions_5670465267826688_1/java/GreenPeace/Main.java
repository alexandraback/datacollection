import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main {

	private static Map<Character, Integer> charToIndex = new HashMap<Character, Integer>(){{
		put('1', 0);
		put('i', 1);
		put('j', 2);
		put('k', 3);
	}};
	private static int[][] letters = new int[][]{
			{0, 1, 2, 3},
			{1, 0, 3, 2},
			{2, 3, 0, 1},
			{3, 2, 1, 0},
	};

	private static int[][] sign = new int[][]{
			{1, 1, 1, 1},
			{1, -1, 1, -1},
			{1, -1, -1, 1},
			{1, 1, -1, -1},
	};
	
	public static void main(String[] args) {
		try {
			Scanner scanner = new Scanner(new FileInputStream("input.txt"));
			scanner.useLocale(Locale.ENGLISH);
			BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
			int tests = scanner.nextInt();
			for (int i = 0; i < tests; i++) {
				int l = scanner.nextInt();
				long x = scanner.nextLong();
				scanner.nextLine();
				String values = scanner.nextLine();
				String answer = solve(x, values);
				out.write("Case #" + (i + 1) + ": " + answer + "\n");
				out.flush();
			}
			out.close();
		} catch (FileNotFoundException e) {
			// ????
		} catch (IOException e) {
			// ????
		}
	}

	private static String solve(long x, String values) {
		int result = 0;
		int resultSign = 1;
		for (int j = 0; j < values.length(); j++) {
			int index = charToIndex.get(values.charAt(j));
			resultSign = resultSign * sign[result][index];
			result = letters[result][index];
		}

		if (result != 0 && x % 4 != 2) {
			return "NO";
		}

		if (result == 0) {
			if (resultSign == 1) {
				return "NO";
			}
			else if (x % 2 == 0) {
				return "NO";
			}
		}

		int[] subresIndex = new int[(int)Math.min(4, x)];
		int[] subresSign = new int[(int)Math.min(4, x)];
		subresIndex[0] = 0;
		subresSign[0] = 1;
		for (int j = 1; j < subresIndex.length; j++) {
			subresIndex[j] = letters[subresIndex[j-1]][result];
			subresSign[j] = subresSign[j-1] * sign[subresIndex[j-1]][result] * resultSign;
		}

		int bestIPosition = -1;
		int bestIOvercount = -1;
		int tmpResult = 0;
		int tmpResultSign = 1;
		for (int j = 0; j < values.length(); j++) {
			int index = charToIndex.get(values.charAt(j));
			tmpResultSign = tmpResultSign * sign[tmpResult][index];
			tmpResult = letters[tmpResult][index];
			for (int k = 0; k < subresSign.length; k++) {
				//if results to i
				if (subresSign[k]*tmpResultSign*sign[subresIndex[k]][tmpResult] == 1 && 
						letters[subresIndex[k]][tmpResult] == 1) {
					if (bestIPosition == -1 || bestIOvercount > k) {
						bestIPosition = j;
						bestIOvercount = k;
					}
					break;
				}
			}
		}

		if (bestIPosition == -1) {
			return "NO";
		}

		int bestKPosition = -1;
		int bestKOvercount = -1;
		tmpResult = 0;
		tmpResultSign = 1;
		for (int j = values.length() - 1; j >= 0; j--) {
			int index = charToIndex.get(values.charAt(j));
			tmpResultSign = tmpResultSign * sign[index][tmpResult];
			tmpResult = letters[index][tmpResult];
			for (int k = 0; k < subresSign.length; k++) {
				//if results to k
				if (subresSign[k]*tmpResultSign*sign[tmpResult][subresIndex[k]] == 1 && 
						letters[tmpResult][subresIndex[k]] == 3) {
					if (bestKPosition == -1 || bestKOvercount > k) {
						bestKPosition = j;
						bestKOvercount = k;
					}
					break;
				}
			}
		}

		if (bestKPosition == -1) {
			return "NO";
		}
		
		int totalOvercount = bestIOvercount + bestKOvercount;
		if (bestIPosition >= bestKPosition) {
			totalOvercount++;
		}
		String answer = totalOvercount < x ? "YES" : "NO";
		return answer;
	}
}