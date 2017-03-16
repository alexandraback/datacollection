package temp;

import java.util.Arrays;
import java.util.Scanner;

public class D {

	static int N;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int T =sc.nextInt();
		for(int t=1;t<=T;t++){
			System.out.print("Case #"+t+": ");
			N=sc.nextInt();
			double[] a = new double[N];
			
			double[] b = new double[N];
			double[] perm = new double[N];
			for(int i=0;i<N;i++){
				a[i]=sc.nextDouble();
			}
			for(int i=0;i<N;i++){
				b[i]=sc.nextDouble();
			}
			Arrays.sort(a);
			Arrays.sort(b);
			for(int i=0;i<N;i++){
//				System.out.println(a[N-i-1]+ " " + b[N-i-1]);
			}
			System.out.println(war2(a,b)+" "+war1(a,b));
//			System.out.println(war2(a,b));
		}
	}
	static int perm1(double[] a,double[] b,double perm[],int used){
		if(Integer.bitCount(used)==N){
			return war1(perm,b);
		}
		int depth=Integer.bitCount(used);
		int max=-1;
		for(int i=0;i<N;i++){
			int bit = 1 << i;
			if((bit&used)>0)continue;
			perm[depth]=a[i];
			max=Math.max(max,perm1(a,b,perm,used+bit));
		}
		return max;
	}
	static int perm2(double[] a,double[] b,double perm[],int used){
		if(Integer.bitCount(used)==N){
			return war2(perm,b);
		}
		int depth=Integer.bitCount(used);
		int max=-1;
		for(int i=0;i<N;i++){
			int bit = 1 << i;
			if((bit&used)>0)continue;
			perm[depth]=a[i];
			max=Math.max(max,perm2(a,b,perm,used+bit));
		}
		return max;
	}
	/*
	static int war2(double[] a,double[] b){
		int res = 0;
		int used=0;
		for(int i=0;i<N;i++){
			int win =1;
			for(int j=N-1;j>=0;j--){
				int bit = 1<<j;
				if((bit&used)>0)continue;
				if(a[i]<b[j]){
					win=0;
					used+=bit;
					break;
				}
			}
			if(win==1){
				for(int j=0;j<N;j++){
					int bit = 1<<j;
					if((bit&used)==0){
						used+=bit;
						break;
					}
				}
			}
			res+=win;
		}
		return res;
	}
	*/
	
	static int war2(double[] a,double[] b){
		int res = 0;
		int used=0;
		for(int i=0;i<N;i++){
			int win =0;
			for(int j=0;j<N;j++){
				int bit = 1<<j;
				if((bit&used)>0)continue;
				if(a[i]>b[j]){
					win=1;
					used+=bit;
					break;
				}
			}
			if(win==0){
				for(int j=N-1;j>=0;j--){
					int bit = 1<<j;
					if((bit&used)>0)continue;
					used+=bit;
					break;
				}
			}
			res+=win;
		}
		return res;
	}
	
	static int war1(double[] a,double[] b){
		int res = 0;
		int used=0;
		for(int i=0;i<N;i++){
			int win =1;
			for(int j=0;j<N;j++){
				int bit = 1<<j;
				if((bit&used)>0)continue;
				if(a[i]<b[j]){
					win=0;
					used+=bit;
					break;
				}
			}
			if(win==1){
				for(int j=0;j<N;j++){
					int bit = 1<<j;
					if((bit&used)==0){
						used+=bit;
						break;
					}
				}
			}
			res+=win;
		}
		return res;
	}
	
	
}
