import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Qb {
	
	public void solve(Scanner scan, PrintWriter out) {
		double C = scan.nextDouble();
		double F = scan.nextDouble();
		double X = scan.nextDouble();
		
		double rate = 2;
		double time = 0;
		
		while (true) {
			double timeToTarget = X/rate;
			double timeWithFarm = C/rate + X/(rate+F);
			if (timeToTarget > timeWithFarm) {
				time += C/rate;
				rate += F;
			} else {
				time += timeToTarget;
				break;
			}
		}
		
		System.out.println(time);
		out.println(time);
	}
	
	public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(new FileReader("inputqb.in"));
        PrintWriter out = new PrintWriter("outputqb.txt");
        int problems = scan.nextInt();
        for (int count = 0; count < problems; count++) {
            System.out.print("Case #" + (count+1) + ": ");
            out.print("Case #" + (count+1) + ": ");
            new Qb().solve(scan, out);
        }
        out.flush();
        out.close();
        scan.close();
    }
	
}