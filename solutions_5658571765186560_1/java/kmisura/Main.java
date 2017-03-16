package com.ominous;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;

public class Main {
	public static void main(String[] args) throws Exception {
		String name = "D-large";
		BufferedReader br = new BufferedReader(new FileReader(new File(name+".in")));
		PrintWriter pw = new PrintWriter(new File(name+".out"));
		int T = Integer.parseInt(br.readLine());
		for (int i = 1; i <= T; i++) {
			String line = br.readLine();
			Omino omino = new Omino(line);
			String response =  omino.richardWins() ? "RICHARD" : "GABRIEL";
			pw.println("Case #" + i + ": " + response);
		}
		br.close();
		pw.flush();
		pw.close();
	}
}
