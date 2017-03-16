/**
 * File Name: Main.java
 * Package Name: com.ncfxy.MyAlgorithm
 * Description： TODO 
 *
 *   ver					date			author
 * ──────────────────────────────────
 *   1.0-SNAPSHOT			2016年4月9日			Administrator
 *
 * Copyright (c) 2016, ncfxy All Rights Reserved.
 */


import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 * ClassName: Main<br/>
 * Description: TODO ADD Description
 *
 * @author Administrator
 * @version 1.0-SNAPSHOT
 * @Date 2016 2016年4月9日 上午9:45:38
 */
public class Main {

	// Scanner cin = new Scanner("input.txt");
	public static void main(String[] args) throws FileNotFoundException {
//		Scanner cin = new Scanner(System.in);
		Scanner cin = new Scanner(new File("A-large.in"));
		FileOutputStream fs = new FileOutputStream(new File("output.txt"));
		PrintStream p = new PrintStream(fs);
		while (cin.hasNext()) {
			int t = cin.nextInt();
			for (int caseNumber = 1; caseNumber <= t; caseNumber++) {
				int n = cin.nextInt();
				if (n == 0) {
					p.println("Case #"+caseNumber+": INSOMNIA");
				} else {
					p.println("Case #"+caseNumber+": "+sol(n));
				}
			}
			try {
				fs.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			break;
		}
	}

	public static int sol(int n) {
		int location[] = new int[10];
		Arrays.fill(location, 0);
		for(int i = 1;i < 10000;i++){
			int temp = n * i;
			fillLocation(temp, location);
			if(!haveZeroNumber(location)){
				return temp;
			}
		}
		return 0;
	}

	public static void fillLocation(int n, int[] location) {
		while (n > 0) {
			int a = n % 10;
			n /= 10;
			location[a]++;
		}
	}
	
	public static boolean haveZeroNumber(int[] location){
		for(int i = 0;i < location.length;i++){
			if(location[i] == 0){
				return true;
			}
		}
		return false;
	}

}
