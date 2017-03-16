package org.rtc.codeJam;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class CJ2014_OB_CookieFarm {

	/**
	 * In this problem, you start with 0 cookies.
	 * You gain cookies at a rate of 2 cookies per second, by clicking on a giant cookie.
	 * Any time you have at least C cookies, you can buy a cookie farm.
	 * Every time you buy a cookie farm, it costs you C cookies and gives you an extra F cookies per second.
	 * <p/>
	 * Once you have X cookies that you haven't spent on farms, you win!
	 * Figure out how long it will take you to win if you use the best possible strategy.
	 */

	public CJ2014_OB_CookieFarm(String inFile, String outFile) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(inFile));
			BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));
			int numCases = getInt(br);
			for (int i = 0; i < numCases; i++) {
				String line = br.readLine();
				String[] nums = line.split(" ");

				double c = Double.parseDouble(nums[0]); // cost of farm
				double f = Double.parseDouble(nums[1]); // farm cookies/sec
				double x = Double.parseDouble(nums[2]); // finish

				double numCookies = 0;
				double numFarms = 0;
				double elapsed = 0;

				while (true) {
					double cookiesPerSec = 2 + (numFarms * f);

					double finishWithoutMoreFarms = (x - numCookies) / cookiesPerSec;
					double nextFarm = c / cookiesPerSec;
					double finishWithNewFarm = nextFarm + (x / (cookiesPerSec + f));

					if (finishWithoutMoreFarms < finishWithNewFarm) {
						elapsed += finishWithoutMoreFarms;
						break;
					} else {
						elapsed += nextFarm;
						numFarms++;
					}
				}

				String outStr = "Case #" + (i + 1) + ": " + elapsed;
				System.out.println(outStr);
				bw.write(outStr, 0, outStr.length());
				bw.newLine();
			}
			br.close();
			bw.close();

		} catch (Exception e) {
			System.err.println(e);
		}
	}

	public static void main(String[] args) {
		// String fileName = args[0];
		// String fileName = "inCookieFarm.txt";
		String fileName = "B-small-attempt0.in";
		CJ2014_OB_CookieFarm se = new CJ2014_OB_CookieFarm(fileName, "out.txt");
	}

	private int getInt(BufferedReader br) throws IOException {
		String line = br.readLine();
		return Integer.parseInt(line);
	}

	private double getDouble(BufferedReader br) throws IOException {
		String line = br.readLine();
		return Double.parseDouble(line);
	}

	private int[] getSet(BufferedReader br, int row) throws IOException {
		String[] set1 = null;
		for (int i = 0; i < 4; i++) {
			String nums = br.readLine();
			if (i == row - 1) {
				set1 = nums.split(" ");
			}
		}
		int[] set = new int[4];
		for (int i = 0; i < 4; i++) {
			set[i] = Integer.parseInt(set1[i]);
		}
		return set;
	}

//	private void test(int n) {
//		int result = getNumber(n);
//		System.out.println("n=" + n + ", result=" + result);
//	}
}
