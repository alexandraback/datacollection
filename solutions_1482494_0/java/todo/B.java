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

	int n;
	int[] a, b;

	void run(){
		T=sc.nextInt();
		sc.nextLine();
		for(caze=1; caze<=T; caze++){
			n=sc.nextInt();
			a=new int[n];
			b=new int[n];
			for(int i=0; i<n; i++){
				a[i]=sc.nextInt();
				b[i]=sc.nextInt();
			}
			solveSmall();
		}
	}

	void solveSmall(){
		TreeSet<Pair> bSet=new TreeSet<Pair>();
		for(int i=0; i<n; i++){
			bSet.add(new Pair(i, b[i], 1));
		}
		int min=INF;
		boolean[] used=new boolean[n];
		for(int sup=0; sup<1<<n; sup++){
			TreeSet<Pair> set=new TreeSet<Pair>();
			set.addAll(bSet);
			for(int i=0; i<n; i++){
				if((sup>>i&1)==1){
					set.add(new Pair(i, a[i], 0));
				}
			}
			fill(used, false);
			boolean ok=true;
			int star=0;
			for(Pair pair : set){
				if(pair.star>star){
					ok=false;
					break;
				}else{
					if(pair.flag==0){
						if(used[pair.index]){

						}else{
							star+=1;
							used[pair.index]=true;
						}
					}else{
						if(used[pair.index]){
							star+=1;
						}else{
							star+=2;
							used[pair.index]=true;
						}
					}
				}
			}
			if(ok){
				min=min(min, Integer.bitCount(sup)+n);
			}
		}
		if(min==INF){
			answer("Too Bad");
		}else{
			answer(""+min);
		}
	}

	class Pair implements Comparable<Pair>{
		int index, star;
		int flag;

		Pair(int index, int star, int flag){
			this.index=index;
			this.star=star;
			this.flag=flag;
		}

		@Override
		public int compareTo(Pair p){
			if(star!=p.star){
				return star-p.star;
			}else if(flag!=p.flag){
				return flag-p.flag;
			}else{
				return index-p.index;
			}
		}
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
