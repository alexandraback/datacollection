// Google Code Jam Qualification Round 2014
// Problem B. Cookie Clicker Alpha

import java.util.*;
import java.io.*;


public class CookieClickerAlpha {
	static String inname = "B-small-attempt0.in";    // input file name here
	static String outname = "B-small-attempt0.out";  // output file name here
	static int n;
	public static void main(String[] args){
		try{
			Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
			//Scanner in = new Scanner(System.in);
			BufferedWriter out = new BufferedWriter(new FileWriter(outname));
			int t = in.nextInt();
			in.nextLine();
			for (int cas = 1; cas <= t; cas++){
				String ans = "";
				double c = in.nextDouble();
				double f = in.nextDouble();
				double x = in.nextDouble();
				
				ans = "" + solve(2.0, c, f, x);
				//System.out.print("Case #" + cas + ": " + ans + "\n");
				out.write("Case #" + cas + ": " + ans + "\n");
			}
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static double solve(double s, double c, double f, double x){
		if(x/s < c/s+x/(f+s)) return x/s;
		else return c/s+solve(f+s, c, f, x);
	}
}