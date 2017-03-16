package r1c;

import java.io.File;
import java.util.Scanner;

public class A {
	public static String inFile = "res/A-small-attempt1.in";
	
	public static void main(String[] args) throws Exception
	{
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(new File(inFile));
		int T = scanner.nextInt();
		
		for (int t = 1; t <= T; t++)
		{
			int R = scanner.nextInt();
			int C = scanner.nextInt();
			int W = scanner.nextInt();
			int moves = solve(R, C, W);
			System.out.println("Case #" + t + ": " + moves);
		}
		
		scanner.close();
	}
	
	
	public static int solve(int R, int C, int W)
	{
		int out = (C / W) * R;
		out += W - 1;
		if (C % W != 0) out += 1;
		return out;
	}

}
