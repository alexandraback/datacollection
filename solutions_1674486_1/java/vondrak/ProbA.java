package Round1;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.List;
import java.util.PriorityQueue;
import java.util.regex.*;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.File;

public class ProbA {

	 public static class pair implements Comparable<pair>{
		
		private int id;
		private String name;
		
		public pair(int id, String name){
			this.id = id;
			this.name = name;
		}
		
		public int compareTo(pair b){
			
			if(b.id > b.id)
				return 1;
			if(b.id > b.id)
				return -1;			
			return 0;
		}
		
		
		
	}
	

	public static void GetTC(int N, int[][] arr){
		
		for(int k = 0; k < N; k++)
		for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){		
			if( arr[i][k] > 0 && arr[k][j] > 0 && i!=j)
				arr[i][j] = 1;
		}
		
	}
	
	
	
	public static boolean FindDiamond(int N, int[][] arr, int[][] arr1){
		
		
		for(int i = 0; i < N; i++){
			HashSet<Integer> visitedNodes = new HashSet<Integer>();
			int[] nodes = new int[N];
			nodes[0] = i; visitedNodes.add(i);
			int qi = 0;
			while( qi < visitedNodes.size()){
				
				int ni = nodes[qi];
				for(int j = 0; j < N; j++){
					if(arr[ni][j] == 1){
						if(visitedNodes.contains(j))
							return true;
						else{
							nodes[visitedNodes.size()] = j;
							visitedNodes.add(j);
						}
					}
				}
				
				qi++;
			}
		
		}
		
		return false;
	}
	 
	
	static int[][] arr, arr1, arr2;
 	
	public static void main(String[] args) throws IOException{
		
		String inFileName = "ProbA.in";
		String outFileName = "ProbA.out";
		
		File inFile = new File(inFileName);
		File outFile = new File(outFileName);
		
		if(!inFile.exists())
			System.out.println("File Does Not Exist!");
		
		
		BufferedReader in = new BufferedReader( new InputStreamReader( new FileInputStream(inFile) ) );
		PrintWriter out = new PrintWriter( new FileWriter(outFileName), true );
		
		String line;
		line = in.readLine();
		int T = Integer.parseInt(line);
		for(int t = 1; t <= T; t++){
			line = in.readLine();
			String[] parts = line.split(" ");

			int N = Integer.parseInt(parts[0]);
			arr = new int[N][N];
			arr1 = new int[N][N];
			arr2 = new int[N][N];
			
			for(int i = 0; i < N; i++)
			for(int j = 0; j <N; j++){
				arr[i][j] = 0;
				arr1[i][j] = 0;
				arr2[j][i] = 0;
			}
				
			
			for(int i = 0; i < N; i++){
				line = in.readLine();
				parts = line.split(" ");
				int M = Integer.parseInt(parts[0]);
				for(int j = 0; j < M; j++){
					int k = Integer.parseInt(parts[j+1])-1;
					arr[k][i] = 1;
					arr1[k][i] = 1; arr2[i][k] = 1;
				}
				
			}
			
			GetTC(N, arr1);
			GetTC(N, arr2);
			
			if(FindDiamond(N, arr, arr1))
				out.print("Case #"+t+": Yes");
			else
				out.print("Case #"+t+": No");

			
			out.println();
		}
		
		
		
		in.close();
		out.close();
		
	}
	
}
