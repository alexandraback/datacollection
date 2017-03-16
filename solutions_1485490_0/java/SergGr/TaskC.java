import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class TaskC
{

	static class LineOutput
	{
		int type;
		BigInteger count;

		LineOutput(StringTokenizer stringTokenizer)
		{
			count = new BigInteger(stringTokenizer.nextToken());
			type = Integer.parseInt(stringTokenizer.nextToken());
		}
	}

	static List<LineOutput> readLine(String line, int count)
	{
		List<LineOutput> res = new ArrayList<LineOutput>(count);
		StringTokenizer stringTokenizer = new StringTokenizer(line);
		for (int i = 0; i < count; i++)
		{
			res.add(new LineOutput(stringTokenizer));
		}
		return res;
	}

	static class Position
	{
		BigInteger sum = BigInteger.ZERO;
		int aPos = 0;
		BigInteger aUsed = BigInteger.ZERO;
		int bPos = 0;
		BigInteger bUsed = BigInteger.ZERO;

	}

	static BigInteger solveUseA(Position pos, List<LineOutput> A, List<LineOutput> B)
	{
		Position nextPosition = new Position();
		LineOutput a = A.get(pos.aPos);
		nextPosition.sum = pos.sum;
		nextPosition.aUsed = pos.aUsed;
		nextPosition.aPos = pos.aPos;
		nextPosition.bUsed = BigInteger.ZERO;
		for (int i = pos.bPos + 1; i < B.size(); i++)
		{
			LineOutput b = B.get(i);
			if (b.type == a.type)
			{
				nextPosition.bPos = i;
				return solve(nextPosition, A, B);
			}
		}
		return BigInteger.ZERO;
	}

	static BigInteger solveUseB(Position pos, List<LineOutput> A, List<LineOutput> B)
	{
		Position nextPosition = new Position();
		LineOutput b = B.get(pos.bPos);
		nextPosition.sum = pos.sum;
		nextPosition.bUsed = pos.bUsed;
		nextPosition.bPos = pos.bPos;
		nextPosition.aUsed = BigInteger.ZERO;
		for (int i = pos.aPos + 1; i < A.size(); i++)
		{
			LineOutput a = A.get(i);
			if (b.type == a.type)
			{
				nextPosition.aPos = i;
				return solve(nextPosition, A, B);
			}
		}
		return pos.sum;
	}

	static BigInteger solveSkipBoth(Position pos, List<LineOutput> A, List<LineOutput> B)
	{
		Position nextPosition = new Position();
		nextPosition.sum = pos.sum;
		nextPosition.sum = pos.sum;
		nextPosition.aPos = pos.aPos + 1;
		nextPosition.aUsed = BigInteger.ZERO;
		nextPosition.bPos = pos.bPos + 1;
		nextPosition.bUsed = BigInteger.ZERO;
		return solve(nextPosition, A, B);
	}

	static BigInteger solve(Position pos, List<LineOutput> A, List<LineOutput> B)
	{
		if ((pos.aPos >= A.size()) || (pos.bPos >= B.size()))
			return pos.sum;

		LineOutput a = A.get(pos.aPos);
		LineOutput b = B.get(pos.bPos);
		if (a.type == b.type)
		{
			BigInteger aLeft = a.count.subtract(pos.aUsed);
			BigInteger bLeft = b.count.subtract(pos.bUsed);

			Position next = new Position();
			BigInteger used = aLeft.min(bLeft);
			next.sum = pos.sum.add(used);
			next.aPos = pos.aPos;
			next.aUsed = pos.aUsed.add(used);
			next.bPos = pos.bPos;
			next.bUsed = pos.bUsed.add(used);

			if (next.aUsed.equals(a.count))
			{
				next.aPos += 1;
				next.aUsed = BigInteger.ZERO;
			}

			if (next.bUsed.equals(b.count))
			{
				next.bPos += 1;
				next.bUsed = BigInteger.ZERO;
			}
			return solve(next, A, B);
		}
		else
		{
			BigInteger useA = solveUseA(pos, A, B);
			BigInteger useB = solveUseB(pos, A, B);
			BigInteger skipBoth = solveSkipBoth(pos, A, B);
			return useA.max(useB).max(skipBoth);
		}
	}

	static BigInteger calc(List<LineOutput> A, List<LineOutput> B)
	{
		Position pos = new Position();
		return solve(pos, A, B);
//		return BigInteger.ZERO;
	}


	public static void main(String[] args) throws IOException
	{
//		final String baseFileName = "taskC";
		final String baseFileName = "C-small-attempt0";
//		final String baseFileName = "C-small-attempt1";
//		final String baseFileName = "C-large";
		PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(baseFileName + ".out")));
		BufferedReader reader = new BufferedReader(new FileReader(baseFileName + ".in"));


		String inLine;
		inLine = reader.readLine();
		final int T = Integer.parseInt(inLine);
		for (int caseIndex = 1; caseIndex <= T; caseIndex++)
		{
			inLine = reader.readLine();
			StringTokenizer st = new StringTokenizer(inLine);

			final int N = Integer.parseInt(st.nextToken());
			final int M = Integer.parseInt(st.nextToken());
			List<LineOutput> A = readLine(reader.readLine(), N);
			List<LineOutput> B = readLine(reader.readLine(), M);
			BigInteger res = calc(A, B);
			writer.printf("Case #%d: %s\r\n", caseIndex, res.toString());
			writer.flush();
		}

		writer.close();
	}
}

