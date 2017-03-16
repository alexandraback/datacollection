import java.util.*;
import java.util.Map.Entry;
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
	int n;
	int[] a;

	void run(){
		T=sc.nextInt();
		sc.nextLine();
		for(caze=1; caze<=T; caze++){
			n=sc.nextInt();
			a=new int[n];
			for(int i=0; i<n; i++){
				a[i]=sc.nextInt();
			}
			solveSmall();
		}
	}

	void solveSmall(){
		boolean ok=false;
		HashMap<Integer, ArrayList<Integer>> map=new HashMap<Integer, ArrayList<Integer>>();
		for(int sup=0; sup<1<<n; sup++){
			int tot=0;
			for(int i=0; i<n; i++){
				if((sup>>i&1)==1){
					tot+=a[i];
				}
			}
			if(!map.containsKey(tot)){
				map.put(tot, new ArrayList<Integer>());
			}
			map.get(tot).add(sup);
		}
		for(Entry<Integer, ArrayList<Integer>> entry : map.entrySet()){
			ArrayList<Integer> list=entry.getValue();
			if(list.size()>1){
				int sup0=list.get(0);
				int[] is0=new int[Integer.bitCount(sup0)];
				int index=0;
				for(int i=0; i<n; i++){
					if((sup0>>i&1)==1){
						is0[index++]=a[i];
					}
				}
				sort(is0);
				for(int j=1; j<list.size(); j++){
					int sup=list.get(j);
					int[] is=new int[Integer.bitCount(sup)];
					index=0;
					for(int i=0; i<n; i++){
						if((sup>>i&1)==1){
							is[index++]=a[i];
						}
					}
					sort(is);
					if(compare(is0, is)){
						ok=true;
						output(is0, is);
						break;
					}
				}
			}
			if(ok){
				break;
			}
		}
		if(!ok){
			println("Impossible");
		}
	}

	boolean compare(int[] is1, int[] is2){
		if(is1.length!=is2.length){
			return true;
		}
		for(int i=0; i<is1.length; i++){
			if(is1[i]!=is2[i]){
				return true;
			}
		}
		return false;
	}

	void output(int[] is1, int[] is2){
		answer("");
		StringBuilder sb=new StringBuilder();
		for(int i=0; i<is1.length; i++){
			sb.append(is1[i]);
			if(i<is1.length-1){
				sb.append(' ');
			}else{
				sb.append('\n');
			}
		}
		for(int i=0; i<is2.length; i++){
			sb.append(is2[i]);
			if(i<is2.length-1){
				sb.append(' ');
			}else{
			}
		}
		println(sb.toString());
	}

	void solveLarge(){

	}

	void answer(String s){
		println("Case #"+caze+":"+s);
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
			System.setOut(new PrintStream(new FileOutputStream(
					"dat/C-small.out")));
		}catch(Exception e){}
		new C().run();
		System.out.flush();
		System.out.close();
	}
}
