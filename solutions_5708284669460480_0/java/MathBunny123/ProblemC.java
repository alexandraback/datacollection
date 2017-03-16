/* Programming competition file template
Made by Horatiu Lazu */

import java.io.*;
import java.util.*;
import java.lang.*;
import java.awt.*;
import java.awt.geom.*;
import java.math.*;

class Pair{
	int value = 0;
	int coins = 0;
	public Pair(int value){
		this.value = value;
	}	
}

class ProblemC{
	public static void main (String [] args){
		new ProblemC();
	}
	/* credits to tchieme for dp solution */
	public  int[] NumberOfCoins(int sum, int[] denominations) {
			int[] a = new int[sum + 1];
			Arrays.fill(a, Integer.MAX_VALUE-1000);
			a[0]=0;
			for (int i = 0; i <= sum; i++) {
				for (int j = denominations.length - 1; j >= 0; j--) {
					if (denominations[j] <= i) {
						a[i] = Math.min(1 + a[i - denominations[j]], a[i]);
					}
				}
			}
			return a;
	}
	
	

	public ProblemC(){
		try{
			BufferedReader in;
			//in = new BufferedReader (new InputStreamReader (System.in)); //Used for CCC
			in = new BufferedReader(new FileReader("C-small-attempt0.in")); //Used for JDCC & others
			
			PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
			int testCases = Integer.parseInt(in.readLine());
			for(int qq = 0; qq < testCases; qq++){
				int ans = 0;
				StringTokenizer st = new StringTokenizer(in.readLine());
				int coinLimit = Integer.parseInt(st.nextToken());
				int coinsG = Integer.parseInt(st.nextToken());
				int maxLimit = Integer.parseInt(st.nextToken());
				int [] dp = new int[maxLimit+1];
				ArrayList<Integer> coins = new ArrayList<Integer>();
				int [] coinsAr = new int[coinsG];
				 st = new StringTokenizer(in.readLine());
				
				for(int i = 0; i < coinsG; i++){
					coins.add(Integer.parseInt(st.nextToken()));
					coinsAr[i] = coins.get(i);
				}
				
				for(int i = 0; i < coins.size(); i++){
					dp[coins.get(i)] = 1;
					int newI = coins.get(i) * 2;
					int coinsI = 2;
					while(true){
						if (newI <= maxLimit){
							if (dp[newI] == 0 || dp[newI] > coinsI){
								dp[newI] = 	coinsI;
							newI += coins.get(i);
							coinsI++;
						}
						else
							break;
					}
				}
				}
				
				for(int i = 1; i <= maxLimit; i++){ //now go through every number.
					if (dp[i] == 0 || dp[i] > coinLimit){
							
					}
				}
				
				
				// works
				int [] arr = NumberOfCoins(maxLimit, coinsAr);
				for(int x = 0; x < arr.length; x++){
					if (arr[x] > coinLimit + 1){
						ans++;
						int [] newArr = new int[coinsAr.length+1];
						for(int p = 0; p < coinsAr.length; p++){
							newArr[p] = coinsAr[p];
						}
						newArr[coinsAr.length] = x;
						//coins.add(i);
						arr = NumberOfCoins(maxLimit, newArr);
							
					}	
				}
				out.println("Case #" + (qq+1) + ": " + ans);
				
				/* now to generate all combinations.*/
				/*for(int ii = 1; ii <= maxLimit; ii++){
					if (dp[ii] == 0){
						boolean found = false;
						for(int x = ii; x >= 0; x--){
							if (dp[x] != 0){
								int least = 0;
								for(int q = 0; q <= (ii-x); q++){
									
								}
							}
						}
						if (found == false){
							ans += ii;	
						}
					}
				}*/
				
				/*
				for(int i = 1; i <= maxLimit; i++){
					ArrayDeque <Integer> Q = new ArrayDeque<Integer>();
					for(int x = 0; x < coins.size(); x++){
						Q.addLast(new Pair(coins.get(x)));	
					}
					while(!Q.isEmpty()){
						int size = Q.size();
						for(int q = 0; q < size; q++){
							Pair temp = Q.removeFirst();
							if (temp.coins < maxLimit){
								
							}
						}	
					}
				}*/
				
				
			}
			
			out.close();
			
		}
		catch(IOException e){
			System.out.println("IO: General");
		}
	}
}