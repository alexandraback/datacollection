package cj2014.q;
import java.io.*;
import java.util.*;

public class B {
	Scanner sc;
	PrintWriter pw;
	double C,F,X;
	
	public static void main(String[] args) throws Exception{
		String filePrefix = args.length>0?args[0]:"B-small-attempt0";

		try {
			new B().run(filePrefix);
		} catch(Exception e) {
			System.err.println("file read error");
		}
	}
	
	public void run(String filePrefix) throws Exception {
		sc = new Scanner(new FileReader(filePrefix + ".in"));
		pw = new PrintWriter(new FileWriter(filePrefix + ".out"));
		int ntest = sc.nextInt();
		for(int test=1; test<=ntest; test++) {
			read(sc);
			pw.print("Case #" + test + ": ");
			System.out.print("Case #" + test + ": ");
			solve();
		}
		System.out.println("Finished.");
		sc.close();
		pw.close();
		
	}
	
	void read(Scanner sc) {
		C = sc.nextDouble();
		F = sc.nextDouble();
		X = sc.nextDouble();
	}
	
	void print(Object s) {
		pw.print(s);
		System.out.print(s);
	}
	
	void println(Object s) {
		pw.println(s);
		System.out.println(s);
	}	
	
	public void solve() {
		double p = 2.0;
		double sum = 0.0;
		while(X/p > C/p+X/(p+F)) {
			sum += C/p;
			p += F;
		}
		double ans = sum + X/p;
		println(ans);
	}
}
