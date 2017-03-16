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

	int caze, T, m, n;
	int[][] a;

	void run(){
		T=sc.nextInt();
		sc.nextLine();
		for(caze=1; caze<=T; caze++){
			n=sc.nextInt();
			m=sc.nextInt();
			a=new int[n][m];
			for(int j=0; j<n; j++){
				for(int i=0; i<m; i++){
					a[j][i]=sc.nextInt();
				}
			}
			solveSmall();
		}
	}

	void solveSmall(){
		int[][] b=new int[n][m];
		for(int j=0; j<n; j++){
			fill(b[j], 100);
		}
		for(int j=0; j<n; j++){
			int max=0;
			for(int i=0; i<m; i++){
				max=max(max, a[j][i]);
			}
			for(int i=0; i<m; i++){
				b[j][i]=min(b[j][i], max);
			}
		}
		for(int i=0; i<m; i++){
			int max=0;
			for(int j=0; j<n; j++){
				max=max(max, a[j][i]);
			}
			for(int j=0; j<n; j++){
				b[j][i]=min(b[j][i], max);
			}
		}
		boolean ok=true;
		for(int j=0; j<n; j++){
			for(int i=0; i<m; i++){
				ok&=b[j][i]==a[j][i];
			}
//			debug(b[j]);
		}
		answer(ok?"YES":"NO");
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
