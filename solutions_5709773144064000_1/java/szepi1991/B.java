import java.io.BufferedInputStream;
import java.util.Scanner;


public class B {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));

		int T =	sc.nextInt();
		for (int t = 1; t <= T; ++t) {
			// if win <= farmcost... just exit
			// otherwise it makes sense to take farm iff 
			//		with 1 farm we can win faster
			double C = sc.nextDouble(); // cost of farm
			double F = sc.nextDouble(); // added rate / farm
			double X = sc.nextDouble(); // winning cookie
			double curRate = 2.0; // initial rate
			double nextRate = curRate + F;
			
			double timeSoFar = 0;
			double withoutFarm;
			double withFarm;
			while ((withoutFarm = X / curRate) > (withFarm = (C / curRate) + (X / nextRate))) {
				timeSoFar += (C / curRate);
				curRate = nextRate;
				nextRate += F;
			}
			timeSoFar += withoutFarm;
			System.out.println("Case #" + t + ": " + timeSoFar);
		}


	}

}
