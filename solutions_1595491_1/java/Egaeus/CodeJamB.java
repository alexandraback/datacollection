import java.io.*;
import java.util.*;
import static java.lang.Integer.*;
import static java.lang.Math.*;
public class CodeJamB {
	static boolean is(int a){
		return a>=0&&a<=10;
	}
	static int normal(int n){
		int max=0;
		if(n%3==0)max=n/3;
		if((n+1)%3==0&&is((n+1)/3)&&is((n+1)/3-1))max=max(max,(n+1)/3);
		if((n-1)%3==0&&is((n-1)/3)&&is((n-1)/3+1))max=max(max,(n-1)/3+1);
		return max;
	}
	static int aNormal(int n){
		int max=0;
		if((n-3)%3==0&&is((n-3)/3)&&is((n-3)/3+1)&&is((n-3)/3+2))max=(n-3)/3+2;
		if((n+2)%3==0&&is((n+2)/3)&&is((n+2)/3-2))max=max(max,(n+2)/3);
		if((n-2)%3==0&&is((n-2)/3)&&is((n-2)/3+2))max=max(max,(n-2)/3+2);
		return max;
	}
	static long f(int i,int s){
		if(s<0)return MIN_VALUE;
		if(i==arr.length)return 0;
		if(mem[i][s]>-1)return mem[i][s];
		return mem[i][s]=max(f(i+1,s-1)+(aNormal(arr[i])>=p?1:0),f(i+1,s)+(normal(arr[i])>=p?1:0));
	}
	static int arr[],p;
	static long[][] mem;
	public static void main(String args[]) throws Throwable {
		System.setOut(new PrintStream("B-Large.out"));
		BufferedReader in = new BufferedReader(new FileReader("B-large.in"));
		//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		for (int t=0,T=parseInt(in.readLine().trim());t++<T;) {
			StringTokenizer st=new StringTokenizer(in.readLine());
			int N=parseInt(st.nextToken()),S=parseInt(st.nextToken());
			p=parseInt(st.nextToken());
			arr=new int[N];mem=new long[N][S+1];
			for(long[] m:mem)Arrays.fill(m,-1);
			for(int i=0;i<N;i++)arr[i]=parseInt(st.nextToken());
			sb.append("Case #"+t+": "+f(0,S)+"\n");
		}
		System.out.print(new String(sb));
	}
}
