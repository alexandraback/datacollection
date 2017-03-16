package round1c;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Pogo
{
	public static final String DATA_SET = "B-small-attempt0";

	public static final String RESOURCE_DIR = "C:/Dev/Test/resources/";
	public static final String BASE_FILE_NAME = RESOURCE_DIR + Pogo.class.getPackage().getName() + "/" + Pogo.class.getSimpleName() + "/" + DATA_SET;
	public static final String INPUT_FILE_NAME = BASE_FILE_NAME + ".in";
	public static final String OUTPUT_FILE_NAME = BASE_FILE_NAME + ".out";

	public void solve(Scanner in, PrintWriter out)
	{
		int X = in.nextInt();
		int Y = in.nextInt();
		StringBuilder sb = new StringBuilder();
		int cX = 0;
		int cY = 0;
		int stepSize = 1;
		int stepCount = 0;
		while (cX != X || cY != Y)
		{
			int xDist = Math.abs(X - cX);
			int yDist = Math.abs(Y - cY);
			if (xDist > yDist)
			{
				if ((cX < X && stepSize <= xDist) ||
				    (cX > X && stepSize > xDist))
				{
					cX += stepSize;
					sb.append("E");
				}
				else
				{
					cX -= stepSize;
					sb.append("W");
				}
			}
			else
			{
				if ((cY < Y && stepSize <= yDist) ||
				    (cY > Y && stepSize > yDist))
				{
					cY += stepSize;
					sb.append("N");
				}
				else
				{
					cY -= stepSize;
					sb.append("S");
				}
			}
			stepSize++;
			stepCount++;
//			System.out.println(stepCount + ": " + sb);
			if (stepCount > 500)
			{
				System.err.println("BAD!");
				break;
			}
		}
		System.out.println(stepCount);
		out.println(sb);
	}

	public static void main(String[] args) throws FileNotFoundException
	{
		File inFile = new File(INPUT_FILE_NAME);
		File outFile = new File(OUTPUT_FILE_NAME);
		Pogo instance = new Pogo();
		Scanner in = new Scanner(inFile);
		PrintWriter out = new PrintWriter(outFile);
		long start = System.currentTimeMillis();
		final int numCases = in.nextInt();
		for (int caseNum = 1; caseNum <= numCases; caseNum++)
		{
			System.out.println("Starting Case #" + caseNum);
			out.print("Case #" + caseNum + ": ");
			instance.solve(in, out);
		}
		System.out.println("Total time: " + (System.currentTimeMillis() - start) + "ms");
		out.close();
		in.close();
	}
}
