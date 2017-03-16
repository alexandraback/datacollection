package com.google.codejam.recyclednumbers;

import java.io.*;
import java.util.*;

public class RecycledNumbers {

	private static String filename = "large";
	
	public static void main(String[] args) throws Exception {
		RandomAccessFile input = new RandomAccessFile(filename + "_in.txt", "r");
		RandomAccessFile output = new RandomAccessFile(filename + "_out.txt", "rw");
		
		int cases = Integer.valueOf(input.readLine());
		for(int i = 0; i < cases; i++){
			String[] nrs = input.readLine().split(" ");
			
			int A = Integer.valueOf(nrs[0]);
			int B = Integer.valueOf(nrs[1]);
			
			long solved = solve(A, B);
			System.out.println("Case #" + (i + 1) + ": " + solved);
			output.writeBytes("Case #" + (i + 1) + ": " + solved + "\n");
		}
		
		output.close();
		input.close();
	}
	
	private static long solve(int A, int B){
		long count = 0L;
		
		HashMap<String, ArrayList<Integer>> hash = new HashMap<String, ArrayList<Integer>>();
		for(int n = A; n <= B; n++){
			String a = String.valueOf(n);
			
			hash.put(a, new ArrayList<Integer>());
			for(Integer i : permute(a)){
				if((i <= n) || (i > B))continue;
				if(hash.get(a).contains(i))continue;
				hash.get(a).add(i);
				count++;
			}
		}
		return count;
	}
	
	private static ArrayList<Integer> permute(String a){
		ArrayList<Integer> permuted = new ArrayList<Integer>();
		
		for(int n = 1; n < a.length(); n++){
			if(a.charAt(n) == '0')continue;
			
			Integer p = Integer.valueOf(a.substring(n) + a.substring(0, n));
			if(!permuted.contains(p))permuted.add(p);
		}
		return permuted;
	}
		
	@SuppressWarnings("unused")
	private static long solved(int A, int B){
		long count = 0;
		
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
