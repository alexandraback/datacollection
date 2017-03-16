package com.google.gcj.pascualino;

import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int t=1;t<=T;t++){
			System.out.print("Case #" + t + ": ");
			long N = sc.nextInt();
			
			long NN = N;
			boolean[] visited = new boolean[10];
			int visitedCount = 0;
			if(N != 0){
				do {
					for(long d = 1; d <= NN; d*= 10){
						int num = (int)((NN / d) % 10);
						if(!visited[num]){
							visited[num] = true;
							visitedCount++;
						}
					}
					if(visitedCount == 10 || NN >= 1000000000000000L){
						break;
					}
					NN += N;
				} while(true);
			}
			if(visitedCount != 10){
				System.out.println("INSOMNIA");
			} else {
				System.out.println(NN);
			}
		}
		sc.close();
	}
}
