import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class TaskA
{
	enum Result
	{
		Diamond,
		Non,
		Continue
	}


	static class Inheritance
	{
		final int N;
		final List<List<Integer>> origInheritance;
		final List<List<Integer>> inheritance;
		List<List<Integer>> newInheritance;

		static List<List<Integer>> deepCopy(List<List<Integer>> src)
		{
			List<List<Integer>> dst = new ArrayList<List<Integer>>();
			for (List<Integer> list : src)
			{
				dst.add(new ArrayList<Integer>(list));
			}
			return dst;
		}

		Inheritance(int n, List<List<Integer>> inheritance)
		{
			N = n;
			origInheritance = deepCopy(inheritance);
			this.inheritance = deepCopy(inheritance);
			newInheritance = deepCopy(inheritance);
		}

		Result findNext()
		{
			List<List<Integer>> oldNewInheritance = newInheritance;
			newInheritance = new ArrayList<List<Integer>>();
			boolean hasNew = false;
			for (int i = 0; i < oldNewInheritance.size(); i++)
			{
				List<Integer> knownBaseList = inheritance.get(i);
				List<Integer> nextBaseList = new ArrayList<Integer>();
				newInheritance.add(nextBaseList);
				List<Integer> newBaseList = oldNewInheritance.get(i);
				for (int newBase : newBaseList)
				{
//					for (int nextBase : inheritance.get(newBase))
					for (int nextBase : origInheritance.get(newBase))
					{
						if (knownBaseList.contains(nextBase))
						{
							System.out.println(i + " " + nextBase);
							return Result.Diamond;
						}


						hasNew = true;
						knownBaseList.add(nextBase);
						nextBaseList.add(nextBase);
					}
				}
			}
			return hasNew ? Result.Continue : Result.Non;
		}

		boolean solve()
		{
			while (true)
			{
				Result res = findNext();
				if (res == Result.Diamond)
					return true;
				else if (res == Result.Non)
				{
					System.out.println("No");

					return false;
				}
			}
		}
	}


	public static void main(String[] args) throws IOException
	{
//		PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("taskA.out")));
//		BufferedReader reader = new BufferedReader(new FileReader("taskA.in"));

//		final String baseFileName = "taskA";
//		final String baseFileName = "A-small-attempt0";
//		final String baseFileName = "A-small-attempt1";
		final String baseFileName = "A-large";
		PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(baseFileName + ".out")));
		BufferedReader reader = new BufferedReader(new FileReader(baseFileName + ".in"));


		String inLine;
		inLine = reader.readLine();
		final int T = Integer.parseInt(inLine);
		for (int caseIndex = 1; caseIndex <= T; caseIndex++)
		{
			inLine = reader.readLine();
			final int N = Integer.parseInt(inLine);
			List<List<Integer>> inheritanceMap = new ArrayList<List<Integer>>();
			for (int i = 0; i < N; i++)
			{
				List<Integer> list = new ArrayList<Integer>();
				inLine = reader.readLine();
				StringTokenizer st = new StringTokenizer(inLine);
				int M = Integer.parseInt(st.nextToken());
				for (int j = 0; j < M; j++)
				{
					list.add(Integer.parseInt(st.nextToken()) - 1);
				}
				inheritanceMap.add(list);
			}
			Inheritance inheritance = new Inheritance(N, inheritanceMap);
			System.out.println(caseIndex);
			boolean res = inheritance.solve();

			writer.printf("Case #%d: %s\r\n", caseIndex,
						  res ? "Yes" : "No");
		}

		writer.close();
	}
}

