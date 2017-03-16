package com.codejam.twelve;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class ProbB {
	public static void main(String[] args) throws IOException {
		FileReader fr = new FileReader(
				"D:\\Dev\\Workspaces\\Android\\codejam\\io\\qualification\\B-small-attempt0.in");
		FileWriter fw = new FileWriter(
				"D:\\Dev\\Workspaces\\Android\\codejam\\io\\qualification\\B-small-attempt0.out");
		BufferedReader br = new BufferedReader(fr);
		BufferedWriter bw = new BufferedWriter(fw);

		int t = Integer.parseInt(br.readLine());

		for (int i = 1; i <= t; i++) {
			String s = br.readLine();
			bw.append("Case #" + i + ": ");

			String ss[] = s.split(" ");
			int nn[] = new int[ss.length];
			for (int j = 0; j < ss.length; j++) {
				nn[j] = Integer.parseInt(ss[j]);
			}

			int N = nn[0];
			int S = nn[1];
			int P = nn[2];
			int sa=0;
			int na=0;

			for (int j = 0; j < N; j++) {
				int trip = nn[3+j];
				int remain = trip-P;
				if(remain<0)
					continue;
				int other = P-(remain/2);
				
				if(other==2){
					sa++;					
				}
				else if(other<2){
					na++;
				}
			}
			
			if(sa>=S)
				sa=S;

			bw.append(""+(na+sa));
			
			bw.newLine();
		}

		bw.flush();
		bw.close();
		br.close();
	}
}
