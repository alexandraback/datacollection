package googlecodejam;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
public class GoodLuckCase1 {

	/**
	 * T = 1.
	R = 100.
	N = 3.
	M = 5.
	K = 7.
	 */
	public static void main(String[] args) throws IOException{
		Scanner k = new Scanner(System.in);
		k.nextLine();
		k.nextLine();
		int r = 100, n = 3, m = 5, numProducts = 7;

		String[] solution = new String[r];
		
		for (int x = 1; x <= r; x++)
		{
			n = 3;
			
			//2, 3, 4, 5
			int[] numbers = new int[4];
			
			int[] products = new int[numProducts];
			for (int y = 0; y < numProducts; y++)
			{
				products[y] = k.nextInt();
			}
			k.nextLine();
			
			int[] temp = new int[4];
			int num;
			for (int y = 0; y < numProducts; y++)
			{
				Arrays.fill(temp, 0);
				
				num = products[y];
				System.out.println("Number is " + num);
				
				while(num%5 == 0)
				{
					num /= 5;
					temp[3]++;
				}
				while(num%4 == 0)
				{
					num /= 4;
					temp[2]++;
				}
				while(num%3 == 0)
				{
					num /= 3;
					temp[1]++;
				}
				temp[0] = temp[2]*2;
				while(num%2 == 0)
				{
					num /= 2;
					temp[0]++;
				}
				
				if(temp[0] > numbers[0])
					numbers[0] = temp[0];
				if(temp[1] > numbers[1])
					numbers[1] = temp[1];
				if(temp[2] > numbers[2])
					numbers[2] = temp[2];
				if(temp[3] > numbers[3])
					numbers[3] = temp[3];
			}
			System.out.println("Number of 5s: " + numbers[3]);
			System.out.println("Number of 4s: " + numbers[2]);
			System.out.println("Number of 3s: " + numbers[1]);
			System.out.println("Number of 2s: " + numbers[0]);
			int[] guess = new int[3];
			int numStart = 0;
			int sum = 0;
			//5
			sum += numbers[3];
			while (numStart < sum)
			{
				guess[numStart] = 5;
				numStart++;
			}
			//3
			sum += numbers[1];
			while (numStart < sum)
			{
				guess[numStart] = 3;
				numStart++;
			}
			//2s and 4s
			while (numStart < 3)
			{
				if(3-numStart < numbers[0])
				{
					guess[numStart] = 4;
					numbers[0] -= 2;
				}
				else if	(3-numStart == products[0])
				{
					guess[numStart] = 4;
					numbers[0]--;
				}
				else if ((int)(Math.random()*2)==1)
					guess[numStart] = 2;
				else
					guess[numStart] = 4;	
				numStart++;
			}
			solution[x-1] = "" + guess[0] + guess[1] + guess[2];
		}
		printOutAnswers(solution);
	}
	public static void printOutAnswers(String[] solution) throws IOException
	{
		//print out caseStorer and write to a file
		PrintWriter out = new PrintWriter(new FileWriter("/Users/davidlong"+
		"/Desktop/javaoutputs/GoodLuck.txt"));
		
		out.println("Case #1: ");
		
		for (int x = 0; x < solution.length; x++)
		{
			out.println(solution[x]);
			System.out.println(solution[x]);
		}
		
		out.close();
	}
}
