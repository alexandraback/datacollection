package iC;

import java.util.ArrayList;
import java.util.Scanner;

public class C1 {

	public static ArrayList<String> pair = new ArrayList<>();
	public static ArrayList<String> comb = new ArrayList<>();
	
	public static ArrayList<String> work(int j, int p, int s, int k){
		ArrayList<String> result = new ArrayList<>();
		boolean jail = false;
		
		for(int i=1; i<=j; i++){
			for(int m=1; m<=p; m++){
				for(int n=1; n<=s; n++){
					jail=false;
					if(comb.contains(Integer.toString(i)+Integer.toString(m)+Integer.toString(n))){
						jail = true;
					}
					if(countPair(i, m, n)>=k){
						jail = true;
					}
					if(!jail){
						result.add(Integer.toString(i)+" "+Integer.toString(m)+" "+Integer.toString(n));
						comb.add(Integer.toString(i)+Integer.toString(m)+Integer.toString(n));
						pair.add(Integer.toString(i)+Integer.toString(m)+Integer.toString(0));
						pair.add(Integer.toString(i)+Integer.toString(0)+Integer.toString(n));
						pair.add(Integer.toString(0)+Integer.toString(m)+Integer.toString(n));
					}
				}
			}
		}
		return result;
	}
	
	public static int countPair(int j, int p, int s){
		String jp = Integer.toString(j)+Integer.toString(p)+Integer.toString(0);
		String js = Integer.toString(j)+Integer.toString(0)+Integer.toString(s);
		String ps = Integer.toString(0)+Integer.toString(p)+Integer.toString(s);
		int maxjp = 0, maxjs = 0, maxps = 0;
		
		for(int i=0; i<pair.size(); i++){
			//System.out.println("Pair: "+pair.get(i));
			if(pair.get(i).compareTo(jp)==0){
				maxjp++;
			}
			if(pair.get(i).compareTo(js)==0){
				maxjs++;
			}
			if(pair.get(i).compareTo(ps)==0){
				maxps++;
			}
		}
		
		//System.out.println("CountPair: "+j+" "+p+" "+s+" "+maxjp+" "+maxjs+" "+maxps);
		
		if(maxjp>maxjs && maxjp>maxps)
			return maxjp;
		if(maxjs>maxjp && maxjs>maxps)
			return maxjs;
		return maxps;
		
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		
		for (int i = 1; i <= t; ++i) {
			pair = new ArrayList<>();
			comb = new ArrayList<>();
			int j = in.nextInt();
			int p = in.nextInt();
			int s = in.nextInt();
			int k = in.nextInt();
			
			ArrayList<String> result = work(j,p,s,k);
			System.out.println("Case #" + i + ": " + result.size());
			
			for(int m=0; m<result.size(); m++)
				System.out.println(result.get(m));
			
		}

	}

}
