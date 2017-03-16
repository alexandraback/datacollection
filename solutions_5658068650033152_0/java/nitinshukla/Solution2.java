package com.nitin.ofss.codejam4;

import java.io.*;
import java.util.*;


public class Solution2 {
	static FileReader fr;
	static Scanner scan;
	static PrintWriter out;
	static int N,M,K;
	public static void main(String[] args) throws IOException {
		initialize();
		int T = scan.nextInt();
		
		for (int i10 = 1; i10 <= T; i10++) {
			int ans=0,num1=0,num2=0;
			int N = scan.nextInt();
			int M = scan.nextInt();
			int K = scan.nextInt();
			if(M<N) swap();
			int max = (N-2)*(M-2);
			if(max<1) ans=K;
			else{
				for(int i=1;i<N-1;i++){
					for(int i1=1;i1<M-1;i1++){
						num2++;
						num1+=get(i,i1);
						if(K<=num1) {ans=num1-num2;break;}
					}
				if(K<=num1) break;
				
				}
			}
			if(ans==0){
				
				ans=K-max;
			}
			if(N<=2 || M<=2) ans=K;
			System.out.printf("Case #%d: %d\n", i10,ans);
			out.printf("Case #%d: %d\n", i10,ans);
		}
		close();
	}

private static int get(int i, int i1) {
			if(i==1 && i1==1) return 5;
			if(i==1) return 3;
			if(i1==1 || i1==M-1) return 2;
			return 1;
	}


private static void swap() {
int temp=N;
N=M;M=temp;
	}

public static void initialize() throws FileNotFoundException{
	fr = new FileReader("in.txt");
	scan = new Scanner(fr);
	out = new PrintWriter("out.txt");
}
public static void close() throws IOException{
	fr.close();
	out.close();
	
}
}
