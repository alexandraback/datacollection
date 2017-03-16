package com.kushd.cj2014;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;

public class Enclosure {
	
	private static Res[][] array = new Res[350][350];

	public static void main(String[] args) {
		FileInputStream fio=null;
		DataInputStream in=null;
		try {
			fio = new FileInputStream("/Users/kushal/Downloads/C-small-attempt0.in");
			in = new DataInputStream(fio);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine = br.readLine();
			int tc = Integer.parseInt(strLine);
			preprocess();
			for(int i=0;i<tc;i++){
				strLine = br.readLine();
				String[] values = strLine.split(" ");
				int n = Integer.parseInt(values[0]);
				int m = Integer.parseInt(values[1]);
				int k = Integer.parseInt(values[2]);
				
				String ans = process(n,m,k);
				System.out.println("Case #"+(i+1)+": "+ans);
			}
			
			
			in.close();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	private static void preprocess() {
		
		for(int i=3;i<=35;i++){
			int j = i;
			while((i*j) < 1000){
				if(i==3 && j==3){
					array[i][j] = new Res(4,5);
				}else if(i==j){
					array[i][j] = new Res();
					array[i][j].minStones = array[i-1][j].minStones +2;
					array[i][j].maxPoints = array[i-1][j].maxPoints + j;
				}else{
					array[i][j] = new Res();
					array[i][j].minStones = array[i][j-1].minStones +2;
					array[i][j].maxPoints = array[i][j-1].maxPoints + i;
				}
				j++;
			}
		}
		
	}

	private static String process(int n, int m, int k) {
		if(n < 3 || m < 3){
			return Integer.toString(k);
		}
		int ans= Integer.MAX_VALUE;
		for(int i=3;i<=35;i++){
			int j = i;
			while((i*j) < 1000){
				if(i<=n && j<=m && array[i][j].maxPoints <= k){
					int extra = k - array[i][j].maxPoints;
					int temp = extra + array[i][j].minStones;
					if(temp < ans){
						ans = temp;
					}
				}
				j++;
			}
		}
		
		if(ans == Integer.MAX_VALUE){
			return "0";
		}
		return Integer.toString(ans);
	}
	
	
}


class Res {
	
	public int minStones;
	public int maxPoints;
	
	Res(int minStones, int maxPoints){
		this.maxPoints = maxPoints;
		this.minStones = minStones;
	}

	public Res() {
		// TODO Auto-generated constructor stub
	}
	
}
