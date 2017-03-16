package com.codejam.twelve;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class ProbA {
	public static void main(String[] args) throws IOException {
		FileReader fr = new FileReader(
				"D:\\Dev\\Workspaces\\Android\\codejam\\io\\qualification\\A-small-attempt0.in");
		FileWriter fw = new FileWriter(
				"D:\\Dev\\Workspaces\\Android\\codejam\\io\\qualification\\A-small-attempt0.out");
		BufferedReader br = new BufferedReader(fr);
		BufferedWriter bw = new BufferedWriter(fw);

		String learnip = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
		String learnop = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

		char mapping[] = new char[26];

		for (int i = 0; i < learnip.length(); i++) {
			if (learnip.charAt(i) != ' ')
				mapping[learnip.charAt(i) - 'a'] = learnop.charAt(i);
		}

		mapping['z' - 'a'] = 'q';
		mapping['q' - 'a'] = 'z';

		int t = Integer.parseInt(br.readLine());

		for (int i = 1; i <= t; i++) {
			String s = br.readLine();
			bw.append("Case #"+i+": ");
			for (int j = 0; j < s.length(); j++) {
				if (s.charAt(j) != ' ')
					bw.append(mapping[s.charAt(j)-'a']);
				else bw.append(' ');
			}
			bw.newLine();
		}
		
		bw.flush();
		bw.close();
		br.close();
	}
}
