package src2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class KingdomRush 
{
	
	int N;
	int[] ai;
	int[] bi;
	
	public KingdomRush(int levels, int[] firstStars, int[] secondStars) {
		this.N = levels ;
		this.ai = firstStars;
		this.bi = secondStars;
	}
	
	public int solve()
	{
		int curStars = 0;
		boolean[] playedFirst = new boolean [ai.length];
		boolean[] playedSecond = new boolean [bi.length];
		boolean doneFirst = false;
		boolean doneSecond = false;
		int res = 0;
		List<Integer> special = new ArrayList<Integer>();
		List<Integer> noSpecial = new ArrayList<Integer>();
		for (int i=0; i<ai.length; i++)
		{	
			boolean spec = bi[i] - ai[i] == 1 ? true : false;
			if (spec) special.add(i);
			else noSpecial.add(i);
		}	
		out: while (true)
		{	
			boolean findNotPlayed = false;
			boolean achieved = false;
			int minRequieredForSec = Integer.MAX_VALUE;
			for (int i = 0; i < bi.length; i++)
			{	
				if (!playedSecond[i]){
					findNotPlayed = true;
					if (curStars >= bi[i])
					{	
						achieved = true;
						if (!playedFirst[i]) curStars+= 2;
						else curStars ++;
						playedSecond[i] = true;
						playedFirst[i] = true;
						res++;
					}
					else if (bi[i]< minRequieredForSec) minRequieredForSec = bi[i];
				}
			}
			if (!findNotPlayed)
			{	
				doneSecond = true;
				break;
			}
			findNotPlayed = false;
			if (!achieved && !doneFirst)
			{	
				for (Integer i: noSpecial) {
					if (!playedFirst[i]) {
						findNotPlayed = true;
						if (curStars >= ai[i]) {
							if (curStars + 1 == minRequieredForSec)
							{
								playedFirst[i] = true;
								achieved = true;
								curStars++;
								res++;
								continue out;
							}
						}
					}
				}
				if (!achieved)
					for (Integer i: special) 
					{
						if (!playedFirst[i]) {
							findNotPlayed = true;
							if (curStars >= ai[i]) {
								achieved = true;
								curStars += 2;
								res+= 2;
								playedFirst[i] = true;
								playedSecond[i] = true;
								continue out;
							}
						}
					}
				if (!achieved)
					for (Integer i: special) 
					{
						if (!playedFirst[i]) {
							findNotPlayed = true;
							if (curStars >= ai[i]) {
									playedFirst[i] = true;
									achieved = true;
									curStars++;
									res++;
									continue out;
							}
						}
					}
				if (!findNotPlayed) doneFirst = true; 
				if (!achieved) return -1;
			}
			else if (!achieved && doneFirst)
			{	
				return -1;
			}
			
		}	
		return res;
	}
	
	public static void main (String[] args) throws NumberFormatException, IOException
	{
		BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
		FileWriter writer = new FileWriter("output.txt");
		BufferedWriter bufferedWriter = new BufferedWriter(writer);
		int numberOfCases = Integer.parseInt(reader.readLine());
		for (int i = 0; i < numberOfCases; i++)
		{
			String buf = reader.readLine();
			int numberOfLevels = Integer.parseInt(buf);
			int[] firstStars = new int[numberOfLevels];
			int[] secondStars = new int[numberOfLevels]; 
			for (int j=0; j<numberOfLevels;j++){
				String[] buf2 = reader.readLine().split(" ");
				firstStars[j] = Integer.parseInt(buf2[0]);
				secondStars[j] = Integer.parseInt(buf2[1]);
			}
			KingdomRush kr = new KingdomRush(numberOfLevels, firstStars, secondStars);
			int res = kr.solve();
			if (res == -1) bufferedWriter.write("Case #" + (i+1) +": " + "Too Bad");
			else bufferedWriter.write("Case #" + (i+1) +": " + res);
			bufferedWriter.newLine();
		}
		bufferedWriter.flush();
		bufferedWriter.close();
		reader.close();
	}
}
