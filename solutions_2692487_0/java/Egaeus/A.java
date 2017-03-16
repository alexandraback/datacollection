import java.io.*;
import static java.lang.Integer.*;
import static java.lang.Math.*;
import java.util.*;
public class A {
	static int[] arr;
	static int[][] mem;
	static int max;
	static int f(int p,int v) {
		if(p==arr.length)return 0;
		if(mem[p][v]>-1)return mem[p][v];
		if(v>arr[p])return f(p+1,min(max+1,v+arr[p]));	
		if(v>1)
			return min(f(p+1,v),f(p,min(max+1,2*v-1)))+1;
		return f(p+1,v)+1;
	}
	public static void main(String[] args) throws Throwable{
		mem=new int[100][1000002];
		Scanner sc=new Scanner(new File("A-small-attempt2.in"));
		System.setOut(new PrintStream("A.out"));
		for(int t=0,T=sc.nextInt();t++<T;) {
			int A=sc.nextInt(),N=sc.nextInt();
			arr=new int[N];
			max=0;
			for(int i=0;i<N;i++){
				arr[i]=sc.nextInt();
				max=max(max,arr[i]);
			}
			for(int i=0;i<N;i++)
				for(int j=0;j<=max+1;j++)
					mem[i][j]=-1;
			Arrays.sort(arr);
			System.out.println("Case #"+t+": "+f(0,A));
		}
	}
}
