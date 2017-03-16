package QualificationRound;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class P4OminousOmino {
	public static boolean win(int x, int r, int c)
	{
		if((r * c) % x != 0)
			return false;
		if( x < 3)
			return true;
		if(x == 3)
			return  !(r == 1 || c == 1);
		if(x == 4)
			return (r >= 3) && (c >= 3);
		return false;
	}
	public static void main(String[] args) {
		/*
		for(int i = 1; i < 5; i++)
			for(int j = 1; j < 5; j++)
				for(int k = 1; k < 5; k++)
					System.out.println("" + i + " " + j + " " + k + 
							" Winner is:" + (win(i,j,k)? "GABRIEL":"RICHARD") );
		*/
		try{
			File fin = new File("src/QualificationRound/D-small-attempt1.in");
			Scanner scan = new Scanner(fin);
			PrintWriter output = new PrintWriter("src/QualificationRound/D-small-attempt1.out.txt");
			int N = scan.nextInt();
			for(int i = 0; i < N; i++)
			{
				boolean t = win(scan.nextInt(), scan.nextInt(), scan.nextInt());
				output.println("Case #" + (i + 1) + ": " + (t?"GABRIEL":"RICHARD"));
			}
			scan.close();
			output.close();
		}catch (Exception e)
		{
		}

	}
}
