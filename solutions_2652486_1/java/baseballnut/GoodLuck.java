package gcj2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class GoodLuck 
{
	public String solve(String[] guesses, int R, int N, int M, int K, int caseNr)
	{
		StringBuffer sb = new StringBuffer("");
		sb.append("Case #");
		sb.append(caseNr);
		sb.append(": \n");
		sb.append(guess(guesses, R, N, M, K));
		return sb.toString();
	}

	private String guess(String[] guesses, int R, int N, int M, int K)
	{
		StringBuffer result = new StringBuffer("");
		for (int i = 0; i < R; i++)
		{
			int[] tries = new int[K];
			String[] parts = guesses[i].split(" ");
			for (int k = 0; k < K; k++) tries[k] = new Integer(parts[k]).intValue();
			int[] finalGuess = new int[N];
			for (int k = 0; k < N; k++) finalGuess[k] = 1;
			int guessed = 0;
			for (int j = 0; j < K; j++)
			{
				if (tries[j] > 1)
				{ //analyze factors
					int toGuess = tries[j];
					for (int k = 0; k < N && finalGuess[k] > 1; k++)
					{
						if (toGuess%finalGuess[k] == 0)
						{
							toGuess = toGuess/finalGuess[k];
						}
					}
					
//					if (singleFactor(toGuess))
					if (toGuess == 2)
					{
						boolean foundFactor = false;
						for (int k = 0; k < N && !foundFactor; k++)
						{
//							if (finalGuess[k] == toGuess) foundFactor = true;
//							else 
							if (finalGuess[k] == 1) 
							{
								finalGuess[k] = toGuess;
								foundFactor = true;
								guessed += 1;
							}
						}
					}
					
//					int quad = divide(toGuess, 3);
					int quad = power(toGuess, 3);
					if (quad > 0)
					{
						int factorsFound = 0;
						for (int k = 0; k < N && factorsFound < quad; k++)
						{
							if (finalGuess[k] == 1)
							{
								finalGuess[k] = 3;
								factorsFound += 1;
								toGuess = toGuess/3;
								guessed += 1;
							}
						}
					}
					
					quad = divide(toGuess, 5);
					if (quad > 0)
					{
						int factorsFound = 0;
						for (int k = 0; k < N && factorsFound < quad; k++)
						{
							if (finalGuess[k] == 1)
							{
								finalGuess[k] = 5;
								factorsFound += 1;
								toGuess = toGuess/5;
								guessed += 1;
							}
						}
					}
					
					quad = divide(toGuess, 7);
					if (quad > 0)
					{
						int factorsFound = 0;
						for (int k = 0; k < N && factorsFound < quad; k++)
						{
							if (finalGuess[k] == 1)
							{
								finalGuess[k] = 7;
								factorsFound += 1;
								toGuess = toGuess/7;
								guessed += 1;
							}
						}
					}
					
					quad = divide(toGuess, 2);
					if (quad > N-guessed)
					{	//at least quad-(N-guessed) 4's
						int fours = quad-(N-guessed);
						int factorsFound = 0;
						for (int k = 0; k < N && factorsFound < fours; k++)
						{
							if (finalGuess[k] == 1)
							{
								finalGuess[k] = 4;
								factorsFound += 1;
								toGuess = toGuess/4;
								guessed += 1;
							}
						}
					}
					
					if ((toGuess > 1) && (guessed == N-1) && (toGuess <= M))
					{
						finalGuess[N-1] = toGuess;
						guessed += 1;
					}
				}
			}
			StringBuffer temp = new StringBuffer("");
			int nextAppend = 2;
			for (int j = 0; j < N; j++)
			{
				if (finalGuess[j] > 1)
				{
					temp.append(finalGuess[j]);
				}
				else 
				{
					temp.append(nextAppend);
					nextAppend += 1;
					if (nextAppend > M) nextAppend = 2;
				}
			}
			temp.append("\n");
			result.append(temp.toString());
		}
		return result.toString();
	}
	
	private int divide(int guess, int factor)
	{
		int result = 0;
		int temp = guess;
		boolean foundAll = false;
		while (!foundAll)
		{
			if (temp%factor == 0)
			{
				result += 1;
				temp = temp/factor;
				if (temp == 1) foundAll = true;
			}
			else foundAll = true;
		}
		
		return result;
	}
	
	private int power(int guess, int factor)
	{
		int temp = guess;
		int result = 0;
		while (temp%factor == 0)
		{
			temp = temp/factor;
			result += 1;
		}
		
		if (temp == 1) return result;
		
		return 0;
	}
	
	private boolean singleFactor(int j)
	{
		if (j < 4) return true;
		if (j == 5) return true;
		if (j == 7) return true;
		return false;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		GoodLuck test = new GoodLuck();
		String fileName = "C-small-2-attempt0.in.txt";
//		String fileName = "in.txt";
		String outName = "outCsmall2.txt";
		try
		{
			BufferedReader br = new BufferedReader(new FileReader(fileName));
			String line = br.readLine();
			BufferedWriter bw = new BufferedWriter(new FileWriter(outName));
			int tests = new Integer(line).intValue();
			for (int i = 0; i < tests; i++)
			{
				line = br.readLine();
				String[] parts = line.split(" ");
				int R = new Integer(parts[0]).intValue();
				int N = new Integer(parts[1]).intValue();
				int M = new Integer(parts[2]).intValue();
				int K = new Integer(parts[3]).intValue();
				String[] guesses = new String[R];
				for (int j = 0; j < R; j++) guesses[j] = br.readLine();
				String line2 = test.solve(guesses, R, N, M, K, i+1);
				System.out.println(line2);
				bw.write(line2+"\n");
			}
			bw.flush();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}		
	}

}
