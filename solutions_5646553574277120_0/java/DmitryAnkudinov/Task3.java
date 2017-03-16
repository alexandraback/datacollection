package Round1C;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class Task3 {
	public static void main(String[] args) throws FileNotFoundException {
		File file = new File("D:/Development/Competitions/GoogleCodeJam/GoogleCodeJam2015/data/Round1C/C-small-attempt2.in");
		PrintStream out = new PrintStream(new FileOutputStream("D:/Development/Competitions/GoogleCodeJam/GoogleCodeJam2015/data/Round1C/C-small-attempt2.out"));
		System.setOut(out);
		Scanner sc = new Scanner(file);
		//Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		int[] result = new int[T];
		
		for (int i = 0; i < T; ++i)
		{
			int C = sc.nextInt();
			int D = sc.nextInt();
			int V = sc.nextInt();
			result[i] = 0;
			ArrayList<Integer> values = new ArrayList<Integer>();
			for (int j = 0; j < D; ++j)
				values.add(sc.nextInt());
			
			boolean isVPresent = values.contains(V);
			if (!values.contains(1))
			{
				values.add(0, 1);
				result[i]++;
			}
			if (!isVPresent)
				values.add(V);
			
			int currentSum = 0;
			int nextUnreachableValue = currentSum * C + 1;
			for (int j = 0; j < values.size() - 1; ++j)
			{
				int currentDenomination = values.get(j);
				currentSum += currentDenomination;
				nextUnreachableValue = currentSum * C + 1;
				int nextDenomination = values.get(j + 1);
				if (nextUnreachableValue < nextDenomination)	
				{
					Integer newDenomination = nextUnreachableValue;
					values.add(j + 1, newDenomination);
					result[i]++;
				}
			}
			
			if ((nextUnreachableValue == V) && (!isVPresent))
				result[i]++;
		}
		sc.close();
		
		for (int i = 0; i < T; ++i)
			System.out.printf("Case #%d: %d\n", i + 1, result[i]);
	}
}


/*
Problem

1
1 3 7
1 2 3


*/