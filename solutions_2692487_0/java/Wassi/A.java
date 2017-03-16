package b1;

import java.util.Arrays;
import java.util.Scanner;

public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int t=1;t<=T;t++){
			int A = in.nextInt();
			int N = in.nextInt();
			int[] m = new int[N];
			for(int n = 0;n<N;n++) m[n] = in.nextInt();
			Arrays.sort(m);
			int action = 0;
			int moves = sol(m,A,0,0);
			
		
			System.out.println("Case #"+t+": "+moves);
		}
	
	}
	
	public static int sol(int[] m, int A, int pos, int steps){
		if(pos>=m.length) return steps;
		if(m[pos]<A){
			
			return sol(m,A+m[pos],pos+1,steps);
		}
		
		int steps1 = sol(m,A,pos+1,steps+1);
		int[] add = howManyToAdd(A, m[pos]);
		if(add[0]==1) return steps1;
		int steps2 = sol(m,add[0]+m[pos],pos+1,steps+add[1]);
		return Math.min(steps1, steps2);
	}
	public static int[] howManyToAdd(int from,int target){
		int [] res = {1,Integer.MAX_VALUE};
		if(from==1) return res;
		int cnt=0;
		while(from<=target){
			from+=from-1;
			cnt++;
		}
		res[0]=from;
		res[1]=cnt;
		return res;
	}

}
