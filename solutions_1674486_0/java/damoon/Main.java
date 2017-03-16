package fun.codeslam;

import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main
{

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException
	{
		Scanner scanner = new Scanner(new InputStreamReader(System.in));

		Integer testCaseCount = scanner.nextInt();

		for (Integer testCaseNumber = 1; testCaseNumber <= testCaseCount; testCaseNumber++)
		{
			System.out.print("Case #" + testCaseNumber + ": ");
			System.out.print(solve(scanner) + "\n");
		}
	}

	private static int[][] reaches;

	private static int[][] links;

	private static String solve(Scanner scanner)
	{
		int classCount = scanner.nextInt();
		
		reaches = new int[classCount+1][classCount+1];

		links = new int[classCount+1][classCount+1];

		for (int i = 1; i <= classCount; i++)
		{
			int linkCount = scanner.nextInt();
			for (int j = 1; j <= linkCount; j++)
			{
				int linktarget = scanner.nextInt();
				links[i][linktarget] = linktarget;
			}
		}
		for (int i = 1; i <= classCount; i++)
		{
			fillReaches(i, i);
		}

		for (int i = 1; i <= classCount; i++)
		{
			for (int j = 1; j <= classCount; j++)
			{
				if (reaches[i][j] > 1) {
					return "Yes";
				}
			}
		}
		return "No";
	}
	
	private static void fillReaches(int classId, int line)
	{
		if (line == 0 || classId == 0) return;
		for (int target : links[line]) {
			reaches[target][classId] ++;
			fillReaches(classId, target);
		}
	}
}
