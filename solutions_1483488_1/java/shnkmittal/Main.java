import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	
	public static int numShift(int A, int digit){

		int num = 0, div;
		num = A %10;
		div = A /10;
		for(int i=1; i < digit ; i++)
		{
			num = num*10;
		}
		num = num + div;
		return num;
	}
	

	public static int recycleCount(int A, int B)
	{
		int count = 0;
		int num = A;
		String digit = "" + A;
		do
		{
			num = numShift(num, digit.length());
			if(num > A && num <= B)
				count++;
		}while(num != A);
		
		//System.out.print("Count: " + count + "\n");
		return count;
	}
	
	public static void runCase(int A, int B, int casenum)
	{
		int count =0;
		for(int i=A; i<B; i++)
		{
			count += recycleCount(i, B);
		}
		System.out.print("Case #" + casenum + ": " + count + "\n");
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		File ffile = new File(args[0]);
		Scanner scanner;
		scanner = new Scanner(new FileReader(ffile));
		
		int N = scanner.nextInt();
		int A, B;
		for(int i =0; i<N; i++)
		{
			A = scanner.nextInt();
			B = scanner.nextInt();
			runCase(A, B, i+1);
		}
		
	}

}
