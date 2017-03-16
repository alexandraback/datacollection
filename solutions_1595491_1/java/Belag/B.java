package qualification;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
	public static void main(String[] Args) throws IOException {
		Scanner sc = new Scanner(new FileReader("B-small.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		System.out.println(caseCnt);
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println(caseNum);
			int N=sc.nextInt();
			int S=sc.nextInt();
			int p=sc.nextInt();
			int[] score = new int[N];
			int total=0;
			for(int i=0;i<N;i++) {
				score[i]=sc.nextInt();
				if(score[i]>=3*p-2) {
					total++;
				} else if(score[i]>=3*p-4 && S>0 && score[i]>=p) {
					total++;
					S--;
				}
			}
			pw.println("Case #" + caseNum + ": " + total);
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}

}
