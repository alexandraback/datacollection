package qualificationB;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Scanner;

public class Main2 {
	public static boolean debug = true;
	public static void main(String[] args) {
		outinit();
		solve();
		outfile();
	}
	
	public static double C;
	public static double F;
	public static double X;
	public static void solve() {
		Scanner sc = new Scanner(System.in);
		double t = sc.nextDouble();
		for(int i=0;i<t;i++) {
			C = sc.nextDouble();
			F = sc.nextDouble();
			X = sc.nextDouble();
			solveTestcase();
		}
	}
	public static void solveTestcase() {
		double mintime = Double.MAX_VALUE;
		for(int i=0;i<=X/2;i++) {
			double time = getTime(i);
			if (time < mintime) {
				mintime = time;
			}
		}
		DecimalFormat df = new DecimalFormat("0.0000000");
		out(String.format(df.format(mintime)));
	}
	public static double getTime(int farm) {
		if (farm<0) {
			return X / 2.0;
		}
		double time = 0;
		for(int i=farm-1;i>=0;i--) {
			time += C / (2.0 + F * i);
		}
		time += X / (2.0 + F * farm);
		return time;
	}
	
	public static int outnum = 0;
	public static BufferedWriter bw;
	public static void outinit() {
		try {
			bw = new BufferedWriter(new FileWriter("out.txt"));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public static void out(Object o) {
		outnum++;
		try {
			bw.write("Case #" + outnum + ": " + o);
			bw.newLine();
			if (debug) {
				System.out.println("Case #" + outnum + ": " + o);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public static void outfile() {
		try {
			bw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
