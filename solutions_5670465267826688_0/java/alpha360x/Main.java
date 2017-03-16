import java.io.BufferedReader;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;

public class Main {

	int[][] map = { { 1, 2, 3, 4 }, { 2, -1, 4, -3 }, { 3, -4, -1, 2 },
			{ 4, 3, -2, -1 } };

	char [] table;
	Set<Integer> impos = new HashSet<Integer>();
	
	public int check(int fst, int snd) {
		boolean positive = fst * snd >= 0;
		fst = Math.abs(fst);
		snd = Math.abs(snd);
		int value = map[fst - 1][snd - 1];
		if (!positive)
			value = -value;
		return value;
	}

	boolean found;

	public void search(int[] current, int target, int base) {
		if (found)
			return;
		int currentVal = 0;
		if (target == 4) {
			if (!impos.contains(base) && current.length > 0) {
				currentVal = current[0];
				for (int i = 1; i < current.length; i++) {
					currentVal = check(currentVal, current[i]);
				}
				found = currentVal == 4;
				impos.add(base);
			}
			
		} else {
			
			for (int i = 1; i <= current.length + target - 4; i++) {
				if (i == 1) {
					currentVal = current[0];
				} else {
					currentVal = check(currentVal, current[i - 1]);
				}
				if (currentVal == target) {
					search(Arrays.copyOfRange(current, i, current.length),
							target + 1, i + base);
				}
			}
		}
	}

	public boolean solve(String s) {
		int[] encoded = new int[s.length()];

		if (s.length() < 3) {
			return false;
		}

		for (int i = 0; i < s.length(); i++) {
			char ch = s.charAt(i);
			int code = 2 + (int) (ch - 'i');
			encoded[i] = code;
		}
		found = false;
		impos = new HashSet<Integer>();
		//table = new int[s.length()][];
		//for (table)
		search(encoded, 2, 0);
		return found;
	}

	public Main() throws IOException {

		Scanner scanner = new Scanner(System.in);
		String userDir = System.getProperty("user.dir");
		FileWriter fWriter = new FileWriter(new File(userDir + "\\result.txt"));

		int count = scanner.nextInt();
		StringBuilder content = new StringBuilder();
		for (int i = 0; i < count; i++) {

			int strCount = scanner.nextInt();

			int repCount = scanner.nextInt();
			String baseString = scanner.next();
			String finalString = baseString;
			for (int j = 0; j < repCount - 1; j++) {
				finalString += baseString;
			}
			boolean result = solve(finalString);
			content.append("Case #").append(i + 1).append(": ")
					.append(result ? "YES" : "NO").append("\r\n");
			//System.out.print(i);
		}

		//System.out.print(content.toString());

		fWriter.write(content.toString());
		fWriter.flush();
		fWriter.close();
	}

	public static void main(String[] args) {
		try {
			new Main();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
