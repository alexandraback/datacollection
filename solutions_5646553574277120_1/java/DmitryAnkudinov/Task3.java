package Round1C;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class Task3 {
	public static void main(String[] args) throws FileNotFoundException {
		File file = new File("D:/Development/Competitions/GoogleCodeJam/GoogleCodeJam2015/data/Round1C/C-large.in");
		PrintStream out = new PrintStream(new FileOutputStream("D:/Development/Competitions/GoogleCodeJam/GoogleCodeJam2015/data/Round1C/C-large.out"));
		Scanner sc = new Scanner(file);
		//Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		int[] result = new int[T];
		
		for (int i = 0; i < T; ++i)
		{
			System.out.printf("Solving case %d\n", i + 1);
			long C = sc.nextLong();
			long D = sc.nextLong();
			long V = sc.nextLong();
			result[i] = 0;
			ArrayList<Long> values = new ArrayList<Long>();
			for (int j = 0; j < D; ++j)
				values.add(sc.nextLong());
			
			boolean isVPresent = values.contains(V);
			if (!values.contains(1))
			{
				values.add(0, 1L);
				result[i]++;
			}
			if (!isVPresent)
				values.add(V);
			
			long currentSum = 0;
			long nextUnreachableValue = currentSum * C + 1;
			long currentDenomination = 1;
			for (int j = 0; j < values.size() - 1;)
			{
				currentSum += currentDenomination;
				nextUnreachableValue = currentSum * C + 1;
				long nextDenomination = values.get(j + 1);
				if (nextUnreachableValue < nextDenomination)	
				{
					currentDenomination = nextUnreachableValue;
					result[i]++;
				}
				else
				{
					++j;
					currentDenomination = values.get(j);
				}
			}
			
			if ((nextUnreachableValue == V) && (!isVPresent))
				result[i]++;
		}
		sc.close();

		System.setOut(out);
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