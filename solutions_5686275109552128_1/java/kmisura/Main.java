package com.pancake;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;

public class Main {

	public static void main(String[] args) throws Exception {
		String name = "B-large";
		BufferedReader br = new BufferedReader(new FileReader(new File(name+".in")));
		PrintWriter pw = new PrintWriter(new File(name+".out"));
		int T = Integer.parseInt(br.readLine());
		for (int i = 1; i <= T; i++) {
			int n = Integer.parseInt(br.readLine());
			if(n>0){
				CorrectPancake serving = new CorrectPancake(br.readLine());
				pw.println("Case #" + i + ": " + serving.getMinTime());
			} else {
				pw.println("Case #" + i + ": 0");
			}
		}
		br.close();
		pw.flush();
		pw.close();
	}
}
