package cookieclickeralpha;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class CookieClickerAlpha {

	static Scanner in=null;
	static PrintWriter out=null;
	
	public static void main(String[] args) {
		
		try {
		File file = new File("cookieclickeralphain.txt");
		File file2=new File("cookieclickeralphaout.txt");
		in = new Scanner(file);
		out = new PrintWriter(file2);
		int testCases = in.nextInt();
		for (int i=0;i<testCases;i++) {
			solveCase(i+1);
		}
		out.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void solveCase(int caseNum) throws Exception {
		double c = in.nextDouble();
		double f = in.nextDouble();
		double x = in.nextDouble();
		System.out.println(c+" "+f+" "+x);
		double time = 0;
		double cookieRate = 2;
		while (true) {
			time+=c/cookieRate;
			if ((x-c)/cookieRate<x/(cookieRate+f)) {
				time+=(x-c)/cookieRate;
				out.println("Case #"+caseNum+": "+time);
				return;
			} else {
				cookieRate+=f;
			}
		}
		
	}
}