import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class MinesweeperMaster {

	/**
	 * @param args input arguments.  First and only expected parameter is the input filename
	 * 
	 * for the output, everything is printed to screen, and piped to a file.
	 * Input is expected to be correct and don't foresee any error handling for wrong input.
	 * 
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// open file and create a buffered reader
		FileReader input = new FileReader(args[0]);
		BufferedReader buffer = new BufferedReader(input);
		
		//read the number of testcases
		int max = Integer.parseInt(buffer.readLine().trim());
		
		// read a line and call the solving procedure for a single test case.  We expect back the result as a string
		for (int i = 1; i <= max; i++) {
			System.out.println("Case #"+i+":");
			solve(buffer.readLine());
		}

	}

	private static void solve(String input) {
		String[] split = input.split("\\s+");
		int R = Integer.parseInt(split[0]);
		int C = Integer.parseInt(split[1]);
		int M = Integer.parseInt(split[2]);
		int open = R*C-M;
		
		// always possible if one of R,C is 1
		if(R == 1)
		{
			for(int i = 1; i < C; i++)
			{
				if(i <= M)
				{
					System.out.print("*");
				} else {
					System.out.print(".");
				}
			}
			System.out.println("c");
			return;
		}
		if(C == 1)
		{
			for(int i = 1; i < R; i++)
			{
				if(i <= M)
				{
					System.out.println("*");
				} else {
					System.out.println(".");
				}
			}
			System.out.println("c");
			return;
		}

		// only one free space can be anywhere
		if(open == 1)
		{
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if(i+j==0)
					{
						System.out.print("c");
					} else {
						System.out.print("*");
					}
				}
				System.out.println();
			}
			return;
		}
		
		//a few impossible combinations
		if(open < 4 || open == 5 || open == 7)
		{
			System.out.println("Impossible");
			return;
		}

		
		// R or C is 2
		if(C == 2)
		{
			if(M%2 == 1)
			{
				System.out.println("Impossible");
				return;
			}
			M /= 2;
			for(int i = 1; i < R; i++)
			{
				if(i <= M)
				{
					System.out.println("**");
				} else {
					System.out.println("..");
				}
			}
			System.out.println(".c");
			return;
			
		}

		if(R == 2)
		{
			if(M%2 == 1)
			{
				System.out.println("Impossible");
				return;
			}
			M/=2;
			for(int i = 1; i < C; i++)
			{
				if(i <= M)
				{
					System.out.print("*");
				} else {
					System.out.print(".");
				}
			}
			System.out.println(".");
			for(int i = 1; i < C; i++)
			{
				if(i <= M)
				{
					System.out.print("*");
				} else {
					System.out.print(".");
				}
			}
			System.out.println("c");
			return;
		}
		
		
		// easy case, lots of open spaces
		if(open >= 2*(C+R-2))
		{
			for(int i = 0; i < R-2; i++)
			{
				for(int j = 0; j < C-2; j++)
				{
					if(M > 0)
					{
						System.out.print("*");
						M--;
					} else {
						System.out.print(".");
					}
				}
				System.out.println("..");
			}
			for (int j = 1; j < C; j++)
			{
				System.out.print(".");
			}
			System.out.println(".");
			for (int j = 1; j < C; j++)
			{
				System.out.print(".");
			}
			System.out.println("c");
			return;
		}
		
		String end = new String("");
		for(int j = 3; j < C; j++)
		{
			end+= "*";
		}
		
		if(open > 7)
		{
			open -= 9;
			String firstend = new String("");
			for(int j = 3; j < C; j++)
			{
				if(open > 0)
				{
					firstend+= ".";
					open -= 2;
				} else {
					firstend+= "*";
				}
			}
			
			System.out.println("c.."+firstend);
			System.out.println("..."+firstend);
			if(open%2 == 0)
			{
				System.out.println("..."+end);
			} else {
				System.out.println("..*"+end);
			}
			for(int i = 3; i < R; i++)
			{
				if(open > 0)
				{
					System.out.println("..*"+end);
					open -= 2;
				} else {
					System.out.println("***"+end);
				}
			}
			return;
		}
		
		// 4, 6 open spaces 
		if(open == 4)
		{
			System.out.println("c.*"+end);
			System.out.println("..*"+end);
			System.out.println("***"+end);
		} else if(open == 6) {
			System.out.println("c.."+end);
			System.out.println("..."+end);
			System.out.println("***"+end);
		}
		for(int i = 3; i < R; i++)
		{
			System.out.println("***"+end);
		}
		
		
		return;
		
		
		
	}


	
}
