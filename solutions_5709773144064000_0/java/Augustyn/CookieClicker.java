import java.util.HashSet;
import java.util.Scanner;

public class CookieClicker {
	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		scanner.nextLine();
		double c, f, x;
		for (int t = 0; t < T; t++) {
			String s = scanner.nextLine();
			String []tt = s.split(" ");
			c=Double.parseDouble(tt[0]);
			f=Double.parseDouble(tt[1]);
			x=Double.parseDouble(tt[2]);
			System.out.println("Case #" + (t + 1) + ": "+solve(c,f,x));

		}

	}

	private static double solve(double c, double f, double x) {
		double d = Double.MAX_VALUE;
		
		double s = 0;
		double speed = 2;
		while(s<d){
			d = Math.min(d, s+x/speed);
			//System.out.println(""+d+" "+s+" "+x +" "+speed);
			s = s + c/speed;
			speed += f;
		}
		
		return d;
	}

}
