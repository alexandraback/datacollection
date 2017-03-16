import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class B{
	Scanner sc=new Scanner(System.in);

	int INF=1<<28;
	double EPS=1e-9;

	int caze, T;
	int E, R, n;
	int[] vs;

	void run(){
		T=sc.nextInt();
		sc.nextLine();
		for(caze=1; caze<=T; caze++){
			E=sc.nextInt();
			R=sc.nextInt();
			n=sc.nextInt();
			vs=new int[n];
			for(int i=0; i<n; i++){
				vs[i]=sc.nextInt();
			}
			solveSmall();
		}
	}

	void solveSmall(){
		int[][] dp=new int[n+1][E+1];
		for(int j=0; j<n; j++){
			for(int i=0; i<=E; i++){
				// dp[j][i]‚©‚ç
				for(int d=0; d<=i; d++){
					int next=min(i-d+R, E);
					dp[j+1][next]=max(dp[j+1][next], dp[j][i]+vs[j]*d);
				}
			}
			// debug(j, dp[j+1]);
		}
		int max=0;
		for(int i=0; i<=E; i++){
			max=max(max, dp[n][i]);
		}
		answer(""+max);
	}

	void solveLarge(){

	}

	void answer(String s){
		println("Case #"+caze+": "+s);
	}

	void println(String s){
		System.out.println(s);
	}

	void print(String s){
		System.out.print(s);
	}

	void debug(Object... os){
		System.err.println(deepToString(os));
	}

	public static void main(String[] args){
		new B().run();
	}
}
