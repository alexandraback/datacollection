package com.dijkstra;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;

public class Main {

	public static void main(String[] args) throws Exception {
		String name = "C-large";
		BufferedReader br = new BufferedReader(new FileReader(new File(name+".in")));
		PrintWriter pw = new PrintWriter(new File(name+".out"));
		int T = Integer.parseInt(br.readLine());
		for (int i = 1; i <= T; i++) {
			String line1 = br.readLine();
			String tokens[] = line1.split(" ");
			int L = Integer.parseInt(tokens[0]);
			long X = Long.parseLong(tokens[1]);
			String line2 = br.readLine();
			
			Dijkstra alternate = new Dijkstra(L, X, line2);
			boolean alternateAnswer = alternate.isValid();
			
			String response = alternateAnswer ? "YES" : "NO";
			pw.println("Case #" + i + ": " + response);
		}
		br.close();
		pw.flush();
		pw.close();
	}
}
