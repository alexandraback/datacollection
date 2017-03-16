import java.io.*;
import java.util.*;
import java.math.BigInteger;

/*
Problem C. BFFs
4
4
2 3 4 1
4
3 3 4 1
4
3 3 4 3
10
7 8 10 10 9 2 9 6 3 3
 */

public class r1ac2 {

	public static int[] f = new int[1001];
	public static int n,m;
	public static int[] r = new int[1001];
	
	public static void check(int d){
		
		int i;
		if((f[r[1]]!=r[2]) && (f[r[1]]!=r[d]))
			return;
		if((f[r[d]]!=r[d-1]) && (f[r[d]]!=r[1]))
			return;
		for(i=2;i<=d-1;i++){
			if((f[r[i]]!=r[i-1]) && (f[r[i]]!=r[i+1]))
				return;
		}
		if(d>m)
			m=d;
	}
	
	public static void dps(int x,int d){
		int i;
		for(i=1;i<d;i++)
			if(r[i]==x)
				return;
		r[d]=x;
		if(d>m)
			check(d);
		dps(f[x],d+1);
		for(i=1;i<=n;i++)
			if(f[i]==x)
				dps(i,d+1);
		r[d]=0;
	}
	
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		// For STDIN, put two stars below.
		// For File In, put one star below.
		/*/
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		/*/
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/sample.in"))));
		/**/
		int t,i,j,k;
		t=sc.nextInt();
		for(i=1;i<=t;i++){
			if(i!=1)
				System.out.println();
			System.out.print("Case #"+i+": ");
			n=sc.nextInt();
			int tmp;
			for(j=1;j<=n;j++){
				tmp=sc.nextInt();
				f[j]=tmp;
			}
			int ans=0;
			m=1;
			for(j=1;j<=n;j++){
				dps(j,1);
			}
			System.out.print(m);
		}
		
	}

}
