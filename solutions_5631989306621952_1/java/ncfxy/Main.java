/**
 * File Name: Main.java
 * Package Name: com.ncfxy.codejam
 * Description： TODO 
 *
 *   ver					date			author
 * ──────────────────────────────────
 *   1.0-SNAPSHOT			2016年4月16日			Administrator
 *
 * Copyright (c) 2016, ncfxy All Rights Reserved.
 */

package com.ncfxy.codejam;

import java.util.Scanner;

/**
 * ClassName: Main<br/>
 * Description: TODO ADD Description
 *
 * @author Administrator
 * @version 1.0-SNAPSHOT
 * @Date 2016 2016年4月16日 上午8:45:47
 */
public class Main {

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int t = cin.nextInt();
			for(int caseNumber = 1;caseNumber <= t;caseNumber++){
				String input = cin.next();
				String output = sol(input);
				System.out.println("Case #"+caseNumber+": "+output);
			}
			
		}
	}
	
	public static String sol(String input){
		String result = ""+input.charAt(0);
		for(int i = 1;i < input.length();i++){
			if(input.charAt(i) >= result.charAt(0)){
				result = input.charAt(i)+result;
			}else{
				result = result + input.charAt(i);
			}
		}
		return result;
	}

}
