import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class Main {

	private static double c;
	private static double f;
	private static double x;
	/**
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.US);
		Scanner in = new Scanner(new FileInputStream("B-small-attempt0.in"));
		PrintWriter out = new PrintWriter("OUTPUT.TXT");
		int t = in.nextInt();
		for (int t0 = 0; t0 < t; ++t0) {
			c = in.nextDouble();
			f = in.nextDouble();
			x = in.nextDouble();
			out.println(String.format("Case #%d: %.8f", t0+1, solve()));
		}
		in.close();
		out.close();
	}

	private static double solve() {
		double cps = 2.0;
		double time = 0.0;
		if (x<=c) return x/cps;
		while (true){
			double time1 = x/cps;
			double time2 = c/cps+x/(cps+f);
			if (time1<=time2){
				time+=time1;
				break;
			}
			else{
				time+=c/cps;
				cps+=f;
			}
		}
		return time;
	}

}
