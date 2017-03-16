package gcj2013.r1b;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class B {

	final boolean DEBUG = false;
	final boolean isSmall = true;
	final String PACKAGE = "gcj2013/r1b";
	final String PROBLEM = "B";
	
	int[] ys;
	double res;
	int N, X, Y;
	
	void f(int rest, int x, int y, double p){
		if(rest==0)return;
		if(y==0){
//			System.out.println((x-10000)+","+y+" P:"+p+" REST:"+rest);
			if(x==X && y==Y){
				res+=p; return;
			}
			ys[x]+=2;
			f(rest-1, 10000, ys[10000]+2, p);
			ys[x]-=2;
		}
		else{
			if(ys[x+1] < y-1 && ys[x-1] < y-1){
				f(rest, x+1, y-1, p*0.5);
				f(rest, x-1, y-1, p*0.5);
			}
			else if(ys[x+1] < y-1){
				f(rest, x+1, y-1, p);
			}
			else if(ys[x-1] < y-1){
				f(rest, x-1, y-1, p);
			}
			else{
				if(x==X && y==Y){
					res+=p; return;
				}
				ys[x]+=2;
//				System.out.println((x-10000)+","+y+" P:"+p+" REST:"+rest);
				f(rest-1, 10000, ys[10000]+2, p);
				ys[x]-=2;
			}
		}
	}
	
	
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
		ys = new int[20001];
		for(int CASE=1;CASE<=T;CASE++){
			for(int i=0;i<=20000;i++)ys[i]=i%2==0?-2:-1;
			N = sc.nextInt();
			X = sc.nextInt()+10000;
			Y = sc.nextInt();
			res = 0;
			f(N, 10000, 0, 1.0);
			System.out.printf("Case #%d: %.10f\n", CASE, res);
		}
	}
	
	public static void main(String[] args) {
		new B().run();
	}
}
