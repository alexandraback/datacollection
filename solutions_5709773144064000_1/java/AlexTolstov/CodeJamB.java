import java.io.*;
import java.util.*;

public class CodeJamB {
	
	static final String path = "C:/gcj2014/Qual/B/";
	static final String problem = "B-small";
	
	Scanner in;
	static PrintWriter out;
	
	double solveOne() {
		double farmCost = in.nextDouble();
		double usualProduce = 2;
		double extraProduce = in.nextDouble();
		double target = in.nextDouble();
		double bestTime = Double.MAX_VALUE / 2020.;
		double speedFactor = 0;
		for (int usedFarms = 0; usedFarms < 100000; usedFarms++) {
			// сначала ∆адно набираем фермы, потом дорабатываем.
			double timeFarms = farmCost * speedFactor;
			double finalSpeed = usualProduce + extraProduce * usedFarms;
			
			speedFactor += 1 / finalSpeed;
			
			double timeFinish = target / finalSpeed;
			
			if (timeFarms + timeFinish < bestTime) {
				bestTime = timeFarms + timeFinish;
			}
		}
		return bestTime;
	}
	
	void solve() {
		in.useLocale(Locale.US);
		int nTests = in.nextInt();
		for (int i = 1; i <= nTests; i++) {
			out.println("Case #" + i + ": " + solveOne());
		}
	}
	
	static void asserT(boolean e) {
		if (!e) {
			throw new Error();
		}
	}
	
	public void run() {
		try {
			in = new Scanner(new FileReader(path + problem + ".in"));
			out = new PrintWriter(new FileWriter(path + problem + ".out"));
		} catch (IOException e) {
			System.out.println("Guten Tag>");
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
		}
		try {
			solve();
		} finally {
			out.close();
		}
	}
	
	public static void main(String[] args) {
		new CodeJamB().run();
	}
}