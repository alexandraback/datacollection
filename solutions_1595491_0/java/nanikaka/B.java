package gcj2012.qual;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class B {

	final boolean DEBUG = false;
	final String PACKAGE = "gcj2012/qual";
	final String PROBLEM = "B";
	
	boolean noSurprise(int x, int p){
		int y = x-p;
		if(y<0)return false;
		if(1<=p){
			if(y==p-1+p-1)return true;
			if(y==p+p-1)return true;
		}
		if(y==p+p)return true;
		if(p+1<=10){
			if(y==p+p+1)return true;
			if(y==p+1+p+1)return true;
		}
		return false;
	}
	boolean surprise(int x, int p){
		int y = x-p;
		if(y<0)return false;
		if(2<=p){
			if(y==p-2+p)return true;
			if(y==p-2+p-2)return true;
			if(y==p-2+p-1)return true;
		}
		if(p+2<=10){
			if(y==p+2+p)return true;
			if(y==p+2+p+1)return true;
			if(y==p+2+p+2)return true;
		}
		return false;
	}
	
	void run(){
		if(!DEBUG){
			try {
				System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small.in")));
//				System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large.in")));
				System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small_out.txt")));
//				System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large_out.txt")));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		boolean[][] nosup = new boolean[31][11], sup = new boolean[31][11], ns = new boolean[31][11], s = new boolean[31][11];
		for(int x=0;x<=30;x++)for(int p=0;p<=10;p++){
			nosup[x][p] = noSurprise(x, p); sup[x][p] = surprise(x, p);
		}
		for(int x=0;x<=30;x++)for(int p=0;p<=10;p++){
			boolean f = false;
			for(int k=p;k<=10;k++)f|=nosup[x][k];
			ns[x][p] = f;
			f = false;
			for(int k=p;k<=10;k++)f|=sup[x][k];
			s[x][p] = f;
		}
		for(int CASE=1;CASE<=T;CASE++){
			int N = sc.nextInt(), S = sc.nextInt(), P = sc.nextInt();
			int[] t = new int[N];
			for(int i=0;i<N;i++)t[i]=sc.nextInt();
			boolean[] proc = new boolean[N];
			for(int i=0;i<N&&0<S;i++)if(!ns[t[i]][P]&&s[t[i]][P]){
				S--; proc[i] = true;
			}
			for(int i=0;i<N&&0<S;i++){
				if(proc[i])continue;
				if(s[t[i]][P]){
					proc[i] = true; S--;
				}
			}
			for(int i=0;i<N&&0<S;i++){
				if(proc[i])continue;
				if(s[t[i]][0]){
					proc[i] = true; S--;
				}
			}
			int res = 0;
			for(int i=0;i<N;i++){
				if(proc[i])res+=s[t[i]][P]?1:0;
				else res+=ns[t[i]][P]?1:0;
			}
			System.out.println("Case #"+CASE+": "+res);
		}
	}
	
	public static void main(String[] args) {
		new B().run();
	}
}
