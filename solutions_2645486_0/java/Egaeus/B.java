import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.lang.Integer.*;
import static java.lang.Math.*;


public class B {
	static long arr[];
	static int E,R,N;
	static long mem[][];
	static long sol(int i,int e) {
		if(i==N)return 0;
		if(mem[i][e]>=0)return mem[i][e];
		long max=0;
		for(int I=0;I<=e;I++)
			max=max(max,sol(i+1,min(E,e-I+R))+arr[i]*I);
		return mem[i][e]=max;
	}
	public static void main(String[] args) throws Throwable{
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		System.setOut(new PrintStream("b.out"));
		mem=new long[1000][1000];
		for(int t=0,T=parseInt(in.readLine().trim());t++<T;) {
			StringTokenizer st=new StringTokenizer(in.readLine());
			E=parseInt(st.nextToken());R=parseInt(st.nextToken());N=parseInt(st.nextToken());
			st=new StringTokenizer(in.readLine());
			arr=new long[N];
			for(int i=0;i<N;i++)arr[i]=parseInt(st.nextToken());
			for(long[] s:mem)Arrays.fill(s, -1);
			System.out.println("Case #"+t+": "+sol(0,E));	
		}
	}
}