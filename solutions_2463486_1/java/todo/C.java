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
	long a, b;

	void run(){
		T=sc.nextInt();
		for(caze=1; caze<=T; caze++){
			a=sc.nextLong();
			b=sc.nextLong();
			solveSmall();
		}
	}

	TreeSet<Long> set;

	void solveSmall(){
		// ‰ñ•¶”‚Ì©æ‚Å‚»‚ê‚ª‰ñ•¶”
		if(set==null){
			set=new TreeSet<Long>();
			for(long i=1; i<1e7; i++){
				if(palin(i)&&palin(i*i)){
//					debug(i*i, i);
					set.add(i*i);
				}
			}
		}
		answer(set.subSet(a, true, b, true).size()+"");
	}

	boolean palin(long a){
		StringBuilder sb=new StringBuilder().append(a);
		return sb.toString().equals(sb.reverse().toString());
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
		new C().run();
	}
}
