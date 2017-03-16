import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;


public class Main {

	public static int findMin (int[]A, int value, int[] used) {
		for(int i=0; i< A.length; i++) {
			if((used[i] !=1) && (value >= A[i]))
				return i;
		}
		return -1;
	}
	
	public static void countGames(int N, int[]A, int[]B, int caseNum) {
		int count = 0;
		int value = 0;
		int pos = -1;
		int [] used_A = new int[A.length];
		int [] used_B = new int[B.length];
				
		while(value < 2*N)
		{
			// Find any 2* game
			pos = findMin(B, value, used_B);
			if(pos < 0)
			{
				//Find any 1* game
				pos = findMin(A, value, used_A);
				if(pos >= 0) {
					value = value + 1;
					used_A[pos] = 1;
					count++;
				} else {
					break;					
				}
			} else {
				if(used_A[pos] == 1)
					value = value +1;
				else
					value = value +2;
			
				used_A[pos] = 1;
				used_B[pos] = 1;
				count++;
			}
		}	
		
		System.out.print("Case #"+ caseNum + ": ");
		if(value == 2*N)
			System.out.print(count + "\n");
		else
			System.out.print("Too Bad\n");
	}
	
	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		
		File ffile = new File(args[0]);
		Scanner scanner;
		scanner = new Scanner(new FileReader(ffile));
		
		int T;
		T = scanner.nextInt();
		
		for(int i=0; i<T; i++) {
			int N = scanner.nextInt();
			int[] A = new int[N];
			int[] B = new int[N];
			
			for(int j=0; j<N; j++)
			{
				A[j] = scanner.nextInt();
				B[j] = scanner.nextInt();
			}
			countGames(N, A, B, i+1);
			
		}
	}

}
