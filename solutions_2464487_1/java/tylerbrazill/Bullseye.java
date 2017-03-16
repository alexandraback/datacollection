import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class Bullseye {
	Bullseye(){
		Scanner in = new Scanner(System.in);
		int tests = in.nextInt();
		for(int te = 1; te<=tests; te++){
			double r, t;
			r = in.nextDouble();
			t = in.nextDouble();
			//System.out.println(paintNeeded(r, 2.0));
			
			long high, low;
			high = (long)1e17;
			low = 0;
			while(high-low > 1){
				long mid = (high+low)/2;
				if(paintNeeded(r, (double)mid) < t)
					low = mid;
				else high = mid;
				//System.out.println(paintNeeded(r, (double)mid) + " " +high + " " + low);
			}
			if(paintNeeded(r, (double)high) > t) high = low;
			System.out.println("Case #"+te+": "+(long)(high));
		}
	}
	double paintNeeded(double r, double n){
		if(n == 0) return 0;
		return 4.0*n*(n+1.0)/2.0 + 2.0*r*n - 3.0*n;
	}
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream(new File("bullseye.in")));
		System.setOut(new PrintStream(new File("bullseye.out")));
		new Bullseye();
	}

}
