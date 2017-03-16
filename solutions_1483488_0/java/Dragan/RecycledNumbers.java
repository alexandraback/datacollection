package com.google.codejam.recyclednumbers;

import java.io.*;

public class RecycledNumbers {

	private static String filename = "small";
	
	public static void main(String[] args) throws Exception {
		RandomAccessFile input = new RandomAccessFile(filename + "_in.txt", "r");
		RandomAccessFile output = new RandomAccessFile(filename + "_out.txt", "rw");
		
		int cases = Integer.valueOf(input.readLine());
		for(int i = 0; i < cases; i++){
			String[] nrs = input.readLine().split(" ");
			
			int A = Integer.valueOf(nrs[0]);
			int B = Integer.valueOf(nrs[1]);
			
			int solved = solve(A, B);
			System.out.println("Case #" + (i + 1) + ": " + solved);
			output.writeBytes("Case #" + (i + 1) + ": " + solved + "\n");
		}
		
		output.close();
		input.close();
	}
		
	private static int solve(int A, int B){
		int count = 0;
		
		String a;
		String b;
		for(int n = A; n < B; n++){
			a = String.valueOf(n);
			for(int k = n + 1; k <= B; k++){
				b = String.valueOf(k);
				if(a.length() != b.length())continue;
				
				for(int i = 0; i < b.length(); i++){
					if(a.charAt(i) == b.charAt(0)){
						boolean match = true;
						for(int j = 0; j < b.length(); j++){
							if(b.charAt(j) != a.charAt((i + j) % b.length())){
								match = false;
								break;
							}
						}
						if(match){
							count++;
							i++;
							break;
						}
					}
				}
			}
		}
		return count;
	}

}
