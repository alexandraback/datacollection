import java.util.Arrays;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class War {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner (new File("war.in"));
		//Scanner in = new Scanner (System.in);
		int cases = in.nextInt();
		
		for (int caseNo = 1; caseNo <= cases; caseNo++)
		{
		   System.out.print("Case #" + caseNo + ": ");
		   solve (in);   
		}

	}

	private static void solve(Scanner in) {
		int size = in.nextInt();
		double[] her = new double[size];
		double [] him = new double[size];
		for (int i = 0; i < size; i++)
			her[i] = in.nextDouble();
		for (int i = 0; i < size; i++)
			him[i] = in.nextDouble();
		
		Arrays.sort(her);
		Arrays.sort(him);
		
		int fairWins = getFairWins (her, him);
		int cheatWins = getUnFairWins(her, him);
		
		System.out.println (cheatWins + " " + fairWins);
		
	}

	private static int getFairWins(double[] her, double[] him) {
		int result = 0;
		int size = him.length;
		int himEnd = size - 1;
		int herEnd = himEnd;
		
		for (int i = 0; i < size; i++)
			if (her[herEnd] > him[himEnd]) {
				result += 1;
				herEnd--;
			}
			else {
				himEnd--;
				herEnd--;
			
			}
		return result;
	}
	
	
	private static int getUnFairWins(double[] her, double[] him) {
		int result = 0;
		int size = him.length;
		int himIndex = 0;
		int herIndex = 0;
		
		for (int i = 0; i < size; i++)
			if (her[herIndex] > him[himIndex]) {
				result += 1;
				herIndex++;
				himIndex++;
			}
			else {
				herIndex++;
				//herEnd--;
			
			}
		return result;
	}
}