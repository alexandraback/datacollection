import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class A{
	Scanner sc=new Scanner(System.in);

	int INF=1<<28;
	double EPS=1e-9;

	int caze, T;
	int n;
	int[] s;

	void run(){
		T=sc.nextInt();
		sc.nextLine();
		for(caze=1; caze<=T; caze++){
			n=sc.nextInt();
			s=new int[n];
			for(int i=0; i<n; i++){
				s[i]=sc.nextInt();
			}
			solveLarge();
		}
	}

	void hoge(){
		int[] a={24, 30, 21};
		double[] p={34.6667, 26.6667, 38.6667};
		int sum=0;
		for(int i=0; i<3; i++){
			sum+=a[i];
		}
		for(int i=0; i<3; i++){
			debug(a[i]+sum*p[i]/100);
		}
	}

	void solveSmall(){

	}

	int sum;

	void solveLarge(){
		double left=0, right=0;
		sum=0;
		for(int i=0; i<n; i++){
			left=max(left, s[i]);
			sum+=s[i];
		}
		right=left+sum;
		left=0;
		if(ok(right)){
			output(right);
		}else{
			for(int t=0; t<1000; t++){
				if(ok((left+right)/2)){
					left=(left+right)/2;
				}else{
					right=(left+right)/2;
				}
			}
			output(left);
		}
	}

	boolean ok(double p){
		// p‚Éo—ˆ‚é‚©
		double remain=1;
		for(int i=0; i<n; i++){
			double d=(p-s[i])/sum;
			if(d>remain+EPS){
				return false;
			}else{
				if(d>0){
					remain-=d;
				}
			}
		}
		return true;
	}

	void output(double p){
		StringBuilder sb=new StringBuilder();
		double temp=0;
		for(int i=0; i<n; i++){
			double d=(p-s[i])/sum;
			d=max(d, 0);
			sb.append(String.format("%.10f", d*100));
			if(i<n-1){
				sb.append(' ');
			}
			temp+=d*100;
		}
		debug(temp);
		answer(sb.toString());
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
		try{
			System.setIn(new FileInputStream("dat/A-small.in"));
			System.setOut(new PrintStream(new FileOutputStream(
					"dat/A-small.out")));
		}catch(Exception e){}
		new A().run();
		System.out.flush();
		System.out.close();
	}
}
