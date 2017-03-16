import java.util.ArrayList;
import java.util.Scanner;

public class RecycledNumbers {
	static ArrayList<pair> list=new ArrayList<pair>();
	public static void main(String[] args) {
		int pow[]=new int[10];
		for(int i=0;i<10;i++){
			pow[i]=(int)Math.pow(10, i);
		}
		
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++){
			int a=sc.nextInt();
			int b=sc.nextInt();
			int ans=0;
			for(int n=a;n<=b;n++){
				int keta=0;
				for(int k=10;n/k>0;k*=10)
					keta++;
				list.clear();
				for(int k=0;k<keta;k++){
					int m=n/pow[k+1]+(n%pow[k+1])*pow[keta-k];
					if(n<m && m<=b){
						if(some(n,m)){
							list.add(new pair(n,m));
							ans++;
						}
					}
				}
			}
			System.out.println("Case #"+(i+1)+": "+ans);
		}
	}
	static boolean some(int n,int m){
		for(pair p : list){
			if(p.equals(n, m)){
				return false;
			}
		}
		return true;
	}
	static class pair{
		int n,m;
		public pair(int n,int m){
			this.n=n;
			this.m=m;
		}
		public boolean equals(int n,int m){
			return this.n==n && this.m==m;
		}
	}
}
