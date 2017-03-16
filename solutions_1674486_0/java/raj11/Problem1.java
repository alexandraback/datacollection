package com.google.codejam;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Problem1 {
	public static void main(String argsp[]) throws NumberFormatException, IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("/Users/ashwinjain/Desktop/SmsLogger/InterviewStreet/src/com/google/codejam/p1")));
		int cases = Integer.parseInt(br.readLine());

		for(int x=0;x<cases;x++){
			int v=  Integer.parseInt(br.readLine());
			int arr[][] = new int[v+1][v+1];
			

			for(int i=1;i<v+1;i++){
				String temp[] = br.readLine().split(" ");
				int con = Integer.parseInt(temp[0]);
				for(int j=0;j<con;j++){
					arr[i][Integer.parseInt(temp[j+1])]=1;
					//					arr[Integer.parseInt(temp[j+1])][i]=1;
				}
			}

			
			boolean f = false;
			for(int t=1;t<v+1;t++){
				Stack stack = new Stack<Integer>();
				boolean visited[] = new boolean[v+1];
				stack.push(t);
				boolean found = false;
				while(!stack.isEmpty() && !found){
					int ver = (Integer) stack.pop();
					for(int i=1;i<arr.length;i++){
						if(arr[ver][i]==1 && visited[i]){
							found=true;
							break;
						}else if(arr[ver][i]==1 && !visited[i]){
							stack.push(i);
							visited[i] = true;
						}
					}
				}
				f=f||found;
			}
			if(f) 
				System.out.println("Case #"+(x+1)+": Yes");
			else
				System.out.println("Case #"+(x+1)+": No");
		}

	}
}
