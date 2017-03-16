package com.abuhijleh.googlejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class GoogleJam {
	static final String code = "yhesocvxduiglbkrztnwjpfmaq";

	public static void main(String[] args) {
		File input = new File("inputFile");
		String[] result;
		Scanner scan;
		try {
			scan = new Scanner(input);
			result = new String[scan.nextInt()];
			scan.nextLine();
			for (int i = 0; i < result.length; i++) {
				result[i] = "Case #" + (i + 1) + ": "
						+ solve(scan.nextInt(), scan.nextInt());
				scan.nextLine();
			}
			System.out.println("Output");
			for (int i = 0; i < result.length; i++)
				System.out.println(result[i]);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static int solve(int x, int y) {
		int count = 0;
		String digits = x + "";
		int length = digits.length();
		int pa = (int) Math.pow(10, length - 1);
		for (int i = x; i <= y; i++) {
			int temp = i;
			int[] temps = new int[length];
			for (int j = 0; j < length ; j++) {
				temp = (temp % 10) * pa + (temp / 10);
				if (temp > i && temp <= y){
					if(check(temps,temp)){
						temps[j] = temp;
						count++;
					}
				}
			}
		}
		return count;
	}

	private static boolean check(int[] temps, int temp) {
		for(int i =0 ;i<temps.length;i++)
			if(temps[i] == temp)
				return false;
		return true;
	}
}
