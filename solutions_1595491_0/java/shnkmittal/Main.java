import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;


public class Main {

	public static int findX(int x, int y, int z, int score)
	{
		int a = -1;
		
		a = (score - x-y-z)/3;
		if(a+x + a+y + a+z == score)
			return a+x;
		else
			return -1;
	}
	
	public static int findValid(int score, int max) {
		int x=-1, y=-1,z=-1;
		int evalid = 0;
		/*Case: x x x*/
		if( (x = findX(0,0,0, score))!= -1 && evalid != 2)
		{
			y=z=x;
			if(z >= max)
				evalid = 2;
			else
				evalid = 1;
		}
	
		/*Case: x x x+1*/
		if( (x = findX(0,0,1, score))!= -1 && evalid !=2)
		{
			y=x;
			z=x+1;
			if(z >= max)
				evalid = 2;
			else
				evalid = 1;
		}
		
		/*Case: x x+1 x+1*/
		if( (x = findX(0,1,1, score))!= -1 && evalid != 2)
		{
			y=x+1;
			z=x+1;
			if(z >= max)
				evalid = 2;
			else
				evalid = 1;
		}
		return evalid;
	}
	
	public static int findSurprised(int score, int max) {
		int x=-1, y=-1,z=-1;
		int evalid = 0;
		/*Case: x x x+2*/
		if( (x = findX(0,0,2, score))!= -1 && evalid != 2)
		{
			y=x;
			z=x+2;
			if(z >= max)
				evalid = 2;
			else
				evalid = 1;
		}
	
		/*Case: x x+1 x+2*/
		if( (x = findX(0,1,2, score))!= -1 && evalid !=2)
		{
			y=x+1;
			z=x+2;
			if(z >= max)
				evalid = 2;
			else
				evalid = 1;
		}
		
		/*Case: x x+2 x+2*/
		if( (x = findX(0,2,2, score))!= -1 && evalid != 2)
		{
			y=x+2;
			z=x+2;
			if(z >= max)
				evalid = 2;
			else
				evalid = 1;
		}
		return evalid;
	}
	
	public static void fillOptions(int[] scores, int[] valid, int[]surprised, int max )
	{
		for(int i = 0; i< scores.length; i++)
		{
			valid[i] = findValid(scores[i], max);
			surprised[i] = findSurprised(scores[i], max);
			valid[i] = valid[i]*10 + surprised[i];
		}
	}
	
	public static int findNextSerprised(int[] valid)
	{
		int val =0;
		Arrays.sort(valid);
		int index = Arrays.binarySearch(valid, 2);
		if(index < 0)
			index = Arrays.binarySearch(valid, 12);
		if(index < 0)
			index = Arrays.binarySearch(valid, 22);
		if(index < 0)
			index = Arrays.binarySearch(valid, 01);
		if(index < 0)
			index = Arrays.binarySearch(valid, 11);
		if(index < 0)
			index = Arrays.binarySearch(valid, 21);
		if(index >= 0)
		{
			val = valid[index];
			valid[index] = 0;
		}
		return val;
	}
	
	public static void runCase (int[] scores, int S, int max, int caseNum)
	{
		int[] valid = new int[scores.length];
		int[] surprised = new int[scores.length];
		int count =0;
		fillOptions(scores, valid, surprised, max);
		for(int i =0; i< S; i++)
		{
			int val = findNextSerprised(valid);
			if(val%10 == 2)
				count++;
		}
		for(int i=0; i< scores.length; i++)
			if(valid[i] >= 20)
				count++;
		System.out.print("Case #" +caseNum + ": "+ count + "\n");
	}
	
	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		if(args.length != 1)
		{
			System.out.print("Please enter file name!\n");
			return;
		}
		File fileName = new File(args[0]);
	    Scanner inFile = new Scanner(fileName);
	    int T = inFile.nextInt();
		for(int i=0; i < T; i++)
		{
			int N = inFile.nextInt();
			int S = inFile.nextInt();
			int max = inFile.nextInt();
			
			int[] scores = new int[N];
			for(int j=0; j<N; j++)
				scores[j]=inFile.nextInt();
			
			runCase(scores, S, max, i+1);	
		}
		
		
	}

}
