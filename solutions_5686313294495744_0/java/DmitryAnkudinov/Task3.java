package Round1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Task3 {
	
	private static class Work implements Comparable<Work>
	{
		public String firstWord;
		public String secondWord;
		public int firstWordPopularity;
		public int secondWordPopularity;
		public int minimumPopularity;
		
		@Override
		public int compareTo(Work o) {
			minimumPopularity = Math.min(firstWordPopularity, secondWordPopularity);
			o.minimumPopularity = Math.min(o.firstWordPopularity, o.secondWordPopularity);
			if (minimumPopularity != o.minimumPopularity)
				return minimumPopularity - o.minimumPopularity;
			
			int maximumPopularity = Math.max(firstWordPopularity, secondWordPopularity);
			int oMaximumPopularity = Math.max(o.firstWordPopularity, o.secondWordPopularity);
			if (maximumPopularity != oMaximumPopularity)
				return maximumPopularity - oMaximumPopularity;

			if (secondWordPopularity < o.secondWordPopularity)
				return secondWordPopularity - o.secondWordPopularity;
			
			return firstWordPopularity - o.firstWordPopularity;
		}
	}
	
	private static int rearrangeArrayList(HashMap<String, Integer> firstWords, HashMap<String, Integer> secondWords, ArrayList<Work> works)
	{
		for (int i = 0; i < works.size(); ++i)
		{
			Work currentWork = works.get(i);
			currentWork.firstWordPopularity = firstWords.get(currentWork.firstWord);
			currentWork.secondWordPopularity = secondWords.get(currentWork.secondWord);
		}
		
		works.sort(null);
		for (int i = 1; i < works.size(); ++i)
		{
			if (works.get(works.size() - 1 - i).minimumPopularity != works.get(works.size() - 1).minimumPopularity)
				return i;
		}
		
		return works.size();
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		File file = new File("D:/Development/Competitions/GoogleCodeJam/GoogleCodeJam2016/data/Round1B/C-small-attempt1.in");
		PrintStream out = new PrintStream(new FileOutputStream("D:/Development/Competitions/GoogleCodeJam/GoogleCodeJam2016/data/Round1B/C-small-attempt1.out"));
		System.setOut(out);
		
		Scanner sc = new Scanner(file);
		int T = sc.nextInt();
		for (int i = 0; i < T; ++i)
		{
			int result = 0;
			int N = sc.nextInt();
			HashMap<String, Integer> firstWords = new HashMap<String, Integer>();
			HashMap<String, Integer> secondWords = new HashMap<String, Integer>();
			ArrayList<Work>          works = new ArrayList<Work>(N);
			
			for (int j = 0; j < N; ++j)
			{
				String firstWord = sc.next();
				String secondWord = sc.next();
				if (firstWords.containsKey(firstWord))
					firstWords.put(firstWord, firstWords.get(firstWord) + 1);
				else
					firstWords.put(firstWord, 1);
				if (secondWords.containsKey(secondWord))
					secondWords.put(secondWord, secondWords.get(secondWord) + 1);
				else
					secondWords.put(secondWord, 1);				
				
				Work newWork = new Work();
				newWork.firstWord = firstWord;
				newWork.secondWord = secondWord;
				works.add(newWork);
			}
			
			rearrangeArrayList(firstWords, secondWords, works);
			
			Work currentWork = works.get(works.size() - 1); 
			while (currentWork.minimumPopularity > 1)
			{
				result++;
				secondWords.put(currentWork.firstWord, firstWords.get(currentWork.firstWord) - 1);
				secondWords.put(currentWork.secondWord, secondWords.get(currentWork.secondWord) - 1);
				works.remove(works.size() - 1);
				rearrangeArrayList(firstWords, secondWords, works);
				currentWork = works.get(works.size() - 1);
			}
			
			System.out.println(String.format("Case #%d: %d", i + 1, result));
		}	
		
		sc.close();
	}
}