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
	int a, b;
	double[] ps;

	void run(){
		T=sc.nextInt();
		sc.nextLine();
		for(caze=1; caze<=T; caze++){
			a=sc.nextInt();
			b=sc.nextInt();
			ps=new double[a];
			for(int i=0; i<a; i++){
				ps[i]=sc.nextDouble();
			}
			solve();
		}
	}

	void test(){
		a=10000;
		b=100000;
		ps=new double[a];
		for(int i=0; i<a; i++){
			ps[i]=Math.random();
		}
		// solveSmall();
		solve();
	}

	void solveSmall(){
		double e1=0;
		double[] e2=new double[a];
		double e3=0;

		for(int sup=0; sup<1<<a; sup++){
			double p=1;
			int first=INF;
			for(int i=0; i<a; i++){
				if((sup>>i&1)==1){
					p*=(1-ps[i]);
					first=min(first, i);
				}else{
					p*=ps[i];
				}
			}
			// (1)
			if(sup==0){
				e1+=p*(b-a+1);
			}else{
				e1+=p*(b-a+1+b+1);
			}
			// (2)
			for(int i=1;i<=a;i++){
				if(a-i<=first){
					e2[i-1]+=p*(i+i+b-a+1);
				}else{
					e2[i-1]+=p*(i+i+b-a+1+b+1);
				}
			}
			
			//(3)
			e3+=p*(1+b+1);
		}
		
		debug(e1,e2,e3);
		
		double min=Double.MAX_VALUE;
		min=min(min,e1);
		for(int i=0;i<a;i++){
			min=min(min,e2[i]);
		}
		min=min(min,e3);
		debug(min);
	}

	void solve(){
		double[] miss=new double[a+1];
		double p=1;
		for(int i=0; i<a; i++){
			miss[i]=p*(1-ps[i]);
			p*=ps[i];
		}
		miss[a]=p;
		double min=Double.MAX_VALUE;
		// (1)
		double e=0;
		for(int i=0; i<a; i++){
			e+=miss[i]*(b-a+1+b+1);
		}
		e+=miss[a]*(b-a+1);
		// debug("(1)", e);
		min=min(min, e);

		// (2)
		double sum=0;
		for(int i=0; i<a; i++){
			sum+=miss[i];
		}
		double sum1=0;
		for(int i=1; i<=a; i++){
			sum1+=miss[a-i];
			double sum2=sum-sum1;
			e=0;
			e+=sum2*(i+i+b-a+1+b+1);
			e+=sum1*(i+i+b-a+1);
			e+=miss[a]*(i+i+b-a+1);
			min=min(min, e);
			// debug("(2)", i, e);
		}

		// (3)
		e=0;
		for(int i=0; i<a+1; i++){
			e+=miss[i]*(1+b+1);
		}
		// debug("(3)",e);
		min=min(min, e);

		answer(min+"");
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
			System.setIn(new FileInputStream("dat/A-large.in"));
			System.setOut(new PrintStream(new FileOutputStream(
					"dat/A-large.out")));
		}catch(Exception e){}
		new A().run();
		System.out.flush();
		System.out.close();
	}
}
