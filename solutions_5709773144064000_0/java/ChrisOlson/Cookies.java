import java.io.PrintWriter;
import java.util.Scanner;


public class Cookies {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int numCases = in.nextInt();
		 int caseN;
		 double R, C, M;
		try{
			PrintWriter writer = new PrintWriter("C:\\Users\\christopher.j.olson\\Desktop\\Cookie_small.txt");

			for (caseN = 1; numCases > 0; numCases--, caseN++) {
				R = in.nextDouble();
				C = in.nextDouble();
				M = in.nextDouble();

				writer.print("Case #" + caseN + ": ");
				writer.println(String.format("%1$,.7f",solve(R, C, M)));
			}
			writer.flush();
			writer.close();
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
	}
	
	public static double solve(double C, double F, double X){
		double profit = 2.0f;
		double time = 0.0f;
		double minTime = X / 2.0f;
		double timeToG;
		while(time < minTime){
			time += C / profit;
			profit += F;
			timeToG = X / profit;
			
			if(time + timeToG < minTime) minTime = time + timeToG;
			
		}
		
		return minTime;
	}

}
