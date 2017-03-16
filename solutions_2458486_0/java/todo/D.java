import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class D{
	Scanner sc=new Scanner(System.in);

	int INF=1<<28;
	double EPS=1e-9;

	int caze, T;
	int n;
	int[] start, needs;
	int[][] gets;
	int nKey;

	void run(){
		T=sc.nextInt();
		for(caze=1; caze<=T; caze++){
			int k=sc.nextInt();
			n=sc.nextInt();
			start=new int[k];
			for(int i=0; i<k; i++){
				start[i]=sc.nextInt();
			}
			needs=new int[n];
			gets=new int[n][];
			for(int j=0; j<n; j++){
				needs[j]=sc.nextInt();
				k=sc.nextInt();
				gets[j]=new int[k];
				for(int i=0; i<k; i++){
					gets[j][i]=sc.nextInt();
				}
			}
			solveSmall();
		}
	}

	void solveSmall(){
		// ƒL[ˆ³k
		TreeSet<Integer> set=new TreeSet<Integer>();
		for(int i : start){
			set.add(i);
		}
		for(int i : needs){
			set.add(i);
		}
		for(int[] is : gets){
			for(int i : is){
				set.add(i);
			}
		}
		Integer[] is=set.toArray(new Integer[0]);
		nKey=is.length;
		compress(start, is);
		compress(needs, is);
		for(int[] a : gets){
			compress(a, is);
		}
		if(false){
			debug("nKey", nKey);
			debug("start", start);
			debug("needs", needs);
			for(int[] a : gets){
				debug("gets", a);
			}
		}

		boolean[] used=new boolean[n];
		LinkedList<Integer> ans=new LinkedList<Integer>();
		for(int k=0; k<n; k++){
			for(int i=0; i<n; i++){
				if(used[i]){
					continue;
				}
				ans.addLast(i);
				if(can(ans)){
					used[i]=true;
					break;
				}else{
					ans.removeLast();
				}
				// ¡‚Ü‚Å+i‚ÅƒS[ƒ‹‚Å‚«‚é‚©
			}
		}
		if(ans.size()==n){
			String s="";
			for(int i : ans){
				s+=(i+1)+" ";
			}
			answer(s.trim());
		}else{
			answer("IMPOSSIBLE");
		}
		// debug("ans", ans);
		// debug();
	}

	void compress(int[] a, Integer[] is){
		for(int i=0; i<a.length; i++){
			a[i]=binarySearch(is, a[i]);
		}
	}

	boolean can(List<Integer> list){
		int[] has=new int[nKey];
		for(int k : start){
			has[k]++;
		}
		int state=0;
		for(int i : list){
			if(--has[needs[i]]<0){
				return false;
			}
			for(int k : gets[i]){
				has[k]++;
			}
			state|=1<<i;
		}
		boolean[] dp=new boolean[1<<n];
		dp[state]=true;
		for(int s=0; s<1<<n; s++){
			if(!dp[s]){
				continue;
			}
			fill(has, 0);
			for(int k : start){
				has[k]++;
			}
			for(int i=0; i<n; i++){
				if((s>>i&1)==1){
					has[needs[i]]--;
					for(int k : gets[i]){
						has[k]++;
					}
				}
			}
			// debug(has);
			for(int i=0; i<n; i++){
				if((s>>i&1)==1){
					continue;
				}
				if(has[needs[i]]>0){
					dp[s|(1<<i)]=true;
				}
			}
			// debug(Integer.toBinaryString(s), dp[s]);
		}
		return dp[(1<<n)-1];
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
		new D().run();
	}
}
