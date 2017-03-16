import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.Scanner;


public class Cookie {
	public static void main(String[] args) throws FileNotFoundException {
		DecimalFormat df = new DecimalFormat("#.#######");
        
		Scanner in = new Scanner(new File("B-large.in.txt"));
		PrintWriter out = new PrintWriter(new File("C2.out"));
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			String s = "Case #" + (i + 1) + ": " + df.format(new Cookie().solve(in));
			out.println(s);
			//System.out.println(s);
			
		}
		out.close();
	}

	private double solve(Scanner in) {

		double finalTime=Double.MAX_VALUE;
		double time=0;
		double c=in.nextDouble(); //10000
		double f=in.nextDouble(); //100
		double x=in.nextDouble(); //100000
		int sec=2;
		
		if (x<c)
			return x/sec;
		
		double multiplier= (x/c);
		//double remain= (x%c);
		double rate=sec;
		
		//c 30   f 2   x 100
		
		while (multiplier>0){
			double cur=time+x/rate;
			if (cur<finalTime)
				finalTime=cur;
			time+=c/rate;
			rate+=f;
			multiplier--;
			
		}

		return finalTime;
	}
}
