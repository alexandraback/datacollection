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
	int n, s, p;
	int[] ts;

	void run(){
		T=sc.nextInt();
		for(caze=1; caze<=T; caze++){
			n=sc.nextInt();
			s=sc.nextInt();
			p=sc.nextInt();
			ts=new int[n];
			for(int i=0; i<n; i++){
				ts[i]=sc.nextInt();
			}
			solve();
		}
	}

	void solve(){
		int count1=0, count2=0, count3=0;
		for(int i=0; i<n; i++){
			int t=ts[i];
			int max1, max2;
			if(t%3==0){
				max1=t/3;
				if(t>=3){
					max2=t/3+1;
				}else{
					max2=t/3;
				}
			}else if(t%3==1){
				max1=max2=t/3+1;
			}else{
				max1=t/3+1;
				max2=t/3+2;
			}
			max2=min(max2, 10);
			if(max1<p&&max2<p){
				count1++;
			}else if(max1<p&&max2>=p){
				count2++;
			}else{
				count3++;
			}
			// debug(t, max1, max2, p);
		}
		int ans=count3+min(count2, s);
		answer(ans+"");
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
			System.setIn(new FileInputStream("dat/B-small.in"));
			System.setOut(new PrintStream(new FileOutputStream(
					"dat/B-small.out")));
		}catch(Exception e){}
		new B().run();
		System.out.flush();
		System.out.close();
	}
}
