package gcj2012.r1b;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	final boolean DEBUG = false;
	final boolean isSmall = true;
	final String PACKAGE = "gcj2012/r1b";
	final String PROBLEM = "A";
	
	void run(){
		if(!DEBUG){
			try {
				if(isSmall)System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small.in")));
				else System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large.in")));
				if(isSmall)System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small_out.txt")));
				else System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large_out.txt")));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		double EPS = 1e-10;
		for(int CASE=1;CASE<=T;CASE++){
			int N = sc.nextInt();
			int J = 0;
			int[] s = new int[N];
			for(int i=0;i<N;i++){
				s[i] = sc.nextInt();
				J+=s[i];
			}
			double[] res = new double[N];
			for(int i=0;i<N;i++){
				int[] a = new int[N-1];
				int id = 0;
				for(int j=0;j<N;j++){
					if(i==j)continue;
					a[id++] = s[j];
				}
				Arrays.sort(a);
				double rest = J;
				int n = 1;
				double now = s[i];
				for(int j=0;j<N-1&&EPS<rest;j++){
					if(a[j]<now){
						if(now-a[j]<=rest){
							n++; rest-=now-a[j]; continue;
						}
						else rest = 0;
					}
					else {
						if((a[j]-now)*n < rest+EPS){
							rest-=(a[j]-now)*n; n++; now = a[j];
						}
						else{
							now += rest/n;
							rest = 0;
						}
					}
				}
				if(EPS<rest)now+=rest/n;
				res[i] = (now-s[i])/J;
			}
			System.out.print("Case #"+CASE+":");
			for(int i=0;i<N;i++)System.out.printf(" %.8f", res[i]*100);
			System.out.println();
		}
	}
	
	public static void main(String[] args) {
		new A().run();
	}
}
