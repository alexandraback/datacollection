package com.google.codejam.dancewithgooglers;

import java.io.*;

public class DanceWithGooglers {

	private static String filename = "large";
	
	public static void main(String[] args) throws Exception {
		RandomAccessFile input = new RandomAccessFile(filename + "_in.txt", "r");
		RandomAccessFile output = new RandomAccessFile(filename + "_out.txt", "rw");
		
		int cases = Integer.valueOf(input.readLine());
		for(int i = 0; i < cases; i++){
			String[] line = input.readLine().split(" ");
			
			int N = Integer.valueOf(line[0]);
			int S = Integer.valueOf(line[1]);
			int p = Integer.valueOf(line[2]);
			
			int[] t = new int[N];
			for(int j = 0; j < N; j++)t[j] = Integer.valueOf(line[j + 3]);
			
			int solved = solve(t, S, p);
			
			System.out.println("Case #" + (i + 1) + ": " + solved);
			output.writeBytes("Case #" + (i + 1) + ": " + solved + "\n");
		}
		
		output.close();
		input.close();
	}
	
	private static int solve(int[] scores, int S, int p){
		int found = 0;
		int surprising = 0;
		
		for(int i : scores){
			boolean[] result = permute(i, p);
			if(!result[0])continue;
			if(!result[1]){
				found++;
			}else{
				surprising++;
			}
		}
		
		if(S > surprising)return found + surprising;
		return found + S;
	}

	private static boolean[] permute(int value, int search){
		boolean found = false;
		boolean surprising = false;
		
		for(int a = 0; a <= 10; a++){
			for(int b = a; b <= a + 2; b++){
				if(b > 10)continue;
				for(int c = a; c <= a + 2; c++){
					if(c > 10)continue;
					if((a + b + c) != value)continue;
					
					if((a >= search) || (b >= search) || (c >= search)){
						found = true;
						
						if((Math.abs(a - b) == 2) || (Math.abs(a - c) == 2) || (Math.abs(b - c) == 2)){
							surprising = true;
						}else{
							return new boolean[]{ true, false };
						}
					}
				}
			}
		}
		return new boolean[]{ found, surprising };
	}
}
