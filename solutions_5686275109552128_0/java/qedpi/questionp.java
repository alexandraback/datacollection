import java.io.*;
import java.util.*;

public class questionp
{
	public static void main(String[] args) throws IOException
	{
	//pancakes
		File f = new File("test.txt");
		Scanner in = new Scanner(f);
		PrintWriter out = new PrintWriter(new FileWriter("testout.txt"));
		int numCases = in.nextInt();
		in.nextLine();

		//problem specific
		int leng;
		int maxCake;
		int limit;
		int curSum, minSum;
		String output;
		
		for(int i = 0; i < numCases; i++){
			minSum = 1000; 
			leng = in.nextInt();
			int[] cakes = new int[leng];
				//read data
			for( int j = 0; j < leng; j++){	//for each beginning pancake
				cakes[j] = in.nextInt();
			}
			
			Arrays.sort(cakes);
			maxCake = cakes[leng - 1];
			
			for(int k = 1; k <= maxCake; k++){	 //for each max pancake size allowed
				curSum = k;
				for( int m = 0; m < leng; m++){	//for each cake
					curSum += Math.ceil(((double)(cakes[m]))/k) - 1;
				}
				minSum = Math.min(minSum, curSum);
			}
			
			output = "Case #" + (i + 1) + ": " + minSum;
			if (i == numCases - 1){ //last case
				out.print(output);
			} else {
				out.println(output);			
			}
		}
		out.close();
	}
}
