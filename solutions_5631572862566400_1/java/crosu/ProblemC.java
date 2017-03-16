import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemC {	
	public static int findCycle(int[] bffs, int start, PrintWriter writer) {
		int count = 1;
		int bff = bffs[start - 1];
		
		while (bff != start && count < bffs.length) {
			count++;
			bff = bffs[bff - 1];
		}
		
		if (bff == start) {
			return count;
		} else {
			return 0;
		}
	}
	
	public static int findLongestChain(int[] bffs, int start, int skip) {
		int maxLen = 1;
		
		for (int i = 0; i < bffs.length; i++) {
			int current = i + 1;
			if (current != skip && bffs[i] == start) {
				int len = 1 + findLongestChain(bffs, current, start);
				maxLen = Integer.max(maxLen, len);
			}
		}
		
		return maxLen;
	}
	
	public static void next_case(long case_num, PrintWriter writer, Scanner scanner) {
		int n = scanner.nextInt();
		
		int[] bffs = new int[n];
		
		for (int i = 0; i < n; i++) {
			bffs[i] = scanner.nextInt();
		}
		
		int maxCycle = 0;
		
		for (int i = 0; i < n; i++) {
			int count = findCycle(bffs, i+1, writer);
			maxCycle = Integer.max(maxCycle, count);
		}
		
		int doubleChainSum = 0;
		
		for (int i = 0; i < n; i++) {
			int current = i + 1;
			int bff = bffs[current - 1];
			int bffs_bff = bffs[bff - 1];
			
			if (bffs_bff == current && current < bff) {
				int currentChain = findLongestChain(bffs, current, bff);
				int bffChain = findLongestChain(bffs, bff, current);
				doubleChainSum += currentChain + bffChain;
			}
		}

		writer.print("Case #" + case_num + ": " + Integer.max(maxCycle, doubleChainSum));
	}
	
	public static void main(String[] args) throws Exception {
		String fileName = "fileC";
		PrintWriter writer = new PrintWriter(fileName + ".out", "UTF-8");
		Scanner scanner = new Scanner(new File(fileName + ".in"));
		int t = scanner.nextInt();
		
		for (int i = 0; i < t; i++) {
			next_case(i+1, writer, scanner);
			
			if (i < t - 1) {
				writer.println("");
			}
		}
		
		writer.close();
		scanner.close();
	}
}
