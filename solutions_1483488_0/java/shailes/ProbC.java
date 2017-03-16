package com.codejam.twelve;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;

public class ProbC {
	public static void main(String[] args) throws IOException {
		FileReader fr = new FileReader(
				"D:\\Dev\\Workspaces\\Android\\codejam\\io\\qualification\\C-small-attempt0.in");
		FileWriter fw = new FileWriter(
				"D:\\Dev\\Workspaces\\Android\\codejam\\io\\qualification\\C-small-attempt0.out");
		BufferedReader br = new BufferedReader(fr);
		BufferedWriter bw = new BufferedWriter(fw);

		int t = Integer.parseInt(br.readLine());

		for (int l = 1; l <= t; l++) {
			String s = br.readLine();
			bw.append("Case #" + l + ": ");

			String ss[] = s.split(" ");

			int A = Integer.parseInt(ss[0]);
			int B = Integer.parseInt(ss[1]);

			int ans = 0;
			HashSet<String> hs = new HashSet<String>();

			for (int i = A; i < B; i++) {
				String n = "" + i;
				int len = n.length();
				for (int j = 0; j < len - 1; j++) {
					n = n.charAt(n.length() - 1)
							+ n.substring(0, n.length() - 1);
					int nn = Integer.parseInt(n);
					if (nn > i && nn <= B) {
						/*System.out.println(i + "," + nn);
						if (hs.contains(i + "," + nn)) {
							System.out.println("**********");
						} else*/
						if (!hs.contains(i + "," + nn)){
							hs.add(i + "," + nn);
							ans++;
						}
					}
				}

			}

			bw.append("" + ans);

			bw.newLine();
		}

		bw.flush();
		bw.close();
		br.close();
	}
}
