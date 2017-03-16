package Qualification;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.Scanner;

public class CookieClickerAlpha {

	private static String WORKING_DIR = "D:\\Working\\CodeJam\\Qualification\\";

	static double farmCost;
	static double cookieRate;
	static double goal;

	static double totalMoney;
	static double money;
	static double rate;
	static double time;

	public static void main(String[] args) {

		try {
			Scanner sc = new Scanner(new File(WORKING_DIR + "input.txt"));
			PrintWriter pw = new PrintWriter(new File(WORKING_DIR + "output.txt"));
			int numCase = sc.nextInt();
			for (int i = 0 ; i<numCase ; i++) {
				farmCost = sc.nextDouble();
				cookieRate = sc.nextDouble();
				goal = sc.nextDouble();

				totalMoney = 0;
				money = 0;
				rate = 2;
				time = 0;
				
				while (buyFarm()) {
					totalMoney += farmCost;
					time += (farmCost/rate);
					rate += cookieRate;
				}
				
				time += goal/rate;
				DecimalFormat f = new DecimalFormat("##.0000000");
				pw.write("Case #" + (i+1) + ": " + f.format(time) + "\n");
				

			}
			pw.flush();
			pw.close();
			sc.close();
			System.out.println("Done!");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

	}

	private static boolean buyFarm() {
		return ((goal-farmCost)/rate > (goal)/(rate + cookieRate));
	}
}
