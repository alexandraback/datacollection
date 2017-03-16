package com.google.codejam.speakingintongues;

import java.io.*;
import java.util.*;

public class SpeakingInTongues {

	private static String filename = "small";
	
	private static HashMap<String, String> hash = new HashMap<String, String>();
	
	public static void main(String[] args) throws Exception {
		String in = "zyeq ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv";
		String out = "qaoz ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup";
		
		for(int c = 0; c < in.length(); c++){
			String key = String.valueOf(in.charAt(c));
			if(hash.containsKey(key)){
				if(!hash.get(key).equals(String.valueOf(out.charAt(c)))){
					System.out.println("!: " + hash.get(key) + " - " + String.valueOf(out.charAt(c)));
				}
				continue;	
			}
			hash.put(key, String.valueOf(out.charAt(c)));
		}
		
		RandomAccessFile input = new RandomAccessFile(filename + "_in.txt", "r");
		RandomAccessFile output = new RandomAccessFile(filename + "_out.txt", "rw");
		
		int cases = Integer.valueOf(input.readLine());
		
		for(int i = 0; i < cases; i++){
			String line = input.readLine();
			
			System.out.println("Case #" + (i + 1) + ": " + solve(line));
			output.writeBytes("Case #" + (i + 1) + ": " + solve(line) + "\n");
		}
		
		output.close();
		input.close();		
	}
	
	private static String solve(String line){
		String solved = "";
		
		for(int i = 0; i < line.length(); i++){
			solved += hash.get(String.valueOf(line.charAt(i)));
		}
		
		return solved;
	}

}
