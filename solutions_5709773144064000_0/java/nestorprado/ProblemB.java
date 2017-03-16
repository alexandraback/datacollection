import java.io.*;
import java.util.*;

public class ProblemB {
	
	private static double cookieClicker(double rate, double c, double f, double x){
		double next = c/rate;
		double notBuy =  x/rate;
		double buy = next + (x/(rate+f));
		return buy < notBuy ? next + cookieClicker(rate+f,c,f,x) : notBuy;	
	}
	
    private static String solve(Scanner in){
    	double c = in.nextDouble();
    	double f = in.nextDouble();
    	double x = in.nextDouble();
    	return String.format("%.7f", cookieClicker(2,c,f,x));
    }

    public static void main(String[] args) {
    	String file = "Qualification\\ProblemBsmall";
    	try{
    		System.out.println(file);
    		Scanner in = new Scanner(new File(file + ".in"));
    		PrintWriter out = new PrintWriter(new File(file + ".out"));
    		int T = in.nextInt();  in.nextLine();
    		for (int i = 1; i <= T; i++) {
    			String s = "Case #" + i + ": " + ProblemB.solve(in);
    			out.println(s);
    			System.out.println(s);
    		}
    		out.close();
    	}catch(Exception e){ e.printStackTrace(); }
    }
}