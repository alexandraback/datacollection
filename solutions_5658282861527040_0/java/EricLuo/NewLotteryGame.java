package codeJam.google.com;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class NewLotteryGame {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File(
				"C:/Users/Zhenyi/Downloads/B-small.in"));
		PrintWriter out = new PrintWriter(
				"C:/Users/Zhenyi/Downloads/B-small.out");
		int T = in.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int A = in.nextInt();
			int B = in.nextInt();
			int K = in.nextInt();
			int count = 0;
			for(int i = 0; i < A; i++){
				for(int j = 0; j < B; j++){
					int tmp = i & j;
					if(tmp < K){
						count++;
					}
				}
			}
			out.write("Case #" + tc + ": " + count +"\n");
		}
		in.close();
		out.flush();
		out.close();
	}
}
