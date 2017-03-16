import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class C{
	Scanner sc=new Scanner(System.in);

	int INF=1<<28;
	double EPS=1e-9;

	int caze, T;
	int A, B;

	void run(){
		T=sc.nextInt();
		for(caze=1; caze<=T; caze++){
			A=sc.nextInt();
			B=sc.nextInt();
			solve();
		}
	}

	void solve(){
		int ans=0;
		for(int n=A; n<=B; n++){
			int digit=(int)(log10(n)+EPS);
			int d=(int)pow(10, digit);
			// debug("n", n);
			for(int m=rot(n, d); m!=n; m=rot(m, d)){
				// debug("m", m);
				if(n<m&&m<=B){
					ans++;
				}
			}
		}
		answer(ans+"");
	}

	int rot(int n, int d){
		return n/10+n%10*d;
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
			System.setIn(new FileInputStream("dat/C-small.in"));
			System.setOut(new PrintStream(new FileOutputStream("dat/C-small.out")));
		}catch(Exception e){}
		new C().run();
		System.out.flush();
		System.out.close();
	}
}
