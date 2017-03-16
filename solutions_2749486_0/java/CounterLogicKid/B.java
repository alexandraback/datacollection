package Round1C;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
public class B {

	public static void main(String[] args) throws IOException{
		Scanner k = new Scanner(System.in);
		
		int T = k.nextInt(); k.nextLine();
		
		String[] solution = new String[T];
		
		for (int a = 1; a <= T; a++)
		{
			int x = k.nextInt(); int y = k.nextInt();
			k.nextLine();
			
			String hori, vert;
			if (x > 0)
			{
				hori = "";
				for (int b = 0; b < x; b++)
				{
					hori += "WE";
				}
			}
			else if (x==0)
			{
				hori = "";
			}
			else
			{
				hori = "";
				for (int b = 0; b > x; b--)
				{
					hori += "EW";
				}
			}
			
			if (y > 0)
			{
				vert = "";
				for (int b = 0; b < y; b++)
				{
					vert += "SN";
				}
			}
			else if (y==0)
			{
				vert = "";
			}
			else
			{
				vert = "";
				for (int b = 0; b > y; b--)
				{
					vert += "NS";
				}
			}
			String total = hori + vert;
			String ans = "Case #" + a + ": " + total;
			solution[a-1] = ans;
		}
		printOutAnswers(solution);
	}
	public static void printOutAnswers(String[] solution) throws IOException
	{
		//print out caseStorer and write to a file
		PrintWriter out = new PrintWriter(new FileWriter("/Users/davidlong"+
		"/Desktop/javaoutputs/B.txt"));
		
		for (int x = 0; x < solution.length; x++)
		{
			out.println(solution[x]);
			System.out.println(solution[x]);
		}
		
		out.close();
	}
}
