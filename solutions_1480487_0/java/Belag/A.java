package codeRound1A;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	public static void main(String[] Args) throws IOException {
		Scanner sc = new Scanner(new FileReader("A-small.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();sc.nextLine();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println(caseNum);
			
			int N = sc.nextInt();
			
			int X=0;
			
			int[] score = new int[N];
			for(int i=0;i<N;i++){
				score[i] = sc.nextInt();
				X+=score[i];
			}
			System.out.println(X);
			
			StringBuilder sb = new StringBuilder();
			
			for(int i=0;i<N;i++) {
				int oldK = -1;
				int k= 0;
				int variableX=0;
				double result=0;
				for(int j=0;j<N;j++) {
					if(score[j]<=score[i]+result*X && i!=j) {
						k++;
						variableX+=score[j];
					}
				}
				while(oldK!=k) {
					if(caseNum==17)
						System.out.println(result+ " "+k);
					oldK = k;
					result = ((double) X + (double) variableX - (double) score[i] * (double) k)/(((double) k + 1)*((double) X))*100.0;
					variableX=0;
					k=0;
					result = Math.max(result,0);
					for(int j=0;j<N;j++) {
						if(score[j]<=score[i]+result*X/100 && i!=j) {
							k++;
							variableX+=score[j];
						}
					}
				}
				sb.append(" "+Math.max(result,0));
			}
			
			
			pw.println("Case #" + caseNum + ":" + sb.toString());
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
}
