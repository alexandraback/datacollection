import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


/**
 * for the bullseye challenge.
 * Google code jam 2013 round 1a.
 * @author Jay
 *
 */
public class Bullseeye {


	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc;
		try {
			sc = new Scanner(new File(args[0]));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return;
		}
		String totalProblems = sc.nextLine();
		int total = Integer.parseInt(totalProblems);
		int pos = 1;
		for (;pos <= total;pos++) {
			String size = sc.nextLine();
			String[] sizeArr = size.split(" ");
			double r = Double.parseDouble(sizeArr[0]);
			double t = Double.parseDouble(sizeArr[1]);
			int rings = 0;
			r++;
			while (canDrawRing(r,t,rings)) {
				t -= ringInk(r,t);
				r += 2;
				rings++;
			}
			
			if (pos != total) {
//				sc.nextLine();
			}
			System.out.println("Case #"+pos+": "+rings);
		}
	}

	private static boolean canDrawRing(double r, double t, int rings) {
		double inkUsed = ringInk(r,t);
		if (t >= inkUsed) {
			return true;
		}
		return false;
	}

	private static double ringInk(double r, double t) {
		return r*2-1;
	}
	
	

}
