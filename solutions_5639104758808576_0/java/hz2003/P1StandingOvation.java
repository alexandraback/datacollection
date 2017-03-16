package QualificationRound;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class P1StandingOvation {
	public static int numberOfFriends(String str)
	{
		int sum[] = new int[str.length()];
		int max = 0;
		sum[0] = str.charAt(0) - '0';
		for(int i = 1; i < sum.length; i++)
		{
			int n = str.charAt(i) - '0';
			sum[i] = sum[i - 1] + n;
			if(n > 0 && (i - sum[i - 1] > max))
				max = i - sum[i - 1];
		}
		return max;
	}
	public static void main(String[] args) {
		File fin = new File("src/QualificationRound/p1.in.txt");
		Scanner scan;
		try {
			scan = new Scanner(fin);
		
			PrintWriter output = new PrintWriter("src/QualificationRound/p1.out.txt");
			int N = scan.nextInt();
			for(int i = 0; i < N; i++)
			{
				int n = scan.nextInt();
				String str = scan.next();
				output.println("Case #" + (i + 1) + ": " + numberOfFriends(str));
			}
			scan.close();
			output.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}