import java.io.*;
import java.util.*;
import java.math.*;

public class C {

    public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int i=0; i<t; i++){
			int n = in.nextInt();
			int[] f = new int[n];
			for(int j=0; j<n; j++){
				f[j] = in.nextInt()-1;
			}
			System.out.println("Case #"+(i+1)+": "+solve(f));
		}
	}
	
	public static int solve(int[] f){
		//could have all some people --> pair <--- some poeple
		ArrayList<ArrayList<Integer>> reverse = new ArrayList<ArrayList<Integer>>();
		for(int i=0; i<f.length; i++){
			reverse.add(new ArrayList<Integer>());
		}
		for(int i=0; i<f.length; i++){
			reverse.get(f[i]).add(i);
		}
		
		int pairsCount = 0;
		for(int i=0; i<f.length; i++){
			if(f[f[i]] == i){
				int a = findMax(reverse, i, f[i]);
				int b = findMax(reverse, f[i], i);
				pairsCount = pairsCount+a+b+2;
			}
		}
		pairsCount /= 2;
		
		//or simply one big cycle
		boolean[] seen = new boolean[f.length];
		int max = 0;//size of max cycle
		
		for(int s =0; s<seen.length; s++){
			int[] order = new int[f.length];
			int o = 1;
			if(!seen[s]){
				seen[s] = true;
				order[s] = o;
				o++;
				int n = f[s];
				while(!seen[n]){
					seen[n] = true;
					order[n] = o;
					o++;
					n = f[n];
				}
				if (order[n] != 0){
					int c = o - order[n];//is there a -1
					if(c>max)
						max = c;
				}
			}
		}
		
		return max>pairsCount ? max : pairsCount;
	}
	
	public static int findMax(ArrayList<ArrayList<Integer>> a, int i, int pair){
		ArrayList<Integer> a2 = a.get(i);
		if(a2.size() == 1)
			return 0;
		int max = 0;
		for(Integer x : a2){
			if(x != pair){
				int l = findMax(a, x);
				if(l>max)
					max = l;
			}
		}
		return max;
	}
	
	public static int findMax(ArrayList<ArrayList<Integer>> a, int i){
		ArrayList<Integer> a2 = a.get(i);
		int max = 0;
		for(Integer x : a2){
			int l = findMax(a, x);
			if(l>max)
				max = l;
		}
		return max+1;
	}
	
	//3 possibilities,  all pairs, a cycle, any number of w
		
		/*//count pairs
		int pairsCount = 0;
		for(int i=0; i<f.length; i++){
			if(f[f[i]] == i)
				pairsCount++;
		}
		pairsCount /= 2;
		
		boolean[] seen = new boolean[f.length];
		int max = 0;
		int twoCount = 0;
		
		
		for(int s =0; s<seen.length; s++){
			int[] order = new int[f.length];
			int o = 1;
			if(!seen[s]){
				seen[s] = true;
				order[s] = o;
				o++;
				int n = f[s];
				while(!seen[n]){
					seen[n] = true;
					order[n] = o;
					o++;
					n = f[n];
				}
				if (order[n] != 0){
					int c = o - order[n];//is there a -1
					if(c>max)
						max = c;
				}
			}
		}
		*/
}