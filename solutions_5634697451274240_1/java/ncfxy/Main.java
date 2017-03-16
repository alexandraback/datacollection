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
		Scanner cin = new Scanner(new File("B-large.in"));
		FileOutputStream fs = new FileOutputStream(new File("output.txt"));
		PrintStream p = new PrintStream(fs);
		while (cin.hasNext()) {
			int t = cin.nextInt();
			for (int caseNumber = 1; caseNumber <= t; caseNumber++) {
				String n = cin.next();
				if (n == null || n.equals("")) {
					p.println("Case #"+caseNumber+": 0");
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

	public static int sol(String n) {
		int result = 0;
		for(int i = 1;i < n.length();i++){
			if(n.charAt(i) != n.charAt(i-1)){
				result++;
			}
		}
		if(n.charAt(n.length()-1) == '-'){
			result++;
		}
		return result;
	}

}
